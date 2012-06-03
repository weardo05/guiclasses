#include "bAttle.h"


mob::mob()
{
	for(int i = 0; i < 4; i ++)
	{this->attacks[i] = new nMove();}
}
mob::mob(string in)
{
	ifstream input; 
	input.open ( in.c_str(), std::ios::in);

	for(int i = 0; i < 5; i ++)
	{this->attacks[i] = new nMove();}

	int a, b;
	string name;

	input >> a >> b >> name;
	this->health = a;
	this->mana = b;	
	this->mobImage = loadImage(name);

	for(int j = 0; j < 5; j++)
	{
		input >> name >> a >> b;
		this->attacks[j] = new nMove(a, b, name);
	}

}
mob::~mob()
{
}
bool mob::useMove(int in, int *damage)
{
	int cost;
	bool used = false;
	cost = this->attacks[in]->costOfUse();
	if((this->mana - cost) >= 0|| (cost == 0) )
	{
		*damage = this->attacks[in]->use();
		this->mana -= cost;
		used = true;
	}
	return used;
}
bool mob::reciveAttack(int damage)
{
	bool dead = false;
	this->health = (this->health - damage);
	if(this->health <= 0)
	{dead = true;}
	return dead;
}
int mob::getHealth()
{
	return this->health;
}
int mob::getMana()
{
	return this->mana;
}

/*60 70 mobpic/mob1.png
bite 5 5
kick 7 4
lick 1 15
tenctcaleSlash 5 5*/