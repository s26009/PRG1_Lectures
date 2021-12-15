#include <iostream>

void print_word(std::string str, size_t length) {
	std::string line = "* " + str;
	size_t difference = length - line.length();
	std::cout << line;
	for(size_t i = 0; i < difference - 1; i++) {
		std::cout << ' ';
	}
	std::cout << "*\n";
}

size_t max_length(size_t size1, size_t size2, size_t size3, size_t size4, size_t size5) {
	size_t max = 0;
	if(size1 > max) max = size1;
	if(size2 > max) max = size2;
	if(size3 > max) max = size3;
	if(size4 > max) max = size4;
	if(size5 > max) max = size5;

	return max;
}

void print_starline(size_t length) {	
	for(size_t i = 0; i < length; i++) {
		std::cout << '*';
	}
	std::cout << '\n';
}

void box_print(std::string str1, std::string str2, std::string str3,
	std::string str4, std::string str5) {
	
	size_t width = max_length(str1.length(), str2.length(), str3.length(),
		str4.length(), str5.length()) + 4;
	
	std::cout << "Width: " << width << '\n';

	print_starline(width);
	print_word(str1, width);
	print_word(str2, width);
	print_word(str3, width);
	print_word(str4, width);
	print_word(str5, width);
	print_starline(width);
}


int main() {
	box_print("Hello", "darkness", "my", "old", "friend");
	return 0;
}
