include $(AM_HOME)/am/arch/isa/riscv64.mk

AM_SRCS := nutshell/isa/riscv/trm.c \
           nutshell/common/mainargs.S \
           nutshell/common/uartlite.c \
           nutshell/common/ioe.c \
           nutshell/common/timer.c \
           dummy/input.c \
           dummy/video.c \
           dummy/audio.c \
           dummy/cte.c \
           dummy/vme.c \
           dummy/mpe.c \
           nutshell/isa/riscv/boot/start.S

CFLAGS  += -I$(AM_HOME)/am/src/nutshell/include -DISA_H=\"riscv.h\"

ASFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/nutshell/common/mainargs.S

LDFLAGS += -L $(AM_HOME)/am/src/nutshell/ldscript
LDFLAGS += -T $(AM_HOME)/am/src/nutshell/isa/riscv/boot/loader64.ld
SEARCH_DIR :=$(AM_HOME)/gcc/lib/gcc/riscv64-unknown-linux-gnu/10.2.0
SEARCH_DIR_A :=$(AM_HOME)/gcc/riscv64-unknown-linux-gnu/lib
SEARCH_DIR_B :=$(AM_HOME)/gcc/sysroot/usr/lib

image:
	@echo + LD "->" $(BINARY_REL).elf
	@$(LD) $(LDFLAGS) --gc-sections -o $(BINARY).elf --start-group $(LINK_FILES) --end-group -L$(SEARCH_DIR)   -lgcc 
	@$(OBJDUMP) -d $(BINARY).elf > $(BINARY).txt
	@echo + OBJCOPY "->" $(BINARY_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(BINARY).elf $(BINARY).bin

run:
	$(MAKE) -C $(NUTSHELL_HOME) emu IMAGE="$(BINARY).bin" DATAWIDTH=64
