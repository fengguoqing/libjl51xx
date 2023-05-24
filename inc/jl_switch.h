/**
 * @file jl_switch.h
 * @brief Initialization
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

#ifndef __JL_SWITCH_H__
#define __JL_SWITCH_H__

#include "jl_types.h"
#include "jl_config.h"
#include "jl_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SWITCH_PORT_NUM    10UL
#define UTP_PORT_MASK      0xFFUL
#define MAX_VLAN_ID        0xFFFUL
#define MAX_QUEUE_NUM      4UL
#define MAX_PCP            7UL
#define MAX_EXP            7UL
#define MAX_DSCP           63UL
#define MAX_QUEUE_WEIGHT   127UL
#define MIN_QUEUE_WEIGHT   1UL

#define VLAN_IDX_MAX			15UL
/* "VLAN INDEX" means "VLAN Table Index" */
#define VLAN_IDX_DEFAULT		0UL
#define VLAN_IDX_DROP			15UL
/* "VLAN ID" means "VLAN Tag ID" */
#define DEFAULT_VLAN_ID			1UL
/* Number of ticks between starts of the aging process */
#define DEFAULT_TICK_NUM		0x7735940UL
/* Default select available tick 0 */
#define DEFAULT_TICK_ID			0UL

#ifdef CONFIG_JL_API_MUTEX
#include "portable/jl_portable.h"
#define JL_API_MUTEX_INIT()						\
	do {								\
		g_switch_ctrl.api_mutex = port_mutex_init();		\
		if (g_switch_ctrl.api_mutex == NULL)			\
			JL_DBG_MSG(JL_FLAG_SYS, _DBG_ERROR, "api mutex init fail\n"); \
	} while (0)

#define JL_API_MUTEX_DEINIT()						\
	do {								\
		if (g_switch_ctrl.api_mutex != NULL) {			\
			port_mutex_deinit(g_switch_ctrl.api_mutex);	\
			g_switch_ctrl.api_mutex = NULL;			\
		}							\
	} while (0)

#define JL_API_MUTEX_LOCK()			\
	do {								\
		if (g_switch_ctrl.api_mutex != NULL)			\
			port_mutex_lock(g_switch_ctrl.api_mutex);	\
	} while (0)

#define JL_API_MUTEX_UNLOCK()						\
	do {								\
		if (g_switch_ctrl.api_mutex != NULL)			\
			port_mutex_unlock(g_switch_ctrl.api_mutex);	\
	} while (0)
#else
#define JL_API_MUTEX_INIT()
#define JL_API_MUTEX_DEINIT()
#define JL_API_MUTEX_LOCK()
#define JL_API_MUTEX_UNLOCK()
#endif /* JL_API_MUTEX */

#define JL_STAT_INIT()		(g_switch_ctrl.stat = STAT_READY)
#define JL_STAT_DEINIT()	(g_switch_ctrl.stat = STAT_UNINIT)
#define JL_STAT_IS_READY()	(g_switch_ctrl.stat == STAT_READY)
#define JL_STAT_IS_UNINIT()	(g_switch_ctrl.stat == STAT_UNINIT)
#define JL_CHECK_STAT()					\
	do {						\
		if (g_switch_ctrl.stat != STAT_READY)	\
			return JL_ERR_INIT;		\
	} while (0)

/* check phy port */
#define JL_CHECK_PORT(x)					\
	do {							\
		if (jl_switch_phyport_check(x) != JL_ERR_OK)	\
			return JL_ERR_PORT;			\
	} while (0)

/* check phy UTP port */
#define JL_CHECK_UTP_PORT(x)					\
	do {							\
		if (jl_switch_phyport_check_utp(x) != JL_ERR_OK)	\
			return JL_ERR_PORT;			\
	} while (0)

/* check phy external port */
#define JL_CHECK_EXT_PORT(x)                    \
	do {                            \
		if (jl_switch_phyport_check_ext(x) != JL_ERR_OK)    \
		return JL_ERR_PORT;         \
	} while (0)

/* check mac portmask */
#define JL_CHECK_PORTMASK(x)					\
	do {							\
		if ((x) != (gp_switch_dev->phy_portmask & (x)))	\
			return JL_ERR_PORT;			\
	} while (0)

#define JL_CHECK_POINTER(x)			\
	do {					\
		if (x == NULL)			\
			return JL_ERR_PARAM;	\
	} while (0)

#define JL_ASSERT(expr) \
	do { \
		if (!(expr)) \
			return JL_ERR_PARAM;	\
	} while (0)

#define JL_CHECK_RETURN(ret)					\
	do {							\
		if (ret != JL_ERR_OK) \
			return ret;		\
	} while (0)

