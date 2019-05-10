#ifndef __OFFSETS_H
#define __OFFSETS_H

// 5.05
#define	KERN_XFAST_SYSCALL		0x1C0

// data
#define M_TEMP_addr                     0x14B4110
#define fpu_ctx_addr                    0x274C040
#define mini_syscore_self_binary_addr   0x14C9D48
#define sbl_driver_mapped_pages_addr    0x271E208
#define sbl_pfs_sx_addr                 0x271E5D8
#define sbl_keymgr_key_rbtree_addr      0x2744558
#define sbl_keymgr_key_slots_addr       0x2744548
#define sbl_keymgr_buf_va_addr          0x2748000
#define sbl_keymgr_buf_gva_addr         0x2748800
#define allproc_addr                    0x2382FF8

// common
#define strlen_addr                     0x3B71A0
#define strstr_addr                     0x17DFB0
#define malloc_addr                     0x10E250
#define free_addr                       0x10E460
#define printf_addr                     0x436040
#define memcpy_addr                     0x1EA530
#define memset_addr                     0x3205C0
#define memcmp_addr                     0x050AC0
#define sx_xlock_addr                   0x0F5E10
#define sx_xunlock_addr                 0x0F5FD0
#define fpu_kern_enter_addr             0x1BFF90
#define fpu_kern_leave_addr             0x1C0090

// Fself
#define sceSblAuthMgrSmStart_addr       0x6418E0
#define sceSblServiceMailbox_addr       0x632540
#define sceSblAuthMgrGetSelfInfo_addr   0x63CD40
#define sceSblAuthMgrIsLoadable2_addr   0x63C4F0
#define sceSblAuthMgrVerifyHeader_addr  0x642B40
#define sceSblACMgrGetPathId_addr       0x0117E0

// Fpkg
#define sceSblPfsKeymgrGenKeys_addr     0x62D480
#define sceSblPfsSetKeys_addr           0x61EFA0
#define sceSblKeymgrClearKey_addr       0x62DB10
#define sceSblKeymgrSetKeyForPfs_addr   0x62D780
#define sceSblKeymgrSetKeyStorage_addr  0x623FC0
#define sceSblKeymgrSmCallfunc_addr     0x62E2A0
#define sceSblDriverSendMsg_addr        0x61D7F0
#define RsaesPkcs1v15Dec2048CRT_addr    0x1FD7D0
#define AesCbcCfb128Encrypt_addr        0x3A2BD0
#define AesCbcCfb128Decrypt_addr        0x3A2E00
#define Sha256Hmac_addr                 0x2D55B0

// Patch
#define proc_rwmem_addr                 0x30D150
#define vmspace_acquire_ref_addr        0x19EF90
#define vmspace_free_addr               0x19EDC0
#define vm_map_lock_read_addr           0x19F140
#define vm_map_unlock_read_addr         0x19F190
#define vm_map_lookup_entry_addr        0x19F760

// Fself hooks
#define sceSblAuthMgrIsLoadable2_hook                             0x63E3A1
#define sceSblAuthMgrVerifyHeader_hook1                           0x63EAFC
#define sceSblAuthMgrVerifyHeader_hook2                           0x63F718
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook 0x64318B
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook   0x643DA2
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId__hook       0x63E25D

// Fpkg hooks
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook    0x64C720
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook         0x64D4FF
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook       0x624065
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                  0x62E96D
#define mountpfs__sceSblPfsSetKeys_hook1                          0x6AAAD5
#define mountpfs__sceSblPfsSetKeys_hook2                          0x6AAD04

// SceShellCore patches

// call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x16D05B 
#define sceKernelIsGenuineCEX_patch2    0x79980B
#define sceKernelIsGenuineCEX_patch3    0x7E5A13
#define sceKernelIsGenuineCEX_patch4    0x94715B
#define Patch_sceBgftNotifyGameWillStart_Error    0x3EA9A2

// call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x16D087
#define nidf_libSceDipsw_patch2         0x23747B
#define nidf_libSceDipsw_patch3         0x799837
#define nidf_libSceDipsw_patch4         0x947187

#define enable_data_mount_patch         0x319A53

// enable fpkg
#define enable_fpkg_patch               0x3E0602
 
// debug pkg free string
#define fake_free_patch                 0xEA96A7

// make pkgs installer working with external hdd
#define pkg_installer_patch	             0x9312A1

#endif
