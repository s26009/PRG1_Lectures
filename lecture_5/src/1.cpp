#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>

void print_hello(int count) {
	std::cout << "Hello, " << count << "\n";
}

auto main(int argc, char* argv[]) -> int {
	
	print_hello(5);

    return 0;
}