#define JL_PORT_P2M(x)		(gp_switch_dev->p2m_port[x])
#define JL_PORT_M2P(x)		(gp_switch_dev->m2p_port[x])
#define JL_PORT_P2VP(x)		(gp_switch_dev->p2vp_port[x])
#define JL_PORT_VP2P(x)		(gp_switch_dev->vp2p_port[x])
#define JL_PORTMASK_P2M(x)	jl_switch_portmask_p2m(x)
#define JL_PORTMASK_M2P(x)	jl_switch_portmask_m2p(x)
#define JL_PORTMASK_P2VP(x)	jl_switch_portmask_p2vp(x)
#define JL_PORTMASK_VP2P(x)	jl_switch_portmask_vp2p(x)
#define JL_PHY_PORTMASK	(gp_switch_dev->phy_portmask)
#define JL_MAC_PORTMASK	(gp_switch_dev->mac_portmask)
#define JL_VENDOR_PORTMASK	(gp_switch_dev->vendor_portmask)

#define JL_FOR_EACH_PHY_PORT(x)	for (x = 0; x < SWITCH_PORT_NUM; x++)		\
						if (jl_switch_phyport_check(x) == JL_ERR_OK)
#define JL_FOR_EACH_PHY_UTP_PORT(x)	for (x = 0; x < SWITCH_PORT_NUM; x++)		\
						if (jl_switch_phyport_check_utp(x) == JL_ERR_OK)
#define JL_FOR_EACH_VENDOR_PORT(x)	for (x = 0; x < SWITCH_PORT_NUM; x++)		\
						if (jl_switch_vendorport_check(x) == JL_ERR_OK)
#define JL_FOR_EACH_MAC_PORT(x)	for (x = 0; x < SWITCH_PORT_NUM; x++)		\
						if (jl_switch_macport_check(x) == JL_ERR_OK)
#define JL_FOR_EACH_PHY_EXT_PORT(x)	for (x = 0; x < SWITCH_PORT_NUM; x++)		\
						if ((jl_switch_phyport_check(x) == JL_ERR_OK)	\
								&& (gp_switch_dev->phy_port_type[x] ==  PORT_TYPE_EXT))
#define JL_FOR_EACH_MAC_EXT_PORT(x)	for (x = 0; x < SWITCH_PORT_NUM; x++)		\
						if ((jl_switch_macport_check(x) == JL_ERR_OK)	\
								&& (gp_switch_dev->mac_port_type[x] ==  PORT_TYPE_EXT))


/* Macros for memory access operations */
#define _REG8P(p, i)                        ((jl_uint8 *) ((jl_uintptr)((p) + (i))))
#define _REG16P(p, i)                       ((jl_uint16 *) ((jl_uintptr)((p) + (i))))
#define _REG32P(p, i)                       ((jl_uint32 *) ((jl_uintptr)((p) + (i))))
#define _REG8(p, i)                         (*(_REG8P(p, i)))
#define _REG16(p, i)                        (*(_REG16P(p, i)))
#define _REG32(p, i)                        (*(_REG32P(p, i)))
#define REG8(addr)                          _REG8((addr), 0)
#define REG16(addr)                         _REG16((addr), 0)
#define REG32(addr)                         _REG32((addr), 0)

/* Macros for address type convert and access operations */
#define ADDR16(addr)                        ((jl_uint32)(jl_uintptr)(addr))
#define ADDR32(addr)                        ((jl_uint32)(jl_uintptr)(addr))
#define ADDR8P(addr)                        ((jl_uint8 *)(jl_uintptr)(addr))
#define ADDR16P(addr)                       ((jl_uint16 *)(jl_uintptr)(addr))
#define ADDR32P(addr)                       ((jl_uint32 *)(jl_uintptr)(addr))

/* Macros for Bit Operations */
#define BITMASK_MAX                         0xFFFFFFFFUL
#define BITOFS_MAX                          31

// For 32 bit OS, Bit Operation support mask 32 bit wide
#ifndef BIT
#define BIT(bitofs)                         (0x1UL << (bitofs))
#endif
#define BITS(start, end)                    ((BITMASK_MAX) << (start) & (BITMASK_MAX) >> (BITOFS_MAX - (end)))
#define GET_BIT(regval, bitofs)             (((regval) >> (bitofs)) & 0x1)
#define SET_BIT(regval, bitofs)             ((regval) |= BIT(bitofs))
#define CLR_BIT(regval, bitofs)             ((regval) &= (~BIT(bitofs)))
#define FLIP_BIT(regval, bitofs)            ((regval) ^= BIT(bitofs))
#define WRITE_BIT(regval, bitofs, val)      do { CLR_BIT(regval, bitofs); ((regval) |= ((val) << bitofs) & BIT(bitofs)); } while (0)
#define CHECK_BIT(regval, bitofs)           (!!((regval) & (0x1UL<<(bitofs))))
#define GET_BITS(regval, start, end)        (((regval) & BITS((start), (end))) >> (start))
#define SET_BITS(regval, start, end)        ((regval) |= BITS((start), (end)))
#define CLR_BITS(regval, start, end)        ((regval) &= (~BITS((start), (end))))
#define FLIP_BITS(regval, start, end)       ((regval) ^= BITS((start), (end)))
#define WRITE_BITS(regval, start, end, val) do { CLR_BITS(regval, start, end); ((regval) |= ((val) << start) & BITS((start), (end))); } while (0)
#define CHECK_BITS_ALL(regval, start, end)  (!((~(regval)) & BITS((start), (end))))
#define CHECK_BITS_ANY(regval, start, end)  ((regval) & BITS((start), (end)))

