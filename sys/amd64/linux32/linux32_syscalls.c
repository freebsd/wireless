/*
 * System call names.
 *
 * DO NOT EDIT-- this file is automatically @generated.
 */

const char *linux32_syscallnames[] = {
#define	nosys	linux_nosys
	"#0",			/* 0 = setup */
	"linux_exit",			/* 1 = linux_exit */
	"linux_fork",			/* 2 = linux_fork */
	"read",			/* 3 = read */
	"linux_write",			/* 4 = linux_write */
	"linux_open",			/* 5 = linux_open */
	"close",			/* 6 = close */
	"linux_waitpid",			/* 7 = linux_waitpid */
	"linux_creat",			/* 8 = linux_creat */
	"linux_link",			/* 9 = linux_link */
	"linux_unlink",			/* 10 = linux_unlink */
	"linux_execve",			/* 11 = linux_execve */
	"linux_chdir",			/* 12 = linux_chdir */
	"linux_time",			/* 13 = linux_time */
	"linux_mknod",			/* 14 = linux_mknod */
	"linux_chmod",			/* 15 = linux_chmod */
	"linux_lchown16",			/* 16 = linux_lchown16 */
	"#17",			/* 17 = break */
	"linux_stat",			/* 18 = linux_stat */
	"linux_lseek",			/* 19 = linux_lseek */
	"linux_getpid",			/* 20 = linux_getpid */
	"linux_mount",			/* 21 = linux_mount */
	"linux_oldumount",			/* 22 = linux_oldumount */
	"linux_setuid16",			/* 23 = linux_setuid16 */
	"linux_getuid16",			/* 24 = linux_getuid16 */
	"linux_stime",			/* 25 = linux_stime */
	"linux_ptrace",			/* 26 = linux_ptrace */
	"linux_alarm",			/* 27 = linux_alarm */
	"#28",			/* 28 = fstat */
	"linux_pause",			/* 29 = linux_pause */
	"linux_utime",			/* 30 = linux_utime */
	"#31",			/* 31 = stty */
	"#32",			/* 32 = gtty */
	"linux_access",			/* 33 = linux_access */
	"linux_nice",			/* 34 = linux_nice */
	"#35",			/* 35 = ftime */
	"sync",			/* 36 = sync */
	"linux_kill",			/* 37 = linux_kill */
	"linux_rename",			/* 38 = linux_rename */
	"linux_mkdir",			/* 39 = linux_mkdir */
	"linux_rmdir",			/* 40 = linux_rmdir */
	"dup",			/* 41 = dup */
	"linux_pipe",			/* 42 = linux_pipe */
	"linux_times",			/* 43 = linux_times */
	"#44",			/* 44 = prof */
	"linux_brk",			/* 45 = linux_brk */
	"linux_setgid16",			/* 46 = linux_setgid16 */
	"linux_getgid16",			/* 47 = linux_getgid16 */
	"linux_signal",			/* 48 = linux_signal */
	"linux_geteuid16",			/* 49 = linux_geteuid16 */
	"linux_getegid16",			/* 50 = linux_getegid16 */
	"acct",			/* 51 = acct */
	"linux_umount",			/* 52 = linux_umount */
	"#53",			/* 53 = lock */
	"linux_ioctl",			/* 54 = linux_ioctl */
	"linux_fcntl",			/* 55 = linux_fcntl */
	"#56",			/* 56 = mpx */
	"setpgid",			/* 57 = setpgid */
	"#58",			/* 58 = ulimit */
	"linux_olduname",			/* 59 = linux_olduname */
	"umask",			/* 60 = umask */
	"chroot",			/* 61 = chroot */
	"linux_ustat",			/* 62 = linux_ustat */
	"dup2",			/* 63 = dup2 */
	"linux_getppid",			/* 64 = linux_getppid */
	"getpgrp",			/* 65 = getpgrp */
	"setsid",			/* 66 = setsid */
	"linux_sigaction",			/* 67 = linux_sigaction */
	"linux_sgetmask",			/* 68 = linux_sgetmask */
	"linux_ssetmask",			/* 69 = linux_ssetmask */
	"linux_setreuid16",			/* 70 = linux_setreuid16 */
	"linux_setregid16",			/* 71 = linux_setregid16 */
	"linux_sigsuspend",			/* 72 = linux_sigsuspend */
	"linux_sigpending",			/* 73 = linux_sigpending */
	"linux_sethostname",			/* 74 = linux_sethostname */
	"linux_setrlimit",			/* 75 = linux_setrlimit */
	"linux_old_getrlimit",			/* 76 = linux_old_getrlimit */
	"linux_getrusage",			/* 77 = linux_getrusage */
	"linux_gettimeofday",			/* 78 = linux_gettimeofday */
	"linux_settimeofday",			/* 79 = linux_settimeofday */
	"linux_getgroups16",			/* 80 = linux_getgroups16 */
	"linux_setgroups16",			/* 81 = linux_setgroups16 */
	"linux_old_select",			/* 82 = linux_old_select */
	"linux_symlink",			/* 83 = linux_symlink */
	"linux_lstat",			/* 84 = linux_lstat */
	"linux_readlink",			/* 85 = linux_readlink */
	"#86",			/* 86 = linux_uselib */
	"swapon",			/* 87 = swapon */
	"linux_reboot",			/* 88 = linux_reboot */
	"linux_readdir",			/* 89 = linux_readdir */
	"linux_mmap",			/* 90 = linux_mmap */
	"munmap",			/* 91 = munmap */
	"linux_truncate",			/* 92 = linux_truncate */
	"linux_ftruncate",			/* 93 = linux_ftruncate */
	"fchmod",			/* 94 = fchmod */
	"fchown",			/* 95 = fchown */
	"linux_getpriority",			/* 96 = linux_getpriority */
	"setpriority",			/* 97 = setpriority */
	"#98",			/* 98 = profil */
	"linux_statfs",			/* 99 = linux_statfs */
	"linux_fstatfs",			/* 100 = linux_fstatfs */
	"#101",			/* 101 = ioperm */
	"linux_socketcall",			/* 102 = linux_socketcall */
	"linux_syslog",			/* 103 = linux_syslog */
	"linux_setitimer",			/* 104 = linux_setitimer */
	"linux_getitimer",			/* 105 = linux_getitimer */
	"linux_newstat",			/* 106 = linux_newstat */
	"linux_newlstat",			/* 107 = linux_newlstat */
	"linux_newfstat",			/* 108 = linux_newfstat */
	"linux_uname",			/* 109 = linux_uname */
	"linux_iopl",			/* 110 = linux_iopl */
	"linux_vhangup",			/* 111 = linux_vhangup */
	"#112",			/* 112 = idle */
	"#113",			/* 113 = vm86old */
	"linux_wait4",			/* 114 = linux_wait4 */
	"linux_swapoff",			/* 115 = linux_swapoff */
	"linux_sysinfo",			/* 116 = linux_sysinfo */
	"linux_ipc",			/* 117 = linux_ipc */
	"fsync",			/* 118 = fsync */
	"linux_sigreturn",			/* 119 = linux_sigreturn */
	"linux_clone",			/* 120 = linux_clone */
	"linux_setdomainname",			/* 121 = linux_setdomainname */
	"linux_newuname",			/* 122 = linux_newuname */
	"#123",			/* 123 = modify_ldt */
	"linux_adjtimex",			/* 124 = linux_adjtimex */
	"linux_mprotect",			/* 125 = linux_mprotect */
	"linux_sigprocmask",			/* 126 = linux_sigprocmask */
	"#127",			/* 127 = create_module */
	"linux_init_module",			/* 128 = linux_init_module */
	"linux_delete_module",			/* 129 = linux_delete_module */
	"#130",			/* 130 = get_kernel_syms */
	"linux_quotactl",			/* 131 = linux_quotactl */
	"getpgid",			/* 132 = getpgid */
	"fchdir",			/* 133 = fchdir */
	"linux_bdflush",			/* 134 = linux_bdflush */
	"linux_sysfs",			/* 135 = linux_sysfs */
	"linux_personality",			/* 136 = linux_personality */
	"#137",			/* 137 = afs_syscall */
	"linux_setfsuid16",			/* 138 = linux_setfsuid16 */
	"linux_setfsgid16",			/* 139 = linux_setfsgid16 */
	"linux_llseek",			/* 140 = linux_llseek */
	"linux_getdents",			/* 141 = linux_getdents */
	"linux_select",			/* 142 = linux_select */
	"flock",			/* 143 = flock */
	"linux_msync",			/* 144 = linux_msync */
	"linux_readv",			/* 145 = linux_readv */
	"linux_writev",			/* 146 = linux_writev */
	"linux_getsid",			/* 147 = linux_getsid */
	"linux_fdatasync",			/* 148 = linux_fdatasync */
	"linux_sysctl",			/* 149 = linux_sysctl */
	"mlock",			/* 150 = mlock */
	"munlock",			/* 151 = munlock */
	"mlockall",			/* 152 = mlockall */
	"munlockall",			/* 153 = munlockall */
	"linux_sched_setparam",			/* 154 = linux_sched_setparam */
	"linux_sched_getparam",			/* 155 = linux_sched_getparam */
	"linux_sched_setscheduler",			/* 156 = linux_sched_setscheduler */
	"linux_sched_getscheduler",			/* 157 = linux_sched_getscheduler */
	"sched_yield",			/* 158 = sched_yield */
	"linux_sched_get_priority_max",			/* 159 = linux_sched_get_priority_max */
	"linux_sched_get_priority_min",			/* 160 = linux_sched_get_priority_min */
	"linux_sched_rr_get_interval",			/* 161 = linux_sched_rr_get_interval */
	"linux_nanosleep",			/* 162 = linux_nanosleep */
	"linux_mremap",			/* 163 = linux_mremap */
	"linux_setresuid16",			/* 164 = linux_setresuid16 */
	"linux_getresuid16",			/* 165 = linux_getresuid16 */
	"#166",			/* 166 = vm86 */
	"#167",			/* 167 = query_module */
	"linux_poll",			/* 168 = linux_poll */
	"#169",			/* 169 = nfsservctl */
	"linux_setresgid16",			/* 170 = linux_setresgid16 */
	"linux_getresgid16",			/* 171 = linux_getresgid16 */
	"linux_prctl",			/* 172 = linux_prctl */
	"linux_rt_sigreturn",			/* 173 = linux_rt_sigreturn */
	"linux_rt_sigaction",			/* 174 = linux_rt_sigaction */
	"linux_rt_sigprocmask",			/* 175 = linux_rt_sigprocmask */
	"linux_rt_sigpending",			/* 176 = linux_rt_sigpending */
	"linux_rt_sigtimedwait",			/* 177 = linux_rt_sigtimedwait */
	"linux_rt_sigqueueinfo",			/* 178 = linux_rt_sigqueueinfo */
	"linux_rt_sigsuspend",			/* 179 = linux_rt_sigsuspend */
	"linux_pread",			/* 180 = linux_pread */
	"linux_pwrite",			/* 181 = linux_pwrite */
	"linux_chown16",			/* 182 = linux_chown16 */
	"linux_getcwd",			/* 183 = linux_getcwd */
	"linux_capget",			/* 184 = linux_capget */
	"linux_capset",			/* 185 = linux_capset */
	"linux_sigaltstack",			/* 186 = linux_sigaltstack */
	"linux_sendfile",			/* 187 = linux_sendfile */
	"#188",			/* 188 = getpmsg */
	"#189",			/* 189 = putpmsg */
	"linux_vfork",			/* 190 = linux_vfork */
	"linux_getrlimit",			/* 191 = linux_getrlimit */
	"linux_mmap2",			/* 192 = linux_mmap2 */
	"linux_truncate64",			/* 193 = linux_truncate64 */
	"linux_ftruncate64",			/* 194 = linux_ftruncate64 */
	"linux_stat64",			/* 195 = linux_stat64 */
	"linux_lstat64",			/* 196 = linux_lstat64 */
	"linux_fstat64",			/* 197 = linux_fstat64 */
	"linux_lchown",			/* 198 = linux_lchown */
	"linux_getuid",			/* 199 = linux_getuid */
	"linux_getgid",			/* 200 = linux_getgid */
	"geteuid",			/* 201 = geteuid */
	"getegid",			/* 202 = getegid */
	"setreuid",			/* 203 = setreuid */
	"setregid",			/* 204 = setregid */
	"linux_getgroups",			/* 205 = linux_getgroups */
	"linux_setgroups",			/* 206 = linux_setgroups */
	"fchown",			/* 207 = fchown */
	"setresuid",			/* 208 = setresuid */
	"getresuid",			/* 209 = getresuid */
	"setresgid",			/* 210 = setresgid */
	"getresgid",			/* 211 = getresgid */
	"linux_chown",			/* 212 = linux_chown */
	"setuid",			/* 213 = setuid */
	"setgid",			/* 214 = setgid */
	"linux_setfsuid",			/* 215 = linux_setfsuid */
	"linux_setfsgid",			/* 216 = linux_setfsgid */
	"linux_pivot_root",			/* 217 = linux_pivot_root */
	"linux_mincore",			/* 218 = linux_mincore */
	"linux_madvise",			/* 219 = linux_madvise */
	"linux_getdents64",			/* 220 = linux_getdents64 */
	"linux_fcntl64",			/* 221 = linux_fcntl64 */
	"#222",			/* 222 =  */
	"#223",			/* 223 =  */
	"linux_gettid",			/* 224 = linux_gettid */
	"#225",			/* 225 = linux_readahead */
	"linux_setxattr",			/* 226 = linux_setxattr */
	"linux_lsetxattr",			/* 227 = linux_lsetxattr */
	"linux_fsetxattr",			/* 228 = linux_fsetxattr */
	"linux_getxattr",			/* 229 = linux_getxattr */
	"linux_lgetxattr",			/* 230 = linux_lgetxattr */
	"linux_fgetxattr",			/* 231 = linux_fgetxattr */
	"linux_listxattr",			/* 232 = linux_listxattr */
	"linux_llistxattr",			/* 233 = linux_llistxattr */
	"linux_flistxattr",			/* 234 = linux_flistxattr */
	"linux_removexattr",			/* 235 = linux_removexattr */
	"linux_lremovexattr",			/* 236 = linux_lremovexattr */
	"linux_fremovexattr",			/* 237 = linux_fremovexattr */
	"linux_tkill",			/* 238 = linux_tkill */
	"linux_sendfile64",			/* 239 = linux_sendfile64 */
	"linux_sys_futex",			/* 240 = linux_sys_futex */
	"linux_sched_setaffinity",			/* 241 = linux_sched_setaffinity */
	"linux_sched_getaffinity",			/* 242 = linux_sched_getaffinity */
	"linux_set_thread_area",			/* 243 = linux_set_thread_area */
	"#244",			/* 244 = linux_get_thread_area */
	"#245",			/* 245 = linux_io_setup */
	"#246",			/* 246 = linux_io_destroy */
	"#247",			/* 247 = linux_io_getevents */
	"#248",			/* 248 = linux_io_submit */
	"#249",			/* 249 = linux_io_cancel */
	"linux_fadvise64",			/* 250 = linux_fadvise64 */
	"#251",			/* 251 =  */
	"linux_exit_group",			/* 252 = linux_exit_group */
	"linux_lookup_dcookie",			/* 253 = linux_lookup_dcookie */
	"linux_epoll_create",			/* 254 = linux_epoll_create */
	"linux_epoll_ctl",			/* 255 = linux_epoll_ctl */
	"linux_epoll_wait",			/* 256 = linux_epoll_wait */
	"linux_remap_file_pages",			/* 257 = linux_remap_file_pages */
	"linux_set_tid_address",			/* 258 = linux_set_tid_address */
	"linux_timer_create",			/* 259 = linux_timer_create */
	"linux_timer_settime",			/* 260 = linux_timer_settime */
	"linux_timer_gettime",			/* 261 = linux_timer_gettime */
	"linux_timer_getoverrun",			/* 262 = linux_timer_getoverrun */
	"linux_timer_delete",			/* 263 = linux_timer_delete */
	"linux_clock_settime",			/* 264 = linux_clock_settime */
	"linux_clock_gettime",			/* 265 = linux_clock_gettime */
	"linux_clock_getres",			/* 266 = linux_clock_getres */
	"linux_clock_nanosleep",			/* 267 = linux_clock_nanosleep */
	"linux_statfs64",			/* 268 = linux_statfs64 */
	"linux_fstatfs64",			/* 269 = linux_fstatfs64 */
	"linux_tgkill",			/* 270 = linux_tgkill */
	"linux_utimes",			/* 271 = linux_utimes */
	"linux_fadvise64_64",			/* 272 = linux_fadvise64_64 */
	"#273",			/* 273 = vserver */
	"linux_mbind",			/* 274 = linux_mbind */
	"linux_get_mempolicy",			/* 275 = linux_get_mempolicy */
	"linux_set_mempolicy",			/* 276 = linux_set_mempolicy */
	"linux_mq_open",			/* 277 = linux_mq_open */
	"linux_mq_unlink",			/* 278 = linux_mq_unlink */
	"linux_mq_timedsend",			/* 279 = linux_mq_timedsend */
	"linux_mq_timedreceive",			/* 280 = linux_mq_timedreceive */
	"linux_mq_notify",			/* 281 = linux_mq_notify */
	"linux_mq_getsetattr",			/* 282 = linux_mq_getsetattr */
	"linux_kexec_load",			/* 283 = linux_kexec_load */
	"linux_waitid",			/* 284 = linux_waitid */
	"#285",			/* 285 =  */
	"linux_add_key",			/* 286 = linux_add_key */
	"linux_request_key",			/* 287 = linux_request_key */
	"linux_keyctl",			/* 288 = linux_keyctl */
	"linux_ioprio_set",			/* 289 = linux_ioprio_set */
	"linux_ioprio_get",			/* 290 = linux_ioprio_get */
	"linux_inotify_init",			/* 291 = linux_inotify_init */
	"linux_inotify_add_watch",			/* 292 = linux_inotify_add_watch */
	"linux_inotify_rm_watch",			/* 293 = linux_inotify_rm_watch */
	"linux_migrate_pages",			/* 294 = linux_migrate_pages */
	"linux_openat",			/* 295 = linux_openat */
	"linux_mkdirat",			/* 296 = linux_mkdirat */
	"linux_mknodat",			/* 297 = linux_mknodat */
	"linux_fchownat",			/* 298 = linux_fchownat */
	"linux_futimesat",			/* 299 = linux_futimesat */
	"linux_fstatat64",			/* 300 = linux_fstatat64 */
	"linux_unlinkat",			/* 301 = linux_unlinkat */
	"linux_renameat",			/* 302 = linux_renameat */
	"linux_linkat",			/* 303 = linux_linkat */
	"linux_symlinkat",			/* 304 = linux_symlinkat */
	"linux_readlinkat",			/* 305 = linux_readlinkat */
	"linux_fchmodat",			/* 306 = linux_fchmodat */
	"linux_faccessat",			/* 307 = linux_faccessat */
	"linux_pselect6",			/* 308 = linux_pselect6 */
	"linux_ppoll",			/* 309 = linux_ppoll */
	"linux_unshare",			/* 310 = linux_unshare */
	"linux_set_robust_list",			/* 311 = linux_set_robust_list */
	"linux_get_robust_list",			/* 312 = linux_get_robust_list */
	"linux_splice",			/* 313 = linux_splice */
	"linux_sync_file_range",			/* 314 = linux_sync_file_range */
	"linux_tee",			/* 315 = linux_tee */
	"linux_vmsplice",			/* 316 = linux_vmsplice */
	"linux_move_pages",			/* 317 = linux_move_pages */
	"linux_getcpu",			/* 318 = linux_getcpu */
	"linux_epoll_pwait",			/* 319 = linux_epoll_pwait */
	"linux_utimensat",			/* 320 = linux_utimensat */
	"linux_signalfd",			/* 321 = linux_signalfd */
	"linux_timerfd_create",			/* 322 = linux_timerfd_create */
	"linux_eventfd",			/* 323 = linux_eventfd */
	"linux_fallocate",			/* 324 = linux_fallocate */
	"linux_timerfd_settime",			/* 325 = linux_timerfd_settime */
	"linux_timerfd_gettime",			/* 326 = linux_timerfd_gettime */
	"linux_signalfd4",			/* 327 = linux_signalfd4 */
	"linux_eventfd2",			/* 328 = linux_eventfd2 */
	"linux_epoll_create1",			/* 329 = linux_epoll_create1 */
	"linux_dup3",			/* 330 = linux_dup3 */
	"linux_pipe2",			/* 331 = linux_pipe2 */
	"linux_inotify_init1",			/* 332 = linux_inotify_init1 */
	"linux_preadv",			/* 333 = linux_preadv */
	"linux_pwritev",			/* 334 = linux_pwritev */
	"linux_rt_tgsigqueueinfo",			/* 335 = linux_rt_tgsigqueueinfo */
	"linux_perf_event_open",			/* 336 = linux_perf_event_open */
	"linux_recvmmsg",			/* 337 = linux_recvmmsg */
	"linux_fanotify_init",			/* 338 = linux_fanotify_init */
	"linux_fanotify_mark",			/* 339 = linux_fanotify_mark */
	"linux_prlimit64",			/* 340 = linux_prlimit64 */
	"linux_name_to_handle_at",			/* 341 = linux_name_to_handle_at */
	"linux_open_by_handle_at",			/* 342 = linux_open_by_handle_at */
	"linux_clock_adjtime",			/* 343 = linux_clock_adjtime */
	"linux_syncfs",			/* 344 = linux_syncfs */
	"linux_sendmmsg",			/* 345 = linux_sendmmsg */
	"linux_setns",			/* 346 = linux_setns */
	"linux_process_vm_readv",			/* 347 = linux_process_vm_readv */
	"linux_process_vm_writev",			/* 348 = linux_process_vm_writev */
	"linux_kcmp",			/* 349 = linux_kcmp */
	"linux_finit_module",			/* 350 = linux_finit_module */
	"linux_sched_setattr",			/* 351 = linux_sched_setattr */
	"linux_sched_getattr",			/* 352 = linux_sched_getattr */
	"linux_renameat2",			/* 353 = linux_renameat2 */
	"linux_seccomp",			/* 354 = linux_seccomp */
	"linux_getrandom",			/* 355 = linux_getrandom */
	"linux_memfd_create",			/* 356 = linux_memfd_create */
	"linux_bpf",			/* 357 = linux_bpf */
	"linux_execveat",			/* 358 = linux_execveat */
	"linux_socket",			/* 359 = linux_socket */
	"linux_socketpair",			/* 360 = linux_socketpair */
	"linux_bind",			/* 361 = linux_bind */
	"linux_connect",			/* 362 = linux_connect */
	"linux_listen",			/* 363 = linux_listen */
	"linux_accept4",			/* 364 = linux_accept4 */
	"linux_getsockopt",			/* 365 = linux_getsockopt */
	"linux_setsockopt",			/* 366 = linux_setsockopt */
	"linux_getsockname",			/* 367 = linux_getsockname */
	"linux_getpeername",			/* 368 = linux_getpeername */
	"linux_sendto",			/* 369 = linux_sendto */
	"linux_sendmsg",			/* 370 = linux_sendmsg */
	"linux_recvfrom",			/* 371 = linux_recvfrom */
	"linux_recvmsg",			/* 372 = linux_recvmsg */
	"linux_shutdown",			/* 373 = linux_shutdown */
	"linux_userfaultfd",			/* 374 = linux_userfaultfd */
	"linux_membarrier",			/* 375 = linux_membarrier */
	"linux_mlock2",			/* 376 = linux_mlock2 */
	"linux_copy_file_range",			/* 377 = linux_copy_file_range */
	"linux_preadv2",			/* 378 = linux_preadv2 */
	"linux_pwritev2",			/* 379 = linux_pwritev2 */
	"linux_pkey_mprotect",			/* 380 = linux_pkey_mprotect */
	"linux_pkey_alloc",			/* 381 = linux_pkey_alloc */
	"linux_pkey_free",			/* 382 = linux_pkey_free */
	"linux_statx",			/* 383 = linux_statx */
	"linux_arch_prctl",			/* 384 = linux_arch_prctl */
	"linux_io_pgetevents",			/* 385 = linux_io_pgetevents */
	"linux_rseq",			/* 386 = linux_rseq */
	"#387",			/* 387 = nosys */
	"#388",			/* 388 = nosys */
	"#389",			/* 389 = nosys */
	"#390",			/* 390 = nosys */
	"#391",			/* 391 = nosys */
	"#392",			/* 392 = nosys */
	"linux_semget",			/* 393 = linux_semget */
	"linux_semctl",			/* 394 = linux_semctl */
	"linux_shmget",			/* 395 = linux_shmget */
	"linux_shmctl",			/* 396 = linux_shmctl */
	"linux_shmat",			/* 397 = linux_shmat */
	"linux_shmdt",			/* 398 = linux_shmdt */
	"linux_msgget",			/* 399 = linux_msgget */
	"linux_msgsnd",			/* 400 = linux_msgsnd */
	"linux_msgrcv",			/* 401 = linux_msgrcv */
	"linux_msgctl",			/* 402 = linux_msgctl */
	"linux_clock_gettime64",			/* 403 = linux_clock_gettime64 */
	"linux_clock_settime64",			/* 404 = linux_clock_settime64 */
	"linux_clock_adjtime64",			/* 405 = linux_clock_adjtime64 */
	"linux_clock_getres_time64",			/* 406 = linux_clock_getres_time64 */
	"linux_clock_nanosleep_time64",			/* 407 = linux_clock_nanosleep_time64 */
	"linux_timer_gettime64",			/* 408 = linux_timer_gettime64 */
	"linux_timer_settime64",			/* 409 = linux_timer_settime64 */
	"linux_timerfd_gettime64",			/* 410 = linux_timerfd_gettime64 */
	"linux_timerfd_settime64",			/* 411 = linux_timerfd_settime64 */
	"linux_utimensat_time64",			/* 412 = linux_utimensat_time64 */
	"linux_pselect6_time64",			/* 413 = linux_pselect6_time64 */
	"linux_ppoll_time64",			/* 414 = linux_ppoll_time64 */
	"#415",			/* 415 = nosys */
	"linux_io_pgetevents_time64",			/* 416 = linux_io_pgetevents_time64 */
	"linux_recvmmsg_time64",			/* 417 = linux_recvmmsg_time64 */
	"linux_mq_timedsend_time64",			/* 418 = linux_mq_timedsend_time64 */
	"linux_mq_timedreceive_time64",			/* 419 = linux_mq_timedreceive_time64 */
	"linux_semtimedop_time64",			/* 420 = linux_semtimedop_time64 */
	"linux_rt_sigtimedwait_time64",			/* 421 = linux_rt_sigtimedwait_time64 */
	"linux_sys_futex_time64",			/* 422 = linux_sys_futex_time64 */
	"linux_sched_rr_get_interval_time64",			/* 423 = linux_sched_rr_get_interval_time64 */
	"linux_pidfd_send_signal",			/* 424 = linux_pidfd_send_signal */
	"linux_io_uring_setup",			/* 425 = linux_io_uring_setup */
	"linux_io_uring_enter",			/* 426 = linux_io_uring_enter */
	"linux_io_uring_register",			/* 427 = linux_io_uring_register */
	"linux_open_tree",			/* 428 = linux_open_tree */
	"linux_move_mount",			/* 429 = linux_move_mount */
	"linux_fsopen",			/* 430 = linux_fsopen */
	"linux_fsconfig",			/* 431 = linux_fsconfig */
	"linux_fsmount",			/* 432 = linux_fsmount */
	"linux_fspick",			/* 433 = linux_fspick */
	"linux_pidfd_open",			/* 434 = linux_pidfd_open */
	"linux_clone3",			/* 435 = linux_clone3 */
	"linux_close_range",			/* 436 = linux_close_range */
	"linux_openat2",			/* 437 = linux_openat2 */
	"linux_pidfd_getfd",			/* 438 = linux_pidfd_getfd */
	"linux_faccessat2",			/* 439 = linux_faccessat2 */
	"linux_process_madvise",			/* 440 = linux_process_madvise */
	"linux_epoll_pwait2_64",			/* 441 = linux_epoll_pwait2_64 */
	"linux_mount_setattr",			/* 442 = linux_mount_setattr */
	"linux_quotactl_fd",			/* 443 = linux_quotactl_fd */
	"linux_landlock_create_ruleset",			/* 444 = linux_landlock_create_ruleset */
	"linux_landlock_add_rule",			/* 445 = linux_landlock_add_rule */
	"linux_landlock_restrict_self",			/* 446 = linux_landlock_restrict_self */
	"linux_memfd_secret",			/* 447 = linux_memfd_secret */
	"linux_process_mrelease",			/* 448 = linux_process_mrelease */
	"linux_futex_waitv",			/* 449 = linux_futex_waitv */
	"linux_set_mempolicy_home_node",			/* 450 = linux_set_mempolicy_home_node */
	"linux_cachestat",			/* 451 = linux_cachestat */
	"linux_fchmodat2",			/* 452 = linux_fchmodat2 */
	"#453",			/* 453 = nosys */
};
