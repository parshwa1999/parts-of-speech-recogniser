/*
This program is created by Parshwa Shah
Date:-30/09/2016
Objective :-
*/

#include<stdio.h>
#include<string.h>
//#include<file.h>
//#include"noun.h"
#include"check.h"

void main()
{
	char input[70],temp[10],fromfile[10];
	int i,j,n=0,ilo=0,k,flag;
	
	int x;
	
	printf("\nEnter your input\n");
	//fgets(input,100,stdin);

	scanf("%[^\n]",input);
	
	for(i=0;strlen(input)+1>=i;i++)
	{
		if(input[i]==' '||input[i]=='\0')
		{
			for(j=0,n=i-ilo-1,k=0;k<=n;j++,k++)
			{
				if(ilo)
					temp[j]=input[ilo+k+1];
				else
					temp[j]=input[ilo+k];
			}
			temp[j]='\0';
			ilo=i;
			puts(temp);
			printf(" is -");
			x=word_type(temp);
		}
	}
			
	


}
