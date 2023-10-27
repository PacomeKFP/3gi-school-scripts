#!/usr/bin/env bash

nasm -f elf32 kernel.asm -o obj/kasm.o
gcc -m32 -c kernel.c -o obj/kc.o -I include -ffreestanding

for d in lib/*.c; do
    path=$(echo $d | tr "/." "\n")
    file_name=$(echo $path | cut -d " " -f 2)
    gcc -m32 -c $d -o obj/$file_name.o -I include -ffreestanding
done

ld -m elf_i386 -T link.ld -o build/os/boot/kernel.bin obj/*.o
qemu-system-i386 -kernel build/os/boot/kernel.bin
grub-mkrescue -o build/IKnowOS.iso build/os/

#read a #to prevent bash to close after execution
