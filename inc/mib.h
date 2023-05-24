/**
 * @file mib.h
 * @brief MIB counter
 */

/**
 * @defgroup mib_group MIB
 * @{
 */

/**
 * @example example_mib_port_cnt.c
 */

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

#ifndef __JL_API_MIB_H__
#define __JL_API_MIB_H__

#include "jl_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @public typedef jl_mib_counter_t
 */
typedef jl_uint64 jl_mib_counter_t;

/**
 * @enum jl_port_mib_cnt_s
 * @brief port MIB counters.
 */
enum jl_port_mib_type_u {
	PORT_MIB_TX_PKT_CNT = 0,/**< 0 */
	PORT_MIB_TX_PKT_BYTE_CNT,/**< 1 */
	PORT_MIB_TX_PKT_UC_CNT,/**< 2 */
	PORT_MIB_TX_PKT_UC_BYTE_CNT,/**< 3 */
	PORT_MIB_TX_PKT_MC_CNT,/**< 4 */
	PORT_MIB_TX_PKT_MC_BYTE_CNT,/**< 5 */
	PORT_MIB_TX_PKT_BC_CNT,/**< 6 */
	PORT_MIB_TX_PKT_BC_BYTE_CNT,/**< 7 */
	PORT_MIB_TX_PKT_DRP_CNT,/**< 8 */
	PORT_MIB_TX_PKT_ERR_CNT,/**< 9 */

	PORT_MIB_RX_PKT_CNT,/**< 10 */
	PORT_MIB_RX_PKT_BYTE_CNT,/**< 11 */
	PORT_MIB_RX_PKT_UC_CNT,/**< 12 */
	PORT_MIB_RX_PKT_UC_BYTE_CNT,/**< 13 */
	PORT_MIB_RX_PKT_MC_CNT,/**< 14 */
	PORT_MIB_RX_PKT_MC_BYTE_CNT,/**< 15 */
	PORT_MIB_RX_PKT_BC_CNT,/**< 16 */
	PORT_MIB_RX_PKT_BC_BYTE_CNT,/**< 17 */
	PORT_MIB_RX_PKT_DRP_CNT,/**< 18 */
	PORT_MIB_RX_PKT_CRC_ERR_CNT,/**< 19 */
	PORT_MIB_RX_FRAG_ERR_CNT,/**< 20 */

	PORT_MIB_TYPE_END/**< Invalid */
};

/**
 * @public typedef jl_port_mib_type_t
 */
typedef enum jl_port_mib_type_u jl_port_mib_type_t;

/**
 * @struct jl_port_mib_cnt_s
 * @brief port MIB counters.
 */
struct jl_port_mib_cnt_s {
	jl_uint32 rc_enable;/**< Indicates read clear mode */
	jl_uint64 tx_pkt_cnt;/**< Tx packet counter */
	jl_uint64 tx_pkt_byte_cnt;/**< Tx packet byte counter */
	jl_uint64 tx_pkt_uc_cnt;/**< Tx unicast packet counter */
	jl_uint64 tx_pkt_uc_byte_cnt;/**< Tx unicast packet byte counter */
	jl_uint64 tx_pkt_mc_cnt;/**< Tx mulicast packet counter */
	jl_uint64 tx_pkt_mc_byte_cnt;/**< Tx mulicast packet byte counter */
	jl_uint64 tx_pkt_bc_cnt;/**< Tx broadcast packet counter */
	jl_uint64 tx_pkt_bc_byte_cnt;/**< Tx broadcast packet byte counter */
	jl_uint32 tx_pkt_drp_cnt;/**< Tx drop packet counter */
	jl_uint32 tx_pkt_err_cnt;/**< Tx error packet counter */

	jl_uint64 rx_pkt_cnt;/**< Rx packet counter */
	jl_uint64 rx_pkt_byte_cnt;/**< Rx packet byte counter */
	jl_uint64 rx_pkt_uc_cnt;/**< Rx unicast packet counter */
	jl_uint64 rx_pkt_uc_byte_cnt;/**< Rx unicast packet byte counter */
	jl_uint64 rx_pkt_mc_cnt;/**< Rx multicast packet counter */
	jl_uint64 rx_pkt_mc_byte_cnt;/**< Rx multicast packet byte counter */
	jl_uint64 rx_pkt_bc_cnt;/**< Rx broacast packet counter */
	jl_uint64 rx_pkt_bc_byte_cnt;/**< Rx broadcast packet byte counter */
	jl_uint32 rx_pkt_drp_cnt;/**< Rx drop packet counter */
	jl_uint32 rx_pkt_crc_err_cnt;/**< Rx CRC error packet counter */
	jl_uint32 rx_frag_err_cnt;/**< Rx fragmentation error counter */
};

/**
 * @typedef jl_port_mib_cnt_t
 */
typedef struct jl_port_mib_cnt_s jl_port_mib_cnt_t;

