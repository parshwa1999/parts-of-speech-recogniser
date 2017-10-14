/*
-Project name :- Parts of Speech Identifier 
-Program name main.c
-Author:- Parshwa Shah

-Brief Description:-This program takes can take a sentence upto 30 word from the user and identify the parts of speech of sentence.
*/


//Header Files included in the program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <stdbool.h>
//header file that contains function line no to calculate no of lines in a file
#include"total_lines.h"

//Defining WORDS as a value 30 which is further used in the program
#define WORDS 30

//Structure in which tries part is used to be allocated ie blocks of tries 
struct trie
{
        char word;			//alphabet which is used to be compared while searching
        struct trie *child;		//to point bottom node ie child
        struct trie *hori;		//to point in horizontal direction of parent
};

// Structure in which we store the input from the user and store the part of speech in which the word lies
struct storage
{
	char input[50];		//to store the input taken from the user ina a string
	bool flag[9];		//to store the type of part of speech if they are of two types
};

typedef struct storage pos; 	//changing name of structure storage to pos
typedef struct trie node;	//changing name of structure trie to node

//Global Variables Declaration
/*
-Declaring an array of pos ie structure storage
-Declaring a variable of len_of_sen to know length of sentence (ie in word not in alphabets) that user enters
-char type_of_word[9][20] to store a two dimentional array to store names of file name
-char speech_parts[9][15] to store a two dimentional array to store names of which parts of speech does booleans belongs to
*/

pos type[WORDS];

int len_of_sen;

char type_of_word[9][20]={"nouns.txt","verbs.txt","adverbs.txt","adjectives.txt","interjection.txt","pronoun.txt","article.txt","preposition.txt","conjuction.txt"};

char speech_parts[9][15]={"noun","verb","adverb","adjective","interjection","pronoun","article","preposition","conjunction"};



//Start of main function (ie start of program)
void main()
{
	//Declaring function file_search
	void file_search();
	
	//Calling fuction file_search
	file_search();
}

//This function is to store from the file and search in a trie the word inputted by user 

void file_search() {
    // Declatation of local variable inside function
    /*
    -Declaring file pointer fptr
    -head to store first block of trie
    -curr currin to use to know the location of alphabets stored
    -no_of_lines to know no of lines in the program
    -i,j,flag,k,m variable are declared with thair usual meaning
    -find used for various purposes
    -word_length to store the length of word
    */
    node *head=NULL,*curr,*currin;
    char find[100],temp[100];
    int no_of_lines,word_length;
    FILE *fptr;
    int i,j,flag,k,m;
    
    //Declatation of Functions
    void user_input();
    void secondary_search();
    
    //calling function user_input
    user_input();
    
	//for loop runs 9 times because their ane 9 different files of 9 parts of speech
	for(m=0;m<9;m++)
	{
		head=NULL;
	
	    // Allocating head for the first time 
	    if(head == NULL)
	    {
	    	head = malloc( sizeof(node) );
		head->word='*';
		curr = head;
	    }
	     

		//calculating no of lines using lines no function declared in header file total_lines.h
		no_of_lines=lines_no(type_of_word[m]);
		
		//opening corresponding file in read mode
		fptr = fopen(type_of_word[m],"r");

		//checking as if that, is file is opened sucessfully
		if(fptr == NULL)
		{
			printf("Cannont open file");
		}
	
		//file opened sucessfully
		else
		{
			//loop1 runs till no_of_lines are there in files
			for( j=1 ; j<=no_of_lines ; j++ )
			{			
				currin=curr;
				//reading  a word from the file
				fscanf(fptr, "%s",find);

					//loop2 runs till length of word is reached
					word_length=strlen(find);			
					for( i = 0 ; i<=word_length; i++ )
					{	
						//creating trie structure
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
							}
					
							if(find[i] == currin->word)
							{
								//getting inside previously created branch
								currin=currin->child;
							}
					
						}
					
						else if(currin->word==find[i])        		
						{
							//getting inside previously created branch
							currin=currin->child;
						}
					}//end of loop2
	    		}//end of loop1
	    	//closing of file
		fclose(fptr);
		}
		
		//herer find is used to search for each word of sentence corresponding to opened files
		for(k=1, strcpy(find,type[0].input); k<=len_of_sen; strcpy(find,type[k].input), k++)
		{
			currin=head;

			//loopq runs till length of word is reached
			word_length=strlen(find);
						
			for(i=0,flag=0;i<=word_length;i++)
			{				
				if(find[i]=='\0' && currin->word=='\0')
		    		{
		    			type[k-1].flag[m]=1;
		    			//below comment is to show accuracy without secondary search
		    			//printf("\n%s-->%s\n",find,speech_parts[m]);
		    			break;
		    		}

				if(find[i]==currin->word)    
				{
					currin=currin->child;		
				}

				else if(find[i]!=currin->word)    
				{
					//for loop runs till horizontally end of trie ie * or word is found
					if(currin->hori != NULL)
					for(currin=currin->hori;currin->word!='*'&&find[i]!=currin->word&&currin->hori!=NULL;currin=currin->hori);
					if(find[i]==currin->word && currin->word!='\0')    
						currin=currin->child;		
		
		    			if(find[i]=='\0' && currin->word=='\0')
		    			{
		    				type[k-1].flag[m]=1;
		    				//below comment is to show accuracy without secondary search
		    				//printf("%s-->%s\n",find,speech_parts[m]);
		    				break;
		    			}


					if(find[i]!=currin->word && currin->word=='*')    
					{
						type[k-1].flag[m]=0;
						break;		
					}
				}
			}
	    	}//end of loopq
	}//loop reruns to check for new file of different parts of speech    

	//calling function secondary search
	secondary_search();
}

