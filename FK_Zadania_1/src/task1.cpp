#include <iostream>
#include <string>

bool is_prime_number(int n) {
	if(n == 0 || n == 1) {
		return false;
	} else {
		for(int i = 2; i <= n/2; ++i) {
			if(n%i == 0) {
				return false;
			}
		}
	}
	return true;
}

void print_prime_numbers(int limit, bool print_at_once) {
	std::string result = "";
	for(int i = 0; i < limit; i++) {
		if(is_prime_number(i)) {
			if(print_at_once) {
				result.append(std::to_string(i).append(" "));
			} else {
				std::cout << i << " ";
			}
		}
	}
	if(print_at_once) {
    	std::cout << result;
	}
	std::cout << '\n';
}

int main() {
	print_prime_numbers(20, true);
	print_prime_numbers(20, false);
    return 0;
}
