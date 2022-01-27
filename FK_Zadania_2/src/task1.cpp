#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

int average_of(std::vector<int> v) {
    if(v.empty()){
        return 0;
    }

    return std::accumulate(v.begin(), v.end(), 0) / v.size();
}

bool is_palindrome(std::string s) {
    std::string p = s;
    std::reverse(p.begin(), p.end());
 
    if (s == p) {
        return true;
	}
	return false;
}

std::vector<std::string> filter_palindromes(std::vector<std::string> v) {
	for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
		if(!is_palindrome(*it)) {
			it = v.erase(it);    
		}
	}
	return v;
}

int main() {
    std::vector<int> vint{8, 4, 2, 7, 9};
    int a = average_of(vint);
    std::cout << "average: " << a << "\n";

    std::vector<std::string> vstr{"aba", "gleb", "abdba"};
    std::vector<std::string> vstr_filtered = filter_palindromes(vstr);
	for (std::string str : vstr_filtered) {
		std::cout << str << ", ";
	}
	std::cout << "\n";

    return 0;
}
