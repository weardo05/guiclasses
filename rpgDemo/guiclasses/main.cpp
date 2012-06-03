#include "bAttle.h"

int main( int argc, char* argv[] )
{
	bool quit = false;
	char state = 's';
	srand ((unsigned int) time (NULL));

	generator world;	
	world.Scrn.newSCreen(STARTLOC);//start screen
	state = startGame(&world);
	
	while( quit != true)
	{
		switch (state)
		{
		case 's': state = 'r'; 
			world.player.setxVel(1);
			world.moveCheckApply();
			world.player.setxVel(0);
				break;			
		case 'n'://new
				break;
		case 'e'://empty
				break;
		case 'i'://inventory
				break;
		case 'f': state = fight();  break;			
		case 'c'://conversation
				break;
		case 'r'://run
			//state = testWalk(&world);
			state = run(&world);
				break;
		case 'q'://quit
			quit = true;
				break;
		}
	}
	world.~generator();
    
    return 0;    
}
