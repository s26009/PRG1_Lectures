#include <iostream>
#include <string>
#include <sstream>
#include "include/s1234/Student.h"

Student::Student(std::string name_value, std::string surname_value, int index_value, 
	int semester_value, int rate_value) : name(name_value), surname(surname_value),
	index(index_value), semester(semester_value), rate(rate_value) {}

std::ostream& operator << (std::ostream &os, const Student &s) {
    return (os << " Name: " << s.name 
			<< "\n Surname: " << s.surname 
			<< "\n Index: " << s.index 
			<< "\n Semester: " << s.semester 
			<< "\n Rate: " << s.rate  << "\n");
}

std::string Student::to_string() {
    std::stringstream ss;
    ss << (*this);
    return ss.str();
}

int main() {
    Student* student = new Student("Gleb", "Skachko", 1, 2, 3);
	std::cout << student->to_string();
    return 0;
}

