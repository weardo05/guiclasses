#include "myGui.h"

Dot::Dot()
{
    //Initialize the offsets
    this->x = 90;
    this->y = 530;

    //Initialize the velocity
    this->xVel = 0;
    this->yVel = 0;

	//Initialize the cammera
	this->camera.x = 0;
	this->camera.y = 0;
	this->camera.h = SCREEN_HEIGHT;
	this->camera.w = SCREEN_WIDTH;

	//Initialize the sheet
	this->direction = 0;
	this->phase = 0;
}
Dot::Dot(int xIn, int yIn)
{
    //Initialize the offsets
    this->x = xIn;
	this->y = yIn;

    //Initialize the velocity
    this->xVel = 0;
    this->yVel = 0;
}
void Dot::intalize()
{
	
    //Initialize the offsets
    this->x = 160;
    this->y = 160;

    //Initialize the velocity
    this->xVel = 0;
    this->yVel = 0;

	//Initialize the cammera
	this->camera.x = 0;
	this->camera.y = 0;
	this->camera.h = SCREEN_HEIGHT;
	this->camera.w = SCREEN_WIDTH;

	//Initialize the sheet
	this->direction = 0;
	this->phase = 0;
}

int Dot::getx()
{
	return this->x;
}
int Dot::gety()
{
	return this->y;
}
int Dot::getxVel()
{
	return this->xVel;
}
int Dot::getyVel()
{
	return this->yVel;
}
void Dot::walkX()
{
	this->x += this->xVel;
	
	//If the dot went too far to the left or right
    if( ( this->x < 0 ) || ( this->x + DOT_WIDTH > LEVEL_WIDTH ) )
	{this->x -= this->xVel;}//move back
	
	this->phase = this->phase + 1;
	if(this->phase >= 4)
	{this->phase = 0;}
	if(this->xVel <= 0)
	{this->direction = 3;}
	else
	{this->direction = 2;}

	this->set_camera();
}
void Dot::walkY()
{
	this->y += this->yVel;

	//If the dot went too far up or down
	if( ( this->y < 0 ) || ( this->y + DOT_HEIGHT > LEVEL_HEIGHT ) )
	{this->y -= this->yVel;}//move back
	
	this->phase = this->phase + 1;
	if(this->phase >= 4)
	{this->phase = 0;}
	if(this->yVel <= 0)
	{this->direction = 0;}
	else
	{this->direction = 1;}

	this->set_camera();
}
void Dot::telport(int xIn, int yIn)
{
	this->x = xIn;
	this->y = yIn;
	this->set_camera();
}

void Dot::set_camera()
{
    //Center the camera over the dot
    this->camera.x = ( x + DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
    this->camera.y = ( y + DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

  
    if( this->camera.x < 0 )//Keep the camera in bounds.
    {this->camera.x = 0;}

    if( this->camera.y < 0 )
    {this->camera.y = 0;}

    if( this->camera.x > LEVEL_WIDTH - this->camera.w )
    {this->camera.x = LEVEL_WIDTH - this->camera.w;}

    if( this->camera.y > LEVEL_HEIGHT - this->camera.h )
    {this->camera.y = LEVEL_HEIGHT - this->camera.h;}
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
	this->player[x] = in;
}
SDL_Surface *Dot::getPlayerImage(int in)
{
	return this->player[in];
}
SDL_Rect Dot::getCamera()
{
	return this->camera;
}
