#include "myGui.h"

bag::bag()
{
}
bool item::isEmpty()
{
	return this->empty;
}
bool bag::addItem(item bag)
{
	int x = 0, y = 0;
	bool isFull = true;
	for(; y <= 5; y++)
	{
		for(x = 0; x < 20;x++)
		{
			if(this->inv[x][y].isEmpty())
			{
			}
		}
	}
	return isFull;
}
item::item()
{
	this->empty = true;
}
int item::sellItem(int ammount)
{ 
	if(ammount <= this->number)
	{
		this->number =- ammount;
		if(ammount == 0)
		{this->empty = true;}
		return (ammount * this->value);
	}
	return 0;
}
