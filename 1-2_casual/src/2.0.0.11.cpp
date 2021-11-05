#include <iostream>
#include <string>
#include <cmath>

int getInteger() {
	auto n = std::string {};
	std::getline(std::cin, n);
	return std::stoi(n);
}

int main(int argc, char *argv[]) {

	std::cout << "Enter hight: ";
	auto hight = getInteger();

	std::cout << "\nEnter width: ";
	auto width = getInteger();

	for(auto i = 0; i < higth; i++) {
		for(auto j = 0; j < width; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	return 0;
}
