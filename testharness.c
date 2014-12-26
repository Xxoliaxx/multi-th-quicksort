#define _GNU_SOURCE
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"sort.h"
#define MAX_WORD_SIZE 256
#define MAX_ARRAY_SIZE 50000

char* array[MAX_ARRAY_SIZE];

char* getNextWord(FILE* fd){

	char ch;
	char wordBuffer[MAX_WORD_SIZE];
	int putChar = 0;

	if(fd == NULL){
		printf("file was not read in properly.\n");
		exit(1);
	}

	while ((ch=fgetc(fd)) != EOF){
		if (isalpha(ch)) break;
		
	}

	if (ch == EOF) return NULL;

	wordBuffer[putChar++] = tolower(ch);

	while ((ch = fgetc(fd)) !=EOF){

		if (isspace(ch) || putChar >= MAX_WORD_SIZE - 1) break;
		if (isalnum(ch)){
			wordBuffer[putChar++] = tolower(ch);
		}
	}
	wordBuffer[putChar] = '\0';
	return strdup(wordBuffer);
}

int main(int argc, char* argv[]){

int i = 0;
char* nextword = NULL;

char** current = argv;
	if (argc == 1){
		fprintf(stderr, "No args given.\nUsage: ./testharness -integer file1.txt file2.txt...\n");
		exit(-1);
	}		
		
	current++; //moving past the first argument which is supposed to be num arguments
	char* temp = *current;
	 
	char* filename = *current;	
	

	FILE* fd = fopen(filename, "r"); 
		if (fd == NULL){
			fprintf(stderr,"can't read the file, moving to next file arg is there is one.\n");
			exit(-1);
		}


	while ((i < MAX_ARRAY_SIZE) && ((nextword = getNextWord(fd)) != NULL)){
		array[i] = nextword;
		i++;	
	}

	fclose(fd);
	
	sortThreaded(array, i);

	for (int u = 0; u < i; u++){
		printf("array[%d] = %s\n", u, array[u]);
	}

	for (int u = 0; u < i; u++){
		free(array[u]);
	}

return 0;
}
