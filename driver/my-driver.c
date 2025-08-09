#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>

#define USER_DATA_SIZE 512

static struct proc_dir_entry *gpio_proc_entry = NULL;
static char user_write_data[USER_DATA_SIZE];

ssize_t gpio_proc_read(struct file *,
                       char __user * user,       //user input data
                       size_t,              //size of read
                       loff_t *)
{
    printk("module read \r\n");
    copy_to_user(user, "Hello Universe\n", 15);


    return 15;
}

ssize_t gpio_proc_write(struct file *, 
                        const char __user *, 
                        size_t, 
                        loff_t *)
{
    //memset(user_write_data, 0, USER_DATA_SIZE);
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
    proc_remove(gpio_proc_entry);
    printk("module exit \r\n");
}

module_init(module_entry);
module_exit(module_end);
MODULE_LICENSE("passive aggressive license");

// ‘ssize_t (*)(struct file *, char *, size_t,  loff_t *)’ {aka ‘long int (*)(struct file *, char *, long unsigned int,  long long int *)’} from incompatible pointer type
//  ‘size_t (*)(struct file *, char *, size_t,  loff_t *)’ {aka ‘long unsigned int (*)(struct file *, char *, long unsigned int,  long long int *)’} [-Werror=incompatible-pointer-types]