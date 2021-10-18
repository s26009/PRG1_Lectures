#include <string>

enum class Time_of_day { MORNING, DAY, EVENING, NIGHT };

struct Time {
    int hour;
    int minute;
    int second;
	long seconds; 

	std::string to_string();
	std::string to_string(Time_of_day tod);
	Time_of_day time_of_day();
	void next_hour();
	void next_minute();
	void next_second();
	void refactor();
	Time(int index, int semester, int rate);
	Time(long seconds);
	Time(){};

	Time operator+ (Time);
	Time operator- (Time);
	bool operator< (Time);
	bool operator> (Time);
	bool operator== (Time);
	bool operator!= (Time);
};
