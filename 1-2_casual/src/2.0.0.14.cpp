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

	for(auto i = 0; i < hight; i++) {
		for(auto j = 0; j < hight; j++) {
			if(i != 0 && i != hight - 1) {
				if(j == 0 || j == hight - 1)  {
					std::cout << "*";
				} else {
					std::cout << " ";
				}		
			} else {
				std::cout << "*";
			}
		}
		std::cout << "\n";
	}
	return 0;
}
