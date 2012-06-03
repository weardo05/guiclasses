#include "myGui.h"

int main( int argc, char* argv[] )
{
	Screen start;
	bool quit = false;

	generator world;
	generator fight;
	generator inventory;
	generator movie;

	char state = 's';

	start.newSCreen(STARTLOC);

	//installations / start game
	
	while( quit != true)
	{
		switch (state)
		{
		case 's'://start
			world.Scrn = start;
			state = startGame(&world, &fight, &inventory, &movie);
			//dont forget to remove
			//quit = true;
				break;
		case 'n'://new
				break;
		case 'e'://empty
				break;
		case 'i'://inventory
				break;
		case 'f'://fight
				break;
		case 'c'://conversation
				break;
		case 'r'://run
			state = run(&world);
				break;
		case 'q'://conversation
			quit = true;
				break;
		}
	}
	world.~generator();
    
    return 0;    
}
