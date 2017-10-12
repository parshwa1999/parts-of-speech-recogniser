#include<stdio.h>
#include<string.h>

int find_noun(char *input)
{
	int flag=1,i;
	char nouns[5][10]={"Neel","Kahan","Tanmay","Parshwa","Soham"};

	
	for(i=0,flag=strcmp(input,nouns[0]) ; flag && i<=5 ; i++,flag=strcmp(input,nouns[i]));
		
	return flag;
}
