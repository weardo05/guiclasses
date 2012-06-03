#include "myGui.h"

Dot::Dot()
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;

	//Initialize the cammera
	this->camera.x = 0;
	this->camera.y = 0;
	this->camera.h =SCREEN_HEIGHT;
	this->camera.w =SCREEN_WIDTH;
}
Dot::Dot(int xIn, int yIn)
{
    //Initialize the offsets
    x = xIn;
    y = yIn;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;
}
void Dot::set_camera()
{
    //Center the camera over the dot
    camera.x = ( x + DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
    camera.y = ( y + DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

  
    if( camera.x < 0 )//Keep the camera in bounds.
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > LEVEL_WIDTH - camera.w )
    {
        camera.x = LEVEL_WIDTH - camera.w;
    }
    if( camera.y > LEVEL_HEIGHT - camera.h )
    {
        camera.y = LEVEL_HEIGHT - camera.h;
    }
}
void Dot::setxVel(int in)
{
	this->xVel = in;
}
void Dot::setyVel(int in)
{
	this->yVel = in;
}
void Dot::setSprite(SDL_Surface *in,int x)
{
	this->dot[x] = in;
}