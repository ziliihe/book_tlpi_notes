#include <linux/reboot.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/reboot.h>
#include <stdio.h>

int reboot(int cmd);

int main()
{
    printf("m1: %x, m2: %x, m2d: %d\n", LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_MAGIC2);
    printf("m2A: %d, m2B: %d, m2C: %d\n", LINUX_REBOOT_MAGIC2A, LINUX_REBOOT_MAGIC2B, LINUX_REBOOT_MAGIC2C);
    return 0;
}