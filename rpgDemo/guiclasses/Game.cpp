#include "bAttle.h"

char startGame(generator *world)
{
	world->loadGamelvls("lvl/lvl1.txt");		
	world->player.setSprite(loadImage(PLAYERLOC),0);	
	world->Scrn.newSCreen(BACKGROUNDLOC);
	world->player.intalize();
	world->Scrn.blit(world->player);
	world->applySprites();	
	world->Scrn.fLip();

	return 'r';
}
char testWalk(generator *world)
{
	
	SDL_Event event;
	
	bool exit = false;
	int q = 0;
	while(q <= 70 )
	{ 
		q++;
		world->fps.start();
		if( SDL_PollEvent( &event ) )
		{ 
			if( event.type == SDL_QUIT )  //If the user has Xed out the window
			{ exit = true;} //Quit the program
		}
		world->player.setyVel(CELLSIZE);
		world->moveCheckApply();
		
		if( world->fps.get_ticks() < 1000 / FRAMES_PER_SECOND )//Cap the frame rate
		{
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - world->fps.get_ticks() );
		}
	}
	return 'q';
}
char run(generator *world)
{
	SDL_Event event;
	char state;
	bool exit = false;
	while(exit != true)
	{		
		world->fps.start();//start timer
		state = world->moveCheckApply();

		if( SDL_PollEvent( &event ) )
		{ 
			if( event.type == SDL_QUIT )  //If the user has Xed out the window
			{state = 'q';  exit = true;} //Quit the program
			
			else if( event.type == SDL_KEYDOWN )
			{
				switch( event.key.keysym.sym )
				{
					case SDLK_UP: world->player.setyVel(-PLAYERSPEED);break;							
					case SDLK_DOWN: world->player.setyVel(PLAYERSPEED);break;
					case SDLK_LEFT: world->player.setxVel(-PLAYERSPEED);break;
					case SDLK_RIGHT: world->player.setxVel(PLAYERSPEED);break;
					case SDLK_i: exit = true;state = 'i';//inventory
						break;
					/*case SDLK_SPACE:break;*///interact
				}
			}
			else if( event.type == SDL_KEYUP )
			{
				switch( event.key.keysym.sym )
				{
					case SDLK_UP: 						
					case SDLK_DOWN: world->player.setyVel(0);break;							
					case SDLK_LEFT: 
					case SDLK_RIGHT: world->player.setxVel(0);break;
				}
			}
		}

		if(state != 'r'){ exit = true;}
		//Cap the frame rate
        if( world->fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - world->fps.get_ticks() );
        }
	}
	world->player.setyVel(0);
	world->player.setxVel(0);

	return state;
}
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    
    SDL_Rect offset;//Holds offsets

    offset.x = x;//Get offsets
    offset.y = y;
   
    SDL_BlitSurface( source, clip, destination, &offset ); //Blit
}
SDL_Surface *loadImage(string filename)
{
	SDL_Surface* loadedImage = NULL;//The image that's loaded	
	SDL_Surface* optimizedImage = NULL; //The optimized surface that will be used
    
    loadedImage = IMG_Load( filename.c_str() );//Load the image
	
	if( loadedImage != NULL ) //If the image loaded
    {
		optimizedImage = SDL_DisplayFormat( loadedImage );//Create an optimized surface

        SDL_FreeSurface( loadedImage );
        
        if( optimizedImage != NULL )//If the surface was optimized
        {            
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );//Color key surface
        }
    }    
    return optimizedImage;//Return the optimized surface
}
char fight()
{    
    int x = 0, y = 0;//The mouse offsets
	SDL_Rect box;

	battle nBattle;
	SDL_Event event;
	char state = 'r';
	char life = 'l';
	bool exit = false;
	bool menu = false;

	box.x = 30;
	box.y = 440;
	box.h =  35;
	box.w = 100;

	while(exit != true)
	{
		nBattle.fps.start();

		if( SDL_PollEvent( &event ) )
		{ 
			if( event.type == SDL_QUIT )  //If the user has Xed out the window
			{state = 'q';  exit = true;} //Quit the program
			
			if( event.type == SDL_MOUSEBUTTONDOWN )
			{				
				if( event.button.button == SDL_BUTTON_LEFT )//If the left mouse button was pressed
				{					
					x = event.button.x;//Get the mouse offsets
					y = event.button.y;

					int eMove = (rand() % 5);

					if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
					{
						life = nBattle.battleHandler(4,eMove);
					}
					if( ( x > (box.x) ) && ( x < (box.x + box.w )) && ( y > (box.y + box.h) ) && ( y < (box.y) + (2 * box.h) ) )
					{
						menu = true;
						nBattle.fight.blit(loadImage("fightpic/specialMenu.png"),-160,-422);
						nBattle.fight.fLip();
					}
					if(menu == true)
					{
						if( ( x > box.x + box.w ) && ( x < box.x + (2 * box.w) ) && ( y > box.y) && ( y < box.y + box.h) )
						{life = nBattle.battleHandler(0,eMove);}
						if( ( x > box.x + box.w ) && ( x < box.x + (2 * box.w) )  && ( y > box.y + box.h) && ( y < box.y + (2* box.h)) )
						{life = nBattle.battleHandler(1,eMove);}
						if( ( x > box.x + box.w ) && ( x < box.x + (2 * box.w) ) && ( y > box.y + (2* box.h)) && ( y < box.y + (3* box.h)) )
						{life = nBattle.battleHandler(2,eMove);}
						if( ( x > box.x + box.w ) && ( x < box.x + (2 * box.w) ) && ( y > box.y + (3* box.h)) && ( y < box.y +  (4* box.h)) )
						{life = nBattle.battleHandler(3,eMove);}

					}
				}
			}
		}

        if(nBattle.fps.get_ticks() < 1000 / FRAMES_PER_SECOND )//Cap the frame rate
        {SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - nBattle.fps.get_ticks() );}

		if(life == 'e')//mob dies
		{
			exit = true;
			state = 's';
		}
		else if (life == 'p')//player dies
		{
			exit = true;
			state = 'q';
		}
	}

	nBattle.~battle();
	return state;
}