#include "myGui.h"

Timer::Timer()
{
	this->startTicks = 0;
    this->pausedTicks = 0;
    this->paused = false;
    this->started = false;
}
void Timer::start()
{
	this->started = true;//Start the timer
	this->paused = false;//Unpause the timer
	this->startTicks = SDL_GetTicks(); //Get the current clock time
}
void Timer::stop()
{
	this->started = false;//Stop the timer
	this->paused = false;//Unpause the timer
}
void Timer::pause()
{
	if( ( this->started == true ) && ( this->paused == false ) )//If the timer is running and isn't already paused
    {
		this->paused = true;//Pause the timer
		this->pausedTicks = SDL_GetTicks() - this->startTicks;//Calculate the paused ticks
    }
}
void Timer::unpause()
{
	if( this->paused == true ) //If the timer is paused
    {
		this->paused = false;//Unpause the timer
		this->startTicks = SDL_GetTicks() - this->pausedTicks;//Reset the starting ticks
		this->pausedTicks = 0; //Reset the paused ticks
    }
}
int Timer::get_ticks()
{
	if( this->started == true ) //If the timer is running
    {
		if( this->paused == true )//If the timer is paused
        {
			return this->pausedTicks;//Return the number of ticks when the timer was paused
        }
        else
        {
			return SDL_GetTicks() - this->startTicks;//Return the current time minus the start time
        }
    }
	return 0; //If the timer isn't running
}
bool Timer::is_started()
{
    return this->started;
}
bool Timer::is_paused()
{
    return this->paused;
}