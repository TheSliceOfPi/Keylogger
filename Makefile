obj-m += keylogger.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	