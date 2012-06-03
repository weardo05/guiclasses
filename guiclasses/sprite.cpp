#include "myGui.h"

Sprite::Sprite()
{
    //Initialize the offsets
    x = 0;
    y = 0;
}
int Sprite::getx()
{
	return this->x;
}
int Sprite::gety()
{
	return this->y;
}
SDL_Surface *Sprite::getimage()
{
	return this->sprite;
}
void Sprite::setx(int in)
{
	this->x = in;
}
void Sprite::sety(int in)
{
	this->y = in;
}
void Sprite::setimage(SDL_Surface *in)
{
	this->sprite = in;
}