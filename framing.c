#include <stdio.h>
#include <string.h>

#define max 100

int main(){
    //variable declarations
char data[max]="", frame[max] = "", startbit[]="0", stopbit[]="1", copystr[max]="";
int length, above32=1,startloc=0,endloc=0,dataloc=0;

scanf("%s",&data); //gets data from checksum
length=strlen(data);

printf("length: %i\n",length);
while(above32){ //loops until length is less than 32
    if(length>32){
            memset(copystr,0,sizeof(copystr)); //resets copystr before copying
            strcat(frame,startbit); //adds start bit
            memcpy(copystr,&data[dataloc],32); //copies 32 bits of data
            strcat(frame,copystr);  //adds the 32 bits of data
            strcat(frame,stopbit); //adds stop bit
            dataloc+=32; //shifts the index of the data to be copied
            length-=32; //reduces length for if comparison
           // printf("copystr: %s \n",copystr);
    }
    else {
            memset(copystr,0,sizeof(copystr));
          //  printf("copystr before else: %s \n",copystr);
            strcat(frame,startbit);
            memcpy(copystr,&data[dataloc],length);
            strcat(frame,copystr);
            strcat(frame,stopbit);
        //    printf("copystr: %s \n",copystr);
            break;
    }
}
//10010101101011010010101010010111011
//memcpy(frame,&data[3],5);
printf("%s\n",frame);
//char sample[]="sample";
//printf("%s",frame);

}
