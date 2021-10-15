#include <string>

struct Time {
    int hour;
    int minute;
    int second;

	std::string to_string();
	void next_hour();
	void next_minute();
	void next_second();
	void refactor();
	Time(int index, int semester, int rate);
};

