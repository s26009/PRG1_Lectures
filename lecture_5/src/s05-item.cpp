#include <iostream>
#include <chrono>
#include <thread>
#include <pthread.h>
#include "include/Item.h"

void Creature::print() {
	std::cout << "crature " << name << " : HP " << hp << "\n";
}

class Weapon : public Item {
	public:	
	void use_on(Creature& creature) override;
	int strength() override;
	Weapon() : Item::Item() {};
};

void Weapon::use_on(Creature& creature) {
	creature.hp -= strength();
}

int Weapon::strength() {
	return 10;
}

class Potion : public Item {
	public:
	void use_on(Creature& creature) override;
	int strength() override;
	Potion() : Item::Item() {};
};

void Potion::use_on(Creature& creature) {
	creature.hp += strength();
}

int Potion::strength() {
	return 10;
}


class Health_potion : public Potion {
	public:	
	int used = 0;
	void use_on(Creature& creature) override;
	int strength() override;
	Health_potion() : Potion::Potion() {};
};

void Health_potion::use_on(Creature& creature) {
	Potion::use_on(creature);
	used++;
};

int Health_potion::strength() {
	return 50;
}

class Sword : public Weapon {
	public:	
	void use_on(Creature& creature) override;
	int strength() override;
	Sword() : Weapon::Weapon() {};
};

void Sword::use_on(Creature& creature) {
	creature.hp -= strength();
}

int Sword::strength() {
	return 35;
}

class Axe : public Weapon {
	public:	
	void use_on(Creature& creature) override;
	int strength() override;
	Axe() : Weapon::Weapon() {};
};

void Axe::use_on(Creature& creature) {
	creature.hp -= strength();
}

int Axe::strength() {
	return 45;
}

class Bow : public Weapon {
	public:	
	void use_on(Creature& creature) override;
	int strength() override;
	Bow() : Weapon::Weapon() {};
};

void Bow::use_on(Creature& creature) {
	creature.hp -= strength();
}

int Bow::strength() {
	return 25;
}


auto main(int argc, char* argv[]) -> int {
	auto creature1 = Creature("creature1", 50);
	auto creature2 = Creature("creature2", 100);
	auto creature3 = Creature("creature3", 150);

	auto potion = Health_potion();
	auto axe = Axe();
	auto bow = Bow();

	creature1.print();
	creature2.print();
	creature3.print();

	axe.use_on(creature3);
	bow.use_on(creature2);
	potion.use_on(creature1);

	std::cout << "\nAxe strength = " << axe.strength() << "\n";
	std::cout << "Bow strength = " << bow.strength() << "\n";
	std::cout << "Potion strength = " << potion.strength() << "\n";
	std::cout << "axe.use_on(creature3)" << "\n";
	std::cout << "bow.use_on(creature2)" << "\n";
	std::cout << "potion.use_on(creature1)" << "\n\n";

	creature1.print();
	creature2.print();
	creature3.print();

    return 0;
}
