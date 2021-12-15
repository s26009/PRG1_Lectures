#include <iostream>

bool is_palindrome(std::string str) {
	std::string reversed = "";
	for(int n = str.length()-1; n >= 0; n--){
		reversed.push_back(str[n]);
	}
	return reversed == str;
}


int main() {
	std::cout << "ABA " << (is_palindrome("ABA") ? "is" : "is not") << " a palindrome!\n";
	std::cout << "ABC " << (is_palindrome("ABC") ? "is" : "is not") << " a palindrome!\n";
    return 0;
}
