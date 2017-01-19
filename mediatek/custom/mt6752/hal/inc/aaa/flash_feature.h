#ifndef __FLASH_FEATURE_H__
#define __FLASH_FEATURE_H__

// flash mode definition
typedef enum
{
    LIB3A_FLASH_MODE_UNSUPPORTED = -1,
    LIB3A_FLASH_MODE_AUTO        =  0,
    LIB3A_FLASH_MODE_SLOWSYNC    =  0, //NOW DO NOT SUPPORT SLOW SYNC, TEMPERALLY THE SAME WITH AUTO
    LIB3A_FLASH_MODE_FORCE_ON    =  1,
    LIB3A_FLASH_MODE_FORCE_OFF   =  2,
    LIB3A_FLASH_MODE_REDEYE      =  3,
    LIB3A_FLASH_MODE_FORCE_TORCH =  4,
    LIB3A_FLASH_MODE_TOTAL_NUM,
    LIB3A_FLASH_MODE_MIN = LIB3A_FLASH_MODE_AUTO,
    LIB3A_FLASH_MODE_MAX = LIB3A_FLASH_MODE_FORCE_TORCH, //cotta-- modified to TORCH for FLASH in video
}LIB3A_FLASH_MODE_T;


enum
{
    e_FLASH_STYLE_OFF_AUTO = 0,
    e_FLASH_STYLE_OFF_ON,
    e_FLASH_STYLE_OFF_OFF,
    e_FLASH_STYLE_ON_ON,
    e_FLASH_STYLE_ON_TORCH,
};

#endif //#ifndef __FLASH_FEATURE_H__