#define JL_MIB_CHECK_TYPE(type)		\
	do {								\
		if (type >= PORT_MIB_TYPE_END)	\
			return JL_ERR_PARAM;		\
	} while(0)


/**
 * @brief Get port read-clear attribute of the MIB counter
 * @details This function gets port read-clear attribute of the MIB counter.
 * @param	port	Index of port number
 * @param	penable	MIB counter read-clear enable or disable
 * @return get port read-clear attribute of the MIB counter successfully or not
 *		@retval JL_ERR_OK		Ok
 *		@retval JL_ERR_INIT		Check Switch State Fail
 *		@retval JL_ERR_PARAM		PARAM Fail
 *		@retval JL_ERR_TIMEOUT		Read Reg Timeout
 *		@retval JL_ERR_FAIL		Read Reg Fail
 *		@retval JL_ERR_PORT		Error Port id
 */
JL_API jl_api_ret_t jl_mib_port_rc_mode_get(jl_port_t port, jl_enable_t *penable);

/**
 * @brief Set port read-clear attribute of the MIB counter
 * @details This function globally sets the read-clear attribute of the MIB counter
 * @param	port	Index of port number
 * @param	enable	MIB counter read-clear enable or disable
 * @return set port read-clear attribute of the MIB counter successfully or not
 *		@retval JL_ERR_OK		Ok
 *		@retval JL_ERR_INIT		Check Switch State Fail
 *		@retval JL_ERR_PARAM		PARAM Fail
 *		@retval JL_ERR_TIMEOUT		Read/Write Reg Timeout
 *		@retval JL_ERR_FAIL		Read/Write Reg Fail
 *		@retval JL_ERR_PORT		Error Port id
 */
JL_API jl_api_ret_t jl_mib_port_rc_mode_set(jl_port_t port, jl_enable_t enable);

/**
 * @brief Clears port MIB counter of the specified type
 * @details This function clears port MIB counter of the specified type
 * @param	port	Index of port number
 * @param	type	The type of MIB rule
 * @return clears port MIB counter of the specified type successfully or not
 *		@retval JL_ERR_OK		Ok
 *		@retval JL_ERR_INIT		Check Switch State Fail
 *		@retval JL_ERR_PARAM		PARAM Fail
 *		@retval JL_ERR_TIMEOUT		Read/Write Reg Timeout
 *		@retval JL_ERR_FAIL		Read/Write Reg Fail
 *		@retval JL_ERR_PORT		Error Port id
 */
JL_API jl_api_ret_t jl_mib_port_clear(jl_port_t port, jl_port_mib_type_t type);

/**
 * @brief Clears port all type MIB counter
 * @details This function clears port all type MIB counter.
 * @param	port	Index of port number
 * @return clears port all types of MIB counter successfully or not
 *		@retval JL_ERR_OK		Ok
 *		@retval JL_ERR_INIT		Check Switch State Fail
 *		@retval JL_ERR_PARAM		PARAM Fail
 *		@retval JL_ERR_TIMEOUT		Read/Write Reg Timeout
 *		@retval JL_ERR_FAIL		Read/Write Reg Fail
 *		@retval JL_ERR_PORT		Error Port id
 */
JL_API jl_api_ret_t jl_mib_port_clear_all(jl_port_t port);

/**
 * @brief Get port MIB counter as specified type
 * @details This function gets the port MIB counter as specified type.
 * @param	port	Index of port number
 * @param	type	The type of MIB counter
 * @param	pcnt	MIB counter value
 * @return get port MIB counter of the specified type successfully or not
 *		@retval JL_ERR_OK		Ok
 *		@retval JL_ERR_INIT		Check Switch State Fail
 *		@retval JL_ERR_PARAM		PARAM Fail
 *		@retval JL_ERR_TIMEOUT		Read Reg Timeout
 *		@retval JL_ERR_FAIL		Read Reg Fail
 *		@retval JL_ERR_PORT		Error Port id
 */
JL_API jl_api_ret_t jl_mib_port_get(jl_port_t port, jl_port_mib_type_t type, jl_mib_counter_t *pcnt);

/**
 * @brief Get all kinds of MIB counters of the specified port
 * @details This function gets all kinds of MIB counters of specified port.
 * @param	port		Index of port number
 * @param	pport_cnt	All kinds of MIB counter of a port
 * @return get all kinds of MIB counters of the specified port successfully or not
 *		@retval JL_ERR_OK		Ok
 *		@retval JL_ERR_INIT		Check Switch State Fail
 *		@retval JL_ERR_PARAM		PARAM Fail
 *		@retval JL_ERR_TIMEOUT		Read Reg Timeout
 *		@retval JL_ERR_FAIL		Read Reg Fail
 *		@retval JL_ERR_PORT		Error Port id
 */
JL_API jl_api_ret_t jl_mib_port_get_all(jl_port_t port, jl_port_mib_cnt_t *pport_cnt);

#ifdef __cplusplus
}
#endif
#endif /* __JL_API_MIB_H__ */
/** @} MIB APIs*/
