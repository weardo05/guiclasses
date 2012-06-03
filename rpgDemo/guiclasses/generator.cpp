#include "myGui.h"

generator::generator()
{    
	SDL_Init( SDL_INIT_EVERYTHING ); //Start SDL
	this->player.set_camera();
	for(int i = 0; i <= 3; i++)
	{this->nState[i] = new sTate();}
	for(int j = 0; j < MAX_OBJECTS; j++)
	{this->SpriteArray[j] = new Sprite();}
	this->chance = 10;
}
generator::~generator()
{


	
	for(int i = 0; i <= 3; i++)
	{this->nState[i]->~sTate();}
	for(int j = 0; j < MAX_OBJECTS; j++)
	{this->SpriteArray[j]->~Sprite();}
    SDL_Quit(); //Quit SDL
 }
//bool generator::setSpriteArray()
//{
//	int spot = 0, widthMin = 0, widthMax = 0, heightMin = 0, heightMax = 0;
//	SDL_Rect pos;
//	bool success = false;
//
//	pos = this->player.getCamera();// gets screen position
//
//	widthMin = ((pos.x)/CELLSIZE);
//	heightMin = ((pos.y)/CELLSIZE);
//	widthMax = (((pos.x) + SCREEN_WIDTH)/CELLSIZE);
//	heightMax = (((pos.y) + SCREEN_HEIGHT)/CELLSIZE);
//
//	for(int j = heightMin; j <= heightMax ; j++)
//	{
//		for(int i = widthMin; i <= widthMax ; i++)
//		{
//			if(!(this->lvl[i][j]->isEmpty()))
//			{	spot++;
//				this->SpriteArray[spot] = new Sprite();
//				//this->SpriteArray[spot]->setWithCell(this->lvl[i][j],i,j,pos);
//			}
//		}
//	}
//
//	return success;
//
//}
void generator::loadState()
{
	int x = (this->player.getx());
	int y = (this->player.gety());

	//if((x % CELLSIZE) >(x % PLAYERSPEED))
	x = ((x/CELLSIZE));
	y = ((y/CELLSIZE));

	if(y >= 1)
	{this->nState[0]->setState(this->lvl[x][y-1]);}
	else{this->nState[0]->setState('r',"n",0,0);}
	this->nState[1]->setState(this->lvl[x+1][y]);
	this->nState[2]->setState(this->lvl[x][y+1]);
	if(x >= 1)
	{this->nState[3]->setState(this->lvl[x-1][y]);}
	else{this->nState[3]->setState('r',"n",0,0);}

}
void generator::applySprites()
{
	int spriteNum = 0, widthMin = 0, widthMax = 0, heightMin = 0, heightMax = 0;
	SDL_Rect pos;
	bool success = false;

	pos = this->player.getCamera();// gets screen position

	widthMin = ((pos.x)/CELLSIZE);
	heightMin = ((pos.y)/CELLSIZE);
	widthMax = (((pos.x) + SCREEN_WIDTH)/CELLSIZE);
	heightMax = (((pos.y) + SCREEN_HEIGHT)/CELLSIZE);
	int x = 1;

	for(int j = heightMin; j <= heightMax ; j++)
	{
		for(int i = widthMin; i <= widthMax ; i++)
		{
			if(!(this->lvl[i][j]->isEmpty()))
			{	
				spriteNum = this->lvl[i][j]->getSpriteNum();
				this->Scrn.blit((this->SpriteArray[spriteNum]),pos,i,j);
				//this->SpriteArray[spot]->setWithCell(this->lvl[i][j],i,j,pos);
			}
		}
	}
	
	//this->Scrn.newSCreen(BACKGROUNDLOC);
	//for(;x < MAX_OBJECTS; x++)
	//{
	//	if(!(this->SpriteArray[x]->isEmpty()))
	//	{
	//		this->Scrn.blit(this->SpriteArray[x]);
	//	}

	//}

}
char generator::moveCheckApply()
{
	int chance = 0;
	char out = 'r';
	char nMove;
	int a = 0;

	int nX, nY;
	int x = this->player.getxVel();
	int y = this->player.getyVel();

	if((x != 0) || (y != 0))
	{	
		this->loadState();

		if( x < 0)
		{a = 3;}
		if( x > 0)
		{a = 1;}
		if( y < 0)
		{a = 0;}
		if( y > 0)
		{a = 2;}

		nMove = this->nState[a]->getState();

		switch(nMove)
		{
		case 'd':
			this->emptyCells();
			nX = this->nState[a]->getX();
			nY = this->nState[a]->getY();
			this->player.telport(nX,nY);
			this->loadGamelvls(this->nState[a]->getLvlName());
			break;
		case 'r':
			if(x != 0)//swap to get rid of walk thru walls
			{this->player.walkX();}
			else
			{this->player.walkY();}
			chance = rand()%100;
			
			if(chance > 98)
			{out = 'f';}
			break;
		case 'w':
			break;

		}
		this->Scrn.blit((this->player));
		this->applySprites();
		this->Scrn.fLip(); //refresh screen

	}
	return out;

}
void generator::loadGamelvls(string fileName)
{
	int value = 0;
	char type = ' ';
	string spriteLoc;
	string conectingFileName;
	char interaction = ' ';
	int x ,y,i,j, spritenum, cellWidths, cellheights;
	char newSprite = ' ';

	ifstream input; 
	input.open ( fileName.c_str(), std::ios::in);

	for(int a = 0; a < ((LEVEL_WIDTH/CELLSIZE) + 10); a++)
	{
		for(int b = 0; b < (LEVEL_HEIGHT/CELLSIZE); b++)
		{this->lvl[a][b] = new lvlCell();}
	}
	
	for(int a = 0; a < MAX_OBJECTS; a++)
	{this->SpriteArray[a] = new Sprite();}

	while(!input.eof ())
	{
		input >> newSprite>> spritenum >> x >> y >> spriteLoc >> interaction  >>  i >> j >>  conectingFileName >> cellWidths >> cellheights; 

		this->lvl[x][y]->set(interaction, i, j,  conectingFileName, spritenum );
	
		for(int a = (x - 1); a < (cellheights + x); a++)
		{
			for(int b = (y - 1); b < (cellWidths + y); b++)
			{this->lvl[a][b]->setAdjacentCells(interaction, conectingFileName, i, j);}
		}
		if(newSprite == 'n')
		{this->SpriteArray[spritenum]->setimage(loadImage(spriteLoc));}
	}
	
	input.close();
}
void generator::emptyCells()
{
	for(int a = 0; a < ((LEVEL_WIDTH/CELLSIZE) + 10); a++)
	{
		for(int b = 0; b < (LEVEL_HEIGHT/CELLSIZE); b++)
		{this->lvl[a][b]->~lvlCell();}
	}
	for(int a = 0; a < MAX_OBJECTS; a++)
	{this->SpriteArray[a]->~Sprite();}


}
/*
int whatever(generator* g)
{
g->whatgskjhds;

}

whatever(this);


*/