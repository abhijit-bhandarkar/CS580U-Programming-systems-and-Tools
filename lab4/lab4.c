/*
   LAB4
   NAME: Abhijit Bhandarkar
   B00659257	
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define INPUT 5			// Number of input strings for MyStrStr() 
#define NUM_TEAMS 8		// Total number of teams in the tournament
#define NUM 100			// Used in game() function to calculate score randomly
#define  HANDICAP 20		// Weight of 20 is assigned to *team_two;
#include "MyFile.h"


//Function to find if a Substring(needle) is present in the main string (haystack) or not

int myStrStr(char *haystack, char *needle, char *buffer)
{

int length1 = strlen(haystack);		//Length of the main string (haystack)
int length2 = strlen(needle);		//Length of the sub-string (needle)
int i, j, temp;
	 
	for(i=0; i < length1; i++)
	 {	
	 	temp = i;
		for(j=0; j < length2; j++)
		{
			if(haystack[temp] == needle[j])
			{	
				buffer[j] = haystack[temp]; 	//Element of haystack is stored in buffer
				if( j == length2-1) 
					return 1;		//Substring matched 
				temp++;
				
			}
			else
				break;
		}
 	}
 	return 0;						//Substring not matched
}


// Function to generate winner among the two teams 

Team * game( Team *team_one, Team *team_two)
{
	Team * winner;
	int score_for_team_one = 0, score_for_team_two = 0;

	score_for_team_one = (rand() % NUM);				// Score of team_one is calculated randomly
	printf("Score of %s is %d\n",team_one->name, score_for_team_one);

	score_for_team_two = (rand() % NUM);				// Score of team_two is calculated randomly
	printf("Score of %s is %d\n",team_two->name, score_for_team_two);

	score_for_team_two +=  HANDICAP; 				// team_two is given handiccap advantage
	printf("Score of %s after handicap advantage is %d\n", team_two->name, score_for_team_two);


	if(score_for_team_one >= score_for_team_two)
   	{
		winner = team_one->name;
		printf("Winner is %s\n\n",winner);
		return team_one->name;
	}
	else
 	{
		winner = team_two->name; 
		printf("Winner is %s\n\n",winner);
		return team_two->name;
	}
}

//Function to arrange matches of the Tournament
Team * tournament(Team ** all_teams)
{
	Team **teams = all_teams;
 	Team *round2[4];			//To store the winners of Round 1
 	Team *round3[2];			//To store the winners of Round 2
 	Team *final_winner[0];			//To store the winner of Round3

 	printf("----------------------- Round 1 --------------------\n");

 	round2[0] = game(all_teams[0], all_teams[1]);
 	round2[1] = game(all_teams[2], all_teams[3]);
 	round2[2] = game(all_teams[4], all_teams[5]);
 	round2[3] = game(all_teams[6], all_teams[7]);

 	printf("\nTeams qualified for the Round 2 are : %s \t %s \t %s \t %s\n",round2[0], round2[1], round2[2], round2[3]);

 	printf("\n----------------------- Round 2 --------------------\n");

 	round3[0] = game(round2[0], round2[1]);
 	round3[1] = game(round2[2], round2[3]);

 	printf("\nTeams qualified for the Round 3 are : %s \t %s\n",round3[0], round3[1]);

 	printf("\n----------------------- Round 3 --------------------\n");
 	final_winner[0] = game(round3[0],round3[1]);

return final_winner[0];
}


int main()
{
	printf("-------------------------- Part 1 : String and Arrays ------------------------------\n\n");
 
	char haystack[][20] = {"apple","orange","blueberry","strawberry","grapefruit"};
 	char needle[][20] = {"app","ge","ueber","strawberry","terrible"};
 	char buffer[20][20] ={};

	for (count = 0; count < INPUT; count++)
	{ 
		result = (myStrStr(haystack[count], needle[count], buffer[count]));
		if(result == 1)
			printf("Main string :%s	Substring :%s.	Result : %d. Substring %s matched in the Main string\n",haystack[count],needle[count],result,buffer[count]);
		else
			printf("Main string :%s	Substring :%s.	Result : %d. Substring not matched \n",haystack[count],needle[count],result);
	}
	printf("\n\n");


	printf("-------------------------- PART 2 : Tournament ---------------------------\n\n");

	Team *league[8] = {"Mumbai","Delhi","Kolkata","Banglore","Hyderabad","Pune","Chennai","Nagpur"};
	Team *tournament_winner[0];			//To store the winner of the tournament

	printf("Team Participating in the tournament : \n");
	for(team_count = 0; team_count < NUM_TEAMS; team_count++)
	{
		printf("Team %d :  %s\n", team_count+1, league[team_count]);
	}

	printf("\n\n");

	srand(time(NULL));

	tournament_winner[0] = tournament(league);

	printf("\nThe winner of the tournament is :%s\n\n",tournament_winner[0]);

return 0;
}

