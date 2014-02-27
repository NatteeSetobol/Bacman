#ifndef maze_H
#define maze_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sprites.h"
#include "timer.h"
#include "sdls.h"
#include "screen.h"


//22,13
int inipebbles();
int lndmzeimg();
int shw_map_pce(int mapnum, int x,int y);
int shw_whte_map_pce(int mapnum, int xx,int yy);
int draw_map(bool turnwhite);
int deletemap();
int delpebs();

#include "maze.cpp"

#endif
