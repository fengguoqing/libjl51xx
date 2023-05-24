//reg_clkgen.h
/*
* Automatically generated by gen_c_api.py, don't edit it
*/
#ifndef __JL_REG_CLKGEN_H__
#define __JL_REG_CLKGEN_H__

#include <jl_types.h>

#define CLKGEN_BASE                                                                  ((jl_uint32)0x00800000U)
#define CLKGEN_BLOCK_SIZE                                                            ((jl_uint32)0x00000100U)

#define CLKGEN_CTL_0_OFFSET                                                          ((jl_uint32)0x00000000U)
#define CLKGEN_CTL_0_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_0_u {
    struct {
        jl_uint32 osc_rstn:1;                                               //[ 0: 0]
        jl_uint32 mcu_rstn:1;                                               //[ 1: 1]
        jl_uint32 mcu_clk_en:1;                                             //[ 2: 2]
        jl_uint32 core_pre_clk_en:1;                                        //[ 3: 3]
        jl_uint32 core_6p25_rstn:1;                                         //[ 4: 4]
        jl_uint32 core_62p5_rstn:1;                                         //[ 5: 5]
        jl_uint32 core_12p5_rstn:1;                                         //[ 6: 6]
        jl_uint32 mag_rstn:1;                                               //[ 7: 7]
        jl_uint32 mag_clk_en:1;                                             //[ 8: 8]
        jl_uint32 patch_rstn:1;                                             //[ 9: 9]
        jl_uint32 top_ana_rstn:1;                                           //[10:10]
        jl_uint32 top_cfg_rstn:1;                                           //[11:11]
        jl_uint32 led_rstn:1;                                               //[12:12]
        jl_uint32 inner_i2c_rstn:1;                                         //[13:13]
        jl_uint32 i2c_rstn:1;                                               //[14:14]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_0_t;

#define CLKGEN_CTL_1_OFFSET                                                          ((jl_uint32)0x00000001U)
#define CLKGEN_CTL_1_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_1_u {
    struct {
        jl_uint32 phy_0_global_rstn:1;                                      //[ 0: 0]
        jl_uint32 phy_1_global_rstn:1;                                      //[ 1: 1]
        jl_uint32 phy_2_global_rstn:1;                                      //[ 2: 2]
        jl_uint32 phy_3_global_rstn:1;                                      //[ 3: 3]
        jl_uint32 phy_4_global_rstn:1;                                      //[ 4: 4]
        jl_uint32 phy_5_global_rstn:1;                                      //[ 5: 5]
        jl_uint32 phy_6_global_rstn:1;                                      //[ 6: 6]
        jl_uint32 phy_7_global_rstn:1;                                      //[ 7: 7]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_1_t;

#define CLKGEN_CTL_2_OFFSET                                                          ((jl_uint32)0x00000002U)
#define CLKGEN_CTL_2_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_2_u {
    struct {
        jl_uint32 phy_mcu_0_clk_en:1;                                       //[ 0: 0]
        jl_uint32 phy_osc_0_clk_en:1;                                       //[ 1: 1]
        jl_uint32 phy_tx_0_clk_en:1;                                        //[ 2: 2]
        jl_uint32 phy_rx_0_clk_en:1;                                        //[ 3: 3]
        jl_uint32 phy_mcu_1_clk_en:1;                                       //[ 4: 4]
        jl_uint32 phy_osc_1_clk_en:1;                                       //[ 5: 5]
        jl_uint32 phy_tx_1_clk_en:1;                                        //[ 6: 6]
        jl_uint32 phy_rx_1_clk_en:1;                                        //[ 7: 7]
        jl_uint32 phy_mcu_2_clk_en:1;                                       //[ 8: 8]
        jl_uint32 phy_osc_2_clk_en:1;                                       //[ 9: 9]
        jl_uint32 phy_tx_2_clk_en:1;                                        //[10:10]
        jl_uint32 phy_rx_2_clk_en:1;                                        //[11:11]
        jl_uint32 phy_mcu_3_clk_en:1;                                       //[12:12]
        jl_uint32 phy_osc_3_clk_en:1;                                       //[13:13]
        jl_uint32 phy_tx_3_clk_en:1;                                        //[14:14]
        jl_uint32 phy_rx_3_clk_en:1;                                        //[15:15]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_2_t;

#define CLKGEN_CTL_3_OFFSET                                                          ((jl_uint32)0x00000003U)
#define CLKGEN_CTL_3_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_3_u {
    struct {
        jl_uint32 phy_mcu_4_clk_en:1;                                       //[ 0: 0]
        jl_uint32 phy_osc_4_clk_en:1;                                       //[ 1: 1]
        jl_uint32 phy_tx_4_clk_en:1;                                        //[ 2: 2]
        jl_uint32 phy_rx_4_clk_en:1;                                        //[ 3: 3]
        jl_uint32 phy_mcu_5_clk_en:1;                                       //[ 4: 4]
        jl_uint32 phy_osc_5_clk_en:1;                                       //[ 5: 5]
        jl_uint32 phy_tx_5_clk_en:1;                                        //[ 6: 6]
        jl_uint32 phy_rx_5_clk_en:1;                                        //[ 7: 7]
        jl_uint32 phy_mcu_6_clk_en:1;                                       //[ 8: 8]
        jl_uint32 phy_osc_6_clk_en:1;                                       //[ 9: 9]
        jl_uint32 phy_tx_6_clk_en:1;                                        //[10:10]
        jl_uint32 phy_rx_6_clk_en:1;                                        //[11:11]
        jl_uint32 phy_mcu_7_clk_en:1;                                       //[12:12]
        jl_uint32 phy_osc_7_clk_en:1;                                       //[13:13]
        jl_uint32 phy_tx_7_clk_en:1;                                        //[14:14]
        jl_uint32 phy_rx_7_clk_en:1;                                        //[15:15]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_3_t;

#define CLKGEN_CTL_4_OFFSET                                                          ((jl_uint32)0x00000004U)
#define CLKGEN_CTL_4_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_4_u {
    struct {
        jl_uint32 phy_tx_0_rstn:1;                                          //[ 0: 0]
        jl_uint32 phy_rx_0_rstn:1;                                          //[ 1: 1]
        jl_uint32 phy_tx_1_rstn:1;                                          //[ 2: 2]
        jl_uint32 phy_rx_1_rstn:1;                                          //[ 3: 3]
        jl_uint32 phy_tx_2_rstn:1;                                          //[ 4: 4]
        jl_uint32 phy_rx_2_rstn:1;                                          //[ 5: 5]
        jl_uint32 phy_tx_3_rstn:1;                                          //[ 6: 6]
        jl_uint32 phy_rx_3_rstn:1;                                          //[ 7: 7]
        jl_uint32 phy_tx_4_rstn:1;                                          //[ 8: 8]
        jl_uint32 phy_rx_4_rstn:1;                                          //[ 9: 9]
        jl_uint32 phy_tx_5_rstn:1;                                          //[10:10]
        jl_uint32 phy_rx_5_rstn:1;                                          //[11:11]
        jl_uint32 phy_tx_6_rstn:1;                                          //[12:12]
        jl_uint32 phy_rx_6_rstn:1;                                          //[13:13]
        jl_uint32 phy_tx_7_rstn:1;                                          //[14:14]
        jl_uint32 phy_rx_7_rstn:1;                                          //[15:15]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_4_t;

#define CLKGEN_CTL_5_OFFSET                                                          ((jl_uint32)0x00000005U)
#define CLKGEN_CTL_5_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_5_u {
    struct {
        jl_uint32 phy_tx_mux_0_clk_sel:1;                                   //[ 0: 0]
        jl_uint32 phy_rx_mux_0_clk_sel:1;                                   //[ 1: 1]
        jl_uint32 phy_tx_mux_1_clk_sel:1;                                   //[ 2: 2]
        jl_uint32 phy_rx_mux_1_clk_sel:1;                                   //[ 3: 3]
        jl_uint32 phy_tx_mux_2_clk_sel:1;                                   //[ 4: 4]
        jl_uint32 phy_rx_mux_2_clk_sel:1;                                   //[ 5: 5]
        jl_uint32 phy_tx_mux_3_clk_sel:1;                                   //[ 6: 6]
        jl_uint32 phy_rx_mux_3_clk_sel:1;                                   //[ 7: 7]
        jl_uint32 phy_tx_mux_4_clk_sel:1;                                   //[ 8: 8]
        jl_uint32 phy_rx_mux_4_clk_sel:1;                                   //[ 9: 9]
        jl_uint32 phy_tx_mux_5_clk_sel:1;                                   //[10:10]
        jl_uint32 phy_rx_mux_5_clk_sel:1;                                   //[11:11]
        jl_uint32 phy_tx_mux_6_clk_sel:1;                                   //[12:12]
        jl_uint32 phy_rx_mux_6_clk_sel:1;                                   //[13:13]
        jl_uint32 phy_tx_mux_7_clk_sel:1;                                   //[14:14]
        jl_uint32 phy_rx_mux_7_clk_sel:1;                                   //[15:15]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_5_t;

#define CLKGEN_CTL_6_OFFSET                                                          ((jl_uint32)0x00000006U)
#define CLKGEN_CTL_6_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_6_u {
    struct {
        jl_uint32 mac_0_clk_en:1;                                           //[ 0: 0]
        jl_uint32 mac_1_clk_en:1;                                           //[ 1: 1]
        jl_uint32 mac_2_clk_en:1;                                           //[ 2: 2]
        jl_uint32 mac_3_clk_en:1;                                           //[ 3: 3]
        jl_uint32 mac_4_clk_en:1;                                           //[ 4: 4]
        jl_uint32 mac_5_clk_en:1;                                           //[ 5: 5]
        jl_uint32 mac_6_clk_en:1;                                           //[ 6: 6]
        jl_uint32 mac_7_clk_en:1;                                           //[ 7: 7]
        jl_uint32 mac_8_clk_en:1;                                           //[ 8: 8]
        jl_uint32 mac_9_clk_en:1;                                           //[ 9: 9]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_6_t;

#define CLKGEN_CTL_7_OFFSET                                                          ((jl_uint32)0x00000007U)
#define CLKGEN_CTL_7_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_7_u {
    struct {
        jl_uint32 mac_0_rstn:1;                                             //[ 0: 0]
        jl_uint32 mac_1_rstn:1;                                             //[ 1: 1]
        jl_uint32 mac_2_rstn:1;                                             //[ 2: 2]
        jl_uint32 mac_3_rstn:1;                                             //[ 3: 3]
        jl_uint32 mac_4_rstn:1;                                             //[ 4: 4]
        jl_uint32 mac_5_rstn:1;                                             //[ 5: 5]
        jl_uint32 mac_6_rstn:1;                                             //[ 6: 6]
        jl_uint32 mac_7_rstn:1;                                             //[ 7: 7]
        jl_uint32 mac_8_rstn:1;                                             //[ 8: 8]
        jl_uint32 mac_9_rstn:1;                                             //[ 9: 9]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_7_t;

#define CLKGEN_CTL_8_OFFSET                                                          ((jl_uint32)0x00000008U)
#define CLKGEN_CTL_8_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_8_u {
    struct {
        jl_uint32 mac_mux_0_clk_sel:1;                                      //[ 0: 0]
        jl_uint32 mac_mux_1_clk_sel:1;                                      //[ 1: 1]
        jl_uint32 mac_mux_2_clk_sel:1;                                      //[ 2: 2]
        jl_uint32 mac_mux_3_clk_sel:1;                                      //[ 3: 3]
        jl_uint32 mac_mux_4_clk_sel:1;                                      //[ 4: 4]
        jl_uint32 mac_mux_5_clk_sel:1;                                      //[ 5: 5]
        jl_uint32 mac_mux_6_clk_sel:1;                                      //[ 6: 6]
        jl_uint32 mac_mux_7_clk_sel:1;                                      //[ 7: 7]
        jl_uint32 mac_mux_8_clk_sel:1;                                      //[ 8: 8]
        jl_uint32 mac_mux_9_clk_sel:1;                                      //[ 9: 9]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_8_t;

#define CLKGEN_CTL_9_OFFSET                                                          ((jl_uint32)0x00000009U)
#define CLKGEN_CTL_9_NUM                                                             ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_9_u {
    struct {
        jl_uint32 ext_rmii_refclk_out_8_clk_en:1;                           //[ 0: 0]
        jl_uint32 inner_rmii_refclk_8_clk_en:1;                             //[ 1: 1]
        jl_uint32 ext_rmii_refclk_out_9_clk_en:1;                           //[ 2: 2]
        jl_uint32 inner_rmii_refclk_9_clk_en:1;                             //[ 3: 3]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_9_t;

#define CLKGEN_CTL_10_OFFSET                                                         ((jl_uint32)0x0000000AU)
#define CLKGEN_CTL_10_NUM                                                            ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_10_u {
    struct {
        jl_uint32 inner_rmii_refclk_8_rstn:1;                               //[ 0: 0]
        jl_uint32 inner_rmii_refclk_9_rstn:1;                               //[ 1: 1]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_10_t;

#define CLKGEN_CTL_11_OFFSET                                                         ((jl_uint32)0x0000000BU)
#define CLKGEN_CTL_11_NUM                                                            ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_11_u {
    struct {
        jl_uint32 ext_mii_txclk_out_8_clk_en:1;                             //[ 0: 0]
        jl_uint32 ext_mii_rxclk_out_8_clk_en:1;                             //[ 1: 1]
        jl_uint32 inner_mii_txclk_8_clk_en:1;                               //[ 2: 2]
        jl_uint32 inner_mii_rxclk_8_clk_en:1;                               //[ 3: 3]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_11_t;

#define CLKGEN_CTL_12_OFFSET                                                         ((jl_uint32)0x0000000CU)
#define CLKGEN_CTL_12_NUM                                                            ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_12_u {
    struct {
        jl_uint32 inner_mii_txclk_8_rstn:1;                                 //[ 0: 0]
        jl_uint32 inner_mii_rxclk_8_rstn:1;                                 //[ 1: 1]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_12_t;

#define CLKGEN_CTL_13_OFFSET                                                         ((jl_uint32)0x0000000DU)
#define CLKGEN_CTL_13_NUM                                                            ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_13_u {
    struct {
        jl_uint32 inner_mii_txclk_9_clk_en:1;                               //[ 0: 0]
        jl_uint32 inner_mii_rxclk_9_clk_en:1;                               //[ 1: 1]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_13_t;

#define CLKGEN_CTL_14_OFFSET                                                         ((jl_uint32)0x0000000EU)
#define CLKGEN_CTL_14_NUM                                                            ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_14_u {
    struct {
        jl_uint32 inner_mii_txclk_9_rstn:1;                                 //[ 0: 0]
        jl_uint32 inner_mii_rxclk_9_rstn:1;                                 //[ 1: 1]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_14_t;

#define CLKGEN_CTL_15_OFFSET                                                         ((jl_uint32)0x0000000FU)
#define CLKGEN_CTL_15_NUM                                                            ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_15_u {
    struct {
        jl_uint32 phy_dbg_int_rstn:1;                                       //[ 0: 0]
        jl_uint32 phy_dbg_ext_rstn:1;                                       //[ 1: 1]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_15_t;

#define CLKGEN_CTL_16_OFFSET                                                         ((jl_uint32)0x00000010U)
#define CLKGEN_CTL_16_NUM                                                            ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_16_u {
    struct {
        jl_uint32 phy_dbg_0_1_mux_clk_sel:1;                                //[ 0: 0]
        jl_uint32 phy_dbg_2_3_mux_clk_sel:1;                                //[ 1: 1]
        jl_uint32 phy_dbg_4_5_mux_clk_sel:1;                                //[ 2: 2]
        jl_uint32 phy_dbg_6_7_mux_clk_sel:1;                                //[ 3: 3]
        jl_uint32 phy_dbg_01_23_mux_clk_sel:1;                              //[ 4: 4]
        jl_uint32 phy_dbg_45_67_mux_clk_sel:1;                              //[ 5: 5]
        jl_uint32 phy_dbg_0123_4567_mux_clk_sel:1;                          //[ 6: 6]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_16_t;

#define CLKGEN_CTL_17_OFFSET                                                         ((jl_uint32)0x00000011U)
#define CLKGEN_CTL_17_NUM                                                            ((jl_uint32)0x00000001U)
typedef union CLKGEN_CTL_17_u {
    struct {
        jl_uint32 p8_mii_mac_phy_sel:1;                                     //[ 0: 0]
        jl_uint32 p8_mii_rmii_sel:1;                                        //[ 1: 1]
        jl_uint32 p5_mode:1;                                                //[ 2: 2]
        jl_uint32 p4_mode:1;                                                //[ 3: 3]
        jl_uint32 mac9_to_p8_mode:1;                                        //[ 4: 4]
        jl_uint32 p8_rmii_refclk_sel:1;                                     //[ 5: 5]
        jl_uint32 p9_rmii_refclk_sel:1;                                     //[ 6: 6]
    } bf;
    jl_uint32 val[1];
} CLKGEN_CTL_17_t;

#endif /* __JL_REG_CLKGEN_H__ */
