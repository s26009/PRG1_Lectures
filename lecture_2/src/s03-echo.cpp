#include <iostream>
#include <string>
#include <cstring>

bool is_without_endl = false; 	//-n
bool is_descending = false;		//-r
bool is_one_per_line = false;	//-l
int flags_amount = 0;

void apply_flag(char flag) {
	switch(flag) {
		case 'n':
			is_without_endl = true; 
			break;
		case 'r':
			is_descending = true;	
			break;
		case 'l':
			is_one_per_line = true;
			break;
		default:
			std::cout << "Unsupported flag: " << flag << "\n";
	}
}

bool is_flag(char* argument) {
	return argument[0] == '-' && strlen(argument) == 2;
}

void parse_flags(int argc, char *argv[]) {
	for(int i = 1; i < argc; i++) {
		if(is_flag(argv[i])) {
			flags_amount++;
			apply_flag(argv[i][1]);
		} else {
			break;
		}
	}
}

int main(int argc, char *argv[]) {
    if(argv[1] == NULL) {
        std :: cout << "pass some arguments: \"s03-echo a b 34 c55\"\n";
        return 0;
    }
	parse_flags(argc, argv);
	if(is_descending) {
		for(int i = argc - 1; i >= 1 + flags_amount; i--) {
			std::cout << argv[i] << (is_one_per_line ? "\n" : " ");
		}
	} else {
		for(int i = 1 + flags_amount; i < argc; i++) {
			std::cout << argv[i] << (is_one_per_line ? "\n" : " ");
		}
	}
	std::cout << (is_without_endl ? "" : "\n");
	return 0;
}
