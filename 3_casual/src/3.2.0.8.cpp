#include <iostream>
#include <stdlib.h>
#include <string>

void *memrand(void *s, size_t n) {
	auto proxy = reinterpret_cast<char*>(s);
	for(auto i = size_t{0}; i < n; i++) {
		proxy[i] = rand() % 200;
	}
	return s;
}

int main(int argc, char *argv[]) {
	char src[] = "Hello";
	time_t t;
	srand((unsigned) time(&t));

	printf("dest before memrand(): %s\n", src);
	memrand(src, 5);
	printf("dest after memrand(): %s\n", src);
	
	return 0;  
}
