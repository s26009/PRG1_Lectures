#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>

void fpprint(void* a, size_t n, void (*fp)(void*, size_t)) {
	(*fp)(a, n);
}

void print_int(void* a, size_t n) {
	int* int_array = (int*)(a);
	for (size_t i = 0; i < n; i++) {
		std::cout << *(int*)(&int_array[i]) << " ";
	}
	std::cout << "\n";
}

void print_str(void* a, size_t n) {
	std::string* str_array = (std::string*)(a);
	for (size_t i = 0; i < n; i++) {
		std::cout << *(std::string*)(&str_array[i]);
	}
	std::cout << "\n";
}

//program print all elements of 'a' array
int main(int argc, char *argv[]) {
    int a[] = { -1, 2, -3 };
    std::string s[] = { "Hello", ",", " world!" };

	auto fpint = &print_int;
	fpprint(a, 3, fpint);

	auto fpstr = &print_str;
	fpprint(s, 3, fpstr);
	return 0;  
}
