#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <fstream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

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
const int xStart = 0;
const int yStart = 0;

const int CELLSIZE = 40;

const string STARTLOC = "pic/start.png";
const string BACKGROUNDLOC = "pic/background.bmp";
const string PLAYERLOC = "pic/player.bmp";

//The dot dimensions
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;

//The dimensions of the level
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;




#endif