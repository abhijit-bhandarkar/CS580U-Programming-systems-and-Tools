//Uninitialized Global variables declared in the main()
int count, result, r2_count, team_count;

//Structure to store the team names
typedef struct Team_Name {
                char name[20];
                }Team;

//Function declarations
int myStrStr(char *haystack, char *needle, char *buffer);
Team * game( Team *team_one, Team *team_two);
Team * tournament(Team ** all_teams);


