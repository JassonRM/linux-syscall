#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/kernel.h>

SYSCALL_DEFINE0(ctrace)
{
  printk("Test");
  return 0;
}
