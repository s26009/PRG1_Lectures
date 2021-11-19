#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	
	std::string helloWorld = "Hello, World!";
	std::string* helloWorldPointer = &helloWorld;

	std::cout << "Pointer: " << helloWorldPointer << "\n";

	return 0;
}
