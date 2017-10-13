#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define WORDS 30

struct storage
{
	char input[12];
	bool type[9];
};

typedef struct storage pos; 

void main()
{


	pos type[WORDS];

	int i,j,len_of_sen;
	char ch;

	for(i=0;ch!='\n' && i<WORDS;i++)
	{//printf("aa");
		ch='a';
		for(j=0;isalpha(ch) && ch!='\n' && j<20;j++)
		{//printf("bb");
			ch=getchar( );
			type[i].input[j]=ch;
		}
		type[i].input[j-1]='\0';
		//printf("----ch=%c------",ch);
	}
	//printf("%d",i);
	len_of_sen=i;

	for(i=0;i<len_of_sen;i++)
		printf("----------%s-----------",type[i].input);












/*	int i,j,k;
	char prev[20],next[20],present[20],input[100];

	printf("Enter the paragraph");
	scanf("%[^\n]",input);
	printf("Hello1");
	
	for(i=0, j=0; input[i]!='\0'; i++)
	{printf("\tHello2");
		if(i>j && !(isspace(input[i])) )
		{	printf("\tHello");
			for(k=0; k<=i-j && j<i ;k++)
			{
				present[k]=input[j];			
			}
			j++;
		}
			printf("%s",present);
	}
*/



}
