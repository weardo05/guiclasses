#ifndef BATTLE_H
#define BATTLE_H

#include "myGui.h"

class nMove
{
	public:
		nMove();
		nMove(int damage, int cost, string name);
		~nMove();
		int use();
		int costOfUse();

	private:
		int damage;
		int cost;
		string name;
};
class mob
{
		friend class move;
	public:
		mob();
		mob(string fileName);
		~mob();
		bool useMove(int move, int *damage);
		bool reciveAttack(int damage);
		int getHealth();
		int getMana();

		SDL_Surface *mobImage;
		SDL_Rect *mobsize;

	private:

		int health;
		int mana;
		nMove *attacks[5];

};
class bScreen
{	
	friend class Sprite;
	friend class Dot;

public:
	bScreen();	
	~bScreen();

	bool blit(Dot in);
	bool initalize();
	bool blit(Sprite *in);
	void fLip();
	void set(SDL_Surface *nEw);
	void clean_up(SDL_Surface *old);
	void newSCreen(string filename);
	void refreshBackground();
	bool blit(SDL_Surface *nEwsurface, int x,int y);
	void manaAndHealth(int hSlice,int mSlice);
	void mobManaAndHealth(int hSlice,int mSlice);
	void loadMandH();

private:

	int scn;
	bool inital;
	SDL_Surface *screen;
	SDL_Surface *background;
	SDL_Surface *health;
	SDL_Surface *mana;

};
class battle
{	
	friend class mob;
	friend class Screen;

	public:
		battle();
		~battle();
		void setMobs(string mFile, string pFile);
		char battleHandler(int move,int enemyMove);
		void flash();
		void flip();
		void flip(int x, int y);
		Timer fps; 
		bScreen fight;

	private:
		int pHealth;
		int pMana;
		SDL_Surface *bBackground;
		SDL_Surface *bSprite[BATTLEIMAGES];
		SDL_Rect *offset[BATTLEIMAGES];
		SDL_Rect *screenArea[BATTLEIMAGES];
		SDL_Rect camera;
		mob *enemey;
		mob *player;		
};

#endif