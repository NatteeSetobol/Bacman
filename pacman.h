#ifndef pacman_H
#define pacman_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sprites.h"
#include "timer.h"

void crte_pacman_sprtes(SDL_Surface* image);
void init_pacman();
void key_pacman();
void go_pacman();
bool pebcolusion();

int fcolusion();
int bcolusion();
int ucolusion();
int dcolusion();

int delpacman();
SDL_Surface* loadpacman();

#include "pacman.cpp"

#endif
