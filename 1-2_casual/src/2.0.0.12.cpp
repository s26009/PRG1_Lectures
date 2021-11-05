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
	auto width = hight;
	for(auto i = 0; i < hight; i++) {
		for(auto j = 0; j < width; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
		width--;
	}
	return 0;
}
