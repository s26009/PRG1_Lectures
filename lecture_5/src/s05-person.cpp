#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>
#include "include/Person.h"

class Mr : public Person {
	public:	
	std::string to_string() override;
	Mr(std::string name, std::string surname) : Person::Person(name, surname) {};
};

class Mrs : public Person {
	public:
	std::string to_string() override;
	Mrs(std::string name, std::string surname) : Person::Person(name, surname) {};
};

class King : public Person {
	public:
	std::string to_string() override;
	King(std::string name, std::string surname) : Person::Person(name, surname) {};
};

class Queen : public Person {
	public:
	std::string to_string() override;
	Queen(std::string name, std::string surname) : Person::Person(name, surname) {};
};

std::string Mr::to_string() {
	return "Mr." + name;
}

std::string Mrs::to_string() {
	return "Mrs." + name;
}

std::string King::to_string() {
	return "King " + name;
}

std::string Queen::to_string() {
	return "Queen " + name;
}

void who_is_it(Person& person) {
	std::cout << person.to_string() << "\n";
}

auto main(int argc, char* argv[]) -> int {

	auto mr = Mr("Hleb", "Skachko");
	who_is_it(mr);
	auto mrs = Mrs("Olga", "Skachko");
	who_is_it(mrs);
	auto king = King("Dmitry", "Skachko");
	who_is_it(king);
	auto queen = Queen("Elizabeth", "Skachko");
	who_is_it(queen);

    return 0;
}
