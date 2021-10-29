#include <string>

class Creature {
	public:
    std::string name;
    int hp;
	
	void print();
	Creature(std::string name_val, int hp_val) 
		: name(name_val), hp(hp_val) {};
};

class Item {
	public:
	virtual void use_on(Creature& creature) = 0;
	virtual int strength() = 0;
	Item() {};
};

