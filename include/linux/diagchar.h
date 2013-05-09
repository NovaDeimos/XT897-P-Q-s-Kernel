/* Copyright (c) 2008-2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef DIAGCHAR_SHARED
#define DIAGCHAR_SHARED

#define MSG_MASKS_TYPE			1
#define LOG_MASKS_TYPE			2
#define EVENT_MASKS_TYPE		4
#define PKT_TYPE			8
#define DEINIT_TYPE			16
#define USER_SPACE_LOG_TYPE		32

#define USB_MODE			1
#define MEMORY_DEVICE_MODE		2
#define NO_LOGGING_MODE			3
#define UART_MODE			4
#define INTERNAL_MODE			5
#define USB_MODE_NAME			"usb"
#define MEMORY_DEVICE_MODE_NAME		"memory"
#define NO_LOGGING_MODE_NAME		"none"
#define UART_MODE_NAME			"uart"
#define INTERNAL_MODE_NAME		"internal"

#define USB_DIAG_CONNECT		0
#define USB_DIAG_DISCONNECT		1
#define USB_DIAG_WRITE_DONE		2
#define USB_DIAG_READ_DONE		3
#define CHANNEL_DIAG_CONNECT		USB_DIAG_CONNECT
#define CHANNEL_DIAG_DISCONNECT		USB_DIAG_DISCONNECT
#define CHANNEL_DIAG_WRITE_DONE		USB_DIAG_WRITE_DONE
#define CHANNEL_DIAG_READ_DONE		USB_DIAG_READ_DONE

struct diag_request {
	char *buf;
	int length;
	int actual;
	int status;
	void *context;
};

struct legacy_diag_ch {
	const char *name;
	struct list_head list;
	void (*notify)(void *priv, unsigned event, struct diag_request *d_req);
	void *priv;
	void *priv_channel;
};

/* different values that go in for diag_data_type */
#define DATA_TYPE_EVENT         	0
#define DATA_TYPE_F3            	1
#define DATA_TYPE_LOG           	2
#define DATA_TYPE_RESPONSE      	3

/* Different IOCTL values */
#define DIAG_IOCTL_COMMAND_REG  	0
#define DIAG_IOCTL_SWITCH_LOGGING	7
#define DIAG_IOCTL_GET_DELAYED_RSP_ID 	8
#define DIAG_IOCTL_LSM_DEINIT		9

/* 15 ~ 17 are allocated for slate feature */
#define DIAG_IOCTL_RESERVED_FOR_ADDON_0  15
#define DIAG_IOCTL_RESERVED_FOR_ADDON_1  16
#define DIAG_IOCTL_RESERVED_FOR_ADDON_2  17

/* Machine ID and corresponding PC Tools IDs */
#define APQ8060_MACHINE_ID	86
#define AO8960_MACHINE_ID	87
#define MSM8660_MACHINE_ID	71
#define MDM9615_MACHINE_ID	104
#define APQ8064_MACHINE_ID	109
#define MSM8930_MACHINE_ID	116
#define MSM8630_MACHINE_ID	117
#define MSM8230_MACHINE_ID	118
#define APQ8030_MACHINE_ID	119
#define MSM8627_MACHINE_ID	120
#define MSM8227_MACHINE_ID	121
#define MSM8660A_MACHINE_ID	122
#define MSM8260A_MACHINE_ID	123
#define MSM8974_MACHINE_ID	126
#define APQ8060_TOOLS_ID	4062
#define AO8960_TOOLS_ID		4064
#define APQ8064_TOOLS_ID	4072
#define MSM8930_TOOLS_ID	4072
#define MSM8974_TOOLS_ID	4072

#define MSG_MASK_0			(0x00000001)
#define MSG_MASK_1			(0x00000002)
#define MSG_MASK_2			(0x00000004)
#define MSG_MASK_3			(0x00000008)
#define MSG_MASK_4			(0x00000010)
#define MSG_MASK_5			(0x00000020)
#define MSG_MASK_6			(0x00000040)
#define MSG_MASK_7			(0x00000080)
#define MSG_MASK_8			(0x00000100)
#define MSG_MASK_9			(0x00000200)
#define MSG_MASK_10			(0x00000400)
#define MSG_MASK_11			(0x00000800)
#define MSG_MASK_12			(0x00001000)
#define MSG_MASK_13			(0x00002000)
#define MSG_MASK_14			(0x00004000)
#define MSG_MASK_15			(0x00008000)
#define MSG_MASK_16			(0x00010000)
#define MSG_MASK_17			(0x00020000)
#define MSG_MASK_18			(0x00040000)
#define MSG_MASK_19			(0x00080000)
#define MSG_MASK_20			(0x00100000)
#define MSG_MASK_21			(0x00200000)
#define MSG_MASK_22			(0x00400000)
#define MSG_MASK_23			(0x00800000)
#define MSG_MASK_24			(0x01000000)
#define MSG_MASK_25			(0x02000000)
#define MSG_MASK_26			(0x04000000)
#define MSG_MASK_27			(0x08000000)
#define MSG_MASK_28			(0x10000000)
#define MSG_MASK_29			(0x20000000)
#define MSG_MASK_30			(0x40000000)
#define MSG_MASK_31			(0x80000000)

