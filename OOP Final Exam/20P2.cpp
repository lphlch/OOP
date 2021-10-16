#include <iostream>
using namespace std;

const int OCCUPATION_WARRIOR = 0;
const int OCCUPATION_MAGE = 1;

class Hero
{
public:
	virtual bool attack(Hero& hero) {
		hero.getHurt(baseDamage);
		if (hero.getCurrentLife() <= 0)
		{
			return true;
		}
		return false;
	}
	virtual void getHurt(double value) {
		life -= value;
	}
	virtual int getOccupation() const=0;
	double getCurrentLife() const { return life; }
	double getBaseDamage() const { return baseDamage; }
protected:
	double life;
	double baseDamage;
};

class Warrior : public Hero
{
	void getHurt(double value) { life -= value * 0.8; }
	int getOccupation() { return OCCUPATION_WARRIOR; }
};

class Mage :public Hero
{
	bool attack(Hero& hero) {
		hero.getHurt(baseDamage * 1.25);
		if (hero.getCurrentLife() <= 0)
		{
			return true;
		}
		return false;
	}
	int getOccupation() { return OCCUPATION_MAGE; }
};

class Arthur : public Warrior
{
	bool attack(Hero& hero) {
		double buffedDamage;
		if (hero.getOccupation() == OCCUPATION_MAGE)
		{
			buffedDamage = baseDamage * 1.1;
		}
		else
		{
			buffedDamage = baseDamage * 0.9;
		}
		hero.getHurt(buffedDamage);
		if (hero.getCurrentLife() <= 0)
		{
			return true;
		}
		return false;
	}
	Arthur(){
		life = 3200;
		baseDamage = 200;
	}
};

class Angela :public Mage
{
	void getHurt(double value) {
		if (life < 500)
		{

		}
	}
	Angela(){
		life = 2500;
		baseDamage = 180;
	}
};