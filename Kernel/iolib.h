#ifndef IOLIB_H
#define IOLIB_H

#define VGA_ADDRESS 0xB8000

extern volatile char *ptr;
void putchar(char c);

/*
* Prints on the same line
*/
void print(const char *str);


/*
* Prints and pushes curser to new line
*/
void println(const char *str);

#endif // IOLIB_H
