/**
 * Copyright (C) ARM Limited 2010-2014. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef GATOR_H_
#define GATOR_H_

/*****************************************************************************/
/* MET portings								     */
/*****************************************************************************/
#define	CONFIG_MET_GATOR

/* naming converting from gator_xxx to met_gator_xxx */
/* gator_fs.c */
#define	gatorfs_lock			met_gatorfs_lock
#define	gatorfs_create_ulong		met_gatorfs_create_ulong
#define	gatorfs_create_ro_ulong		met_gatorfs_create_ro_ulong
#define	gatorfs_mkdir			met_gatorfs_mkdir

/* gator_events_mali_common.c */
#define	gator_mali_get_mali_name	met_gator_mali_get_mali_name
#define	gator_mali_create_file_system	met_gator_mali_create_file_system
#define	gator_mali_initialise_counters	met_gator_mali_initialise_counters

/* gator_events_mali_t6xx_hw.c */
#define	gator_events_mali_t6xx_hw_init	met_gator_events_mali_t6xx_hw_init

/* met_mali.c */
#define	gator_events_get_key		met_gator_events_get_key
#define	gator_events_install		met_gator_events_install
#define	gator_op_create_files		met_gator_op_create_files

int gator_events_mali_t6xx_hw_init(void);
/*****************************************************************************/

#include <linux/version.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/list.h>

#define GATOR_PERF_SUPPORT		LINUX_VERSION_CODE >= KERNEL_VERSION(3, 0, 0)
#define GATOR_PERF_PMU_SUPPORT  GATOR_PERF_SUPPORT && defined(CONFIG_PERF_EVENTS) && (!(defined(__arm__) || defined(__aarch64__)) || defined(CONFIG_HW_PERF_EVENTS))
#define GATOR_NO_PERF_SUPPORT   (!(GATOR_PERF_SUPPORT))
#define GATOR_CPU_FREQ_SUPPORT  (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 38)) && defined(CONFIG_CPU_FREQ)
#define GATOR_IKS_SUPPORT       defined(CONFIG_BL_SWITCHER)

// cpu ids
#define ARM1136     0xb36
#define ARM1156     0xb56
#define ARM1176     0xb76
#define ARM11MPCORE 0xb02
#define CORTEX_A5   0xc05
#define CORTEX_A7   0xc07
#define CORTEX_A8   0xc08
#define CORTEX_A9   0xc09
#define CORTEX_A12  0xc0d
#define CORTEX_A15  0xc0f
#define CORTEX_A17  0xc0e
#define SCORPION    0x00f
#define SCORPIONMP  0x02d
#define KRAITSIM    0x049
#define KRAIT       0x04d
#define KRAIT_S4_PRO 0x06f
#define CORTEX_A53  0xd03
#define CORTEX_A57  0xd07
#define AARCH64     0xd0f
#define OTHER       0xfff

#define MAXSIZE_CORE_NAME 32

struct gator_cpu {
	const int cpuid;
	// Human readable name
	const char core_name[MAXSIZE_CORE_NAME];
	// gatorfs event and Perf PMU name
	const char * const pmnc_name;
	// compatible from Documentation/devicetree/bindings/arm/cpus.txt
	const char * const dt_name;
	const int pmnc_counters;
};

const struct gator_cpu *gator_find_cpu_by_cpuid(const u32 cpuid);
const struct gator_cpu *gator_find_cpu_by_pmu_name(const char *const name);

/******************************************************************************
 * Filesystem
 ******************************************************************************/
struct dentry *gatorfs_mkdir(struct super_block *sb, struct dentry *root,
			     char const *name);

int gatorfs_create_ulong(struct super_block *sb, struct dentry *root,
			 char const *name, unsigned long *val);

int gatorfs_create_ro_ulong(struct super_block *sb, struct dentry *root,
			    char const *name, unsigned long *val);

/******************************************************************************
 * Tracepoints
 ******************************************************************************/
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 32)
#	error Kernels prior to 2.6.32 not supported
#elif LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 35)
#	define GATOR_DEFINE_PROBE(probe_name, proto) \
		static void probe_##probe_name(PARAMS(proto))
#	define GATOR_REGISTER_TRACE(probe_name) \
		register_trace_##probe_name(probe_##probe_name)
#	define GATOR_UNREGISTER_TRACE(probe_name) \
		unregister_trace_##probe_name(probe_##probe_name)
#elif LINUX_VERSION_CODE < KERNEL_VERSION(3, 15, 0)
#	define GATOR_DEFINE_PROBE(probe_name, proto) \
		static void probe_##probe_name(void *data, PARAMS(proto))
#	define GATOR_REGISTER_TRACE(probe_name) \
		register_trace_##probe_name(probe_##probe_name, NULL)
#	define GATOR_UNREGISTER_TRACE(probe_name) \
		unregister_trace_##probe_name(probe_##probe_name, NULL)
#else
#	define GATOR_DEFINE_PROBE(probe_name, proto) \
		extern struct tracepoint *gator_tracepoint_##probe_name; \
		static void probe_##probe_name(void *data, PARAMS(proto))
#	define GATOR_REGISTER_TRACE(probe_name) \
		tracepoint_probe_register(gator_tracepoint_##probe_name, probe_##probe_name, NULL)
#	define GATOR_UNREGISTER_TRACE(probe_name) \
		tracepoint_probe_unregister(gator_tracepoint_##probe_name, probe_##probe_name, NULL)
#endif

/******************************************************************************
 * Events
 ******************************************************************************/
struct gator_interface {
	void (*shutdown)(void);	// Complementary function to init
	int (*create_files)(struct super_block *sb, struct dentry *root);
	int (*start)(void);
	void (*stop)(void);		// Complementary function to start
	int (*online)(int **buffer, bool migrate);
	int (*offline)(int **buffer, bool migrate);
	void (*online_dispatch)(int cpu, bool migrate);	// called in process context but may not be running on core 'cpu'
	void (*offline_dispatch)(int cpu, bool migrate);	// called in process context but may not be running on core 'cpu'
	int (*read)(int **buffer);
	int (*read64)(long long **buffer);
	int (*read_proc)(long long **buffer, struct task_struct *);
	struct list_head list;
};

int gator_events_install(struct gator_interface *interface);
int gator_events_get_key(void);
u32 gator_cpuid(void);

void gator_backtrace_handler(struct pt_regs *const regs);

#if !GATOR_IKS_SUPPORT

#define get_physical_cpu() smp_processor_id()
#define lcpu_to_pcpu(lcpu) lcpu
#define pcpu_to_lcpu(pcpu) pcpu

#else

#define get_physical_cpu() lcpu_to_pcpu(get_logical_cpu())
int lcpu_to_pcpu(const int lcpu);
int pcpu_to_lcpu(const int pcpu);

#endif

#define get_logical_cpu() smp_processor_id()
#define on_primary_core() (get_logical_cpu() == 0)

#endif // GATOR_H_
