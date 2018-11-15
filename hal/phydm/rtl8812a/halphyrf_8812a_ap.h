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

#ifndef __HAL_PHY_RF_8812A_H__
#define __HAL_PHY_RF_8812A_H__

/*--------------------------Define Parameters-------------------------------*/
#define	IQK_DELAY_TIME_8812A		10		/* ms */
#define	index_mapping_NUM_8812A	15
#define AVG_THERMAL_NUM_8812A	4
#define RF_T_METER_8812A		0x42

void
_phy_iq_calibrate_8812a(
	struct PHY_DM_STRUCT		*p_dm_odm,
	u8		channel
);

/*
 * LC calibrate
 *   */
void
phy_lc_calibrate_8812a(
	struct PHY_DM_STRUCT		*p_dm_odm
);

/*
 * AP calibrate
 *   */
void
phy_ap_calibrate_8812a(
	struct _ADAPTER	*p_adapter,
	s8		delta);
void
phy_digital_predistortion_8812a(struct _ADAPTER	*p_adapter);

#endif	/*  #ifndef __HAL_PHY_RF_8812A_H__ */
