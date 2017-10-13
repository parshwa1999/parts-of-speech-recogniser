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
	char input[100];
	bool flag[9];
};

typedef struct storage pos; 
typedef struct trie node;

//Global Variables
pos type[WORDS];
int len_of_sen;
char type_of_word[9][20]={"nouns.txt","verbs.txt","adverbs.txt","adjectives.txt","interjection.txt","pronoun.txt","article.txt"};
char speech_parts[9][15]={"noun","verb","adverb","adjective","interjection","pronoun","article"};

void main(){
	void file_search();
	file_search();
}

void file_search() {
   // Declatation 
    node *head=NULL,*curr,*currin;
    char find[100],temp[100];
    int no_of_lines;
    FILE *ptr;
    int i,j,flag,k,m;
    
    //Declatation of Functions
    void seperator();
    void secondary_search();
    
    //calling function seperator
    
    seperator();
    

	for(m=0;m<2;m++)
	{//printf("%d",m);
	   //Storing a linked list
	head=NULL;
	no_of_lines=90000;

	    if(head == NULL)
	    {
		head = malloc( sizeof(node) );
		head->word='*';
		curr = head;
	    }
	       strcpy(temp,type_of_word[m]);
		ptr = fopen(temp,"r");

		if(ptr == NULL)
		{
			printf("Cannont open file");
		}
	
		else
		{
			for( j=1 ; j<=no_of_lines ; j++ )
			{	//fprintf("\n%d",j);			
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
	

		//printf("Enter a word");


		//scanf("%s",find);
	
		for(k=1, strcpy(find,type[0].input); k<=len_of_sen+1; strcpy(find,type[k].input), k++)
		{
		//printf("%d",k);
		//printf("%s_______q______%s\n\n",find,type[k].input);	
			currin=curr;
			for(i=0,flag=0;i<=strlen(find);i++)
			{//printf("1");
		    		if(find[i]=='\0' && currin->word=='\0')
		    		{
		    			type[k-1].flag[m]=1;
		    			printf("aaaa%s-->%s\n",find,speech_parts[m]);
		    			break;
		    		}

				if(find[i]==currin->word)    
				{//printf("dir in child  %c",currin->word);
					currin=currin->child;		
				}

				else if(find[i]!=currin->word)    
				{
				
					//printf("\nhi");
					for(currin=currin->hori;currin->word!='*'&&find[i]!=currin->word&&currin->hori!=NULL;currin=currin->hori);
				//	printf("hori %c",currin->word);
					if(find[i]==currin->word && currin->word!='\0')    
						currin=currin->child;
						
			    		if(find[i]=='\0' && currin->word=='\0')
			    		{
			    			type[k-1].flag[m]=1;
			    			printf("eeee%s-->%s\n",find,speech_parts[m]);
			    			break;
			    		}
					
		
					if(find[i]!=currin->word && currin->word=='*')    
					{
		//				flag=1;
						type[k-1].flag[m]=0;
						break;		
					}
					//printf("%c ",currin->hori->word);
				}
			}
		//	flag?printf("'%s' Not a noun",find):0;
	    	}
	}    


	secondary_search();

    //return (EXIT_SUCCESS);
}


void seperator()
{

	int i,j;
	char ch;

	printf("Enter a Word");
	
	for(i=0;ch!='\n' && i<WORDS;i++)
	{//printf("aa");
		ch='a';
		for(j=0;isalpha(ch) && ch!='\n' && j<100;j++)
		{//printf("bb");
			ch=getchar( );
			type[i].input[j]=ch;
		}
		type[i].input[j-1]='\0';
		//printf("----ch=%c------",ch);
	}
	//printf("%d",i);
	len_of_sen=i;

//	for(i=0;i<len_of_sen;i++)
//		printf("%s",type[i].input);

}

void secondary_search()
{
	int i,m,count;
	char temp[100];
	
	for(m=0;m<=len_of_sen;m++)
	{	count=0;
	//	printf("%d",m);
		/*for(i=0;i<=4;i++)
		{
			if(type[m].flag[i])
			printf("%s is %s\n",type[m].input,speech_parts[i]);
		}*/
		
		for(i=0;i<=4;i++)
		{
			if(type[m].flag[i])
				count++;			
		}
		//printf("WB %d",count);
		if(count==1)
		{//printf("WB %d",count);
			for(i=0;i<4;i++)
			{
				if(type[m].flag[i])
				printf("%s is %s\n",type[m].input,speech_parts[i]);
			}	
		}		

		else if(count>1 )
		{
			strcpy(temp,type[m].input);
		
			if(type[m].flag[0] &&( !strcmp(type[m-1].input,"a") || !strcmp(type[m-1].input,"an") || !strcmp(type[m-1].input,"the") || !strcmp(type[m-1].input,"this") || !strcmp(type[m-1].input,"those") || !strcmp(type[m-1].input,"that") || !strcmp(type[m-1].input,"these") || !strcmp(type[m-1].input,"any") || !strcmp(type[m-1].input,"no") || !strcmp(type[m-1].input,"few") || !strcmp(type[m-1].input,"several")))
			{
				printf("%s is a Noun*\n",type[m].input);
			}
			
			/*if(type[m+1].flag[3])
			printf("hhh");*/
			
			else if(type[m].flag[1] && type[m+1].flag[3] )
				printf("%s is a Verb*\n",type[m].input);
			
			//if(type[m].flag[1]  )
			//	printf("Verb**\n");
		
			else if(type[m].flag[2] && !type[m-1].flag[1] )
				printf("%s is a adverb*\n",type[m].input);

			/*else if(type[m].flag[3] && (type[m].input[strlen( (type[m].input) - 3)]=='e' || type[m].input[strlen( (type[m].input) - 2)]=='s' || type[m].input[strlen( (type[m].input) - 3)]=='t'))
				printf("%s is a adjective*\n",type[m].input);*/



		}

	}


}
