/*
	LAB 5
	NAME: Abhijit Bhandarkar
	B00659257
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Myfile.h"
#define JEDI_LENGTH 5

int heap_usage = 0;

//Function to find jedi name from First and Last name of a person
char *jedi(char *f_name, char *l_name, char *buffer)
{
        int i, j;
        char last[3], first[2];
        for(i = 0; i < 3; i++)
        {
                last[i] = l_name[i];
        }
        last[3] = '\0';
        for(j = 0; j < 2; j++)
        {
                first[j] = f_name[j];
        }
        first[2] = '\0';

        buffer = strcat(last,first);

	if(strlen(buffer) < JEDI_LENGTH )
	{	printf("Jedi name is smaller than the specified length of 5.\n");
        	buffer[5] = '\0';
        	printf("Jedi name is %s\n\n", buffer);
	}
	else
        {	buffer[5] = '\0';
        	printf("Jedi name is %s\n\n", buffer);
	}
return buffer;
}

//Function to allocates the requested amount of memory on the heap
void * allocate(unsigned int size)
{
	void *alloted_size = (unsigned int*)malloc(sizeof(unsigned int));
	if(alloted_size == NULL	)
	{
		fprintf(stderr,"Memory allocation failure\n");
		exit(0);
	}
	else
	{		
		heap_usage = heap_usage + size;
		printf("\nAllocated Memory:%d, Total Heap memory in use:%d\n\n", size, heap_usage);
		return alloted_size;
	}
}


//Function to free the memory parameter
void * deallocate(void *allocated_size, int size)
{
	heap_usage = heap_usage - size;
	printf("Deallocated Memory:%d, Total Heap memory in use:%d\n\n",size,heap_usage);
	allocated_size = NULL;
	free(allocated_size);
	return allocated_size;	
}


void main( )
{
 FILE *fp ;
 char buffer[5] = "NULL";
 struct name *name1;
 char s[100];

 printf("Enter First and Last name of a person\n");

// To take the First name Last name as input from console
 fp = fopen("names.c","a+");
 while(strlen(gets(s)) > 0)
 {
        fputs(s,fp);
        fputs("\n",fp);
 }
 fclose(fp);

 name1 = (struct name*) malloc (sizeof(struct name));

 int *a =  allocate(sizeof(struct name));

 fp = fopen ( "names.c", "a+" ) ;

 	if ( fp == NULL )
 	{
	 puts ( "Cannot open file" ) ;
	 exit(0);
 	}
//Loop to read from the file names.c and print the First, Last name and store Jedi name in the structure	 
 while(fscanf (fp, "%s %s", &(name1)->fname, &(name1)->lname) != EOF )
 	{ 
	 printf("First Name : %s\t Last Name : %s\n", (name1)->fname, (name1)->lname ) ;	
	 memcpy((name1)->jedi_name, jedi((name1)->fname, (name1)->lname, buffer),sizeof(*jedi));
	}


 fclose (fp) ;

deallocate(a, sizeof(struct name));	//Memory allocated to struct is freed
}


