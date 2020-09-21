#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bit.h"

//LRC Implementation
int global_terminate = 0;
bit_t *checksum(int size){
	bit_t *sum = malloc(sizeof(bit_t) * size);
	int j;
	for (j = 0; j != size; ++j) sum[j] = 0;
	while(1){ 
		int i;
		int delimit_counter = 0;
		for (i = 0; i != size; ++i){
			bit_t curr_bit = get_bit();
			if (curr_bit == DELIMIT){
				delimit_counter++;
				if (delimit_counter == DELIMIT_REPEAT)
					return sum;
			} else if(curr_bit == END) {
				global_terminate = ~global_terminate;
				return sum;
			}	
			else {
				printf("%d", curr_bit);
				sum[i] ^=  curr_bit;
			}
		}
	}
}
int main(){
	while (!global_terminate){
		bit_t *sum = checksum(BLOCK_SIZE);
		int i;
 		for (i = 0; i != BLOCK_SIZE; ++i)
			printf("%d", sum[i]);
		printf("%c%c", DELIMITER, DELIMITER);
		free(sum);
	}
}
