#include <iostream>
#include <string>


std :: string get_password_from_user () {
	std :: cout << "password: ";
	auto n = std :: string {};
	std :: getline ( std :: cin , n);
	return n;
}

int main(int argc, char *argv[]) {
    if(argv[1] == NULL) {
        std :: cout << "pass the password as an argument: \"s03-password abcd1234\"\n";
        return 0;
    }
	const std :: string PASSWORD = argv[1];
	std :: string entered_password;

	do {
		entered_password = get_password_from_user();
	} while (entered_password != PASSWORD);

	std :: cout << "OK\n";
	return 0;
}