#define BITMASK_SET(regval, mask)           ((regval) |= (mask))
#define BITMASK_CLR(regval, mask)           ((regval) &= (~(mask)))
#define BITMASK_FLIP(regval, mask)          ((regval) ^= (mask))
#define BITMASK_CHECK_ALL(regval, mask)     (!((~(regval)) & (mask)))
#define BITMASK_CHECK_ANY(regval, mask)     ((regval) & (mask))

#define ECO_R0P0	0U /**< ECO Version r0p0 */
#define ECO_R0P1	1U /**< ECO Version r0p1 */
#define ECO_R0P2	2U /**< ECO Version r0p2 */
#define ECO_R1P0	3U /**< ECO Version r1p0 */
#define CORE_VER0	0x547fU /**< Switch Core Version V1 */
#define CORE_VER1	0x4087U /**< Switch Core Version V2 */

/**
 * @defgroup initialization_group Initialization
 * @{
 */

/**
 * @union mac_addr
 * @brief Initialization mac_addr.
 */
union mac_addr {
	jl_uint8 addr[ETHER_ADDR_LEN];/**< Indicates MAC Address */
	jl_uint64 val:48;/**< Indicates 48 bit MAC Address */
};

/**
 * @typedef jl_mac_addr_t
 */
typedef union mac_addr jl_mac_addr_t;

/**
 * @enum chip_id_e
 * @brief Initialization chip_id_e.
 */
enum chip_id_e {
	CHIP_ID_JL5104 = 0,/**< JL5104 */
	CHIP_ID_JL5105,/**< JL5105 */
	CHIP_ID_JL5106,/**< JL5106 */
	CHIP_ID_JL5108,/**< JL5108 */
	CHIP_ID_JL5109,/**< JL5109 */
	CHIP_ID_JL5110,/**< JL5110 */
	CHIP_ID_END/**< Invalid */
};

/**
 * @public typedef jl_chip_id_t
 */
typedef enum chip_id_e jl_chip_id_t;

/**
 * @public typedef jl_hw_info_t
 */
typedef jl_uint32 jl_hw_info_t;

/**
 * @enum stat_e
 * @brief Initialization stat_e.
 */
enum stat_e {
	STAT_UNINIT = 0,/**< Uninitialized State */
	STAT_READY,/**< Ready State */
	STAT_END/**< Invalid State */
};

/**
 * @public typedef jl_stat_t
 */
typedef enum stat_e jl_stat_t;

/**
 * @enum port_type_e
 * @brief Initialization port_type_e.
 */
enum port_type_e {
	PORT_TYPE_UTP = 0,/**< UTP Port */
	/* XXX external (phy) port type: MII, RMII2MII */
	PORT_TYPE_EXT,/**< External Port */
	PORT_TYPE_UNDEF,/**< Undefined Port */
	PORT_TYPE_END/**< Invalid Type */
};

/**
 * @public typedef jl_port_type_t
 */
typedef enum port_type_e jl_port_type_t;


/**
 * @struct jl_switch_info_s
 * @brief Initialization switch info.
 */
struct jl_switch_info_s {
	jl_hw_info_t core_ver;/**< Indicates switch pa core version */
	jl_chip_id_t pkg;/**< Indicates pkg chip id */
	jl_hw_info_t eco_ver;/**< Indicates switch pa eco version */
	jl_uint32 sdk_ver;/**< Indicates SDK version */
};

/**
 * @typedef jl_switch_info_t
 */
typedef struct jl_switch_info_s jl_switch_info_t;

/**
 * @brief Initialize the switch system
 * @details This function initialize the switch system and sets chip registers to default configuration.
 * @param None
 * @return the switch system is initialized or not
 * @retval JL_ERR_OK		Ok
 * @retval JL_ERR_FAIL		Fail
 */
JL_API jl_api_ret_t jl_switch_init(void);

/**
 * @brief Deinitialize the switch system
 * @details This function de-initialize the switch system.
 * @param None
 * @return the switch system is deinitialized or not
 * @retval JL_ERR_OK		Ok
 * @retval JL_ERR_FAIL		Fail
 */
JL_API jl_api_ret_t jl_switch_deinit(void);

