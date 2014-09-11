/****************************************************************************
 * @file     HIDTransfer_API.h
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 8/07/12 11:00a $ 
 * @brief    NUC200 Series USB HID Transfer API Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/

#ifndef _CDROM1_API_H
#define _CDROM1_API_H
//-------------------------------------------------------------------------------------------------

#define CTRL_EP_NUM         0
#define HID_IN_EP_NUM		4
#define HID_OUT_EP_NUM		5


#define HID_FUNCTION    0

extern const uint8_t gau8VendorStringDescriptor[];
extern const uint8_t gau8ProductStringDescriptor[];

extern const uint8_t gau8StringLang[];
extern const uint8_t gau8StringSerial[];

extern const uint8_t gau8DeviceDescriptor[];
extern const uint8_t gau8ConfigDescriptor[];

extern uint8_t g_au8DeviceReport[];
extern const uint32_t g_u32DeviceReportSize;
extern const uint8_t  gau8DeviceReportDescriptor[];
extern const uint32_t gu32DeviceReportDescriptorSize; 

extern uint32_t g_u32TotalLen;
extern uint8_t  g_u8CmdState;

void HID_MainProcess(void);

//-------------------------------------------------------------------------------------------------
#endif

