# Emulating Cortex-m7 cpu on QEMU

## Requirements

1. GNU arm gcc toolchains 
  - https://developer.arm.com/downloads/-/gnu-rm
1. qemu for windows
  - https://qemu.weilnetz.de/w64/
1. Windows 10


## How to build

Modify the path of toolchain in makefile:

```
GCC_TOOLCHAIN   := D:/toolchains/arm/arm-eabi-v103/bin/arm-none-eabi
```

For release build:

```
$ make 
```

For debug build:

```
$ make DEBUG=1
```

To clean build artifacts:

```
$ make clean
```

If the build was successful, the HelloWorld.elf executable will be located in the build/gcc/output directory.


## How to run

```
make qemu
```


## How to debug with gdb

Append -s and -S options to the previous qemu command.

- -s: enable to attach gdb to QEMU at port 1234
- -S: start and halted CPU (wait for attach from gdb)

It is recommended to use the 'debug build' so that gdb can automatically map symbols.
Run these commands after starting the QEMU with above options:

```
$ arm-none-eabi-gdb.exe -x gdbinit
```


## Description

This demo just prints Tx/Rx message of queue to serial port, use no
other hardware and use only primary core (currently hart 0).
Other cores are simply going to wfi state and execute nothing else.
