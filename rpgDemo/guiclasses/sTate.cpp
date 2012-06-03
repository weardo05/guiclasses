#include "myGui.h"

sTate::sTate()
{
	this->cState = 'r';
}
sTate::~sTate()
{

}
void sTate::setState(char in, string name, int xIn, int yIn)
{
	this->cState = in;
	this->lvlName = name;
	this->x = xIn;
	this->y = yIn;
}
void sTate::setState(lvlCell *in)
{
	this->cState = in->getInteractType();
	this->lvlName = in->getlvlFileName();
	this->x = in->getx();
	this->y = in->gety();
}
char sTate::getState()
{
	return this->cState;
}
void sTate::setType(char in)
{
	this->cType = in;
}
char sTate::getType()
{
	return this->cType;
}
string sTate::getLvlName()
{
	return this->lvlName;
}
int sTate::getX()
{
	return this->x;
}
int sTate::getY()
{
	return this->y;
}
 