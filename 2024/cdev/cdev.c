/* [[file:../Notas.org::*Imports][Imports:1]] */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/fs.h>
/* Imports:1 ends here */

/* [[file:../Notas.org::*Argumentos][Argumentos:1]] */
static int major_num = 202;
static int minor_num = 0;
module_param(major_num, int, 0660);
MODULE_PARM_DESC(major_num, "Major num to be used by the char device");
module_param(minor_num, int, 0660);
MODULE_PARM_DESC(minor_num, "Minor num to be used by the char device");
/* Argumentos:1 ends here */

/* [[file:../Notas.org::*FileSystem][FileSystem:1]] */
static struct cdev my_dev;
static int dev_open (struct inode *inode, struct file *file)
{
	pr_info("dev_open is called \n");
	return 0;
}
static int dev_close (struct inode *inode, struct file *file)
{
	pr_info("dev_open is called \n");
	return 0;
}
static long dev_ioctl (struct file *file, unsigned int cmd, unsigned long arg)
{
	pr_info("dev_ioctl is called\n cmd = %d, arg = %ld", cmd, arg);
	return 0;
}
static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = dev_open,
	.release = dev_close,
	.unlocked_ioctl = dev_ioctl,
};
/* FileSystem:1 ends here */

/* [[file:../Notas.org::*Inicialización][Inicialización:1]] */
static int __init helloworld_init(void)
{
	int ret;
	dev_t dev = MKDEV(major_num, minor_num);
	ret = register_chrdev_region(dev, 1, "my_char_device");
	if (ret < 0) {
		pr_err("Unable to allocate major number %d\n", major_num);
		return ret;
	}
	cdev_init(&my_dev, &fops);
	ret = cdev_add(&my_dev, dev, 1);
	if (ret < 0) {
		unregister_chrdev_region(dev, 1);
		pr_err("Unable to add cdev\n");
		return ret;
	}
	pr_info("Hola Mundo!\n");
	return 0;
}
static void __exit helloworld_exit(void)
{
	pr_info("Fin del mundo\n");
	cdev_del(&my_dev);
	unregister_chrdev_region(MKDEV(major_num, minor_num), 1);
}
module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_AUTHOR("Valentino Slavkin");
MODULE_LICENSE("GPL");
/* Inicialización:1 ends here */
