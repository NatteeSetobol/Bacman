#ifndef screen_H
#define screen_H
#include "timer.h"
#include "SDL/SDL.h"


//functions
bool init();
int paintbg();
//Uint32 get_pixel32( SDL_Surface *surface, int x, int y );
//void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );
SDL_Surface *flip_surface( SDL_Surface *surface, int flags );
SDL_Surface *rotate_surface( SDL_Surface *surface);
SDL_Surface *rotate_surface90( SDL_Surface *surface );

SDL_Surface *turn_maze_white(SDL_Surface *surface);

#include "screen.cpp"

#endif
