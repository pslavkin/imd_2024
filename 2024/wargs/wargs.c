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

/* [[file:../Notas.org::*Imprimiendo][Imprimiendo:1]] */
static int __init helloworld_init(void)
{
	pr_info("Hola Mundo!\n");
	pr_info("INT: %d\n", myint);
	pr_info("STR: %s\n", mystring);
	return 0;
}
/* Imprimiendo:1 ends here */

/* [[file:../Notas.org::*Imprimiendo][Imprimiendo:2]] */
static void __exit helloworld_exit(void)
  {
	  pr_info("Fin del mundo\n");
	  pr_info("INT: %d\n", myint);
	  pr_info("STR: %s\n", mystring);
  }
module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_AUTHOR("Valentino Slavkin");
MODULE_LICENSE("GPL");
/* Imprimiendo:2 ends here */
