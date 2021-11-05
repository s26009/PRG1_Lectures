#include <iostream>
#include <string>
#include <cmath>

int getInteger() {
	auto n = std::string {};
	std::getline(std::cin, n);
	return std::stoi(n);
}

int main(int argc, char *argv[]) {

	std::cout << "Enter number: ";
	auto number = getInteger();

	int factorial;
	if (number >= 0) {
		factorial = 1;
		for(int i = 1; i <= number; ++i) {
			factorial *= i;
		}
	}
	std::cout << number << "! = " << factorial << "\n";
	return 0;
}
