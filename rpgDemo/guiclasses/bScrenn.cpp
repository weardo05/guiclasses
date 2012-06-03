#include "bAttle.h"


bScreen::bScreen()
{
	this->scn = 0;

	inital = false;
}
bScreen::~bScreen()
{
}
bool bScreen::initalize()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "weardoRpg", NULL );

    //If everything initialized fine
	inital = true; 
    return true;

	}
void bScreen::fLip()
{
	SDL_Flip(this->screen);
}
void bScreen::set(SDL_Surface *nEw)
{
    //Rectangle to hold the offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = 0;
    offset.y = 0;


    //Blit the surface
    SDL_BlitSurface( nEw, NULL, this->screen, &offset );

}
void bScreen::refreshBackground()
{
    //Holds offsets
    SDL_Rect offset;
    //Get offsets
    offset.x = 0;
    offset.y = 0;

	SDL_BlitSurface(this->background, NULL ,this->screen, &offset);

}
void bScreen::clean_up(SDL_Surface *old)
{
    //Free the surface
    SDL_FreeSurface( old );

    //Quit SDL
    SDL_Quit();
}
void bScreen::newSCreen(string filename)
{
	SDL_Surface *image = NULL;
    image = loadImage(filename);
	if(this->inital == false)
	{this->initalize();}
	this->background = image;
	this->set(image);
	this->fLip();
}
bool bScreen::blit(Sprite *in)
{
	SDL_Surface *temp = NULL;
	SDL_Rect pos;	
	SDL_Rect sCam;
	bool success = false;
	temp = in->getimage();
	sCam = in->getCamera();
	pos.x = (in->getx() - sCam.x);
	pos.y = (in->gety() - sCam.y);

	SDL_BlitSurface(temp , NULL, this->screen, &pos );// clip and null it is the cammer

	//delete temp;

	return success;
}
bool bScreen::blit(Dot in)
{
	SDL_Surface *temp = NULL;
	SDL_Surface *nScreen = NULL;
	SDL_Rect *player = new SDL_Rect;
	SDL_Rect pos;
	SDL_Rect offset;
	SDL_Rect camera;
	bool success = false;
	camera = in.getCamera();

	offset.x = 0;
	offset.y = 0;
	
	pos.x = (in.getx()) - (camera.x);
	pos.y = (in.gety())- (camera.y);
	temp = in.getPlayerImage(0);
	player->x = 10 + ((in.phase/2)*PLAYERSPRITEW);
	player->y = 3 + ((in.direction)*PLAYERSPRITEH);
	player->w = 20;
	player->h = 30;
	
	SDL_BlitSurface(this->background, &camera, this->screen, &offset);

	SDL_BlitSurface(temp , player, this->screen, &pos );
	
	
	//rember to ask about possible memory leak here 
	//	delete temp;

	return success;

}
bool bScreen::blit(SDL_Surface *nEwsurface, int x,int y)
{
	bool success = false;
	SDL_Rect offset;
	SDL_Rect in;

	offset.x = 0;
	offset.y = 0;
	in.x = x;
	in.y = y;

	SDL_BlitSurface(nEwsurface , &in, this->screen, &offset );
	
	
	//rember to ask about possible memory leak here 
	//	delete temp;

	return success;

}
void bScreen::mobManaAndHealth(int h, int m)
{
	bool success = false;
	SDL_Rect offset;
	SDL_Rect in;

	offset.x = 0;
	offset.y = 0;
	in.x = 420;
	in.y = 64;
	in.w = 3;

	for(int i = 0; i < h; i++)
	{
		SDL_BlitSurface(this->health,  &offset ,this->screen, &in);
		in.x = (in.x + in.w);
	}
	in.x = 420;
	in.y = 90;
	for(int i = 0; i < m; i++)
	{
		SDL_BlitSurface(this->mana,  &offset ,this->screen, &in);
		in.x = (in.x + in.w);
	}


}
void bScreen::manaAndHealth(int h, int m)
{
	bool success = false;
	SDL_Rect offset;
	SDL_Rect in;

	offset.x = 0;
	offset.y = 0;
	in.x = 723;
	in.y = 516;
	in.w = 3;

	for(int i = 0; i < h; i++)
	{
		SDL_BlitSurface(this->health,  &offset ,this->screen, &in);
		in.x = (in.x + in.w);
	}
	in.x = 723;
	in.y = 542;
	for(int i = 0; i < m; i++)
	{
		SDL_BlitSurface(this->mana,  &offset ,this->screen, &in);
		in.x = (in.x + in.w);
	}


}
void bScreen::loadMandH()
{
	this->mana = loadImage("fightpic/mana.png");
	this->health = loadImage("fightpic/health.png");
	this->manaAndHealth(50,50);
	this->mobManaAndHealth(50,50);
}