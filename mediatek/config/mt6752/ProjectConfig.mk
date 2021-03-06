MTK_CPU=arm_cortexa7

MTK_SEC_SECRO_AC_SUPPORT=yes

TARGET_ARCH_VARIANT=armv7-a-neon

MTK_FIRST_MD=1
MTK_FLIGHT_MODE_POWER_OFF_MD=yes

MTK_YAML_SCATTER_FILE_SUPPORT=yes


MTK_ION_SUPPORT=yes

MTK_ENABLE_MD1=no
MD1_SIZE=0x05000000
MD1_SMEM_SIZE=0x00000800

MTK_ENABLE_MD2=no
MD2_SIZE=0x01000000
MD2_SMEM_SIZE=0x00200000

MTK_MD1_SUPPORT=5

MTK_SWIP_VORBIS=yes

MTK_PRODUCT_INFO_SUPPORT=yes

MTK_VSS_SUPPORT=no

MTK_GPT_SCHEME_SUPPORT=yes

MTK_NATIVE_FENCE_SUPPORT=yes

MTK_USES_VR_DYNAMIC_QUALITY_MECHANISM=yes
MTK_PQ_SUPPORT=PQ_HW_VER_2
MTK_FM_RX_AUDIO=FM_DIGITAL_INPUT

MTK_BWC_SUPPORT=yes

MTK_LCEEFT_SUPPORT=yes

MTK_WFD_SUPPORT=yes

MTK_AUDIO_BLOUD_CUSTOMPARAMETER_REV=MTK_AUDIO_BLOUD_CUSTOMPARAMETER_V5

FEATURE_FTM_AUDIO_AUTOTEST=yes

# Capability of the underlay modem
#  single or gemini
MTK_SHARE_MODEM_SUPPORT=2

MTK_MD_SHUT_DOWN_NT=yes

MTK_MASS_STORAGE=yes

# common part
MTK_COMBO_SUPPORT=yes
CUSTOM_HAL_COMBO=mt6752
CUSTOM_HAL_ANT=mt6752_ant_m1
MTK_COMBO_CHIP=CONSYS_6752
#MTK_COMBO_CORE_DUMP_SUPPORT=no
#MTK_COMBO_QUICK_SLEEP_SUPPORT=no
# common part end

MTK_WLAN_SUPPORT=yes
MTK_WLAN_CHIP=CONSYS_MT6752

#
# MTK Chip
#

# BT driver part
MTK_COMBO_SUPPORT=yes
MTK_BT_SUPPORT=yes
MTK_BT_CHIP=MTK_CONSYS_MT6752


MTK_GPS_CHIP=MTK_GPS_MT6752

MTK_AUDENH_SUPPORT=yes

# display framework impl
MTK_DP_FRAMEWORK=yes

MTK_HANDSFREE_DMNR_SUPPORT=yes


MTK_VOICE_UI_SUPPORT=yes

MTK_TINY_UTIL=yes

MTK_KERNEL_POWER_OFF_CHARGING=yes

MTK_DMNR_TUNING_AT_MD=no

MTK_VIDEO_THUMBNAIL_PLAY_SUPPORT=yes

MTK_PLATFORM_OPTIMIZE=yes

MTK_CTP_RESET_CONFIG=yes

MTK_GPU_SUPPORT=yes
USE_OPENGL_RENDERER=true

MTK_VIDEO_HEVC_SUPPORT=yes
BUILD_MD32=yes
MTK_NEW_COMBO_EMMC_SUPPORT=yes
LINUX_KERNEL_VERSION=kernel-3.10

# sim switch driver
CUSTOM_KERNEL_SSW = ssw_generic_v2

# triple buffer # yu-fu
NUM_FRAMEBUFFER_SURFACE_BUFFERS=2

MTK_TLR_SUPPORT = yes
MTK_LOMO_SUPPORT=yes
MTK_CAM_GESTURE_SUPPORT=yes

MTK_CLEARMOTION_SUPPORT=no
MTK_CAM_OT_SUPPORT=yes
MTK_CAM_NR3D_SUPPORT = yes
MTK_IPO_SUPPORT=no

MTK_CAM_NATIVE_PIP_SUPPORT= yes

MTK_MERGE_INTERFACE_SUPPORT = yes
MTK_CAM_LOMO_SUPPORT=yes

MTK_PERMISSION_CONTROL = yes
MTK_MOBILE_MANAGEMENT = yes
MTK_HIGH_RESOLUTION_AUDIO_SUPPORT = yes

MTK_MMPROFILE_SUPPORT=yes
MTK_THERMAL_PA_VIA_ATCMD = yes

MTK_ATF_SUPPORT = yes
MTK_TEE_SUPPORT = no
TRUSTONIC_TEE_SUPPORT = no
MTK_ATF_BOOT_OPTION = 0
MTK_APPENDED_DTB_SUPPORT = yes
MTK_LTE_SUPPORT = yes

MTK_MIRAVISION_SETTING_SUPPORT=yes
MTK_UART_USB_SWITCH=yes
MTK_ENABLE_S263_DECODER = yes
MTK_ENABLE_DIVX_DECODER = yes
MTK_OPERAMAX_SUPPORT = Auto

MTK_SLOW_MOTION_VIDEO_SUPPORT = yes

MTK_BT_BLE_MANAGER_SUPPORT = yes
MTK_NFC_HCE_SUPPORT = yes
#MTK_BESLOUDNESS_SUPPORT = yes

MTK_SEC_MODEM_AUTH=no
MTK_SEC_MODEM_ENCODE=no
MTK_VOICE_CONTACT_SEARCH_SUPPORT = yes

MTK_VIDEO_VP8ENC_SUPPORT = yes

MTK_JAZZ=yes

MTK_BESLOUDNESS_SUPPORT=yes

MTK_SECURITY_SW_SUPPORT = yes
MTK_LOSSLESS_BT_AUDIO_SUPPORT = yes
MTK_BESSURROUND_SUPPORT = yes
MD32_TOOLCHAIN_MODULE=IPDesigner/12R2.36-64

MTK_WFD_SINK_SUPPORT = yes
MTK_WFD_SINK_UIBC_SUPPORT = yes

MTK_DOLBY_DAP_SUPPORT = yes
MTK_AUDIO_DDPLUS_SUPPORT = yes
