#include <stdio.h>
#ifdef KERNEL_HDR
#include <asm/siginfo.h>
#include <asm/statfs.h>
#include <linux/ipc.h>
#include <linux/mqueue.h>
#include <linux/resource.h>
#else
#include <mqueue.h>
#include <signal.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/resource.h>
#include <sys/statfs.h>
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
  value ("size of clock_t", sizeof (__kernel_clock_t));
  value ("size of __ipc_pid_t", sizeof (__kernel_ipc_pid_t));
  value ("size of struct ipc_perm", sizeof (struct ipc64_perm));
  value ("size of mqd_t", sizeof (__kernel_mqd_t));
#else
  value ("size of clock_t", sizeof (clock_t));
  value ("size of __ipc_pid_t", sizeof (__ipc_pid_t));
  value ("size of struct ipc_perm", sizeof (struct ipc_perm));
  value ("size of mqd_t", sizeof (mqd_t));
#endif
  value ("siginfo_t _sifields offset",
	 __builtin_offsetof (siginfo_t, _sifields));
  value ("siginfo_t si_utime offset",
	 __builtin_offsetof (siginfo_t, si_utime));
  value ("size of struct mq_attr", sizeof (struct mq_attr));
  value ("size of struct rlimit", sizeof (struct rlimit));
  value ("size of struct statfs", sizeof (struct statfs));
  value ("size of struct statfs64", sizeof (struct statfs64));
  return 0;
}
