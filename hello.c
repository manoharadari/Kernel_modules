#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/cdev.h>
static dev_t hello_dev_n;
struct cdev *hello_cdev = NULL;

static int hello_open(struct inode *inode , struct file *file)
{
	printk(KERN_INFO"hello open called\n");


	return 0;
}
static int hello_release(struct inode *inode , struct file *file)
{
	printk(KERN_INFO"hello release called\n");


	return 0;
}

static ssize_t hello_read( struct file *file , char *userdata , size_t count , loff_t *loff)
{
	printk(KERN_INFO"hello read called\n");


	return 0;
}

static ssize_t hello_write( struct file *file ,const char *user , size_t count , loff_t *loff)
{
	printk(KERN_INFO"hello write called\n");


	return 0;
}

static struct file_operations hello_fops =  \
{
	//.owner  = THIS_MODULE,
	.open = hello_open,
	.release = hello_release,
	.read = hello_read,
	.write = hello_write,
};


static int __init hello_init(void)
{
	printk(KERN_INFO"hello world\n");
	alloc_chrdev_region(&hello_dev_n , 0 , 255 , "helloC");

	hello_cdev = cdev_alloc();
	hello_cdev->ops = &hello_fops;
	hello_cdev->owner = THIS_MODULE;

	cdev_add(hello_cdev , hello_dev_n , 255);
#if 0
	i3f( (ret = register_chrdev_region(HELLO_MAJOR_NUMBER , 255 , "helloC")) != 0)
	 {
		 printk("error in register_chrdev_region\n");
		 return ret;
	 }
#endif

	return 0;

}

static void __exit hello_exit(void)
{
	printk(KERN_INFO"hello world module exited\n");
	unregister_chrdev_region(hello_dev_n , 255);
	cdev_del(hello_cdev);
}
module_init(hello_init);
module_exit(hello_exit)
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("hello module");
