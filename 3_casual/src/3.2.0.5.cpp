#include <iostream>
#include <string>

void *memcpy(void *dest, void *src, size_t n) {
	auto proxy = reinterpret_cast<char*>(dest);
	auto source = reinterpret_cast<char*>(src);
	for(auto i = size_t{0}; i < n; i++) {
		proxy[i] = source[i];
	}
	return dest;
}

int main(int argc, char *argv[]) {
	char src[] = "Hello";  
	char dest[] = "00000000000000";  

	printf("dest before memcpy(): %s\n", dest);
	memcpy(dest, src, 6);
	printf("dest after memcpy(): %s\n", dest);
	
	return 0;  
}
