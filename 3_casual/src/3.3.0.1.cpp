#include <iostream>
#include <stdlib.h>
#include <string>
#include<time.h>
#include <stdio.h>

void call_with_random_int(void (*fp)(int const)) {
	(*fp)(rand());
}

void print_int(int num) {
	std::cout << num << std::endl;
}

int main(int argc, char *argv[]) {
	srand(time(0));
	auto fp = &print_int;
	call_with_random_int(fp);
	return 0;  
}
