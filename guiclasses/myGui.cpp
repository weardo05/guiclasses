#include "myGui.h"

char startGame(generator *world, generator *fight, generator *inventory, generator *movie)
{
	//remove start screen
	//initlize screen 
	// opening movie
	//world->lvl = loadGamelvls("lvl/rpg.txt");
	
	
	
	
	world->Scrn.fLip();

	return 'r';
}
char run(generator *world)
{
	SDL_Event event;
	char state;
	bool exit = false;
	while(exit != true)
	{
		if( SDL_PollEvent( &event ) )
		{ 
			if( event.type == SDL_QUIT )  //If the user has Xed out the window
			{state = 'q';  exit = true;} //Quit the program
			
			else if( event.type == SDL_KEYDOWN )
			{
				switch( event.key.keysym.sym )
				{
					case SDLK_UP: world->player.setyVel(CELLSIZE);
						break;
					case SDLK_DOWN: world->player.setyVel(-CELLSIZE);
						break;
					case SDLK_LEFT: world->player.setxVel(-CELLSIZE);
						break;
					case SDLK_RIGHT: world->player.setxVel(CELLSIZE);
						break;
					case SDLK_i: exit = true;
						state = 'i';//inventory
						break;/*
					case SDLK_SPACE://interact
						break;*/
				}
			}
			else if( event.type == SDL_KEYUP )
			{
				switch( event.key.keysym.sym )
				{
					case SDLK_UP: 						
					case SDLK_DOWN: world->player.setyVel(0);
						break;
					case SDLK_LEFT: 
					case SDLK_RIGHT: world->player.setxVel(0);
						break;
				}
			}
		
		}
	}
	world->player.setyVel(0);
	world->player.setxVel(0);

	return state;
}
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
SDL_Surface *loadImage( string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    //SDL_Surface* optimizedImage = NULL;

    //Load the image using SDL_image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
   //     optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
  //      SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return loadedImage;
}
lvlCell loadGamelvls(string fileName)
{
	char isSprite;
	int value = 0;
	char type = ' ';
	string spriteLoc;
	char interaction;
	int x ,y ,z;
	lvlCell load;
	ifstream input; 
	input.open ( fileName.c_str(), std::ios::in);

	for(int k = 0; k <= 50; k++)
	{
		for(int j = 0; j <= 50; j++)
		{
			for(int i = 0; i <= 50; i++)
			{
				while(!input.eof ())
				{
					input >> isSprite >> value >> type >> spriteLoc >> interaction >> x >> y >> z;
					
				}
			}
		}
	}


	return load;
}
