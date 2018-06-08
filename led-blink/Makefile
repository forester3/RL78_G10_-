#=======================================================================
#   @brief  RL78 Makefile 
#   @author     forester3
#   @copyright	Copyright (C) 2018 forester3   @n
#				Released under the MIT license @n
#				https://github.com/forester3
#=======================================================================

TARGET		=	led_blink

BUILD		=	build

VPATH		=	../

ASOURCES	=	common/start.s

CSOURCES	=	led_blink.c         \
                hwinit.c        	\
                common/inthandler.c	\
				common/vects.c

USER_LIBS	=	

LDSCRIPT	=	../common/linker_script.ld

USER_DEFS	=	F_CLK=20000000

MCU_TARGET	=	-mcpu=g10

INC_SYS		=

INC_APP		=	. ../common

OPTIMIZE	=	-O2

AOPT		=	-fdata-sections -g2 -x 	\
				assembler-with-cpp		\
				-MMD -MP

CP_OPT		=	-Wall -Werror \
				-Wno-unused-variable \
				-fno-exceptions

CC_OPT		=	-g2 -Wall -Werror \
				-Wno-unused-variable \
				-fno-exceptions

SYSINCS		=	$(addprefix -I, $(INC_SYS))
APPINCS		=	$(addprefix -I, $(INC_APP))
AINCS		=	$(SYSINCS) $(APPINCS)
CINCS		=	$(SYSINCS) $(APPINCS)
PINCS		=	$(SYSINCS) $(APPINCS)
LIBINCS		=	$(addprefix -L, $(LIB_ROOT))
DEFS		=	$(addprefix -D, $(USER_DEFS))
LIBS		=	$(addprefix -l, $(USER_LIBS))

# You should not have to change anything below here.

AS			=	rl78-elf-as
CC			=	rl78-elf-gcc
CP			=	rl78-elf-g++
AR			=	rl78-elf-ar
LD			=	rl78-elf-ld
OBJCOPY		=	rl78-elf-objcopy
OBJDUMP		=	rl78-elf-objdump
SIZE		=	rl78-elf-size


AFLAGS		=	 $(MCU_TARGET) $(DEFS)
CFLAGS		=	-std=gnu11 $(CC_OPT) $(OPTIMIZE) $(MCU_TARGET) $(DEFS)
PFLAGS		=	-std=c++14 $(CP_OPT) $(OPTIMIZE) $(MCU_TARGET) $(DEFS)

override LDFLAGS = $(MCU_TARGET) -nostdlib -Wl,-Map,$(TARGET).map -T $(LDSCRIPT)


OBJCOPY_OPT	=	--srec-forceS3 --srec-len 32

OBJECTS	=	$(addprefix $(BUILD)/,$(patsubst %.s,%.o,$(ASOURCES))) \
			$(addprefix $(BUILD)/,$(patsubst %.c,%.o,$(CSOURCES))) \
			$(addprefix $(BUILD)/,$(patsubst %.cpp,%.o,$(PSOURCES)))

DOBJECTS =	$(addprefix $(BUILD)/,$(patsubst %.c,%.o,$(CSOURCES))) \
			$(addprefix $(BUILD)/,$(patsubst %.cpp,%.o,$(PSOURCES)))

DEPENDS =   $(patsubst %.o,%.d, $(DOBJECTS))

.PHONY: all clean
.SUFFIXES :
.SUFFIXES : .rc .hpp .s .h .c .cpp .d .o

all: $(BUILD) $(TARGET).elf text

$(TARGET).elf: $(OBJECTS) $(LDSCRIPT) Makefile
	$(CC) $(LDFLAGS) $(LIBINCS) -o $@ $(OBJECTS) $(LIBS)
	$(SIZE) $@

$(BUILD)/%.o: %.s
	mkdir -p $(dir $@); \
	$(CC) -c $(AOPT) $(AFLAGS) $(AINCS) -o $@ $<

$(BUILD)/%.o : %.c
	mkdir -p $(dir $@); \
	$(CC) -c $(COPT) $(CFLAGS) $(CINCS) $(CCWARN) -o $@ $<

$(BUILD)/%.o : %.cpp
	mkdir -p $(dir $@); \
	$(CP) -c $(POPT) $(PFLAGS) $(PINCS) $(CPWARN) -o $@ $<

$(BUILD)/%.d: %.c
	mkdir -p $(dir $@); \
	$(CC) -MM -DDEPEND_ESCAPE $(COPT) $(CFLAGS) $(APPINCS) $< \
	| sed 's/$(notdir $*)\.o:/$(subst /,\/,$(patsubst %.d,%.o,$@) $@):/' > $@ ; \
	[ -s $@ ] || rm -f $@

$(BUILD)/%.d: %.cpp
	mkdir -p $(dir $@); \
	$(CP) -MM -DDEPEND_ESCAPE $(POPT) $(PFLAGS) $(APPINCS) $< \
	| sed 's/$(notdir $*)\.o:/$(subst /,\/,$(patsubst %.d,%.o,$@) $@):/' > $@ ; \
	[ -s $@ ] || rm -f $@

clean:
	rm -rf $(BUILD) $(TARGET).elf $(TARGET).mot $(TARGET).lst $(TARGET).map

clean_depend:
	rm -f $(DEPENDS)

lst:  $(TARGET).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

# Rules for building the .text rom images

text: mot lst

bin: $(TARGET).bin
mot: $(TARGET).mot
lst: $(TARGET).lst

%.mot: %.elf
	$(OBJCOPY) $(OBJCOPY_OPT) -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

deploy:
	rl78g10flash /dev/ttyUSB0 -vvwcr $(TARGET).mot 4k
reset:
	rl78g10flash /dev/ttyUSB0 -r

-include $(DEPENDS)
