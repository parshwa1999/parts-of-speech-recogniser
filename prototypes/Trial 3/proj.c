/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: parshwadev
 *
 * Created on 2 December, 2016, 12:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

struct trie{
        char word;
        struct trie *child;
        struct trie *hori;
    };
    
typedef struct trie node;


int main(int argc, char** argv) {
   // Declatation 
    node *head=NULL,*curr,*currin;
    char find[20];
    int no_of_lines=5444;
    FILE *ptr;
    int i,j,flag;
    
    
    
    
   //Storing a linked list
    if(head == NULL)
    {
        head = malloc( sizeof(node) );
        head->word='*';
        curr = head;
    }
       
	ptr = fopen("nouns.txt","r");

	if(ptr == NULL)
	{
		printf("Cannont open file");
		return 0;
	}
	
	else
	{
		for( j=1 ; j<=no_of_lines ; j++ )
		{	//printf("\n%d",j);
			
			currin=curr;
			fscanf(ptr, "%s",find);
			
			//for(i=0;find[i-1]!='\0';i++)			
			//printf("%c",find[i]);					
				for( i = 0 ; i<=strlen(find)   ; i++ )
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
					
		//					printf("%d",i);
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

	fclose(ptr);


    
	}
    
	printf("SEARCH started");    
	currin=curr;

	printf("Enter a word");
	scanf("%s",find);


	for(i=0,flag=0;i<=strlen(find);i++)
	{
    		if(find[i]=='\0' && currin->word=='\0')
    		{
    			printf("\nnoun\n");
    			break;
    		}

		if(find[i]==currin->word)    
		{
			currin=currin->child;		
		}

		else if(find[i]!=currin->word)    
		{
			for(currin=currin->hori;currin->word!='*' && find[i]!=currin->word;currin=currin->hori);		
			
			if(find[i]==currin->word)    
				currin=currin->child;		
		
			if(find[i]!=currin->word && currin->word=='*')    
			{
				flag=1;
				break;		
			}
		}

    		/*if(currin->word=='*')
    		{
    			printf("\nEnter no is not a noun\n");
			break;
    		}*/
	}

    	flag?printf("Not a noun"):0;
    

    return (EXIT_SUCCESS);
}


