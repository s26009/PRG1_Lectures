#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>

check with needle the type

ssize_t fpsearch(void* a, size_t n, bool (*fp)(void*, void*), void* needle) {
	int* int_array = (int*)(a);
	for (size_t i = 0; i < n; i++) {
		if((*fp)(&int_array[i]) == true) {
			return true;
		};
	}
	return false;
}

bool compareInts(void* _num1, void* _num2) {
	int num1 = *(int*)_num1;
	int num2 = *(int*)_num2;
	if(num1 > num2) {
		return true;
	}
	return false;
}

//program checks if there is at least 1 positive number in 'a' array
//		returns 1 if yes
//		returns 0 if not
int main(int argc, char *argv[]) {
    int a[] = { -1, 2, -3 };
//  int a[] = { -1, -2, -3 };

	auto fp = &is_positive;
	std::cout << any(a, 3, fp) << "\n";
	return 0;  
}
