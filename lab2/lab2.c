/*	Lab2
	NAME : Abhijit Bhandarkar
	B00659257
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

// A function to convert Decimal number into it's equivalent Binary format
void decimal_To_Binary(int num1)
{
	unsigned int mask_value = 2147483648;	//2147483648 = 1000 0000 0000 0000 0000 0000 0000 0000, for 32 bit value
	
	printf("Binary value of %d is : ",num1);
	while(mask_value != 0)
	{
	if ((num1 & mask_value) == 0)
		printf("%d",0);
	else 
		printf("%d",1);
	mask_value = (mask_value >> 1);		//Right shift operation
	}
	printf("\n");
}

int main()
{
	printf("\n-------- PART 1 : Using Loops and Bit Operations ---------\n\n");

	// Printing first 20 numbers of Fibonacci series

	int num = 20;		// num is a variable to decide total number of elements in the Fibonacci series
	int f0 = 0;		// First element of Fibonacci series
	int f1 = 1;		// Second element of Fibonacci series
	int next;		// To caclulate next number in the Fibonacci series
	int i;			// Counter variable to be used in for loop

	printf("First %d numbers of Fibonacci series starting from 0 are : \n", num);

	for(i = 0; i < num; i++)
	{
		if(i == 0)
			printf("%d\n",f0);
		else if (i == 1)
			printf("%d\n",f1);
		else
			{
			next = f0 + f1;
			f0 = f1;
			f1 = next;
			printf("%d\n",next);
			}
	}
	printf("-------------------------- PART 1 Complete -------------------------\n\n");


	printf("\n--------------------- PART 2 : BITS AND BYTES ----------------------\n\n");
	printf("----------------------- PART A : Binary Printer --------------------\n\n");

	//Using a function call for Decimal to Binary conversion

	decimal_To_Binary(2); 		//Function call for Decimal to Binary conversion
	printf("\n");

	decimal_To_Binary(255); 	//Function call for Decimal to Binary conversion
	printf("\n");

	decimal_To_Binary(32); 		//Function call for Decimal to Binary conversion
	printf("\n");

	decimal_To_Binary(-1); 		//Function call for Decimal to Binary conversion
	printf("\n");

	decimal_To_Binary(-255); 	//Function call for Decimal to Binary conversion
	printf("\n");


	printf("\n--------------- PART A : Binary Printer Complete -------------------\n\n");


	printf("\n------------- PART B :Printing a Random Binary Value ---------------\n\n");

	srand(time(NULL));		//To generate random number everytime when rand() is executed
	int rand_num = (rand() % INT_MAX) + (rand() % INT_MIN);	
	printf("The random number is : %d\n", rand_num);
	decimal_To_Binary(rand_num); 	//Function call for Decimal to Binary conversion
	
	printf("\n---------- PART B :Printing a Random Binary Value Complete ----------\n\n\n");

return 0;
}
