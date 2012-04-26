#include <stdio.h>
#ifdef KERNEL_HDR
#include <asm/posix_types.h>
#include <asm/sigcontext.h>
#include <asm/siginfo.h>
#include <asm/stat.h>
#include <asm/statfs.h>
#include <linux/ipc.h>
#include <linux/mqueue.h>
#include <linux/msg.h>
#include <linux/resource.h>
#include <linux/sem.h>
#include <linux/shm.h>
#include <linux/time.h>
#include <linux/timex.h>
#else
#include <mqueue.h>
#include <signal.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/resource.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/timex.h>
#include <sys/types.h>
#endif

void
value (const char *name, int size)
{
  printf ("%s: %d\n", name, size);
}

int
main ()
{
#ifdef KERNEL_HDR
  value ("size of ino_t", sizeof (__kernel_ino_t));
  value ("size of pid_t", sizeof (__kernel_pid_t));
  value ("size of uid_t", sizeof (__kernel_uid32_t));
  value ("size of gid_t", sizeof (__kernel_gid32_t));
  value ("size of fsid_t", sizeof (__kernel_fsid_t));
  value ("size of time_t", sizeof (__kernel_time_t));
  value ("size of clock_t", sizeof (__kernel_clock_t));
  value ("size of suseconds_t", sizeof (__kernel_suseconds_t));
  value ("size of daddr_t", sizeof (__kernel_daddr_t));
  value ("size of __ipc_pid_t", sizeof (__kernel_ipc_pid_t));
  value ("size of struct ipc_perm", sizeof (struct ipc64_perm));
  value ("size of mqd_t", sizeof (__kernel_mqd_t));
  value ("size of struct msqid_ds", sizeof (struct msqid64_ds));
  value ("size of struct semid_ds", sizeof (struct semid64_ds));
  value ("size of struct shmid_ds", sizeof (struct shmid64_ds));
  value ("size of struct shminfo", sizeof (struct shminfo64));
#else
  value ("size of ino_t", sizeof (ino_t));
  value ("size of pid_t", sizeof (pid_t));
  value ("size of uid_t", sizeof (uid_t));
  value ("size of gid_t", sizeof (gid_t));
  value ("size of fsid_t", sizeof (fsid_t));
  value ("size of time_t", sizeof (time_t));
  value ("size of clock_t", sizeof (clock_t));
  value ("size of suseconds_t", sizeof (suseconds_t));
  value ("size of daddr_t", sizeof (daddr_t));
  value ("size of __ipc_pid_t", sizeof (__ipc_pid_t));
  value ("size of struct ipc_perm", sizeof (struct ipc_perm));
  value ("size of mqd_t", sizeof (mqd_t));
  value ("size of struct msqid_ds", sizeof (struct msqid_ds));
  value ("size of struct semid_ds", sizeof (struct semid_ds));
  value ("size of struct shmid_ds", sizeof (struct shmid_ds));
  value ("size of struct shminfo", sizeof (struct shminfo));
#endif
  value ("size of struct timeval", sizeof (struct timeval));
  value ("size of struct timespec", sizeof (struct timespec));
  value ("siginfo_t _sifields offset",
	 __builtin_offsetof (siginfo_t, _sifields));
  value ("siginfo_t si_utime offset",
	 __builtin_offsetof (siginfo_t, si_utime));
  value ("size of struct mq_attr", sizeof (struct mq_attr));
  value ("size of struct rlimit", sizeof (struct rlimit));
#ifdef __x86_64__
  value ("size of struct stat", sizeof (struct stat));
#else
  value ("size of struct stat64", sizeof (struct stat64));
#endif
  value ("size of struct statfs", sizeof (struct statfs));
  value ("size of struct statfs64", sizeof (struct statfs64));
  value ("size of struct timex", sizeof (struct timex));
  value ("size of struct msginfo", sizeof (struct msginfo));
  value ("size of struct msgbuf", sizeof (struct msgbuf));
  value ("size of struct seminfo", sizeof (struct seminfo));
  value ("size of struct sembuf", sizeof (struct sembuf));
  value ("size of struct shm_info", sizeof (struct shm_info));
#ifndef __x86_64__
  value ("size of struct _fpreg", sizeof (struct _fpreg));
  value ("size of struct _fpxreg", sizeof (struct _fpxreg));
  value ("size of struct _xmmreg", sizeof (struct _xmmreg));
#endif
  value ("size of struct _fpstate", sizeof (struct _fpstate));
  value ("size of struct sigcontext", sizeof (struct sigcontext));
  return 0;
}
