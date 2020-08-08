#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 6.72
#define	XFAST_SYSCALL_addr              0x00001C0

// Names - Data
#define PRISON0_addr                    0x113E518
#define ROOTVNODE_addr                  0x2300320
#define PMAP_STORE_addr                 0x1BB7880
#define DT_HASH_SEGMENT_addr            0x0C00468

// Functions
#define pmap_protect_addr               0x050F50
#define pmap_protect_p_addr             0x050F9C

// Patches
// debug menu error
#define debug_menu_error_patch1         0x0507B09
#define debug_menu_error_patch2         0x0508D5C

// disable signature check
#define disable_signature_check_patch   0x06A8EB0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x066AEB0
#define enable_debug_rifs_patch2        0x066AEE0

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch          0x01D895A

// sdk version spoof - enable all VR fws
#define sdk_version_patch               0x1A84248

// enable debug log
#define enable_debug_log_patch          0x0123367

// enable uart output
#define enable_uart_patch               0x1A6EB18

#endif