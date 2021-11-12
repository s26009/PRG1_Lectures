#include <iostream>
#include <string>
#include <cmath>

int getInteger() {
	auto n = std::string {};
	std::getline(std::cin, n);
	return std::stoi(n);
}

void init(int*& a, int n) {
	a = new int[n];
	for (int i = 0; i < n; i++) {
    	a[i] = 0;
	}
}

void printArray(int a[], int n) {
	std::cout << "a[" << n << "] = { ";
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}	
	std::cout << "}\n";
}


void iota(int*& a, int n, int start) {
	a = new int[n];
	for (int i = 0; i < n; i++) {
    	a[i] = start++;
	}
} 

int main(int argc, char *argv[]) {
	int *a;

	std::cout << "Array capacity: ";
	int capacity = getInteger();

	std::cout << "Start: ";
	int start = getInteger();

	iota(a, capacity, start);
	printArray(a, capacity);

	return 0;
}
