#include <iostream>
#include <string>


void print_fizzbuzz (int number) {
	if(number % 3 == 0 && number % 5 == 0) {
		std :: cout << number << " FizzBuzz\n";
	} else if (number % 3 == 0) {
		std :: cout << number << " Fizz\n";
	} else if (number % 5 == 0) {
		std :: cout << number << " Buzz\n";
	}
}

int main(int argc, char *argv[]) {
    if(argv[1] == NULL) {
        std :: cout << "pass the number as an argument: \"s03-fizzbuzz 20\"\n";
        return 0;
    }
	const int FIZZBUZZ_NUMBER = std::__cxx11::stoi(argv[1]);
	
	for(int i = 1; i <= FIZZBUZZ_NUMBER; i++) {
		print_fizzbuzz(i);
	}

	return 0;
}
