/*
Purpose: Identify whether entry is a valid identifier in C
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 200
#define NUM_KEY 32 

int check (char [], int);

/*
Function purpose: 
	This is the main function that takes user input and builds a
	potential identifier from each character unless the input
	is empty
Parameters: none
Return value: none
*/

int main(void)
{
	char ch;                   /*holds chars from input*/
	char ident[MAX_LEN] = "";  /*holds an identifier*/
	int  i = 0;                /*for iteration*/
	int valid;  			

	while ((ch = getchar()) != EOF){
		
		/*if an empty input ----> invalid */
		if (ch == '\n' && strlen(ident)== 0)
			printf("invalid\n");

		/*build an identifier from each char until '\n'*/
		else if (ch != '\n'){
			ident[i] = ch;
			i++;
			} 
			
		/*check if identifier contains illegal characters*/
		else if ((ch == '\n') && (strlen(ident) > 0)){
			ident[i] = '\0';
			valid = check (ident, strlen(ident));
			
			if (valid == 1) printf ("valid\n");
			else printf ("invalid\n");	
			 
			i = 0;
			ident[i] = '\0';	
			}
		}
		
return 0;		
}

/*-----------------------------------------------------------------*/
/*
Function purpose: The function check whether the potential identifier
	contains any illegal characters or is a key word in C	
Parameters: potential identifier ident[], its length n
Return value: if valid identifier--> 1, 0 otherwise
*/	

int check (char ident[], int n)
{
	int valid = 1;
	int j;
	char *key_words[] = {"auto", "break", "case", "char", "const", 
						"continue", "default", "do", "double", 
						"else", "enum", "extern", "float", "for",
						"goto", "if", "int", "long", "register",
						"return", "short", "signed", "sizeof", 
						"static", "struct", "switch", "typedef",
						"union", "unsigned", "void", "volatile", 
						"while"};
						
	/*check if identifier contains illegal characters*/					
	for (j=0; j < strlen(ident); j++ ) {
		if ((isdigit(ident[0]) == 0) && (ident[j] == '_' || \
			 isalpha(ident[j]) || isdigit(ident[j])))
			continue;
		else {		
			valid = 0;
			break;
			}
		}
	/*check if identifier is a keyword*/
	if (valid == 1){
		for (j = 0; j < NUM_KEY; j++){
			if (strcmp(ident, key_words[j]) == 0){
				valid = 0;
				break;	
				}
			}
		}
	
	return valid;
}