#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>

bool all(void* a, size_t n, bool (*fp)(void*)) {
	int* int_array = (int*)(a);
	for (size_t i = 0; i < n; i++) {
		if((*fp)(&int_array[i]) == false) {
			return false;	
		};
	}	
	return true;
}

bool is_positive(void* _num) {
	int num = *(int*)_num;
	if(num < 0) {
		return false;
	}
	return true;
}

//program checks if all elements in 'a' array are positive
//		returns 1 if yes
//		returns 0 if not
int main(int argc, char *argv[]) {
    int a[] = { 1, 2, 3 };
//  int a[] = { 1, -2, 3 };

	auto fp = &is_positive;
	std::cout << all(a, 3, fp) << "\n";
	return 0;  
}
