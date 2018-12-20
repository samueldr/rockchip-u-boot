/*
 * (C) Copyright 2016 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __EVB_RK3399_H
#define __EVB_RK3399_H

#include <configs/rk3399_common.h>

#ifndef CONFIG_SPL_BUILD
#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND RKIMG_BOOTCOMMAND
#endif

#define CONFIG_MMC_SDHCI_SDMA
#define CONFIG_SYS_MMC_ENV_DEV 0

#define SDRAM_BANK_SIZE			(2UL << 30)
#define CONFIG_MISC_INIT_R
#define CONFIG_SERIAL_TAG
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BMP_16BPP
#define CONFIG_BMP_24BPP
#define CONFIG_BMP_32BPP


/*
设置"stdin=serial,usbkbd\0"  , 在console_init_r中，由于没有usb start, 
所以第一次设置stdin时，没有usbkbd，只能设置为serial, 在进入console之后
执行usb start, usbkbd probe,并且iomux_doenv(stdin), 添加usbkbd作为stdin

设置加上vidconsole之后，在console_init_r中，会搜索videoconsole设备，并且
probe，并且显示logo. 但是同时也会把stdout stderr设为vidconsole，这样会导致
串口终端中无法显示
"stdout=serial,vidconsole\0" \
"stderr=serial,vidconsole\0"
*/

#define ROCKCHIP_DEVICE_SETTINGS \
		"stdin=serial,usbkbd\0" \
		"stdout=serial,vidconsole\0" \
		"stderr=serial,vidconsole\0"

#endif