//This function is used to take input from the user
void user_input()
{

	//Below variable have their usual meaning
	int i,j;
	char ch;

	printf("Enter a Sentence\n");
	
	//loopwor to store no of words
	for(i=0;ch!='\n' && i<WORDS;i++)
	{
		//Assigning ch=a as ch can garbage value or ' ' so must be assigned a character ie a
		ch='a';
		for(j=0;isalpha(ch) && ch!='\n' && j<50;j++)
		{
			ch=getchar( );
			type[i].input[j]=ch;
		}
		//Allocating last element of string as null character
		type[i].input[j-1]='\0';
	}//end of loop wor

	//to know the length of sentence
	len_of_sen=i;
}

//this function is used to cross check and confirm part of speech allocated
void secondary_search()
{
	//count is to count that no of times the word occurs in different files
	//Rest Variables carry their usual meaning
	int i,m,count,flag=0;
	char temp[100];
	
	
	for(m=0;m<=len_of_sen;m++)
	{	
		flag=0;
		count=0;
		
		for(i=0;i<9;i++)
		{
			if(type[m].flag[i])
				count++;			
		}
		
		if(count==1)
		{
			for(i=0;i<9;i++)
			{
				if(type[m].flag[i])
				printf("%s is %s\n",type[m].input,speech_parts[i]);
			}	
		}
		
		else if(count>1 )
		{
			printf("\n");
			strcpy(temp,type[m].input);

			//To check if the word is found in two files		
			if(type[m].flag[0] &&( !strcmp(type[m-1].input,"a") || !strcmp(type[m-1].input,"an") || !strcmp(type[m-1].input,"the") || !strcmp(type[m-1].input,"this") || !strcmp(type[m-1].input,"those") || !strcmp(type[m-1].input,"that") || !strcmp(type[m-1].input,"these") || !strcmp(type[m-1].input,"any") || !strcmp(type[m-1].input,"no") || !strcmp(type[m-1].input,"few") || !strcmp(type[m-1].input,"several")))
			{
				flag=1;
				printf("%s is a Noun*\n",type[m].input);
			}
			
			else if(type[m].flag[1] && type[m+1].flag[3] || type[m+1].flag[6])
			{
				flag=1;
				printf("%s is a Verb*\n",type[m].input);
			}
		
			else if(type[m].flag[2] && !type[m-1].flag[1] )
			{
				flag=1;
				printf("%s is a adverb*\n",type[m].input);
			}

			else if(type[m].flag[4] && (type[m-1].flag[4] || type[m+1].flag[4]))
			{
				flag=1;
				printf("%s is a interjection*\n",type[m].input);
			}
			
			else if(type[m].flag[5] && (type[m-1].flag[5] || type[m+1].flag[5]))
			{
				flag=1;
				printf("%s is a pronoun*\n",type[m].input);
			}
			
			else if(type[m].flag[7] && (type[m-1].flag[7] || type[m+1].flag[7]))
			{
				flag=1;			
				printf("%s is a preposition*\n",type[m].input);
			}
			else if(type[m].flag[8] && (type[m-1].flag[8] || type[m+1].flag[8]))
			{
				flag=1;
				printf("%s is a conjunction*\n",type[m].input);
			}

			if(flag==0)
			{
				printf("\ncan't guess -----%s it can be ",type[m].input);
				for(i=0;i<=9;i++)
				{
					if(type[m].flag[i])
					printf(",%s",speech_parts[i]);
				}
			}
			printf("\n");

		}


	}
}
