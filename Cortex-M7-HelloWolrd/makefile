# Copyright (c) 2014-2019 Arm Limited (or its affiliates). All rights reserved.
# Use, modification and redistribution of this file is subject to your possession of a
# valid End User License Agreement for the Arm Product of which these examples are part of 
# and your compliance with all applicable terms and conditions of such licence agreement.
#
# This example is intended to be built with Arm Compiler 6
#
# Environment variables for build options that the user might wish to change
#

APP ?= HelloWorld.elf
QUIET ?= @
OPT_LEVEL ?= 0
PLATFORM ?= CORTEXA
OUTPUTCHAN ?= SEMIHOSTED

# Other switches the user should not normally need to change:
ARCH = armv8.4-a
DEBUG_FLAGS = -g
OBJCOPYFLAGS4ICCM = -O binary -j .text -j .text.* -S -g
OBJCOPYFLAGS4DCCM = -O binary -j .rodata -j .rodata.* -j .data -j .data.* -R .debug -S -g

SHELL=$(windir)\system32\cmd.exe
RM_FILES = $(foreach file,$(1),if exist $(file) del /q $(file))
RM_DIRS = $(foreach dir,$(1),if exist $(dir) rmdir /s /q $(dir)$(EOL))

ifeq ($(QUIET),@)
PROGRESS = @echo Compiling $<...
endif

CC = armclang
SRC_DIR = src
ASM_DIR = asm
INC_DIR = include -I.
OBJ_DIR = obj
LINK = armlink

INCLUDES = -I$(INC_DIR)

DEPEND_FLAGS = -MD -MF $@.d
CPPFLAGS = $(DEFINES) $(INCLUDES) $(DEPEND_FLAGS) 
CFLAGS = $(DEBUG_FLAGS) -O$(OPT_LEVEL)
ASFLAGS = $(DEBUG_FLAGS)
LDFLAGS = --scatter=scatter.scat
TARGET_ARCH = --target=aarch64-arm-none-eabi -march=$(ARCH) -ffp-contract=fast -Wno-pointer-to-int-cast
LINK_TARGET_ARCH = --noremove --entry=bootcode --startup=bootcode --datacompressor=off --diag_suppress=L6314,L6318 

SPEC_FLAGS   := -DCPUARCH_M7S=1 -DWORDSIZE=32

ARCH               := armv8.4-a
CPU                := cortex-m7
LINK_GCC            := arm_m7.ld
GCC_LINKER_FILE       := -T link/$(LINK_GCC)

GCC_TOOLCHAIN   := D:/toolchains/arm/arm-eabi-v103/bin/arm-none-eabi
#GCC_TOOLCHAIN   := arm-none-eabi
GCC_ASM         := $(GCC_TOOLCHAIN)-as
GCC_TOOL        := $(GCC_TOOLCHAIN)-gcc
GCC_LINKER_ASM  := $(GCC_TOOLCHAIN)-ld
GCC_LINKER_CSRC := $(GCC_TOOLCHAIN)-gcc
GCC_DISASS      := $(GCC_TOOLCHAIN)-objdump
GCC_COPY      := $(GCC_TOOLCHAIN)-objcopy

# GCC options
GCC_ASM_OPTS          := -g -mcpu=cortex-m7 -mthumb -fno-builtin -I $(INC_DIR)
GCC_CC_OPTS           := -g -O0 -std=gnu11 -mcpu=cortex-m7 -mthumb -c $(CEXTFLAGS) $(SPEC_FLAGS) -ffunction-sections -fdata-sections -fno-builtin -Wall -I $(INC_DIR)

GCC_LINKER_OPTS_ASM   :=
GCC_LINKER_OPTS_CSRC  :=
GCC_LINKER_FILE       := -T $(LINK_GCC)  --specs=nosys.specs
GCC_DISASS_OPTS       := -d -x --disassemble-zeroes

APP_C_SRC := $(wildcard $(SRC_DIR)/*.c)
APP_S_SRC := $(wildcard $(ASM_DIR)/*.S)
OBJ_FILES := $(APP_C_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) 
OBJ_FILES += $(APP_S_SRC:$(ASM_DIR)/%.s=$(OBJ_DIR)/%.o)


ASM         := $(GCC_ASM)
CC          := $(GCC_TOOL)
LINKER_ASM  := $(GCC_LINKER_ASM)
LINKER_CSRC := $(GCC_LINKER_CSRC)

# GCC toolchain options selected
ASM_OPTS                  := $(GCC_ASM_OPTS)
CC_OPTS                   := $(GCC_CC_OPTS)
CC_SPECIAL_OPTS_DHRYSTONE := $(GCC_SPECIAL_OPTS_DHRYSTONE)
CC_SPECIAL_OPTS_DAXPY     := $(GCC_SPECIAL_OPTS_DAXPY)
LINKER_OPTS_ASM           := $(GCC_LINKER_OPTS_ASM)
LINKER_OPTS_CSRC          := $(GCC_LINKER_OPTS_CSRC)
LINKER_FILE               := $(GCC_LINKER_FILE)


.phony: all clean qemu qemu_remote

all: FORCE $(APP)

FORCE:
	@echo being

$(APP): $(OBJ_DIR) $(OBJ_FILES) 
	@echo Linking $@
	@echo $(GCC_LINKER_CSRC) $(GCC_LINKER_FILE) $(OBJ_FILES) -o $@
	$(QUIET) $(GCC_LINKER_CSRC) $(GCC_LINKER_FILE) $(OBJ_FILES) -o $@ -lgcc
	$(GCC_DISASS) $(GCC_DISASS_OPTS) $@ > HelloWorld.disass
	@$(GCC_COPY) $(OBJCOPYFLAGS4ICCM) $@ $(APP)_ATCM.bin
	@$(GCC_COPY) $(OBJCOPYFLAGS4DCCM) $@ $(APP)_BTCM.bin
	@echo Done.

clean:
	$(call RM_DIRS,$(OBJ_DIR))
	$(call RM_FILES,$(APP))
	$(call RM_FILES, HelloWorld.disass)
	$(call RM_FILES, *.s)
	$(call RM_FILES, *.bin)

qemu:
	C:\msys64\mingw64\bin\qemu-system-arm.exe -machine mps2-an385 -monitor null -semihosting --semihosting-config enable=on,target=native -kernel $(APP) -serial stdio -nographic
	
qemu_remote:
	start /b C:\msys64\mingw64\bin\qemu-system-arm.exe -machine mps2-an385  -monitor null -semihosting --semihosting-config enable=on,target=native -kernel $(APP) -serial stdio -nographic -S -s
	
$(OBJ_DIR):
	mkdir $@
	@echo $(OBJ_FILES)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo begin to comple c source
	$(PROGRESS)
	@echo $(CC) -c $(GCC_CC_OPTS) -o $@ $<
	$(QUIET) $(CC) -c $(GCC_CC_OPTS) -o $@ $<
	$(QUIET) $(CC) -c $(GCC_CC_OPTS) -S $< $(SRC_DIR)/

$(OBJ_DIR)/%.o : $(ASM_DIR)/%.S
	@echo begin to comple asm
	$(PROGRESS)
	@echo $(CC) -c $(ASM_OPTS)  -o $@ $<
	$(QUIET) $(CC) -c $(ASM_OPTS)  -o $@ $<

# Make sure everything is rebuilt if this makefile is changed
$(OBJ_FILES) $(APP): makefile
