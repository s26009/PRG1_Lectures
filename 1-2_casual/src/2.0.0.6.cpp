/*
 * A reverse-polish notation calculator.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

int compare( int first, int second) {
	if (first < second) {
		return -1;
	} else if (first > second) {
		return 1;
	}
	return 0;
}

void printCompare(int a, int b) {
	switch(compare(a,b)) {
		case 1:
			std :: cout << a << " > " << b << "\n";
			break;
		case 0:
			std :: cout << a << " == " << b << "\n";
			break;
		case -1:
			std :: cout << a << " < " << b << "\n";
			break;
		default:
			std :: cout << "Error while comparison.\n";
	}
}

auto make_args(int argc, char* argv[]) -> std::vector<std::string>
{
    auto args = std::vector<std::string>{};
    std::copy_n(argv, argc, std::back_inserter(args));
    return args;
}

int main(int argc, char *argv[]) {

	auto const args = make_args(argc - 1, argv + 1);

    auto stack = std::stack<double>{};
    for (auto const each : args) {
		printCompare(stoi(args[0]), stoi(each));
    }
	return 0;
}
