#include <iostream>
#include <string>

void *memset(void *s, int c, size_t n) {
	auto proxy = reinterpret_cast<char*>(s);
	for(auto i = size_t{0}; i < n; i++) {
		proxy[i] = c; //overwrites n-th byte
	}
	return s;
}

int main(int argc, char *argv[]) {
	char str[50] = "Hleb Skachko";
    printf("Before memset(): %s\n", str);
  
    // Fill 8 characters starting from str[13] with '.'
    memset(str, '~', size_t{5});
  
    printf("After memset():  %s\n", str);
    return 0;
}
