#ifndef __rt_trace_defs_h
#define __rt_trace_defs_h

/*
 * This file is autogenerated from
 *   file:           ../../inst/rt_trace/rtl/rt_regs.r
 *     id:           rt_regs.r,v 1.18 2005/02/08 15:45:00 stefans Exp
 *     last modfied: Mon Apr 11 16:09:14 2005
 *
 *   by /n/asic/design/tools/rdesc/src/rdes2c --outfile rt_trace_defs.h ../../inst/rt_trace/rtl/rt_regs.r
 *      id: $Id: rt_trace_defs.h,v 1.1 2005/04/24 18:30:58 starvik Exp $
 * Any changes here will be lost.
 *
 * -*- buffer-read-only: t -*-
 */
/* Main access macros */
#ifndef REG_RD
#define REG_RD( scope, inst, reg ) \
  REG_READ( reg_##scope##_##reg, \
            (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_WR
#define REG_WR( scope, inst, reg, val ) \
  REG_WRITE( reg_##scope##_##reg, \
             (inst) + REG_WR_ADDR_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_VECT
#define REG_RD_VECT( scope, inst, reg, index ) \
  REG_READ( reg_##scope##_##reg, \
            (inst) + REG_RD_ADDR_##scope##_##reg + \
	    (index) * STRIDE_##scope##_##reg )
#endif

#ifndef REG_WR_VECT
#define REG_WR_VECT( scope, inst, reg, index, val ) \
  REG_WRITE( reg_##scope##_##reg, \
             (inst) + REG_WR_ADDR_##scope##_##reg + \
	     (index) * STRIDE_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_INT
#define REG_RD_INT( scope, inst, reg ) \
  REG_READ( int, (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_WR_INT
#define REG_WR_INT( scope, inst, reg, val ) \
  REG_WRITE( int, (inst) + REG_WR_ADDR_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_INT_VECT
#define REG_RD_INT_VECT( scope, inst, reg, index ) \
  REG_READ( int, (inst) + REG_RD_ADDR_##scope##_##reg + \
	    (index) * STRIDE_##scope##_##reg )
#endif

#ifndef REG_WR_INT_VECT
#define REG_WR_INT_VECT( scope, inst, reg, index, val ) \
  REG_WRITE( int, (inst) + REG_WR_ADDR_##scope##_##reg + \
	     (index) * STRIDE_##scope##_##reg, (val) )
#endif

#ifndef REG_TYPE_CONV
#define REG_TYPE_CONV( type, orgtype, val ) \
  ( { union { orgtype o; type n; } r; r.o = val; r.n; } )
#endif

#ifndef reg_page_size
#define reg_page_size 8192
#endif

#ifndef REG_ADDR
#define REG_ADDR( scope, inst, reg ) \
  ( (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_ADDR_VECT
#define REG_ADDR_VECT( scope, inst, reg, index ) \
  ( (inst) + REG_RD_ADDR_##scope##_##reg + \
    (index) * STRIDE_##scope##_##reg )
#endif

/* C-code for register scope rt_trace */

/* Register rw_cfg, scope rt_trace, type rw */
typedef struct {
  unsigned int en       : 1;
  unsigned int mode     : 1;
  unsigned int owner    : 1;
  unsigned int wp       : 1;
  unsigned int stall    : 1;
  unsigned int dummy1   : 3;
  unsigned int wp_start : 7;
  unsigned int dummy2   : 1;
  unsigned int wp_stop  : 7;
  unsigned int dummy3   : 9;
} reg_rt_trace_rw_cfg;
#define REG_RD_ADDR_rt_trace_rw_cfg 0
#define REG_WR_ADDR_rt_trace_rw_cfg 0

/* Register rw_tap_ctrl, scope rt_trace, type rw */
typedef struct {
  unsigned int ack_data : 1;
  unsigned int ack_guru : 1;
  unsigned int dummy1   : 30;
} reg_rt_trace_rw_tap_ctrl;
#define REG_RD_ADDR_rt_trace_rw_tap_ctrl 4
#define REG_WR_ADDR_rt_trace_rw_tap_ctrl 4

/* Register r_tap_stat, scope rt_trace, type r */
typedef struct {
  unsigned int dav   : 1;
  unsigned int empty : 1;
  unsigned int dummy1 : 30;
} reg_rt_trace_r_tap_stat;
#define REG_RD_ADDR_rt_trace_r_tap_stat 8

/* Register rw_tap_data, scope rt_trace, type rw */
typedef unsigned int reg_rt_trace_rw_tap_data;
#define REG_RD_ADDR_rt_trace_rw_tap_data 12
#define REG_WR_ADDR_rt_trace_rw_tap_data 12

/* Register rw_tap_hdata, scope rt_trace, type rw */
typedef struct {
  unsigned int op     : 4;
  unsigned int sub_op : 4;
  unsigned int dummy1 : 24;
} reg_rt_trace_rw_tap_hdata;
#define REG_RD_ADDR_rt_trace_rw_tap_hdata 16
#define REG_WR_ADDR_rt_trace_rw_tap_hdata 16

/* Register r_redir, scope rt_trace, type r */
typedef unsigned int reg_rt_trace_r_redir;
#define REG_RD_ADDR_rt_trace_r_redir 20

/* Constants */
enum {
  regk_rt_trace_brk                        = 0x0000000c,
  regk_rt_trace_dbg                        = 0x00000003,
  regk_rt_trace_dbgdi                      = 0x00000004,
  regk_rt_trace_dbgdo                      = 0x00000005,
  regk_rt_trace_gmode                      = 0x00000000,
  regk_rt_trace_no                         = 0x00000000,
  regk_rt_trace_nop                        = 0x00000000,
  regk_rt_trace_normal                     = 0x00000000,
  regk_rt_trace_rdmem                      = 0x00000007,
  regk_rt_trace_rdmemb                     = 0x00000009,
  regk_rt_trace_rdpreg                     = 0x00000002,
  regk_rt_trace_rdreg                      = 0x00000001,
  regk_rt_trace_rdsreg                     = 0x00000003,
  regk_rt_trace_redir                      = 0x00000006,
  regk_rt_trace_ret                        = 0x0000000b,
  regk_rt_trace_rw_cfg_default             = 0x00000000,
  regk_rt_trace_trcfg                      = 0x00000001,
  regk_rt_trace_wp                         = 0x00000001,
  regk_rt_trace_wp0                        = 0x00000001,
  regk_rt_trace_wp1                        = 0x00000002,
  regk_rt_trace_wp2                        = 0x00000004,
  regk_rt_trace_wp3                        = 0x00000008,
  regk_rt_trace_wp4                        = 0x00000010,
  regk_rt_trace_wp5                        = 0x00000020,
  regk_rt_trace_wp6                        = 0x00000040,
  regk_rt_trace_wrmem                      = 0x00000008,
  regk_rt_trace_wrmemb                     = 0x0000000a,
  regk_rt_trace_wrpreg                     = 0x00000005,
  regk_rt_trace_wrreg                      = 0x00000004,
  regk_rt_trace_wrsreg                     = 0x00000006,
  regk_rt_trace_yes                        = 0x00000001
};
#endif /* __rt_trace_defs_h */
