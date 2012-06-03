#include "bAttle.h"

battle::battle()
{    
	SDL_Init( SDL_INIT_EVERYTHING ); //Start SDL
	this->bBackground = loadImage(BATTLEBACKGROUND);
	this->bSprite[0] = new SDL_Surface;
	this->bSprite[0] = loadImage(BATTLEPMENU);
	this->offset[0] = new SDL_Rect;
	this->offset[0]->x = 25;
	this->offset[0]->y = 425;
	this->fight.newSCreen(BATTLEBACKGROUND);
	//this->fight.set(loadImage("pic/background.bmp"));
	this->setMobs(BATTLEPLAYER,BATTLEMOB);
	this->fight.blit(this->enemey->mobImage, -222, -222);
	this->fight.blit(this->player->mobImage, -690,-335);

	this->fight.loadMandH();
	this->fight.fLip();
	
	
	
}
battle::~battle()
{
	this->fight.~bScreen();
	this->player->~mob();
	this->enemey->~mob();   
}
void battle::setMobs(string mFile, string pFile)
{
	this->player = new mob(mFile);
	this->enemey = new mob(pFile);
}
char battle::battleHandler(int move,int enemyMove)
{
	bool dead = false;
	char death = 'n';
	int edamage = 0, damage = 0;

	this->player->useMove(move, &damage);	
	dead = this->enemey->reciveAttack(damage);
	if(dead == true)
	{death = 'e';}
	
	dead = false;
	this->enemey->useMove(enemyMove, &damage);
	dead = this->player->reciveAttack(damage);
	
	if(dead == true)
	{death = 'p';}
	
	this->flip(this->player->getHealth(),this->player->getMana());

	return death;
}
void battle::flash()
{
	this->fight.blit(this->player->mobImage, -790,-335);
	this->fight.fLip();
}
void battle::flip()
{	
	this->fight.refreshBackground();
	this->fight.blit(this->enemey->mobImage, -222, -222);
	this->fight.blit(this->player->mobImage, -690,-335);
	this->fight.fLip();
}
void battle::flip(int x, int y)
{	
	x = x /4;	
	y = y /4;
	this->fight.refreshBackground();
	this->fight.blit(this->enemey->mobImage, -222, -222);
	this->fight.blit(this->player->mobImage, -690,-335);
	this->fight.manaAndHealth(x, y);
	this->fight.mobManaAndHealth(this->enemey->getHealth(),this->enemey->getMana());
	this->fight.fLip();
}


