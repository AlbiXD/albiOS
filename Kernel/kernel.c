#include "iolib.h"

void init_vga(){
    ptr = (volatile char *) VGA_ADDRESS;
}

void main() {
    init_vga();
    print("hello");
    while (1);
}


