int numSeconds(int hours, int minutes, int seconds);

struct Time calDifference(int time_Value2, int time_Value1);

struct Time{
                int hours;
                int minutes;
                int seconds;
        };


enum Month {January = 0, February, March, April, May, June, July, August, September, October, November, December};

struct DateTime{
		enum Month month_Name;
		int day;
		int year;
		struct Time NewTime;
		};

