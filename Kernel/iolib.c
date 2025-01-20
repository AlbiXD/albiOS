#include "iolib.h"
#define VGA_ADDRESS 0xB8000
#define VGA_COLUMNS 80

volatile char *ptr = (volatile char *) VGA_ADDRESS;
int cursor_pos = 0;

void putchar(char c) {
    *(ptr+cursor_pos) = c;
    cursor_pos += 2;
}



void print(const char* str) {

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            cursor_pos += (VGA_COLUMNS * 2) - (cursor_pos % (VGA_COLUMNS * 2));
        } else {
            ptr[cursor_pos] = str[i];        
            ptr[cursor_pos + 1] = 0x02;      
            cursor_pos += 2;                 
        }
    }
}
