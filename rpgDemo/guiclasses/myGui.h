#ifndef MYGUI_H
#define MYGUI_H

#include "source.h"

class Sprite
{
	friend class lvlCell;

   public:
    
    Sprite();	 //Initializes the variables  
	~Sprite();

	bool isEmpty();
	int getx();
	int gety();
	SDL_Surface *getimage();
	SDL_Rect getCamera();
	void setWithCell(lvlCell *in, int xin, int yin, SDL_Rect cam);
	void setSprite(int xin,int yin, string loc);
	void setx(int in);
	void sety(int in);
	void setimage(SDL_Surface *in);

	private:

		bool empty;
		int x, y;  //The X and Y offsets
		int Sprite_WIDTH;
		int Sprite_HEIGHT;
		string imageAdress;
		SDL_Surface *sprite;
		SDL_Rect camera;
};
class Dot
{
	public:
    
    Dot();					//Initializes the variables
	Dot(int xIn, int yIn);
	void intalize();
	
   // void show(Screen *old);			 //Shows the dot on the screen
    void set_camera();		 //Sets the camera over the dot
	void walkX();
	void walkY();
	void telport(int xIn, int yIn);

	void setxVel(int in);
	void setyVel(int in);
	void setSprite(SDL_Surface *input,int x);
	
	int getx();
	int gety();
	int getxVel();
	int getyVel();

	SDL_Surface *getPlayerImage(int in);
	SDL_Rect getCamera();

		
    //private:

    int xVel;
	int yVel;//The velocity of the dot
		
    int x;
	int y;//The X and Y offsets of the dot	
	
	int direction;
	int phase;
	SDL_Event event; //The event structure
	SDL_Rect camera; //The camera
	SDL_Surface *player[8];	
};
class Timer
{
    public:
    
    Timer();	//Initializes variables

	void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();    //Gets the timer's time
	    
    bool is_started(); //Checks the status of the timer
    bool is_paused();  //Checks the status of the timer
	
    private:
   
    int startTicks; //The clock time when the timer started  
    int pausedTicks;//The ticks stored when the timer was paused
	    
    bool paused; //The timer status
    bool started;//The timer status
};
class sTate
{
	public:
		sTate();
		~sTate();
		void setState(char in, string name, int xIn, int yIn);
		char getState();
		void setType(char in);
		char getType();
		string getLvlName();
		int getX();
		int getY();
		void setState(lvlCell *in);

	private:
		int x, y;
		string lvlName;
		char cState;
		char cType;

};
class Screen
{	
	friend class Sprite;
	friend class Dot;

public:
	Screen();	
	~Screen();

	bool blit(SDL_Surface *nEwsurface, SDL_Rect in);
	bool blit(Dot in);
	bool initalize();
	bool blit(Sprite *in, SDL_Rect pos,int i,int j);
	void fLip();
	void set(SDL_Surface *nEw);
	void clean_up(SDL_Surface *old);
	void newSCreen(string filename);
	void refreshBackground(SDL_Rect in);

private:
	int scn;
	bool inital;
	SDL_Surface *screen;
	SDL_Surface *background;

};
class lvlCell
{
	public:
		lvlCell();
		~lvlCell();
		
		char getType();
		int getx();
		int gety();
		int getSpriteNum();
		string getlvlFileName();
		void setAdjacentCells(char interaction,string conectingFileName, int i, int j);
		char getInteractType();	
		void set( char interaction, int i, int j, string conectingFileName, int spritenum );
		bool isEmpty();
		
		void setCell();


	private:

		int x,y;
		bool empty;
		char cType;
		char interactType;
		int spriteNum;
		string lvlFileName;
};
class generator 
{	
	friend class Sprite;
	friend class Dot;
	friend class Timer;
	friend class Screen;
	friend class lvlCell;

	public:
		generator();
		~generator();

		//bool setSpriteArray();				
		void loadState();
		void applySprites();
		char moveCheckApply();//d is door w is wall r is road
		void loadGamelvls(string fileName);
		void emptyCells();
	
		Screen Scrn;
		sTate *nState[4];
		Dot player;
		Sprite *SpriteArray[MAX_OBJECTS];
		Timer fps;
		lvlCell *lvl[(LEVEL_WIDTH/CELLSIZE) + 10][LEVEL_HEIGHT/CELLSIZE];


	private:

		int chance;//should come from lvl.txt
		int floor;

};
class item
{
public:
		item();
		bool isEmpty();
		int sellItem(int ammount);
		bool useItem(string &use);//returns what the item does
private:

	bool empty;
	int number;
	string type;
	int value;
	bool consumable;
	string name;
	string use;
	string imageLoc;	
};
class bag 
{
public:
	bag();
	bool addItem(item newItem);
	bool sellItem(int &price,int ammount);

private:
	item inv[20][5];
};

//main functions

char testWalk(generator *world);
char startGame(generator *world);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip );
SDL_Surface *loadImage(string filename );
void loadGamelvls(string fileName, generator *in);
char fight();
char run(generator *world);


#endif