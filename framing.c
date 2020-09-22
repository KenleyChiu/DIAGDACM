#include <stdio.h>
#include <string.h>

#define max 10000

int main(){
    //variable declarations
char data[max]="", frame[max] = "", startbit[]="0", stopbit[]="1", copystr[max]="", delimiter[]="||";
int length, above288=1,startloc=0,endloc=0,dataloc=0;
//288 bits = 36 bytes
scanf("%s",&data); //gets data from checksum
length=strlen(data);

while(above288){ //loops until length is less than 290
    if(length>290){ //compares 290 to account for 2 delimiter characters
            memset(copystr,0,sizeof(copystr)); //resets copystr
            strcat(frame,startbit); //adds start bit
            memcpy(copystr,&data[dataloc],288); //copies 288 bits of data
            strcat(frame,copystr);  //adds the 288 bits of data
            strcat(frame,stopbit); //adds stop bit
            strcat(frame,delimiter);
            dataloc+=290; //shifts the index of the data to be copied
            length-=290; //reduces length for if comparison
           // printf("copystr: %s \n",copystr);
    }
    else {
            memset(copystr,0,sizeof(copystr));
          //  printf("copystr before else: %s \n",copystr);
            strcat(frame,startbit);
            memcpy(copystr,&data[dataloc],length);
            strcat(frame,copystr);
            strcat(frame,stopbit);
            //strcat(frame,delimiter);

        //    printf("copystr: %s \n",copystr);
            break;
    }
}
//10010101101011010010101010010111||011
//10010101101011010010101010010111011
//10010101101011010010101010010111||01110010101101011010010101010010||10010101101011010010101010010111||0101
//memcpy(frame,&data[3],5);
printf("%s\n",frame);
//char sample[]="sample";
//printf("%s",frame);

}

