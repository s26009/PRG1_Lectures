#include <iostream>

bool is_divisible(int n, int divider) { return n%divider == 0; }

bool is_even(int n) { return is_divisible(n, 2); }

int main() {
	std::cout << "6 " << (is_even(6) ? "is" : "is not") << " an even number!\n";
	std::cout << "7 " << (is_even(7) ? "is" : "is not") << " an even number!\n";
    return 0;
}
