#include <iostream>
#include <string>
#include <cmath>

int getInteger() {
	auto n = std::string {};
	std::getline(std::cin, n);
	return std::stoi(n);
}

int main(int argc, char *argv[]) {

	std::cout << "Enter a number: ";
	auto number = getInteger();
	std::cout << "\n0";
	int sum = 0;
	for (int n = 2; n <= number; n++) {
		bool isPrime = true;
		double squareRoot = sqrt(n) + 2;
		int r = 2;
		while (r <= squareRoot && isPrime) {
		    if (n % r == 0) isPrime = false;
		    r++;
		}
		if(isPrime) {
			sum += n;
			std::cout << " + " << n;
		}
	}
	std::cout << " = " << sum << "\n";
	return 0;
}
