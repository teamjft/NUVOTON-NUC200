/****************************************************************************
 * @file     UAC_API.h
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 8/07/12 11:14a $ 
 * @brief    NUC200 Series UAC API Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/

#ifndef __VENDORUSB_H__
#define __VENDORUSB_H__

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

int32_t UAC_MainProcess(void);

#ifdef  __cplusplus
}
#endif

#endif // #ifndef __VENDORUSB_H__



