#include "bAttle.h"

nMove::nMove()
{
}
nMove::nMove(int inDamage, int inCost, string inName)
{
	this->damage = inDamage;
	this->cost = inCost;
	this->name = inName;
}
nMove::~nMove()
{
}
int nMove::use()
{
	return this->damage;
}
int nMove::costOfUse()
{
	return this->cost;
}