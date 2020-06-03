#ifndef __DEFINES_H__
#define __DEFINES_H__
#pragma once

#define VERSION "2.1.4"

//#define DEBUG_SOCKET

#define LOG_IP   "192.168.1.3\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define LOG_PORT 9023

#define FAKE_FW_VERSION 0x07020000

struct filedesc {
	void *useless1[3];
	void *fd_rdir;
	void *fd_jdir;
};

struct proc {
	char useless[64];
	struct ucred *p_ucred;
	struct filedesc *p_fd;
};

struct thread {
	void *useless;
	struct proc *td_proc;
};

struct auditinfo_addr {
	char useless[184];
};

struct ucred {
	uint32_t useless1;
	uint32_t cr_uid;     // effective user id
	uint32_t cr_ruid;    // real user id
	uint32_t useless2;
	uint32_t useless3;
	uint32_t cr_rgid;    // real group id
	uint32_t useless4;
	void *useless5;
	void *useless6;
	void *cr_prison;     // jail(2)
	void *useless7;
	uint32_t useless8;
	void *useless9[2];
    void *useless10;
	struct auditinfo_addr useless11;
	uint32_t *cr_groups; // groups
	uint32_t useless12;
};

struct payload_info {
	uint8_t* buffer;
	size_t size;
};

struct payload_header {
	uint64_t signature;
	size_t entrypoint_offset;
};

struct install_payload_args {
	void* syscall_handler;
	struct payload_info* payload_info;
};

static inline __attribute__((always_inline)) uint64_t __readmsr(unsigned long __register) {
	unsigned long __edx;
	unsigned long __eax;
	__asm__ ("rdmsr" : "=d"(__edx), "=a"(__eax) : "c"(__register));
	return (((uint64_t)__edx) << 32) | (uint64_t)__eax;
}

#define X86_CR0_WP (1 << 16)

static inline __attribute__((always_inline)) uint64_t readCr0(void) {
	uint64_t cr0;
	__asm__ volatile ("movq %0, %%cr0" : "=r" (cr0) : : "memory");
	return cr0;
}

static inline __attribute__((always_inline)) void writeCr0(uint64_t cr0) {
	__asm__ volatile("movq %%cr0, %0" : : "r" (cr0) : "memory");
}

static inline __attribute__((always_inline)) void disable_interrupts(void) {
	__asm__ volatile("cli");
}

static inline __attribute__((always_inline)) void enable_interrupts(void) {
	__asm__ volatile("sti");
}

static inline __attribute__((always_inline)) uint64_t read_flags(void) {
	uint64_t flags;
	__asm__ volatile("pushf; pop %0;" : "=r" (flags));
	return flags;
}

static inline __attribute__((always_inline)) uint64_t intr_disable(void) {
	uint64_t flags = read_flags();
	disable_interrupts();
	return flags;
}

static inline __attribute__((always_inline)) void intr_restore(uint64_t flags) {
	__asm__ volatile("push %0; popf;" : : "rm" (flags) : "memory");
}

#endif
