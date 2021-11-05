#include <iostream>
#include <string>
#include <cmath>

int getInteger() {
	auto n = std::string {};
	std::getline(std::cin, n);
	return std::stoi(n);
}

int main(int argc, char *argv[]) {

	std::cout << "Enter limit: ";
	auto limit = getInteger();
	std::cout << "\nEnter divider: ";
	auto divider = getInteger();
	std::cout << "\n";

	for (int n = 0; n <= limit; n++) {
		if(n % divider == 0) std::cout << n << " ";
	}

	std::cout << "\n";
	return 0;
}
