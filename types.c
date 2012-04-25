#include <stdio.h>
#ifdef KERNEL_HDR
#include <asm/siginfo.h>
#include <linux/ipc.h>
#else
#include <signal.h>
#include <time.h>
#include <sys/ipc.h>
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
  value ("size of struct ipc_perm", sizeof (struct ipc64_perm));
#else
  value ("size of clock_t", sizeof (clock_t));
  value ("size of struct ipc_perm", sizeof (struct ipc_perm));
#endif
  value ("siginfo_t _sifields offset",
	 __builtin_offsetof (siginfo_t, _sifields));
  value ("siginfo_t si_utime offset",
	 __builtin_offsetof (siginfo_t, si_utime));
  return 0;
}
