#ifndef font_H
#define font_H
#include "sdls.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "screen.h"
#include "timer.h"

int print(char* msg,int x, int y);
int inifont();

#include "font.cpp"

#endif
