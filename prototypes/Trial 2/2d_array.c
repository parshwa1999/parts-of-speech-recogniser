/*
This program is created by Parshwa Shah
Date:-30/09/2016
Objective :-
*/

#include<stdio.h>
#include<string.h>


int main()
{
	int binarysearch(int,char *,char [][10]);
	void strcopy(char *,char *);
	char temp[10],search[10][10],extra[10];
	int i,j,flag,lines=9;
	FILE *ptr;

	printf("Enter a string");
	scanf("%s",temp);

	ptr = fopen("temp.txt","r");

	if(ptr == NULL)
	{
		printf("Cannont open file");
		return 0;
	}
	
	else 
	{
		for( i=0 ; i<10 ; i++ )
		{
			fscanf(ptr,"%s",extra);
			strcopy(extra,search[i]);
		}
		
/*		for( i=0 ; i<10 ; i++ )
		{
			flag = strcmp(search[i],temp);
			if(!flag)
			{
			printf("%s is a noun",search[i]);
			return 1;
			}
		}
		
		printf("Noun is not found");
*/
		for(i=0;i<10;i++)
		//printf("\n%s",search[i]);
		//printf("END>>>>>>>>>>>>>>>>>>>>");
		flag = binarysearch(lines,temp,search);		
		
		fclose(ptr);
	}
	if(flag)
	printf("%s is a noun",temp);
	
	else
	printf("%s is not a noun",temp);
		
	return 1;
}

void strcopy(char *source,char *des)
{
	int i;
	for(i=0;source[i] != '\n' && source[i] != '\0' ;i++)
	des[i] = source[i];
		
	des[i]='\0';
}

int binarysearch(int high,char *check,char search[10][10])
{
	int low=0,middle,i;
	
	while(low<=high)
	{
 		middle = low + (high-low)/2;
 		
		if( search[middle][0] == check[0] )
 		{
 			for(i=1;search[middle][i]!='\0' && check[i]!='\0' && check[i]==search[middle][i];i++);
 			if(i==strlen(search[middle]) && i==strlen(check))
 			return 1;
 			
 			else if(search[middle][0] < check[0])
 			low=middle+1;
 		
 			else
 			high=middle-1;			
 		}
 
 		else if(search[middle][0] < check[0])
 		low=middle+1;
 		
 		else
 		high=middle-1;			
	}
	return 0;
}
