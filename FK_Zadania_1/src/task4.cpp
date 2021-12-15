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
	
	std::string names[5];
	int female_names_count = 0;

	std::cout << "Enter 5 names.\n\n";
	std::cout << "Name 1: ";
	std::cin >> names[0];
	std::cout << "Name 2: ";
	std::cin >> names[1];
	std::cout << "Name 3: ";
	std::cin >> names[2];
	std::cout << "Name 4: ";
	std::cin >> names[3];
	std::cout << "Name 5: ";
	std::cin >> names[4];

	for(int i = 0; i < 5; i++) {
		if(names[i].back() == 'a') {
			female_names_count++;
		}
	}
	
	std::cout << "\n" << female_names_count << " of these names are female ones.\n";

    return 0;
}
