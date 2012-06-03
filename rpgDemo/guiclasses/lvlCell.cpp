#include "myGui.h"

lvlCell::lvlCell()
{
	this->interactType = 'r';
	this->empty = true;
}
lvlCell::~lvlCell()
{
}

int lvlCell::getx()
{
	return this->x;
}
int lvlCell::gety()
{
	return this->y;
}
string lvlCell::getlvlFileName()
{
	return this->lvlFileName;
}
void lvlCell::setAdjacentCells(char interaction,string conectingFileName, int i, int j)
{
	this->interactType = interaction;
	this->lvlFileName = conectingFileName;
	this->x = i;
	this->y = j;

}
char lvlCell::getType()
{
	return this->cType;
}
char lvlCell::getInteractType()
{
	return this->interactType;
}
void lvlCell::set(char interaction, int i, int j, string conectingFileName, int spritenum )
{	
	this->spriteNum = spritenum;
	this->empty = false;
	this->interactType = interaction;
	this->x = i;
	this->y = j;
	this->lvlFileName = conectingFileName;
}
bool lvlCell::isEmpty()
{
	return this->empty;
}
int lvlCell::getSpriteNum()
{return this->spriteNum;}
