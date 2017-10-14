#include <stdio.h>

int lines_no(char *file)
{
	int count=0;
	FILE *fptr;
	char ch;
	
	fptr = fopen(file,"r");
	
	while(ch!=EOF)
	{
		ch=fgetc(fptr);
		if(ch=='\n')
		count++;
	}
	fclose(fptr);
	return count;
}
