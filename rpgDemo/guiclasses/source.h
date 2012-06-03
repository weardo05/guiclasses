#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <fstream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <time.h>


using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using namespace std;

//Screen attributes
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;

const int XSTART = 90;
const int YSTART = 530;

const int CELLSIZE = 10;

const string BATTLEBACKGROUND = "fightpic/fightBack.bmp";
const string BATTLEPMENU = "fightpic/specialMenu.png";
const string BATTLEPLAYER = "player.txt";
const string BATTLEMOB = "mob/mob1.txt";

const string STARTLOC = "pic/start.png";
const string BACKGROUNDLOC = "pic/background.bmp";
const string PLAYERLOC = "pic/test.bmp";

//The dot dimensions
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;

//The dimensions of the level
const int LEVEL_WIDTH = 1600;
const int LEVEL_HEIGHT = 1200;

//sprite array
const int MAX_OBJECTS = 40;

const int PLAYERSPRITEH = 34;
const int PLAYERSPRITEW = 30;
const int PLAYERSPEED = 10;


const int BATTLEIMAGES = 10;




#endif