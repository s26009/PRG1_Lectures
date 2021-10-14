#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if(argv[1] == NULL) {
        std :: cout << "pass some number as an argument: \"s03-beer 13\"\n";
        return 0;
    }
	int beer_number = std::__cxx11::stoi(argv[1]);
	
	do {
		std::cout 
		<< beer_number << " bottles of beer on the wall, " 
		<< beer_number << " bottles of beer\nTake one down, pass it around, " 
		<< beer_number - 1 << " bottles of beer on the wall...\n";
	} while(beer_number-- > 1);

	std::cout << "No more bottles of beer on the wall, no more bottles of beer."
	<< "\nGo to the store and buy some more, " << std::__cxx11::stoi(argv[1]) <<
	" bottles of beer on the wall..\n";

	return 0;
}
