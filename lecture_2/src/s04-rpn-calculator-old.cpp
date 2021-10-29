#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

bool is_number(const char* argument) {
    for (int i=0; argument[i] != '\0'; i++) {
        if (std::isdigit(argument[i]) == 0) return false;
    }
    return true;
}

bool is_operation(const char* argument) {
	std::string const operations = "+-//**sqrt!%";
	std::string const argument_str = std::string(argument);
    return operations.find(argument_str) != std::string::npos;
}

void calculate_and_print(int first, int second, std::string operation) {
	if(operation.length() < 2) {
		switch(operation[0]) {
			case '+':
				std::cout << first  << " + " << second  << " = " << 
					first + second << "\n";
				break;
			case '-':
				std::cout << first  << " - " << second  << " = " << 
					first - second << "\n";
				break;
			case '*':
				std::cout << first  << " * " << second  << " = " << 
					first * second << "\n";
				break;
			case '/':
				std::cout << first  << " / " << second  << " = " << 
					(float) first / (float) second << "\n";
				break;
			case '%':
				std::cout << first  << " % " << second  << " = " << 
					first % second << "\n";
				break;
			case '!':
				int factorial;
				if (first < 0) {
        			std::cout << "There's no factorial of a negative number.";
					break;
				} else {
					factorial = 1;
					for(int i = 1; i <= first; ++i) {
						factorial *= i;
					}
				}
				std::cout << "!" << first  << " = " << factorial << "\n";
				break;
			default:
				std::cout << "Unknown operation: " << operation << "\n";
		}
	} else {
		if(operation == "//") {
			std::cout << first  << " // " << second  << " = " << 
				first / second << "\n";
		} else if(operation == "**") {
			std::cout << first  << " ** " << second  << " = " << 
				pow(first, second) << "\n";
		} else if(operation == "sqrt") {
			std::cout << first  << "sqrt " << " = " << 
				sqrt(first) << "\n";
		}
	}
}

int main(int argc, char *argv[]) {
	if(argc < 4) {
		std :: cout << "pass 3 arguments, two numbers and operation\n\n" << 
		"+ sum\n" << 
		"- subtraction\n" << 
		"* multiplication\n" << 
		"/ division\n" << 
		"// division whole\n" << 
		"% remainder of the division\n" << 
		"** exponentiation\n" << 
		"sqrt square root\n" << 
		"! factorial\n\n" << 
		"sample: \"./s04-rpn-calculator 5 10 +\"\n";
		return 0;
	}

	int first;
	int second;
	std::string operation;

	if(is_number(argv[1]) && 
		is_number(argv[2]) && 
		is_operation(argv[3])) {
			first = std::__cxx11::stoi(argv[1]);
			second = std::__cxx11::stoi(argv[2]);
			operation = std::string(argv[3]);
	} else {
		std::cout << "Incorrect arguments.\n";
		return 0;
	}

	calculate_and_print(first, second, operation);
	return 0;
}













