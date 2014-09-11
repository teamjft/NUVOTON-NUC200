/****************************************************************************
 * @file     UAC_HID_API.h
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 8/07/12 11:34a $ 
 * @brief    NUC200 Series UAC HID API Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __UAC_HID_API_H__
#define __UAC_HID_API_H__

#ifdef  __cplusplus
extern "C"
{
#endif


extern const uint8_t gau8DeviceDescriptor[];
extern const uint8_t gau8ConfigDescriptor[];
extern const uint8_t gau8VendorStringDescriptor[];
extern const uint8_t gau8ProductStringDescriptor[];

extern const uint8_t gau8StringLang[];
extern const uint8_t gau8StringSerial[];
extern const uint8_t gau8StringAudio[];


extern const uint8_t g_HID_au8KeyboardReportDescriptor[];
extern const uint32_t g_HID_u32KeyboardReportDescriptorSize;
extern const uint8_t g_HID_au8ControlReportDescriptor[];
extern const uint32_t g_HID_u32ControlReportDescriptorSize;

extern uint8_t g_au8KeyboardReport[];
extern const uint32_t g_u32KeyboardReportSize;


int32_t UACHID_MainProcess(void);

#ifdef  __cplusplus
}
#endif

#endif // #ifndef __UAC_HID_API_H__



