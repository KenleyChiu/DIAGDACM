#include<stdio.h>
#include<math.h>
#include <stdlib.h>


char convertToAscii(int binary[])
{
	int j,total=0;
	for(j=8; j>0; j--)
	{
		total=total+binary[j-1]*pow(2,j-1);
//		printf("%d,",total);
	}
	
	return total;
}

int main()
{
	int count=8,binary[8];
	char c,out;
	
	while((c=fgetc(stdin))!= EOF)
	{
		if(c!='|')
		{
			binary[count-1]=c-'0';
//			printf("%d", binary[count-1]);
			count--;
			if(count==0)
			{
				out=convertToAscii(binary);
				printf("%c",out);
				count=8;
			}
		}
	}
}
