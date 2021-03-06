/*This file has been prepared for Doxygen automatic documentation generation.*/
//! \file *********************************************************************
//!
//! \brief This file contains the interface :
//!  - between MEMORY  <-> USB (chip in USB device mode)
//!  - between MEMORY* <-> RAM (e.g. Embedded FileSystem control)
//!  *in this case the memory may be a USB MS device connected on the USB host of the chip
//!
//! - Compiler:           IAR EWAVR and GNU GCC for AVR
//! - Supported devices:  AT90USB1287, AT90USB1286, AT90USB647, AT90USB646
//!
//! \author               Atmel Corporation: http://www.atmel.com \n
//!                       Support and FAQ: http://support.atmel.no/
//!
//! ***************************************************************************

/* Copyright (c) 2007, Atmel Corporation All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. The name of ATMEL may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY AND
 * SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _MEM_CTRL_H_
#define _MEM_CTRL_H_

#include "conf/conf_access.h"
#include "ctrl_status.h"

// Active interface between MEMORIES and RAM (e.g. Embedded File System)
#ifndef  ACCESS_MEM_TO_RAM
#  define  ACCESS_MEM_TO_RAM    DISABLE
#endif

// Active the Logical Unit
#ifndef  LUN_0
#  define  LUN_0                DISABLE
#endif
#ifndef  LUN_1
#  define  LUN_1                DISABLE
#endif
#ifndef  LUN_2
#  define  LUN_2                DISABLE
#endif
#ifndef  LUN_3
#  define  LUN_3                DISABLE
#endif
#ifndef  LUN_4
#  define  LUN_4                DISABLE
#endif
#ifndef  LUN_5
#  define  LUN_5                DISABLE
#endif
#ifndef  LUN_6
#  define  LUN_6                DISABLE
#endif
#ifndef  LUN_7
#  define  LUN_7                DISABLE
#endif
#ifndef  LUN_USB
#  define  LUN_USB              DISABLE
#endif

// LUN 0 DEFINE
#define  LUN_ID_VIRTUAL                          LUN_ID_0
#define  LUN_0_INCLUDE                           "lib_mem\virtual_mem\virtual_mem.h"
#define  Lun_0_test_unit_ready()                 virtual_test_unit_ready()
#define  Lun_0_read_capacity(nb_sect)            virtual_read_capacity(nb_sect)
#define  Lun_0_wr_protect()                      virtual_wr_protect()
#define  Lun_0_removal()                         virtual_removal()
#define  Lun_0_read_10(ad, sec)                  virtual_read_10(ad, sec)
#define  Lun_0_write_10(ad, sec)                 virtual_write_10(ad, sec)
#define  Lun_0_ram_2_mem(addr , ram)             virtual_ram_2_mem(addr, ram)
#define  Lun_0_mem_2_ram(addr , ram)             virtual_mem_2_ram(addr, ram)
#define  LUN_0_NAME                              "VIRTUAL_MEM_ON_CHIP"

// LUN 1 DEFINE
#define  LUN_ID_NF                               LUN_ID_1
#define  LUN_1_INCLUDE                           "lib_mem\nf\nf_mngt.h"
#define  Lun_1_test_unit_ready()                 nf_test_unit_ready()
#define  Lun_1_read_capacity(nb_sect)            nf_read_capacity(nb_sect)
#define  Lun_1_wr_protect()                      nf_wr_protect()
#define  Lun_1_removal()                         nf_removal()
#define  Lun_1_read_10(ad, sec)                  nf_read_10(ad, sec)
#define  Lun_1_write_10(ad, sec)                 nf_write_10(ad, sec)
#define  Lun_1_ram_2_mem(addr , ram)             nf_ram_2_nf(addr, ram)
#define  Lun_1_mem_2_ram(addr , ram)             nf_nf_2_ram(addr, ram)
#define  LUN_1_NAME                               "\"NAND Flash\""

// LUN 2 DEFINE
#define  LUN_ID_DF                               LUN_ID_2
#define  LUN_2_INCLUDE                           "lib_mem\df\df_mem.h"
#define  Lun_2_test_unit_ready()                 df_test_unit_ready()
#define  Lun_2_read_capacity(nb_sect)            df_read_capacity(nb_sect)
#define  Lun_2_wr_protect()                      df_wr_protect()
#define  Lun_2_removal()                         df_removal()
#define  Lun_2_read_10(ad, sec)                  df_read_10(ad, sec)
#define  Lun_2_write_10(ad, sec)                 df_write_10(ad, sec)
#define  Lun_2_ram_2_mem(addr , ram)             df_ram_2_df(addr, ram)
#define  Lun_2_mem_2_ram(addr , ram)             df_df_2_ram(addr, ram)
#define  LUN_2_NAME                               "\"On board data flash\""

// LUN 3 DEFINE
#define  LUN_ID_MMC_SD                           LUN_ID_3
#define  LUN_3_INCLUDE                           "lib_mem\mmc_sd\mmc_sd_mem.h"
#define  Lun_3_test_unit_ready()                 mmc_sd_test_unit_ready()
#define  Lun_3_read_capacity(nb_sect)            mmc_sd_read_capacity(nb_sect)
#define  Lun_3_wr_protect()                      mmc_sd_wr_protect()
#define  Lun_3_removal()                         mmc_sd_removal()
#define  Lun_3_read_10(ad, sec)                  mmc_sd_read_10(ad, sec)
#define  Lun_3_write_10(ad, sec)                 mmc_sd_write_10(ad, sec)
#define  Lun_3_ram_2_mem(addr , ram)             mmc_ram_2_mmc(addr, ram)
#define  Lun_3_mem_2_ram(addr , ram)             mmc_mmc_2_ram(addr, ram)
#define  LUN_3_NAME                               "\"MMC\""

// LUN USB DEFINE
#define  LUN_USB_INCLUDE                           "lib_mem\host_mem\host_mem.h"
#define  Lun_usb_test_unit_ready(lun)              host_test_unit_ready(lun)
#define  Lun_usb_read_capacity(lun,nb_sect)        host_read_capacity(lun,nb_sect)
#define  Lun_usb_wr_protect(lun)                   host_wr_protect(lun)
#define  Lun_usb_removal()                         host_removal()
#define  Lun_usb_ram_2_mem(lun, addr , ram)        host_write_10_ram(lun,addr, ram)
#define  Lun_usb_mem_2_ram(lun, addr , ram)        host_read_10_ram(lun,addr, ram)
#define  LUN_USB_NAME                              "\"USB Remote memory\""


// FYC: Memory = Logical Unit
#if (LUN_0 == ENABLE)
   #include    LUN_0_INCLUDE
#endif
#if (LUN_1 == ENABLE)
   #include    LUN_1_INCLUDE
#endif
#if (LUN_2 == ENABLE)
   #include    LUN_2_INCLUDE
#endif
#if (LUN_3 == ENABLE)
   #include    LUN_3_INCLUDE
#endif
#if (LUN_4 == ENABLE)
   #include    LUN_4_INCLUDE
#endif
#if (LUN_5 == ENABLE)
   #include    LUN_5_INCLUDE
#endif
#if (LUN_6 == ENABLE)
   #include    LUN_6_INCLUDE
#endif
#if (LUN_7 == ENABLE)
   #include    LUN_7_INCLUDE
#endif
#if (LUN_USB == ENABLE)
   #include    LUN_USB_INCLUDE
#endif


//_____ D E F I N I T I O N S ______________________________________________


//**** Listing of commun interface ****************************************

U8             get_nb_lun();
U8             get_cur_lun();
Ctrl_status    mem_test_unit_ready( U8 lun );
Ctrl_status    mem_read_capacity( U8 lun , U32 _MEM_TYPE_SLOW_ *u32_nb_sector );
U8             mem_sector_size( U8 lun );
Bool           mem_wr_protect( U8 lun );
Bool           mem_removal( U8 lun );
U8 code*       mem_name( U8 lun );


//**** Listing of READ/WRITE interface ************************************

//---- Interface for USB ---------------------------------------------------
Ctrl_status memory_2_usb( U8 lun , U32 addr , U16 nb_sector );
Ctrl_status usb_2_memory( U8 lun , U32 addr , U16 nb_sector );

//---- Interface for RAM to MEM --------------------------------------------
Ctrl_status    memory_2_ram( U8 lun , const U32 _MEM_TYPE_SLOW_ addr , U8 _MEM_TYPE_SLOW_ *ram );
Ctrl_status    ram_2_memory( U8 lun , const U32 _MEM_TYPE_SLOW_ addr , U8 _MEM_TYPE_SLOW_ * ram );

#define  ID_STREAM_ERR        0xFF
U8             stream_mem_to_mem( U8 src_lun , U32 src_addr , U8 dest_lun , U32 dest_addr , U16 nb_sector );
Ctrl_status    stream_state( U8 Id );
U16            stream_stop( U8 Id );

#endif   // _MEM_CTRL_H_

