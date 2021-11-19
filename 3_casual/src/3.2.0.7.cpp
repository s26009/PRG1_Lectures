#include <iostream>
#include <string>

void swap(char* ptr1, char* ptr2) {
	int buffer = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = buffer;
}

void *memrev(void *s, size_t n) {
	auto proxy = reinterpret_cast<char*>(s);
	for(auto i = size_t{0}; i < n/2; i++) {
		swap(&proxy[i], &proxy[n - i]);
	}
	return s;
}

int main(int argc, char *argv[]) {
	char src[] = "Hello";

	printf("dest before memrev(): %s\n", src);
	memrev(src, 4);
	printf("dest after memrev(): %s\n", src);
	
	return 0;  
}
