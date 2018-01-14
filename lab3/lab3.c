/*
	LAB3
	NAME : Abhijit Bhandarkar
	B00659257
*/

#include<stdio.h>
#include"MyFile.h"		//Includes struct definitions and  Function declarations
#define SECONDS_IN_A_MINUTE 60 
#define MINUTES_IN_AN_HOUR 60
#define SECONDS_IN_ONE_HOUR 3600
#define TRACE printf("The line number is : %d\n",__LINE__)


int main()
{

// Structures values used for testing
struct Time time1 = {3,45,15};
struct Time time2 = {9,44,03};
struct Time time3 = {1,30,45};
struct Time time4 = {16,30,45};
struct Time time5 = {00,01,01};
struct Time time6 = {23,59,59};
struct Time time7 = {12,00,00};
struct Time time8 = {12,00,00};

//This char array stores value of months from January through December
char mon[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};	



	printf("------------------------ PART 1 ------------------------ \n\n");
	printf("-------------------- PART 1 Testing--------------------- \n\n");
	printf("Total seconds in 2 hr 10 min and 20 sec are: %d \n\n",numSeconds(2,10,20));
		
	printf("------------------- PART 2 : PART A  ------------------- \n\n");
	

	printf("Time 1 : %02d:%02d:%02d",3,45,15);
	printf(" and  Time 2 : %02d:%02d:%02d\n",9,44,03);
//Time calculation in seconds for time 1 and time2
	int time2_Seconds = numSeconds(time2.hours, time2.minutes, time2.seconds);
	int time1_Seconds = numSeconds(time1.hours, time1.minutes, time1.seconds);
//Calculation of time elapsed between time1 and time2
	struct Time time21 = calDifference(time2_Seconds,time1_Seconds);
	printf("The time elapsed between Time 1 and 2 is %d Hours %d Minutes and %d Seconds\n\n", time21.hours, time21.minutes, time21.seconds);



	printf("Time 3 : %02d:%02d:%02d",1,30,45);
	printf(" and Time 4 : %02d:%02d:%02d\n",16,30,45);
//Time calculation in seconds for time3 and time4
	int time4_Seconds = numSeconds(time4.hours, time4.minutes, time4.seconds);
	int time3_Seconds = numSeconds(time3.hours, time3.minutes, time3.seconds);
//Calculation of time elapsed between time3 and time4
	struct Time time43 = calDifference(time4_Seconds,time3_Seconds);
	printf("The time elapsed between time 3 and 4 is %d Hours %d Minutes and %d Seconds\n\n", time43.hours, time43.minutes, time43.seconds);



	printf("Time 5 : %02d:%02d:%02d",00,01,01);
	printf(" and Time 6 : %02d:%02d:%02d\n",23,59,59);
//Time calculation in seconds for time5 and time6
	int time6_Seconds = numSeconds(time6.hours, time6.minutes, time6.seconds);
	int time5_Seconds = numSeconds(time5.hours, time5.minutes, time5.seconds);
//Calculation of time elapsed between time5 and time6
	struct Time time65 = calDifference(time6_Seconds,time5_Seconds);
	printf("The time elapsed between time 5 and 6 is %d Hours %d Minutes and %d Seconds\n\n", time65.hours, time65.minutes, time65.seconds);



	printf("Time 7 : %02d:%02d:%02d",12,00,00);
	printf(" and Time 8 : %02d:%02d:%02d\n",12,00,00);
//Time calculation in seconds for time7 and time8
	int time8_Seconds = numSeconds(time8.hours, time8.minutes, time8.seconds);
	int time7_Seconds = numSeconds(time7.hours, time7.minutes, time7.seconds);
//Calculation of time elapsed between time7 and time8
	struct Time time87 = calDifference(time8_Seconds,time7_Seconds);
	printf("The time elapsed between time 7 and 8 is %d Hours %d Minutes and %d Seconds\n\n", time87.hours, time87.minutes, time87.seconds);



	printf("------------------- PART 2 : PART B  ------------------- \n\n");


	struct DateTime DateTime1= {.month_Name= January, .day=19, .year=1809,{12,01,00}};	
	printf("DateTime 1 : %s %02d %02d %02d:%02d:%02d\n", mon[DateTime1.month_Name], DateTime1.day, DateTime1.year, DateTime1.NewTime.hours, DateTime1.NewTime.minutes, DateTime1.NewTime.seconds);


	struct DateTime DateTime2= {.month_Name= November, .day=11, .year=1922,{06,00,00}};	
	printf("DateTime 2 : %s %02d %02d %02d:%02d:%02d\n",mon[DateTime2.month_Name],DateTime2.day, DateTime2.year, DateTime2.NewTime.hours, DateTime2.NewTime.minutes, DateTime2.NewTime.seconds);


	struct DateTime DateTime3= {.month_Name= January, .day=06, .year=2000,{8,22,00}};	
	printf("DateTime 3 : %s %02d %02d %02d:%02d:%02d\n",mon[DateTime3.month_Name], DateTime3.day, DateTime3.year, DateTime3.NewTime.hours, DateTime3.NewTime.minutes, DateTime3.NewTime.seconds);

	printf("\n\n");
	return 0;
}



// Function definition of numSeconds(), which converts the given time into Seconds
int numSeconds(int hours, int minutes, int seconds)
{
	printf("",TRACE);		//To print line number

	int total_Sec;
	int hours_Sec, minutes_Sec;
	hours_Sec = hours * MINUTES_IN_AN_HOUR * SECONDS_IN_A_MINUTE ;
 	minutes_Sec = minutes * SECONDS_IN_A_MINUTE ;

	total_Sec = hours_Sec + minutes_Sec + seconds ;	
	return total_Sec;

}


// Function definition of calDifference()which will calculate the difference between 2 times and return value in hr,min,sec format
struct Time calDifference(int time_Value2, int time_Value1)
	{	
	struct Time temp;
	int time_Difference = time_Value2 - time_Value1 ;

	int hr = time_Difference / (SECONDS_IN_ONE_HOUR);
	int min = (time_Difference - (hr * SECONDS_IN_ONE_HOUR)) / MINUTES_IN_AN_HOUR ;
	int sec = (time_Difference - (hr * SECONDS_IN_ONE_HOUR)- (min * MINUTES_IN_AN_HOUR) );

	temp.hours = hr, temp.minutes = min, temp.seconds = sec;  	//Time elapsed is stored in local structure temp
	return temp;
	}


