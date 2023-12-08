CROSS_COMPILE=arm-linux-gnueabihf-
CC=$(CROSS_COMPILE)gcc --std=c99
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy #格式转换工具

APP = imx6ull.elf
BIN = imx6ull.bin #不带操作系统，elf头没用，将elf头去掉

SRC      = $(shell find driver  -name "*.c")
OBJS     = $(patsubst %.c,%.o,$(SRC))
OBJS    += start/start.o
OBJS    += main.o

INCLUDE  = -I include
CFLAGS   = -c
LDFLAGS  =  -static  -L ./lib -lgcc

all:$(OBJS) 
	$(LD) -Timx6ull.lds -Ttext=0x87800000 $(OBJS) -o $(APP) $(LDFLAGS)
	$(OBJCOPY) -O binary $(APP) $(BIN) 

%.o:%.c
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE)

%.o:%.S
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE)

clean:
	rm -rf $(OBJS)

distclean:
	rm -rf $(OBJS) $(APP) $(BIN)
