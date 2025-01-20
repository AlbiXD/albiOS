#ifndef IOLIB_H
#define IOLIB_H

#define VGA_ADDRESS 0xB8000

extern volatile char *ptr;
void putchar(char c);

void print(const char *str);

#endif // IOLIB_H
