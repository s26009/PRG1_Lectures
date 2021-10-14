#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	if(argv[1] == NULL) {
		std :: cout << "pass a number as an argument: \"s03-countdown 5\"\n";
		return 0;
	}
	const int COUNTDOWN_NUMBER = std::__cxx11::stoi(argv[1]);

	for(int i = COUNTDOWN_NUMBER; i > -1; i--) {
		std :: cout << i << "...\n";
	}

	return 0;
}
