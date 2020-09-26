#include <stdio.h>
#include <string.h>

#define max 10000

int main(){
    //variable declarations
char data[max]="", frame[max] = "", startbit[]="0", stopbit[]="1", copystr[max]="", delimiter[]="||";
int length, dataloc=0, counter=0, i=0;
//288 bits = 36 bytes
scanf("%s",&data); //gets data from checksum
length=strlen(data);
int lastcheck=length;


for(i=0;i<length;i++){ //handles every frame except the last

        if(data[i]!='|'){ //iterates counter until delimiter is foumd
        counter++; //counts number of bits before a delimiter
        }

        else{
        memset(copystr,0,sizeof(copystr)); //resets copystr
        strcat(frame,startbit); //adds start bit
        memcpy(copystr,&data[dataloc],counter); //copies bits of data found before delimiter
        strcat(frame,copystr);  //adds the copied data
        strcat(frame,stopbit); //adds stop bit
        strcat(frame,delimiter); //adds delimiter
            dataloc=i+2; //+2 to skip delimiter indices
            counter=0; //resets counter
            i++; //iterates one more to skip delimeter

        }

    }

if(lastcheck!=0){ //appends the last frame that the for loop doesn't account for
            memset(copystr,0,sizeof(copystr));
            strcat(frame,startbit);
            memcpy(copystr,&data[dataloc],lastcheck); //copies the remaining bits after the last delimeter
            strcat(frame,copystr);                    //memcpy only copies until the last index
            strcat(frame,stopbit);                    //lastcheck = length to make sure that memcpy will reach end of data
}




printf("%s\n",frame);


}

