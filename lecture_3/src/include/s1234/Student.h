#include <string>

struct Student {
    std::string name;
    std::string surname;
    int index;
    int semester;
    int rate;

	std::string to_string();
	Student(std::string name, std::string surname, 
		int index, int semester, int rate);
};

