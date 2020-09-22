#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bit.h"


//LRC Implementation
int global_terminate_check = 0;
bit_t *checksum_check(int size){
	bit_t *sum = malloc(sizeof(bit_t) * size);
	bit_t *prev_group = malloc(sizeof(bit_t) * size);
	int j;
	int exit_trigger = 0;
	for (j = 0; j != size; ++j) sum[j] = 0;
	for (j = 0; j != size; ++j) prev_group[j] = 0;
	while(1){
	 
		int i;
		int delimit_counter = 0;
		for (i = 0; i != size; ++i){
			bit_t curr_bit = get_bit();
			if (curr_bit == DELIMIT){
				delimit_counter++;
				if (delimit_counter == DELIMIT_REPEAT){
					exit_trigger = 1;
					break;
				}
			} else if(curr_bit == END) {
				global_terminate_check = ~global_terminate_check;
				exit_trigger = 1;
				break;
			}	
			else {
				prev_group[i] = curr_bit;
				sum[i] ^= curr_bit;
			}
		}
		
		if (!exit_trigger)
			for (i = 0; i != size; ++i)
				printf("%d", prev_group[i]);
		else break;
		
	}
	int l;
			//Check if sum is 0
	for (l = 0; l != size; ++l){
		if (sum[l] != 0) return NULL;
	}

}
int main(){
	while (!global_terminate_check){
		bit_t *sum = checksum_check(BLOCK_SIZE);
		if (sum != NULL && !global_terminate_check){
			printf("%c%c", DELIMITER, DELIMITER);
			//free(sum);
		}
	}
}
