#include "bit.h"

bit_t get_bit(){
	char bit_char;
	while (scanf("%c", &bit_char) != EOF && bit_char != '\n'){
		if (bit_char == DELIMITER) return DELIMIT;
		if (bit_char == '0') return LOW;
		if (bit_char == ' ') continue;
		else if (bit_char == '1') return HIGH;
	}
	return END;
}
