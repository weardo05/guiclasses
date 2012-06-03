#ifndef myGUI_H
#define myGUI_H

#include "source.h"
	
class Sprite
{
   public:
    
    Sprite();	 //Initializes the variables  

	int getx();
	int gety();
	SDL_Surface *getimage();
	void setx(int in);
	void sety(int in);
	void setimage(SDL_Surface *in);

	 private:

    int x, y;  //The X and Y offsets
	int Sprite_WIDTH;
	int Sprite_HEIGHT;
	string imageAdress;

	SDL_Surface *sprite;   
};
class Dot
{
	public:
    
    Dot();					//Initializes the variables
	Dot(int xIn, int yIn);
	
    void show();			 //Shows the dot on the screen
    void set_camera();		 //Sets the camera over the dot
	void setxVel(int in);
	void setyVel(int in);
	void setSprite(SDL_Surface *input,int x);

	
    private:

    int xVel;
	int yVel;//The velocity of the dot
		
    int x;
	int y;//The X and Y offsets of the dot	
	
	SDL_Event event; //The event structure
	SDL_Rect camera; //The camera
	SDL_Surface *dot[8];	
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
		void setState(char in);
		char getState();

	private:
		char cState;

};
class Screen
{
public:
	Screen();	
	~Screen();
	void fLip();
	bool initalize();
	bool blit(Sprite in);
	void set(SDL_Surface *nEw);
	void clean_up(SDL_Surface *old);
	void newSCreen(string filename);

private:
	bool inital;
	SDL_Surface *screen;

};
class lvlCell
{
	public:
		lvlCell();
		~lvlCell();

		int getValue();
		char getType();
		string getFileName();		
		char getInteractType();	
		
		void setValue(int input);
		void setType(char input);
		void setInteractType(char input);
		void setFileName(string input);

	private:

		bool sprite;
		int cValue;
		char cType;
		char interactType;
		string fileName;
		lvlCell *mAtrix[100][100];
};
class generator 
{
	public:
		generator();
		~generator();
		bool setSpriteArray();
				
		void loadState(int xIn, int yIn);
		void applySprites();
		void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip );

	
		Screen Scrn;
		sTate *nState[3];
		Dot player;
		Sprite *SpriteArray[40];
		Timer fps;
		lvlCell *lvl[100][100][50];

		private:

			int chance;
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
char startGame(generator *world, generator *fight, generator *inventory, generator *movie);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip );
SDL_Surface *loadImage(string filename );
lvlCell loadGamelvls(string fileName);

char run(generator *world);


#endif