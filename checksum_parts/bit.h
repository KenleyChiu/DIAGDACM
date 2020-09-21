#ifndef BIT_H
#define BIT_H
#include <stdbool.h>
#include <stdio.h>
#define HIGH 1
#define LOW 0
#define INVALID -255
#define END 255
#define DELIMITER '|'
#define DELIMIT_REPEAT 2
#define DELIMIT 2
#define MAX 1000
#define BLOCK_SIZE 8
typedef int bit_t;
bit_t to_bit(char c);
bit_t get_bit();
	

#endif
