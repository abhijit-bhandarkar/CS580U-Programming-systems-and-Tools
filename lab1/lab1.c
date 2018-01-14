/*
 	Lab1
	NAME: Abhijit G Bhandarkar
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

	printf("\n------------------ Part 1 : Print 'Hello World!' ----------------------\n\n");

//Hello World! Program

	printf("Hello World!\n\n");	//Printing output as "Hello World!"

	printf("--------------------------- Part 1 Complete ---------------------------\n\n\n");


	printf("**************** Part 2 : Using Variables and Arithmetic ****************\n\n");
	printf("-------------------- PART A : Expression Evaluation ---------------------\n\n");

//Logic to evaluate given expressions

	float x = 2.55;
	float answer1, answer2;

//The value of expression (3*x^3 - 5*x^2 + 6) is stored in the variable 'answer1'

	answer1 = 3 * pow(x, 3) - 5 * pow(x, 2)	 + 6;
	printf("The value of (3*x^3 - 5*x^2 + 6) is %f \n\n", answer1);

//The value of expression (3.31 * 10^-8 * 2.01 * 10^-7) / (7.16 * 10^-6 + 2.01 * 10^-8) is stored in the variable 'answer2'

	answer2 = (3.31 * pow(10,-8) * 2.01 * pow(10,-7)) / ( 7.16 * pow(10,-6) + 2.01 * pow(10,-8)); 
	printf("The value of (3.31 * 10^-8 * 2.01 * 10^-7) / (7.16 * 10^-6 + 2.01 * 10^-8) is %5.20f \n\n\n", answer2);


	printf("-------  PART B : Rounding of of an integer to next largest even multiple of another integer -------\n\n");


//To round off an integer i to the next largest even multiple of another integer j, the formula is: next_multiple = i + j - i % j

	int next_multiple1, next_multiple2, next_multiple3;	


//The round off value of 365 to the next largest even multiple of 7 is stored in 'next_multiple1'

	next_multiple1 = 365 + 7 - 365 % 7 ;
	printf("The round off value of 365 to the next largest even multiple of 7 is : %d \n\n", next_multiple1);


//The round off value of 12258 to the next largest even multiple of 28 is stored in 'next_multiple2'

	next_multiple2 = 12258 + 28 - 12258 % 28 ;
	printf("The round off value of 12258 to the next largest even multiple of 28 is : %d \n\n", next_multiple2);


//The round off value of 996 to the next largest even multiple of 4 is stored in 'next_multiple3'

	next_multiple3 = 996 + 4 - 996 % 4 ;
	printf("The round off value of 996 to the next largest even multiple of 4 is : %d \n\n", next_multiple3);



/* 
Below is the logic for Rounding Off part of the assignment using FUNCTION call.  
Earlier I had implemnted it using functions.
But as discussed with professor, since the functions are to be covered in the lectures, I have commented the below code and used hardcoded values.

	int round_Of_Value(int i, int j)
	{
		int next_multiple;
		next_multiple = (i + j - i % j);
		return next_multiple;
	}

//for i = 365 and  j = 7;
	next_multiple1 = round_Of_Value(365, 7);
	printf("The round off value of 365 to the next largest even multiple of 7 is : %d \n\n",next_multiple1);

//for i = 12258 and j = 28;
	next_multiple2 = round_Of_Value(12258,28);
	printf("The round off value of 12258 to the next largest even multiple of 28 is : %d \n\n",next_multiple2);

//for i = 996 and j = 4;
	next_multiple3 = round_Of_Value(996,4);
	printf("The round off value of 996 to the next largest even multiple of 4 is : %d \n\n",next_multiple3);
*/


	printf("------------------------- PART C :Type Casting -------------------------\n\n");

// Type casting of value of ( 365 + 7 - 365 % 7 )to int, float and char

// Type casting of value of ( 365 + 7 - 365 % 7 )to int

	int next_multiple1_int;
	next_multiple1_int = (int)next_multiple1;
	printf("Type casted value of (365 + 7 - 365 % 7) to int is : %d\n", next_multiple1_int);

// Type casting of value of ( 365 + 7 - 365 % 7 )to float

	float next_multiple1_float;
	next_multiple1_float = (float)next_multiple1;
	printf("Type casted value of (365 + 7 - 365 % 7) to float is : %5.5f\n", next_multiple1_float);

// Type casting of value of ( 365 + 7 - 365 % 7 )to char

	char next_multiple1_char;
	next_multiple1_char = (char)next_multiple1;
	printf("Type casted value of (365 + 7 - 365 % 7) to char is : %c\n\n", next_multiple1_char);



// Type casting of value of (12258 + 28 - 12258 % 28)to int, float and char

// Type casting of value of (12258 + 28 - 12258 % 28)to int

	int next_multiple2_int;
	next_multiple2_int = (int)next_multiple2;
	printf("Type casted value of (12258 + 28 - 12258 % 28) to int is : %d\n", next_multiple2_int);

// Type casting of value of (12258 + 28 - 12258 % 28)to float

	float next_multiple2_float;
	next_multiple2_float = (float)next_multiple2;
	printf("Type casted value of (12258 + 28 - 12258 % 28) to float is : %5.5f\n", next_multiple2_float);

// Type casting of value of (12258 + 28 - 12258 % 28)to char

	char next_multiple2_char;
	next_multiple2_char = (char)next_multiple2;
	printf("Type casted value of (12258 + 28 - 12258 % 28) to char is : %c\n\n", next_multiple2_char);


// Type casting of value of (996 + 4 - 996 % 4)to int, float and char

// Type casting of value of (996 + 4 - 996 % 4)to int

	int next_multiple3_int;
	next_multiple3_int = (int)next_multiple3;
	printf("Type casted value of (996 + 4 - 996 % 4) to int is : %d\n", next_multiple3_int);

// Type casting of value of (996 + 4 - 996 % 4)to float

	float next_multiple3_float;
	next_multiple3_float = (float)next_multiple3;
	printf("Type casted value of (996 + 4 - 996 % 4) to float is : %5.5f\n", next_multiple3_float);

// Type casting of value of (996 + 4 - 996 % 4)to char

	char next_multiple3_char;
	next_multiple3_char = (char)next_multiple3;
	printf("Type casted value of (996 + 4 - 996 % 4) to char is : %c\n\n", next_multiple3_char);


return 0;
}

