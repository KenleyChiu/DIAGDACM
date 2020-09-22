#include <stdio.h>
#include <string.h>


int main(){
	char input[2000]="", dataAll[2000]="", startbit='0', stopbit='1';
	char delim[]="||";
	int len;
	
	//printf("Input frame: ");
	scanf("%s", &input);
	
	char *frame = strtok(input, delim);
	
//	printf("\n");
	while(frame!=NULL){
		int len = strlen(frame), i=0;
		char data[300] = "";
		while(i!=len){
			if((i==len-1) && (frame[i]==stopbit)){ //validates if loop reached the stop bit
				break;
			}
			else if ((frame[0]=='0')&&(i!=0)){ //validates the start bit and that the index entails a data bit
				data[i-1] = frame[i]; 
			}
			i++;
		}
		frame = strtok(NULL, delim);
		if(frame!=NULL){ //to check whether input hasn't reached end
			strcat(data, delim); //concatenates "||" to end of data
			strcat(dataAll, data); //concatenates this data to whole data set
		}
		else{ //to check whether input reached end
			strcat(dataAll, data); //concatenates this data to whole data set
		}
	}
	
	
	//printf("Data and checksum: ");
//	printf("\n");
	printf("%s\n", dataAll); //display data appended with checksum
	
	
}
