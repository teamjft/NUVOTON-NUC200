/****************************************************************************
 * @file     HIDTransferSys.h
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 8/07/12 11:00a $ 
 * @brief    NUC200 Series USB HID Transfer System Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __UDC_H__
#define __UDC_H__

#ifdef  __cplusplus
extern "C"
{
#endif

#define	HID_MAX_PACKET_SIZE_CTRL        8
#define HID_MAX_PACKET_SIZE_INT_IN		64
#define HID_MAX_PACKET_SIZE_INT_OUT     64

/* UDC Class REQUEST */
#define	BULK_ONLY_MASS_STORAGE_RESET	0xFF
#define	GET_MAX_LUN						0xFE

/* HID Class REQUEST */
#define GET_REPORT          0x01
#define GET_IDLE            0x02
#define GET_PROTOCOL        0x03
#define SET_REPORT          0x09
#define SET_IDLE            0x0A
#define SET_PROTOCOL        0x0B

/* UDC Bulk In/Out state */
#define	BULK_CBW		0x00
#define	BULK_IN			0x01
#define	BULK_OUT		0x02
#define	BULK_CSW		0x04
#define BULK_NORMAL		0xFF


#define	UFI_TEST_UNIT_READY								0x00
#define	UFI_REQUEST_SENSE								0x03
#define	UFI_INQUIRY										0x12
#define	UFI_MODE_SELECT_6								0x15
#define	UFI_MODE_SENSE_6								0x1A
#define	UFI_START_STOP									0x1B
#define	UFI_PREVENT_ALLOW_MEDIUM_REMOVAL				0x1E
#define	UFI_READ_FORMAT_CAPACITY						0x23
#define	UFI_READ_CAPACITY								0x25
#define	UFI_READ_10										0x28
#define	UFI_WRITE_10									0x2A
#define	UFI_VERIFY_10									0x2F
#define	UFI_MODE_SELECT_10								0x55
#define	UFI_MODE_SENSE_10								0x5A

#define	CBW_SIGNATURE	0x43425355
#define	CSW_SIGNATURE	0x53425355


typedef struct
{

	const uint8_t *au8DeviceDescriptor;
	const uint8_t *au8ConfigDescriptor;

	const uint8_t *pu8IntInEPDescriptor;

	const uint8_t *pu8ReportDescriptor;
	uint32_t u32ReportDescriptorSize;

	const uint8_t *pu8HIDDescriptor;

	uint8_t *pu8Report;
	uint32_t u32ReportSize;
    int8_t isReportReady;

	void * *device;
	
} S_HID_DEVICE;


/* For mass storage */
struct CBW
{
	uint32_t	dCBWSignature;
	uint32_t	dCBWTag;
	uint32_t	dCBWDataTransferLength;
	uint8_t	bmCBWFlags;
	uint8_t	bCBWLUN;
	uint8_t	bCBWCBLength;
	uint8_t	u8OPCode;
	uint8_t	u8LUN;
	uint8_t	au8Data[14];
};

struct CSW
{
	uint32_t	dCSWSignature;
	uint32_t	dCSWTag;
	uint32_t	dCSWDataResidue;
	uint8_t	bCSWStatus;
};

extern S_HID_DEVICE g_HID_sDevice;

static __INLINE void _HID_CLR_CTRL_READY_AND_TRIG_STALL()
{
	_USBD_CLEAR_EP_READY_AND_TRIG_STALL(0);
	_USBD_CLEAR_EP_READY_AND_TRIG_STALL(1);
}

static __INLINE void _HID_CLR_CTRL_READY()
{
	_USBD_CLEAR_EP_READY(0);
	_USBD_CLEAR_EP_READY(1);
}

int32_t HID_Open(void *pfGetInReport, void *pfSetOutReport);

void HID_Close(void);
void HID_CtrlSetupSetConfiguration(void * pVoid);
void HID_CtrlSetupGetDescriptor(void * pVoid);


void HID_CtrlReset(void * pVoid);

void HID_IntInCallback(void * pVoid);
void HID_IntOutCallback(void * pVoid);
void HID_CtrlSetupSetReport(void * pVoid);
void HID_CtrlSetupSetIdle(void * pVoid);
void HID_CtrlSetupSetProtocol(void * pVoid);
void HID_CtrlGetDescriptorIn(void * pVoid);
void HID_CtrlGetDescriptorOut(void * pVoid);

#ifdef  __cplusplus
}
#endif

#endif // __UDC_H__














