#include <iostream>

int count_chars(std::string str, char c) { 
	int result = 0;
 
	for (unsigned i = 0; i < str.length(); ++i) {
		if(str.at(i) == c) result++;
	}
	

	return result; 
}

int main() {
	std::cout << count_chars("Test string", 't') << '\n';
    return 0;
}
