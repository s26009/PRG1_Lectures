#include <iostream>
#include <string>

std::string get_compare_message(std::string name1, std::string name2) {
	if(name1.length() > name2.length()) {
		return "First name is longer than second one!";
	}
	if(name1.length() < name2.length()) {
		return "Second name is longer...";
	}
	return "Names are the same size.";
}

int main() {
	
	std::string name1;
	std::string name2;
	
	std::cout << "Enter a name: ";
	std::cin >> name1;
	std::cout << "Enter another name: ";
	std::cin >> name2;

	std::cout << get_compare_message(name1, name2) << '\n';
	
    return 0;
}
