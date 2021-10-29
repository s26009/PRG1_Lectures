#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>
#include <cstring>
#include <string>
#include <mutex>
#include <queue>

std::mutex m;

void fillQueue(std::queue<std::string>& queue) {
	int count = 50;
	while(count --> 0)
		queue.push("Element #" + std::to_string(count));
}

void print(int id, std::queue<std::string>& queue) {
		m.lock();
		std::cout << queue.front()  << " poped by thread #" << id << "\n";
		queue.pop();
		m.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void showAllElements(int id, std::queue<std::string>& queue) {
	while(!queue.empty()) {
		print(id, queue);
	}
}

auto main(int argc, char* argv[]) -> int {
	std::queue<std::string> commonQueue;
    fillQueue(commonQueue);
	std::thread t1(showAllElements, 1, std::ref(commonQueue));
    std::thread t2(showAllElements, 2, std::ref(commonQueue));
    std::thread t3(showAllElements, 3, std::ref(commonQueue));
    std::thread t4(showAllElements, 4, std::ref(commonQueue));
	t2.join();
	t1.join();	
	t3.join();
	t4.join();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Finished.\n";
    return 0;
}
