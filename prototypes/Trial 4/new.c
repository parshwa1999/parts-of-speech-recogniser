#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <stdbool.h>

#define WORDS 30

struct trie
{
        char word;
        struct trie *child;
        struct trie *hori;
};
    
struct storage
{
	char input[12];
	bool type[9];
};

typedef struct storage pos; 
typedef struct trie node;

//Global Variables
pos type[WORDS];
int len_of_sen;
char type_of_word[9][20]={"nouns.txt","verbs.txt","abverbs.txt","adjectives.txt"};
char speech_parts[9][15]={"noun","verb","abverb","adjective"};

int main() {

void maien();

maien();


}




void maien() {
   // Declatation 
    node *head=NULL,*curr,*currin;
    char find[20];
    int no_of_lines=19;
    FILE *ptr;
    int i,m,j,flag,k;
    
    void seperator();    
    seperator();

    
    for(m=0,head=NULL;m<3;m++)
    {
	    //Declatation of Functions
	    
	    
	    //calling function seperator
	    
	    //seperator();
	    
	   //Storing a linked list
	    if(head == NULL)
	    {
		head = malloc( sizeof(node) );
		head->word='*';
		curr = head;
	    }
	       
		ptr = fopen(type_of_word[m],"r");

		if(ptr == NULL)
		{
			printf("Cannont open file");
		//	return 0;
		}
	
		else
		{
			for( j=1 ; j<=no_of_lines ; j++ )
			{	//printf("\n%d",j);			
				currin=curr;
				fscanf(ptr, "%s",find);
			
				//for(i=0;find[i-1]!='\0';i++)			
				//printf("%c",find[i]);					
					for( i = 0 ; i<=strlen(find); i++ )
					{
						if(find[i] != currin->word)
						{
							for(;currin->word!='*' && find[i]!=currin->word;currin=currin->hori);
						
							if(currin->word == '*')
							{
								currin->word = find[i];
								// Side ways allocation of memory
								currin->hori=malloc(sizeof(node));
								currin->hori->word='*';
								currin->hori->hori=NULL;
								currin->hori->child=NULL;
							
								// Downwards allocation of memory
								currin->child=malloc(sizeof(node));
								currin->child->word='*';
								currin->child->hori=NULL;
								currin->child->child=NULL;

							
								// Getting inside created link rewritten
								currin=currin->child;
				//				printf("\tx");
							}
					
			//				printf("%d",i);
							if(find[i] == currin->word)
							{
								currin=currin->child;
				//				printf("\tdd");
							}
					
						}
					
						else if(currin->word==find[i])        		
						{
							currin=currin->child;
				//			printf("\ty");					
						}
					}
					
					//printf("%d",i);
			}
	    	}
	//printf("Hello2");
		fclose(ptr);
	/*if(head->hori==NULL)
	printf("pointer is null\n");
	else
	printf("123%c\n",head->hori->word);*/
	//printf("Hello1");
    
	}
    
    
    	//  To search for the words
	printf("SEARCH started\n\n");    
/*	printf("%s",type_of_word[1]);
	printf("%s",type_of_word[2]);
	printf("%s",type_of_word[0]);*/
	//printf("Enter a word");


	//scanf("%s",find);
	
	for(k=0, strcpy(find,type[0].input); k<len_of_sen; strcpy(find,type[k].input), k++)
	{//printf("%sqqq\n\n",find);
		currin=curr;
		for(i=0,flag=0;i<=strlen(find);i++)
		{
	    		if(find[i]=='\0' && currin->word=='\0')
	    		{
	    			printf("%s",speech_parts[m]);
	    			break;
	    		}

			if(find[i]==currin->word)    
			{//printf("dir in child  %c",currin->word);
				currin=currin->child;		
			}

			else if(find[i]!=currin->word)    
			{
				
				for(currin=currin->hori;currin->word!='*'&&find[i]!=currin->word&&currin->hori!=NULL;currin=currin->hori);
			//	printf("hori %c",currin->word);
				if(find[i]==currin->word)    
					currin=currin->child;		
		
				if(find[i]!=currin->word && currin->word=='*')    
				{
//					flag=1;
					break;		
				}
				//printf("%c ",currin->hori->word);
			}
		}
//		flag?printf("'%s' Not a noun",find):0;
    	}
    

 //   return (EXIT_SUCCESS);
}


void seperator()
{




	int i,j;
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
		printf("%s",type[i].input);

}
