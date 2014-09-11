/****************************************************************************
 * @file     VCOM_API.c
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 8/07/12 2:01p $ 
 * @brief    NUC200 Series USB VOCM API Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/

#ifndef _VCOM_API_H
#define _VCOM_API_H


#define CTRL_EP_NUM         0
#define INT_IN_EP_NUM       3   
#define BULK_OUT_EP_NUM     2
#define BULK_IN_EP_NUM      1

extern const uint8_t gau8DeviceDescriptor[];
extern const uint8_t gau8ConfigDescriptor[];
extern const uint8_t gau8VendorStringDescriptor[];
extern const uint8_t gau8ProductStringDescriptor[];

extern const uint8_t gau8StringLang[];
extern const uint8_t gau8StringSerial[];
extern const uint8_t gau8StringAudio[];

void VCOM_SendData(void);
void VCOM_IntInAckCallback(void* pVoid);
void VCOM_BulkInAckCallback(void* pVoid);
void VCOM_BulkOutAckCallback(void* pVoid);
void VCOM_MainProcess(void);

#endif

