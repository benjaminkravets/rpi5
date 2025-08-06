#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>

static struct proc_dir_entry *gpio_proc_entry = NULL;

ssize_t gpio_proc_read(struct file *,
                       char __user *,       //user input data
                       size_t,              //size of read
                       loff_t *)
{
    printk("module read \r\n");
    copy_

    return 0;
}

ssize_t gpio_proc_write(struct file *, const char __user *, size_t, loff_t *)
{
    printk("module write \r\n");

    return 0;
}

struct proc_ops gpio_proc_ops = {
    .proc_read = gpio_proc_read,
    .proc_write = gpio_proc_write};

static int __init module_entry(void)
{
    printk("module init \r\n");

    gpio_proc_entry = proc_create("gpio_proc", 0666, NULL, &gpio_proc_ops);
    return 0;
}

static void __exit module_end(void)
{
    printk("module exit \r\n");
}

module_init(module_entry);
module_exit(module_end);
MODULE_LICENSE("passive aggressive license");

// ‘ssize_t (*)(struct file *, char *, size_t,  loff_t *)’ {aka ‘long int (*)(struct file *, char *, long unsigned int,  long long int *)’} from incompatible pointer type
//  ‘size_t (*)(struct file *, char *, size_t,  loff_t *)’ {aka ‘long unsigned int (*)(struct file *, char *, long unsigned int,  long long int *)’} [-Werror=incompatible-pointer-types]