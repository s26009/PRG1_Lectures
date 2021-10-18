#include <iostream>
#include <string>
#include <sstream>
#include "include/s1234/Time.h"

Time::Time(int hour_value, 
	int minute_value, int second_value) {
		seconds = second_value + minute_value * 60 + hour_value * 3600;
		refactor();
	}

Time::Time(long seconds_value) : seconds(seconds_value) {
		refactor();
	}

std::ostream& operator << (std::ostream &os, const Time &s) {
    return (os << s.hour 
			<< ":" << s.minute 
			<< ":" << s.second);
}

std::string Time::to_string() {
    std::stringstream ss;
    ss << (*this);
    return ss.str();
}

std::string Time::to_string(Time_of_day tod) {
	switch(tod) {
		case Time_of_day::MORNING: return "Morning";
		case Time_of_day::DAY: return "Day";
		case Time_of_day::EVENING: return "Evening";
		case Time_of_day::NIGHT: return "Night";
		default: return "the end of the world";
	}
}

void Time::refactor() {
	if(seconds >= 86400) {
		seconds -= 86400;
	}
	if(seconds < 0) {
		seconds += 86400;
	}
	hour = seconds / 3600;
	minute = (seconds % 3600) / 60;
	second = (seconds % 3600) % 60;
}

void Time::next_hour() {
	seconds += 3600;
	refactor();
}

void Time::next_minute() {
	seconds += 60;
	refactor();
}

void Time::next_second() {
	seconds++;
	refactor();
}

Time Time::operator+(Time time2) {
	return Time(seconds + time2.seconds);
}

Time Time::operator-(Time time2) {
	return Time(seconds - time2.seconds);
}

bool Time::operator>(Time time2) {
	return seconds > time2.seconds;
}

bool Time::operator<(Time time2) {
	return seconds < time2.seconds;
}

bool Time::operator==(Time time2) {
	return seconds == time2.seconds;
}

bool Time::operator!=(Time time2) {
	return seconds != time2.seconds;
}

uint64_t Time::count_seconds() {
	return seconds;
}

uint64_t Time::count_minutes() {
	return seconds / 60;
}

Time Time::time_to_midnight() {
	return Time(86400 - seconds);
}

int main() {
    Time time1 = Time(19, 234, 359);
    Time time2 = Time(15, 50, 15);
	std::cout << time1.to_string();

	time1.next_hour();
	std::cout << "\nnext_hour()\n" << time1.to_string();
	time1.next_minute();
	std::cout << "\nnext_minute()\n" << time1.to_string();
	time1.next_second();
	std::cout << "\nnext_second()\n" << time1.to_string();
	std::cout << "\n" << time1.to_string(Time_of_day::MORNING) << "\n";

	Time time3 = time1 + time2;
	std::cout << time1.to_string() << " + " << time2.to_string() <<
	" = " << time3.to_string() << "\n";
	
	time3 = time1 - time2;
	std::cout << time1.to_string() << " - " << time2.to_string() <<
	" = " << time3.to_string() << "\n";

	std::cout << time1.to_string() << " < " << time2.to_string() <<
	" = " << (time1 < time2) << "\n";

	std::cout << time1.to_string() << " > " << time2.to_string() <<
	" = " << (time1 > time2) << "\n";

	std::cout << time1.to_string() << " == " << time2.to_string() <<
	" = " << (time1 == time2) << "\n";
		
	std::cout << time1.to_string() << " != " << time2.to_string() <<
	" = " << (time1 != time2) << "\n";

		
	std::cout << time2.to_string() << " -> count_seconds() = " 
		<< time2.count_seconds() << "\n";
		
	std::cout << time2.to_string() << " -> count_minutes() = " 
		<< time2.count_minutes() << "\n";
		
	std::cout << time2.to_string() << " -> time_to_midnight() = " 
		<< time2.time_to_midnight() << "\n";

	
	
    return 0;
}

