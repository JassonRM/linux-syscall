#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/kernel.h>

SYSCALL_DEFINE0(ctrace)
{
  usleep_range(1000, 100000);
  return 0;
}
