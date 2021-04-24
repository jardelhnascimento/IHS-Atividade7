#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");
 
static int inteiro = -1;
module_param(inteiro, int, 0660);
 
static int mod_init(void){
    int i=0;
    printk(KERN_ALERT "Ola");
 
    for(i=0;i<inteiro; i++){
    	printk(KERN_ALERT "!");
    }
    printk(KERN_ALERT "\n");
    return 0;
}
 
static void mod_exit(void){
	if (inteiro!=-1){
    		printk(KERN_ALERT "Adeus! O parametro passado na inicialização foi: %d\n", inteiro);
    	}
    	else{
    		printk(KERN_ALERT "Adeus!");
    	}
    	printk(KERN_ALERT "\n");
}
module_init(mod_init);
module_exit(mod_exit);