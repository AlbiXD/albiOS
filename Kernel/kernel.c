#include "iolib.h"

void init_vga(){
    ptr = (volatile char *) VGA_ADDRESS;
}

void main() {
    init_vga();
    print("albi\n");
    print("b\n");
    print("b");
    print("b\n");
    print("b\n");
    print("albi\n");
    print("b\n");
    print("b");
    print("b\n");
    print("b\n");
    while (1);
}


