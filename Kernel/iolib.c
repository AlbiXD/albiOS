#include "iolib.h"
#define VGA_ADDRESS 0xB8000

volatile char *ptr = (volatile char *) VGA_ADDRESS;
int counter = 0;

void putchar(char c) {
    *(ptr+counter) = c;
    counter += 2;

void print(const char * str){
    for(int i = 0; str[i] != '\0'; i++){
        ptr[counter] = str[i];        
        counter += 2;
    }

}
