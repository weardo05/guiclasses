#include "myGui.h"

generator::generator()
{    
	SDL_Init( SDL_INIT_EVERYTHING ); //Start SDL
	

}
generator::~generator()
{


   
    SDL_Quit(); //Quit SDL
 }
void generator::loadState(int x,int y)
{
	int z = this->floor;

	this->nState[0]->setState((this->lvl[x][y-1][z]->getInteractType()));

}
void generator::applySprites()
{
	int x = 0;
	
	for(;x <= 40; x++)
	{this->Scrn.blit(*this->SpriteArray[x]);}

}
