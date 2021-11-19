#include <iostream>
#include <string>

void swap(int* ptr1, int* ptr2) {
	int buffer = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = buffer;
}

int main(int argc, char *argv[]) {
	
	int a = int {42};
	int b = int {64};
	std::cout << a << " " << b << "\n";
	swap(&a, &b);
	std::cout << a << " " << b << "\n";

	return 0;
}
