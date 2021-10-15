#include <iostream>
#include <string>
#include <sstream>
#include "include/s1234/Time.h"

Time::Time(int hour_value, 
	int minute_value, int second_value) :
	hour(hour_value), minute(minute_value), second(second_value) {
		refactor();
	}

std::ostream& operator << (std::ostream &os, const Time &s) {
    return (os << s.hour 
			<< ":" << s.minute 
			<< ":" << s.second  << "\n");
}

std::string Time::to_string() {
    std::stringstream ss;
    ss << (*this);
    return ss.str();
}

void Time::refactor() {
	if(this->hour > 23) { 
		hour -= 24;
		refactor();
	}
	if(this->minute > 59) {
		minute -= 60;
		hour++;
		refactor();
	}
	if(this->second > 59) {
		second -= 60;
		minute++;
		refactor();
	}
}

void Time::next_hour() {
	this->hour++;
	refactor();
}

void Time::next_minute() {
	this->minute++;
	refactor();
}

void Time::next_second() {
	this->second++;
	refactor();
}

int main() {
    Time* time = new Time(19, 234, 359);
	std::cout << time->to_string();

	time->next_hour();
	std::cout << "next_hour()\n" << time->to_string();
	time->next_minute();
	std::cout << "next_minute()\n" << time->to_string();
	time->next_second();
	std::cout << "next_second()\n" << time->to_string();
    return 0;
}

