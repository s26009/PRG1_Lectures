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
	int iterator = 1;
	if (number >= 0) {
		factorial = 1;
		do {
			factorial *= iterator;
			++iterator;
		} while(iterator <= number);
	}
	std::cout << number << "! = " << factorial << "\n";
	return 0;
}
