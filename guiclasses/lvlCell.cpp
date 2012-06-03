#include "myGui.h"

lvlCell::lvlCell()
{
}
lvlCell::~lvlCell()
{
	
}
int lvlCell::getValue()
{
	return this->cValue;
}
char lvlCell::getType()
{
	return this->cType;
}
char lvlCell::getInteractType()
{
	return this->interactType;
}
string lvlCell::getFileName()
{
	return this->fileName;
}
void lvlCell::setValue(int in)
{
	this->cValue = in;
}
void lvlCell::setType(char in)
{
	this->cType = in;
}
void lvlCell::setInteractType(char in)
{
	this->interactType = in;
}
void lvlCell::setFileName(string in)
{
	this->fileName = in;
}