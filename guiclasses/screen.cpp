#include "myGui.h"

Screen::Screen()
{

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
	SDL_Flip( screen );
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
	this->set(image);
	this->fLip();
}
bool Screen::blit(Sprite in)
{
	SDL_Surface *temp = NULL;
	SDL_Rect pos;
	bool success = false;
	pos.x = in.getx();
	pos.y = in.gety();
	temp = in.getimage();	

	SDL_BlitSurface(temp , NULL, this->screen, &pos );// clip and null it is the cammer

	delete temp;

	return success;
}