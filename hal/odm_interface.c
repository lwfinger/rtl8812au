/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/

//============================================================
// include files
//============================================================

#include "odm_precomp.h"
//
// ODM IO Relative API.
//

u1Byte
ODM_Read1Byte(
	PDM_ODM_T		pDM_Odm,
	u4Byte			RegAddr
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	return rtw_read8(Adapter,RegAddr);
}


u2Byte
ODM_Read2Byte(
	PDM_ODM_T		pDM_Odm,
	u4Byte			RegAddr
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	return rtw_read16(Adapter,RegAddr);
}

u4Byte
ODM_Read4Byte(
	PDM_ODM_T		pDM_Odm,
	u4Byte			RegAddr
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	return rtw_read32(Adapter,RegAddr);
}


VOID
ODM_Write1Byte(
	PDM_ODM_T		pDM_Odm,
	u4Byte			RegAddr,
	u1Byte			Data
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	rtw_write8(Adapter,RegAddr, Data);
}


VOID
ODM_Write2Byte(
	PDM_ODM_T		pDM_Odm,
	u4Byte			RegAddr,
	u2Byte			Data
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	rtw_write16(Adapter,RegAddr, Data);
}


VOID
ODM_Write4Byte(
	PDM_ODM_T		pDM_Odm,
	u4Byte			RegAddr,
	u4Byte			Data
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	rtw_write32(Adapter,RegAddr, Data);
}

VOID
ODM_SetMACReg(
	PDM_ODM_T	pDM_Odm,
	u4Byte		RegAddr,
	u4Byte		BitMask,
	u4Byte		Data
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	PHY_SetBBReg(Adapter, RegAddr, BitMask, Data);
}

u4Byte
ODM_GetMACReg(
	PDM_ODM_T	pDM_Odm,
	u4Byte		RegAddr,
	u4Byte		BitMask
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	return PHY_QueryBBReg(Adapter, RegAddr, BitMask);
}

VOID
ODM_SetBBReg(
	PDM_ODM_T	pDM_Odm,
	u4Byte		RegAddr,
	u4Byte		BitMask,
	u4Byte		Data
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	PHY_SetBBReg(Adapter, RegAddr, BitMask, Data);
}

u4Byte
ODM_GetBBReg(
	PDM_ODM_T	pDM_Odm,
	u4Byte		RegAddr,
	u4Byte		BitMask
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	return PHY_QueryBBReg(Adapter, RegAddr, BitMask);
}


VOID
ODM_SetRFReg(
	PDM_ODM_T			pDM_Odm,
	ODM_RF_RADIO_PATH_E	eRFPath,
	u4Byte				RegAddr,
	u4Byte				BitMask,
	u4Byte				Data
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	PHY_SetRFReg(Adapter, eRFPath, RegAddr, BitMask, Data);
}


u4Byte
ODM_GetRFReg(
	PDM_ODM_T			pDM_Odm,
	ODM_RF_RADIO_PATH_E	eRFPath,
	u4Byte				RegAddr,
	u4Byte				BitMask
	)
{
	PADAPTER		Adapter = pDM_Odm->Adapter;

	return PHY_QueryRFReg(Adapter, eRFPath, RegAddr, BitMask);
}

//
// ODM Memory relative API.
//
VOID
ODM_AllocateMemory(
	PDM_ODM_T	pDM_Odm,
	PVOID		*pPtr,
	u4Byte		length
	)
{
	*pPtr = rtw_zvmalloc(length);
}

// length could be ignored, used to detect memory leakage.
VOID
ODM_FreeMemory(
	PDM_ODM_T	pDM_Odm,
	PVOID		pPtr,
	u4Byte		length
	)
{
	rtw_vmfree(pPtr, length);
}

VOID
ODM_MoveMemory(
	PDM_ODM_T	pDM_Odm,
	PVOID		pDest,
	PVOID		pSrc,
	u4Byte		Length
	)
{
	_rtw_memcpy(pDest, pSrc, Length);
}

s4Byte ODM_CompareMemory(
	PDM_ODM_T	pDM_Odm,
	PVOID           pBuf1,
      PVOID           pBuf2,
      u4Byte          length
       )
{
	return _rtw_memcmp(pBuf1,pBuf2,length);
}

//
// ODM MISC relative API.
//
VOID
ODM_AcquireSpinLock(
	PDM_ODM_T			pDM_Odm,
	RT_SPINLOCK_TYPE	type
	)
{
}

VOID
ODM_ReleaseSpinLock(
	PDM_ODM_T			pDM_Odm,
	RT_SPINLOCK_TYPE	type
	)
{
}

//
// Work item relative API. FOr MP driver only~!
//
VOID
ODM_InitializeWorkItem(
	PDM_ODM_T					pDM_Odm,
	PRT_WORK_ITEM				pRtWorkItem,
	RT_WORKITEM_CALL_BACK		RtWorkItemCallback,
	PVOID						pContext,
	const char*					szID
	)
{
}

VOID
ODM_StartWorkItem(
	PRT_WORK_ITEM	pRtWorkItem
	)
{
}


VOID
ODM_StopWorkItem(
	PRT_WORK_ITEM	pRtWorkItem
	)
{
}

VOID
ODM_FreeWorkItem(
	PRT_WORK_ITEM	pRtWorkItem
	)
{
}

VOID
ODM_ScheduleWorkItem(
	PRT_WORK_ITEM	pRtWorkItem
	)
{
}

VOID
ODM_IsWorkItemScheduled(
	PRT_WORK_ITEM	pRtWorkItem
	)
{
}

//
// ODM Timer relative API.
//
VOID
ODM_StallExecution(
	u4Byte	usDelay
	)
{
	rtw_udelay_os(usDelay);
}

VOID
ODM_delay_ms(u4Byte	ms)
{
	rtw_mdelay_os(ms);
}

VOID
ODM_delay_us(u4Byte	us)
{
	rtw_udelay_os(us);
}

VOID
ODM_sleep_ms(u4Byte	ms)
{
	rtw_msleep_os(ms);
}

VOID
ODM_sleep_us(u4Byte	us)
{
	rtw_usleep_os(us);
}

VOID
ODM_SetTimer(
	PDM_ODM_T		pDM_Odm,
	PRT_TIMER		pTimer,
	u4Byte			msDelay
	)
{
	_set_timer(pTimer,msDelay ); //ms
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 15, 0)
VOID
ODM_InitializeTimer(
	PDM_ODM_T			pDM_Odm,
	PRT_TIMER			pTimer,
	RT_TIMER_CALL_BACK	CallBackFunc,
	PVOID				pContext,
	const char*			szID
	)
{
	PADAPTER Adapter = pDM_Odm->Adapter;

	_init_timer(pTimer,Adapter->pnetdev,CallBackFunc,pDM_Odm);
}
#endif

VOID
ODM_CancelTimer(
	PDM_ODM_T		pDM_Odm,
	PRT_TIMER		pTimer
	)
{
	_cancel_timer_ex(pTimer);
}

VOID
ODM_ReleaseTimer(
	PDM_ODM_T		pDM_Odm,
	PRT_TIMER		pTimer
	)
{
}

//
// ODM FW relative API.
//
u4Byte
ODM_FillH2CCmd(
	pu1Byte		pH2CBuffer,
	u4Byte		H2CBufferLen,
	u4Byte		CmdNum,
	pu4Byte		pElementID,
	pu4Byte		pCmdLen,
	pu1Byte*		pCmbBuffer,
	pu1Byte		CmdStartSeq
	)
{
	return	TRUE;
}
