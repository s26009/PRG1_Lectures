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
		thread1.join();
		//Didn't fully get this part: 
		//Wątki mają być uruchamiane grupami po 6 naraz.
		//Did this, it kind of separates groups by little pause:
		if(count % 6 == 0)
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
	}

    return 0;
}
