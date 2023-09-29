#ifndef MAIN_H
#define MAIN_H

unsigned int binary_to_uint(const char *bin);
void print_binary(unsigned long int in);
int get_bit(unsigned long int in, unsigned int ind);
int set_bit(unsigned long int *in, unsigned int ind);
int clear_bit(unsigned long int *in, unsigned int ind);
unsigned int flips_bit(unsigned long int in, unsigned long int im);
int _atoi(const char *is);
int _putchar(char ch);
int get_endian(void);

#endif
