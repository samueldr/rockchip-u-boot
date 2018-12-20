/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef VIDEO_ROCKCHIP_H
#define VIDEO_ROCKCHIP_H

#define DRM_ROCKCHIP_FB_WIDTH		1920
#define DRM_ROCKCHIP_FB_HEIGHT		1080
#define DRM_ROCKCHIP_FB_BPP		VIDEO_BPP32

#define MEMORY_POOL_SIZE	32 * 1024 * 1024
#define DRM_ROCKCHIP_FB_SIZE \
	VNBYTES(DRM_ROCKCHIP_FB_BPP) * DRM_ROCKCHIP_FB_WIDTH * DRM_ROCKCHIP_FB_HEIGHT

void rockchip_show_bmp(const char *bmp);
void rockchip_show_logo(void);
void rockchip_display_fixup(void *blob);

#endif
