; boot.asm - A simple bootloader
[bits 16]
[org 0x7c00]
mov ah, 0x0e
mov al, 'L'
int 0x10
mov al, 'o'
int 0x10
mov al, 'a'
int 0x10
mov al, 'd'
int 0x10
mov al, 'i'
int 0x10
mov al, 'n'
int 0x10
mov al, 'g'
int 0x10
jmp $
times 510 - ($ - $$) db 0
dw 0xaa55