/*  These masks are to be used for support of all legacy messages in the sw.
The user does not need to remember the names as they will be embedded in
the appropriate macros. */
#define MSG_LEGACY_LOW			MSG_MASK_0
#define MSG_LEGACY_MED			MSG_MASK_1
#define MSG_LEGACY_HIGH			MSG_MASK_2
#define MSG_LEGACY_ERROR		MSG_MASK_3
#define MSG_LEGACY_FATAL		MSG_MASK_4

/* Legacy Message Priorities */
#define MSG_LVL_FATAL			(MSG_LEGACY_FATAL)
#define MSG_LVL_ERROR			(MSG_LEGACY_ERROR | MSG_LVL_FATAL)
#define MSG_LVL_HIGH			(MSG_LEGACY_HIGH | MSG_LVL_ERROR)
#define MSG_LVL_MED			(MSG_LEGACY_MED | MSG_LVL_HIGH)
#define MSG_LVL_LOW			(MSG_LEGACY_LOW | MSG_LVL_MED)

#define MSG_LVL_NONE			0

/* This needs to be modified manually now, when we add
 a new RANGE of SSIDs to the msg_mask_tbl */
#define MSG_MASK_TBL_CNT		24
#define EVENT_LAST_ID			0x08AD

#define MSG_SSID_0			0
#define MSG_SSID_0_LAST			90
#define MSG_SSID_1			500
#define MSG_SSID_1_LAST			506
#define MSG_SSID_2			1000
#define MSG_SSID_2_LAST			1007
#define MSG_SSID_3			2000
#define MSG_SSID_3_LAST			2008
#define MSG_SSID_4			3000
#define MSG_SSID_4_LAST			3014
#define MSG_SSID_5			4000
#define MSG_SSID_5_LAST			4010
#define MSG_SSID_6			4500
#define MSG_SSID_6_LAST			4526
#define MSG_SSID_7			4600
#define MSG_SSID_7_LAST			4612
#define MSG_SSID_8			5000
#define MSG_SSID_8_LAST			5029
#define MSG_SSID_9			5500
#define MSG_SSID_9_LAST			5516
#define MSG_SSID_10			6000
#define MSG_SSID_10_LAST		6072
#define MSG_SSID_11			6500
#define MSG_SSID_11_LAST		6521
#define MSG_SSID_12			7000
#define MSG_SSID_12_LAST		7003
#define MSG_SSID_13			7100
#define MSG_SSID_13_LAST		7111
#define MSG_SSID_14			7200
#define MSG_SSID_14_LAST		7201
#define MSG_SSID_15			8000
#define MSG_SSID_15_LAST		8000
#define MSG_SSID_16			8500
#define MSG_SSID_16_LAST		8523
#define MSG_SSID_17			9000
#define MSG_SSID_17_LAST		9008
#define MSG_SSID_18			9500
#define MSG_SSID_18_LAST		9509
#define MSG_SSID_19			10200
#define MSG_SSID_19_LAST		10210
#define MSG_SSID_20			10251
#define MSG_SSID_20_LAST		10255
#define MSG_SSID_21			10300
#define MSG_SSID_21_LAST		10300
#define MSG_SSID_22			10350
#define MSG_SSID_22_LAST		10361
#define MSG_SSID_23			0xC000
#define MSG_SSID_23_LAST		0xC063

struct diagpkt_delay_params {
	void *rsp_ptr;
	int size;
	int *num_bytes_ptr;
};

