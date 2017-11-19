//testhello.c
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");

static short myshort = 1;
static int myint = 44;
static long int mylong = 9999;
static char *mystring = "hi";
static int myintArray[2] = {-1, -1};
static int arr_argc = 0;

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP |S_IWGRP);
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
module_param(mylong, long, S_IRUSR);
module_param(mystring, charp, 0000);
module_param_array(myintArray, int, &arr_argc, 0000);

static int __init testhello_init(void){
	int i;
	printk("<1>Hello \n====\n");
	printk("<1>myshort = %hd\n", myshort);
	printk("<1>myint = %d\n", myint);
	printk("<1>mylong = %ld\n", mylong);
	printk("<1>mystring = %s\n", mystring);

	for(i = 0; i < (sizeof(myintArray) / sizeof(int)); i++){
		printk("<1>myintArray[%d] = %d\n", i, myintArray[i]);
	}
		printk("<1>got %d arguments \n", arr_argc);
		return 0;
}

static void __exit testhello_exit(void){
	printk("<1>Goodbye =========\n");
}

module_init(testhello_init);
module_exit(testhello_exit); 
