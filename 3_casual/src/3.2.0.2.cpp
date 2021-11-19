#include <iostream>
#include <string>

void print(std::string* ptr) {
	std::cout << "Pointer: " << ptr << " Value: " << *ptr << "\n";	
}

int main(int argc, char *argv[]) {
	
	std::string helloWorld = "Hello, World!";
	std::string* helloWorldPointer = &helloWorld;

	print(helloWorldPointer);

	return 0;
}
