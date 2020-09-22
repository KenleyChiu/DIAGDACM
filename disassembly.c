#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void convertToBinary(int c)
{
	int j;
	
    for(j=8; j > 0; j--)
    {
        if(c >= pow(2,j-1))
        {
            printf("1");
            c=c-pow(2,j-1);
        }
        else
        {
            printf("0");
        }
    }
}

int main()
{
	int c, counter=0;
	while((c=fgetc(stdin)) != EOF)
	{
			convertToBinary(c);
			counter++;
			if(counter%35==0)
			{
				printf("||");
				counter=0;
			}
	}
	return 0;
}
