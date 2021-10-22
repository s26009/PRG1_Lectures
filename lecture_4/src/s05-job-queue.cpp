#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>
#include <cstring>
#include <string>
#include "include/safe_queue.h"

void print(int id, SafeQueue<std::string>& itemQueue) {
	//std::cout << itemQueue.empty() << " ";
	while(!itemQueue.empty()) {
		std::cout << "from thread " << id <<  " : " << itemQueue.dequeue() << "\n";
		//I'm not sure why, but without this sleep program stucks:		
		std::this_thread::sleep_for(std::chrono::milliseconds(20));	
	}
}

void fillQueue(SafeQueue<std::string>& queue) {
	int count = 50;
	while(count --> 0)
		queue.enqueue("Element #" + std::to_string(count));
}

auto main(int argc, char* argv[]) -> int
{
	SafeQueue<std::string> itemQueue;
    fillQueue(itemQueue);
    std::thread t1(print, 1, std::ref(itemQueue));
    std::thread t2(print, 2, std::ref(itemQueue));
    std::thread t3(print, 3, std::ref(itemQueue));
    std::thread t4(print, 4, std::ref(itemQueue));
	t1.detach();
	t2.detach();	
	t3.detach();
	t4.detach();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Finished.\n";
    return 0;
}
