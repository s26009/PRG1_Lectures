#include <iostream>
#include <string>

int compare(int first, int second) {
	if (first < second) {
		return -1;
	} else if (first > second) {
		return 1;
	} 
	return 0;
}

int main(int argc, char *argv[]) {
	const int NUMBER_TO_GUESS = rand() % 100 + 1;
	int entered_number = 0;
	do {
		std::cout << "guess: ";
		std::cin >> entered_number;
		switch(compare(entered_number, NUMBER_TO_GUESS)) {
			case 1:
				std::cout << "Too much.\n";
				break;
			case 0:
				std::cout << "Well done! It's " << NUMBER_TO_GUESS << "\n";
				break;
			case -1:
				std::cout << "Too small\n";
				break;
			default:
				std::cout << "Error while comparing.\n";
		}
	} while (entered_number != NUMBER_TO_GUESS);
	return 0;
}
