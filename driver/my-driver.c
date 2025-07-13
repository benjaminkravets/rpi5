#include <linux/module.h>
#include <linux/kernel.h>
//#include <linux/init.h>

static int  __init module_entry(void)
{
    printk("module init \r\n");
    return 0;
}

static void __exit module_end(void)
{
    printk("module exit \r\n");

}


module_init(module_entry);
module_exit(module_end);
MODULE_LICENSE("passive aggressive license");