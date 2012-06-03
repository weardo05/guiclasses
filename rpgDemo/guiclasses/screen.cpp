#include "myGui.h"

Screen::Screen()
{
	this->scn = 0;

	inital = false;
}
Screen::~Screen()
{
}
bool Screen::initalize()
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
void Screen::fLip()
{
	SDL_Flip(this->screen);
}
void Screen::set(SDL_Surface *nEw)
{
    //Rectangle to hold the offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = 0;
    offset.y = 0;

    //Blit the surface
    SDL_BlitSurface( nEw, NULL, this->screen, &offset );

}
void Screen::refreshBackground(SDL_Rect in)
{
	SDL_Rect *camera = NULL;
    //Holds offsets
    SDL_Rect offset;

	camera = &in;
    //Get offsets
    offset.x = 0;
    offset.y = 0;

	SDL_BlitSurface(this->background,camera ,this->screen, &offset);

}
void Screen::clean_up(SDL_Surface *old)
{
    //Free the surface
    SDL_FreeSurface( old );

    //Quit SDL
    SDL_Quit();
}
void Screen::newSCreen(string filename)
{
	SDL_Surface *image = NULL;
    image = loadImage(filename);
	if(this->inital == false)
	{this->initalize();}
	this->background = image;
	this->set(image);
	this->fLip();
}
bool Screen::blit(Sprite *in, SDL_Rect sCam, int i, int j)
{
	SDL_Surface *temp = NULL;
	SDL_Rect pos;
	bool success = false;
	temp = in->getimage();
	pos.x = ((CELLSIZE * i) - sCam.x);
	pos.y = ((CELLSIZE * j) - sCam.y);

	SDL_BlitSurface(temp , NULL, this->screen, &pos );// clip and null it is the cammer

	//delete temp;

	return success;
}
bool Screen::blit(Dot in)
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
bool Screen::blit(SDL_Surface *nEwsurface, SDL_Rect in)
{
	bool success = false;
	SDL_Rect offset;

	offset.x = 0;
	offset.y = 0;
	
	SDL_BlitSurface(this->background, NULL, this->screen, &offset);

	SDL_BlitSurface(nEwsurface , &in, this->screen, &offset );
	
	//rember to ask about possible memory leak here 
	//	delete temp;

	return success;

}
