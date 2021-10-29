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


class Hello : public Greeting {
	public:
	std::string greet(Person& person) override;
	Hello() : Greeting::Greeting() {};
};

class Good_evening : public Greeting {
	public:
	std::string greet(Person& person) override;
	Good_evening() : Greeting::Greeting() {};
};

class Farewell : public Greeting {
	public:
	std::string greet(Person& person) override;
	Farewell() : Greeting::Greeting() {};
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


std::string Hello::greet(Person& person) {
	return "Hello, " + person.to_string();
}

std::string Good_evening::greet(Person& person) {
	return "Good evening, " + person.to_string();
}

std::string Farewell::greet(Person& person) {
	return "Farewell " + person.to_string();
}

void who_is_it(Person& person) {
	std::cout << person.to_string() << "\n";
}

auto main(int argc, char* argv[]) -> int {
	auto hello = Hello{};
	auto good_evening = Good_evening{};
	auto farewell = Farewell{};

	auto mr = Mr("Hleb", "Skachko");
	who_is_it(mr);
	std::cout << hello.greet(mr) << "\n";

	auto mrs = Mrs("Olga", "Skachko");
	who_is_it(mrs);
	std::cout << good_evening.greet(mrs) << "\n";

	auto king = King("Dmitry", "Skachko");
	who_is_it(king);
	std::cout << farewell.greet(king) << "\n";

	auto queen = Queen("Elizabeth", "Skachko");
	who_is_it(queen);

    return 0;
}
