#!/bin/bash

# Export the cross-compiler path (adjust this to your setup)
export PATH=$PATH:/usr/local/i386elfgcc/bin

BOOTLOADER_DIR="Bootloader"
KERNEL_DIR="Kernel"
BIN_DIR="Binaries"
OS_IMAGE="$BIN_DIR/OS.bin"

mkdir -p "$BIN_DIR"

nasm "$BOOTLOADER_DIR/boot.asm" -f bin -o "$BIN_DIR/boot.bin"

nasm "$BOOTLOADER_DIR/kernel_entry.asm" -f elf -o "$BIN_DIR/kernel_entry.o"


i386-elf-gcc -ffreestanding -m32 -g -c "$KERNEL_DIR/kernel.c" -o "$BIN_DIR/kernel.o"


i386-elf-gcc -ffreestanding -m32 -g -c "$KERNEL_DIR/iolib.c" -o "$BIN_DIR/iolib.o"


i386-elf-ld -o "$BIN_DIR/full_kernel.bin" -Ttext 0x1000 "$BIN_DIR/kernel_entry.o" "$BIN_DIR/kernel.o" "$BIN_DIR/iolib.o" --oformat binary -e main


nasm "$BOOTLOADER_DIR/zeroes.asm" -f bin -o "$BIN_DIR/zeroes.bin"


cat "$BIN_DIR/boot.bin" "$BIN_DIR/full_kernel.bin" "$BIN_DIR/zeroes.bin" > "$OS_IMAGE"


qemu-system-x86_64 -drive format=raw,file="$OS_IMAGE",index=0,if=floppy -m 128M 
