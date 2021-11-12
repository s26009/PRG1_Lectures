#include <iostream>
#include <string>
#include <cmath>

int getInteger() {
	auto n = std::string {};
	std::getline(std::cin, n);
	return std::stoi(n);
}

void initHard(int*& a) {
	a = new int[10] { 42 , 9 , -1 , 18 , 59 , 3 , 101 , 31 , 72 , 12 };
}

void printArray(int a[], int n) {
	std::cout << "a[" << n << "] = { ";
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}	
	std::cout << "}\n";
}

int amax(int*& a, int n) {
	int max = 0;	
	for (int i = 0; i < n; i++) {
		if(a[i] >= max) max = a[i];
	}	
	return max;
}

int main(int argc, char *argv[]) {
	int *a;
	int capacity = 10;

	initHard(a);
	printArray(a, capacity);
	std::cout << "Max = " << amax(a, capacity) << "\n";

	return 0;
}
