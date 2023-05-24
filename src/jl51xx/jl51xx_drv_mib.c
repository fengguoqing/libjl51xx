/*
 * Copyright (c) 2014-2022 JLSemi Limited
 * All Rights Reserved
 *
 * THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of JLSemi Limited
 * The copyright notice above does not evidence any actual or intended
 * publication of such source code.
 *
 * No part of this code may be reproduced, stored in a retrieval system,
 * or transmitted, in any form or by any means, electronic, mechanical,
 * photocopying, recording, or otherwise, without the prior written
 * permission of JLSemi Limited
 */

#include "jl_base.h"
#include "driver/jl_reg_io.h"
#include "jl51xx/reg_ethmac.h"
#include "jl51xx/jl51xx_drv_mib.h"
#include "mib.h"

#define ETHMAC_REG_ADDR(idx, ofs)			(ETHMAC0_BASE + idx * ETHMAC0_BLOCK_SIZE + ofs)
jl_ret_t jl51xx_mib_port_rc_mode_get(jl_port_t port, jl_enable_t *pregval)
{
	jl_ret_t ret;
	jl_uint32 val;

	ret = jl_apb_reg_read(ETHMAC_REG_ADDR(JL_PORT_P2M(port), STATISTIC_MODE_0_OFFSET),
					&val);
	if (ret)
		return ret;

	if (val & BIT(0))
		*pregval = 1;
	else
		*pregval = 0;

	return JL_ERR_OK;
}

jl_ret_t jl51xx_mib_port_rc_mode_set(jl_port_t port, jl_uint32 regval)
{
	jl_ret_t ret;
	jl_uint32 val;

	ret = jl_apb_reg_read(ETHMAC_REG_ADDR(JL_PORT_P2M(port), STATISTIC_MODE_0_OFFSET),
					&val);
	if (ret)
		return ret;

	if (regval == 1)
		SET_BIT(val, 0);
	else if (regval == 0)
		CLR_BIT(val, 0);
	else
		return JL_ERR_PARAM;

	ret = jl_apb_reg_write(
					ETHMAC_REG_ADDR(JL_PORT_P2M(port), STATISTIC_MODE_0_OFFSET),
					val);
	return ret;
}

jl_ret_t jl51xx_mib_port_clear(jl_port_t port, jl_uint16 type)
{
	jl_ret_t ret;
	jl_uint32 val = 0;

	val = type << 4;
	val |= BIT(0);

	ret = jl_apb_reg_write(
					ETHMAC_REG_ADDR(JL_PORT_P2M(port), STATISTIC_MODE_1_OFFSET),
					val);
	return ret;
}
#define MIB_TYPE_END		21
jl_ret_t jl51xx_mib_port_get(jl_port_t port, jl_uint16 type, jl_uint64 *pregval)
{
	jl_ret_t ret;
	jl_uint32 burst = 0;
	jl_uint32 buf[2] = {0};
	jl_uint32 *ptr = (jl_uint32 *)pregval;

	jl_uint32 mib_base_addr = ETHMAC_REG_ADDR(JL_PORT_P2M(port), TX_PKT_CNT_OFFSET);
	CONST_T jl_uint8 mib_reg_offset[MIB_TYPE_END] = {
		0, 2, 4, 6, 8, 10, 12, 14, 16, 17,
		18, 20, 22, 24, 26, 28, 30, 32, 34, 35, 36 };

	if (type > MIB_TYPE_END)
		return JL_ERR_PARAM;

	switch(type) {
		case PORT_MIB_TX_PKT_CNT:
		case PORT_MIB_TX_PKT_BYTE_CNT:
		case PORT_MIB_TX_PKT_UC_CNT:
		case PORT_MIB_TX_PKT_UC_BYTE_CNT:
		case PORT_MIB_TX_PKT_MC_CNT:
		case PORT_MIB_TX_PKT_MC_BYTE_CNT:
		case PORT_MIB_TX_PKT_BC_CNT:
		case PORT_MIB_TX_PKT_BC_BYTE_CNT:
		case PORT_MIB_RX_PKT_CNT:
		case PORT_MIB_RX_PKT_BYTE_CNT:
		case PORT_MIB_RX_PKT_UC_CNT:
		case PORT_MIB_RX_PKT_UC_BYTE_CNT:
		case PORT_MIB_RX_PKT_MC_CNT:
		case PORT_MIB_RX_PKT_MC_BYTE_CNT:
		case PORT_MIB_RX_PKT_BC_CNT:
		case PORT_MIB_RX_PKT_BC_BYTE_CNT:
			burst = 2;
			break;
		case PORT_MIB_TX_PKT_DRP_CNT:
		case PORT_MIB_TX_PKT_ERR_CNT:
		case PORT_MIB_RX_PKT_DRP_CNT:
		case PORT_MIB_RX_PKT_CRC_ERR_CNT:
		case PORT_MIB_RX_FRAG_ERR_CNT:
			burst = 1;
			break;
		default:
			JL_DBG_MSG(JL_FLAG_EMAC, _DBG_ERROR, "mib type overflow!\n");
			break;
	}
	ret = jl_apb_reg_burst_read(mib_base_addr + mib_reg_offset[type], buf, burst);
	JL_DBG_MSG(JL_FLAG_EMAC, _DBG_ON, "%s regaddr=0x%4x, buf[0]=0x%4x, buf[1]=0x%4x, burst=%d errmsg:%s!\n",
			__func__, mib_base_addr + mib_reg_offset[type],
			buf[0], buf[1], burst, JL_ERRMSG(ret));

	*ptr++= buf[0];
	*ptr = buf[1];

	return ret;
}
