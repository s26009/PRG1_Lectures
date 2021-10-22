#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>

void print_hello(int count) {
	std::cout << "Hello, " << count << "\n";
}

auto main(int argc, char* argv[]) -> int
{
	int count = 42;
	
	while(count --> 0){
		std::thread thread1(print_hello, count);
		thread1.detach();
	}
	
	std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}
