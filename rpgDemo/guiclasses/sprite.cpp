#include "myGui.h"

Sprite::Sprite()
{
	this->empty = true;
	this->sprite = NULL;
	
}
Sprite::~Sprite()
{
	SDL_FreeSurface(this->sprite);
	if(this->sprite == NULL)
	{
		this->empty = true;
	}
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
void Sprite::setSprite(int xin,int yin, string loc)
{
	this->sprite = loadImage(loc);
	if (this->sprite != NULL)
	{
		this->x = xin;
		this->y = yin;
		this->empty = false;
		this->Sprite_HEIGHT = CELLSIZE;
		this->Sprite_WIDTH = CELLSIZE;
	}
}
bool Sprite::isEmpty()
{
	return this->empty;
}
SDL_Rect Sprite::getCamera()
{
	return this->camera;
}