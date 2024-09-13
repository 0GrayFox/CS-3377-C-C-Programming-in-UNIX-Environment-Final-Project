# OS Example

This project demonstrates a basic operating system setup, including a bootloader, kernel, and a simple shell. It is designed to be run using QEMU for x86 architecture.

## Features

- **Bootloader**: Simple assembly code to initialize the system.
- **Kernel**: A minimal C kernel that displays text and supports a basic shell loop.
- **File System**: Placeholder for file system support.
- **Shell**: Displays a simple prompt and prints a fixed command.

## Prerequisites

To build and run this project, you need the following tools installed:

- **NASM**: Assembler for the bootloader.
- **GCC**: Compiler for the kernel.
- **Clang**: Provides `lld` linker (for macOS users).
- **QEMU**: Emulator to run the OS image.

### Installing Dependencies

On macOS, you can use Homebrew to install the required tools:

```bash
brew install nasm gcc llvm qemu
nasm -f bin -o boot.bin boot.asm
gcc -ffreestanding -m16 -c -o kernel.o os_example.c
clang -nostdlib -T linker.ld -o kernel.bin kernel.o -fuse-ld=lld
cat boot.bin kernel.bin > os-image.bin
qemu-system-x86_64 -drive format=raw,file=os-image.bin



