#include <iostream>
#include <string>

void *memfrob(void *s, size_t n) {
	auto proxy = reinterpret_cast<char*>(s);
	for(auto i = size_t{0}; i < n; i++) {
		proxy[i] = (proxy[i] ^ 42);
	}
	return s;
}

int main(int argc, char *argv[]) {
	char src[] = "Hello";

	printf("dest before memfrob(): %s\n", src);
	memfrob(src, 5);
	printf("dest after memfrob(): %s\n", src);
	memfrob(src, 5);
	printf("dest after 2nd memfrob(): %s\n", src);
	
	return 0;  
}