static const uint32_t msg_bld_masks_0[] = {
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_ERROR,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_ERROR,
	MSG_LVL_LOW,
	MSG_LVL_ERROR,
	MSG_LVL_ERROR,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_ERROR,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_MASK_7 | \
		MSG_MASK_8|MSG_MASK_9|MSG_MASK_10|MSG_MASK_11|MSG_MASK_12 | \
		MSG_MASK_13|MSG_MASK_14|MSG_MASK_15|MSG_MASK_16 | \
		MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20|MSG_MASK_21,
	MSG_LVL_MED|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10| \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14| \
		MSG_MASK_15|MSG_MASK_16|MSG_MASK_17,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10| \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14|MSG_MASK_15| \
		MSG_MASK_16|MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20| \
		MSG_MASK_21|MSG_MASK_22|MSG_MASK_23|MSG_MASK_24|MSG_MASK_25,
	MSG_LVL_MED|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW | MSG_MASK_5 | \
		MSG_MASK_6 | MSG_MASK_7 | MSG_MASK_8,
	MSG_LVL_LOW | MSG_MASK_5 | \
		MSG_MASK_6,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_MED | MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10| \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14|MSG_MASK_15 | \
		MSG_MASK_16|MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW|MSG_LVL_MED|MSG_LVL_HIGH|MSG_LVL_ERROR|MSG_LVL_FATAL,
	MSG_LVL_MED,
	MSG_LVL_LOW|MSG_LVL_MED|MSG_LVL_HIGH|MSG_LVL_ERROR|MSG_LVL_FATAL,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_1[] = {
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH
};

static const uint32_t msg_bld_masks_2[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED,
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_3[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_4[] = {
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_5[] = {
	MSG_LVL_HIGH,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED|MSG_LVL_MED|MSG_MASK_5|MSG_MASK_6|MSG_MASK_7| \
		MSG_MASK_8|MSG_MASK_9,
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_6[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_7[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_8[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_9[] = {
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5,
	MSG_LVL_MED|MSG_MASK_5
};

static const uint32_t msg_bld_masks_10[] =  {
	MSG_LVL_MED,
	MSG_LVL_ERROR,
	MSG_LVL_LOW,
	MSG_LVL_LOW|MSG_MASK_5 | \
		MSG_MASK_6|MSG_MASK_7|MSG_MASK_8|MSG_MASK_9|MSG_MASK_10| \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14|MSG_MASK_15| \
		MSG_MASK_16|MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20| \
		MSG_MASK_21|MSG_MASK_22,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW|MSG_MASK_5,
	MSG_LVL_LOW|MSG_MASK_0 | MSG_MASK_1 | MSG_MASK_2 | \
		MSG_MASK_3 | MSG_MASK_4 | MSG_MASK_5 | MSG_MASK_6,
	MSG_LVL_HIGH,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_11[] = {
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
};

static const uint32_t msg_bld_masks_12[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_13[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_14[] = {
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_15[] = {
	MSG_LVL_MED
};

static const uint32_t msg_bld_masks_16[] = {
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
};

static const uint32_t msg_bld_masks_17[] =  {
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED,
	MSG_LVL_MED | MSG_MASK_6 | \
		MSG_MASK_7 | MSG_MASK_8 | MSG_MASK_9,
	MSG_LVL_MED | MSG_MASK_5 | \
		MSG_MASK_6 | MSG_MASK_7 | MSG_MASK_8 | MSG_MASK_9 | \
		MSG_MASK_10 | MSG_MASK_11 | MSG_MASK_12 | MSG_MASK_13 | \
		MSG_MASK_14 | MSG_MASK_15 | MSG_MASK_16 | MSG_MASK_17,
	MSG_LVL_MED,
	MSG_LVL_MED | MSG_MASK_5 | \
		MSG_MASK_6 | MSG_MASK_7 | MSG_MASK_8 | MSG_MASK_9 | \
		MSG_MASK_10 | MSG_MASK_11 | MSG_MASK_12 | MSG_MASK_13 | \
		MSG_MASK_14 | MSG_MASK_15 | MSG_MASK_16 | MSG_MASK_17 | \
		MSG_MASK_18 | MSG_MASK_19 | MSG_MASK_20 | MSG_MASK_21 | \
		MSG_MASK_22,
	MSG_LVL_MED,
	MSG_LVL_MED,
};

static const uint32_t msg_bld_masks_18[] = {
	MSG_LVL_LOW,
	MSG_LVL_LOW | MSG_MASK_8 | MSG_MASK_9 | MSG_MASK_10 | \
		MSG_MASK_11|MSG_MASK_12|MSG_MASK_13|MSG_MASK_14|MSG_MASK_15 | \
		MSG_MASK_16|MSG_MASK_17|MSG_MASK_18|MSG_MASK_19|MSG_MASK_20,
	MSG_LVL_LOW | MSG_MASK_5 | MSG_MASK_6,
	MSG_LVL_LOW | MSG_MASK_5,
	MSG_LVL_LOW | MSG_MASK_5 | MSG_MASK_6,
	MSG_LVL_LOW,
	MSG_LVL_LOW | MSG_MASK_5 | \
		MSG_MASK_6 | MSG_MASK_7 | MSG_MASK_8 | MSG_MASK_9,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_19[] = {
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_20[] = {
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW,
	MSG_LVL_LOW
};

static const uint32_t msg_bld_masks_21[] = {
	MSG_LVL_HIGH
};

static const uint32_t msg_bld_masks_22[] = {
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH,
	MSG_LVL_HIGH
};

/* LOG CODES */

#define LOG_0	0x0
#define LOG_1	0x15A7
#define LOG_2	0x0
#define LOG_3	0x0
#define LOG_4	0x4910
#define LOG_5	0x5420
#define LOG_6	0x0
#define LOG_7	0x74FF
#define LOG_8	0x0
#define LOG_9	0x0
#define LOG_10	0xA38A
#define LOG_11	0xB201
#define LOG_12	0x0
#define LOG_13	0x0
#define LOG_14	0x0
#define LOG_15	0x0

#define LOG_GET_ITEM_NUM(xx_code) (xx_code & 0x0FFF)

#endif
