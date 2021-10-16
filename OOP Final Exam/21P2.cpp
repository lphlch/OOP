const int LEVEL1VEST = 1;
const int LEVEL2VEST = 2;

class BulletproofVest 
{
protected:
	int durability;
	bool damaged;
public:
	virtual int getHurt(int value)=0;
	virtual  int getLevel()=0;
	int getDurability()const {
		if(damaged || durability<=0)
		{
			return 0;
		}
		else
		{
			return durability;
		}
	}
	bool getDamaged() const{return damaged;}
	virtual ~BulletproofVest(){};

};

class Level1Vest :public BulletproofVest
{
public:
	Level1Vest(){durability=150;damaged=false;}
	int getHurt(int value){

		int dua=getDurability();
		if(getDamaged())
		{
			return 0;
		}

		double realValue=0.6*value;

		if(dua<realValue)
		{
			damaged=true;
			durability=0;
			return dua;
		}
		else
		{
			/*Èô·À¾ßÄÍ¾Ã¶È×ãÒÔ¿Û³ý*/
			durability=durability-realValue;
			if(durability<=0) 
			{
				durability=0;
				damaged=true;
			}
			return realValue;
		}
	}

	int getLevel(){return LEVEL1VEST;}
};

class Level2Vest:public BulletproofVest
{
public:
	Level2Vest(){durability=250;damaged=false;isMiss=false;}
	int getHurt(int value){
		if(getDamaged()) return 0;
		if(isMiss)
		{
			isMiss=!isMiss;
			return 0;
		}
		else
		{
			int dua=getDurability();
			int realValue=value*0.4;
			if(dua>=realValue)
			{
				durability-=realValue;
				if(durability<=0) 
				{
					durability=0;
					damaged=true;
				}
				return realValue;
			}
			else
			{
				damaged=true;
				durability=0;
				return dua;
			}
		}

	}
	int getLevel(){return LEVEL2VEST;}
	//virtual ~Level2Vest(){};
private:
	bool isMiss;
};


class Gun
{
public:
	static const int baseDamage=21;
	bool shoot(){return magazineBulletNumber;}
	virtual int hit(BulletproofVest &vest)=0;
	bool reload(){
		if(magazineBulletNumber==magazineCapacity)
		{
			return false;
		}
		else if(residualBulletNumber==0)
		{
			return false;
		}
		else
		{
			if(magazineCapacity-magazineBulletNumber>residualBulletNumber)
			{
				magazineBulletNumber+=residualBulletNumber;
				residualBulletNumber=0;
			}
			else
			{
				residualBulletNumber=residualBulletNumber-(magazineCapacity-magazineBulletNumber);
				magazineBulletNumber=magazineCapacity;
			}
			return true;
		}

	}
	int getMagazineCapacity(){return magazineCapacity;}
	int getMagazineBulletNumber(){return magazineBulletNumber;}
	int getResidualBulletNumber(){return residualBulletNumber;}
	int getBaseDamage(){return baseDamage;}
	virtual ~Gun(){};
protected:
	int magazineCapacity;
	int magazineBulletNumber;
	int residualBulletNumber;
};

class AutomaticRifle : public Gun
{
public:
	AutomaticRifle(){magazineCapacity=40;magazineBulletNumber=0;residualBulletNumber=200;}
	int hit(BulletproofVest &vest){
		if(shoot())
		{
			magazineBulletNumber--;
			return vest.getHurt(baseDamage*2);
		}
		return 0;
	}
};

class SniperRifle :public Gun
{
public:
	SniperRifle(){magazineCapacity=20;magazineBulletNumber=0;residualBulletNumber=100;}
	int hit(BulletproofVest &vest){
		if(shoot())
		{
			magazineBulletNumber--;
			if(vest.getLevel()==LEVEL1VEST)
			{
				return vest.getHurt(baseDamage*4);
			}
			else
			{
				return vest.getHurt(baseDamage*3);
			}
		}
		return 0;
	}
};