/**
 * @brief Get chip's version info
 * @details This function is used to get the version information
 * @param pinfo	info returned chip's version info
 * @return version info is sucessfully get or not
 * @retval JL_ERR_OK		Ok
 * @retval JL_ERR_FAIL		Fail
 */
JL_API jl_api_ret_t jl_switch_info(jl_switch_info_t *pinfo);

/**
 * @brief set state to the switch
 * @details This function indicates set uninit or ready state to the switch .
 * @param state	the state of switch
 * @return function result
 * @retval JL_ERR_OK		Ok
 * @retval JL_ERR_PARAM		Fail
 */
JL_API jl_ret_t jl_switch_init_state_set(jl_stat_t state);

/**
 * @brief get state from the switch
 * @details This function indicates get uninit or ready state from the switch.
 * @param pstate	the pstate of switch
 * @return function result
 * @retval JL_ERR_OK		Ok
 * @retval JL_ERR_PARAM		Fail
 */
JL_API jl_ret_t jl_switch_init_state_get(jl_stat_t *pstate);
/** @} Initialization APIs*/

/**
 * @struct switch_dev_s
 * @brief Initialization switch dev.
 */
struct switch_dev_s {
	jl_chip_id_t		chip_id;/**< Indicates the switch chip ID */
	jl_uint32		p2m_port[SWITCH_PORT_NUM];/**< Indicates PHY to MAC port mapping arrary */
	jl_uint32		m2p_port[SWITCH_PORT_NUM];/**< Indicates MAC to PHY port mapping arrary */
	jl_uint32		p2vp_port[SWITCH_PORT_NUM];/**< Indicates PHY to vendor port mapping arrary */
	jl_uint32		vp2p_port[SWITCH_PORT_NUM];/**< Indicates vendor port to PHY id mapping arrary */
	jl_port_type_t		phy_port_type[SWITCH_PORT_NUM];/**< Indicates PHY port type: UTP port, EXT port or Undefined port etc */
	jl_port_type_t		mac_port_type[SWITCH_PORT_NUM];/**< Indicates MAC port type */
	jl_port_type_t		vendor_port_type[SWITCH_PORT_NUM];/**< Indicates vendor port type: UTP port or Undefined port. EXT port is excluded */
	jl_portmask_t		phy_portmask;/**< Indicates the portmask of valid PHY */
	jl_portmask_t		mac_portmask;/**< Indicates the portmask of valid MAC */
	jl_portmask_t		vendor_portmask;/**< Indicates the portmask of vendor specific port */
};

/**
 * @typedef jl_switch_dev_t
 */
typedef struct switch_dev_s jl_switch_dev_t;


/**
 * @struct switch_ctrl_s
 * @brief Initialization switch ctrl.
 */
struct switch_ctrl_s {
	jl_stat_t stat;/**< Indicates the state of the switch */
	jl_hw_info_t core_ver;/**< Indicates switch pa core version */
	jl_hw_info_t eco_ver;/**< Indicates switch pa eco version */
	void *api_mutex;/**< Indicates the User defined Mutex API. If the sdk runs under muti-thread applications, the api_mutex must be defined */
};

/**
 * @typedef jl_switch_ctrl_t
 */
typedef struct switch_ctrl_s jl_switch_ctrl_t;

#ifdef CONFIG_JL_CHIP_ID_51XX
JL_API extern jl_switch_dev_t g_switch_dev_5104;
JL_API extern jl_switch_dev_t g_switch_dev_5105;
JL_API extern jl_switch_dev_t g_switch_dev_5106;
JL_API extern jl_switch_dev_t g_switch_dev_5108;
JL_API extern jl_switch_dev_t g_switch_dev_5109;
JL_API extern jl_switch_dev_t g_switch_dev_5110;
#endif
JL_API extern jl_switch_ctrl_t g_switch_ctrl;
JL_API extern jl_switch_dev_t *gp_switch_dev;


JL_API jl_ret_t jl_switch_phyport_check(jl_port_t phy_port);
JL_API jl_ret_t jl_switch_phyport_check_utp(jl_port_t phy_port);
JL_API jl_ret_t jl_switch_phyport_check_ext(jl_port_t phy_port);
JL_API jl_ret_t jl_switch_macport_check(jl_port_t mac_port);
JL_API jl_portmask_t jl_switch_portmask_p2m(jl_portmask_t phy_portmask);
JL_API jl_portmask_t jl_switch_portmask_m2p(jl_portmask_t mac_portmask);
JL_API jl_portmask_t jl_switch_portmask_p2vp(jl_portmask_t phy_portmask);
JL_API jl_portmask_t jl_switch_portmask_vp2p(jl_portmask_t phy_portmask);

#ifdef __cplusplus
}
#endif
#endif /* __JL_SWITCH_H__ */
