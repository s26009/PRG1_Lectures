#include <string>

class Person {
	public:
    std::string name;
    std::string surname;

	virtual std::string to_string() = 0;
	Person(std::string name_val, std::string surname_val) 
		: name(name_val), surname(surname_val) {};
};

