#include <iostream>

void print_every(std::string str, int n) { 
	for (unsigned i = 0; i < str.length(); i+=n) {
		std::cout << str.at(i) << " ";
	}
	std::cout << '\n';
}

int main() {
	print_every("Test string", 3);
    return 0;
}
