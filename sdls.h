#ifndef sdls_H
#define sdls_H

#include "SDL/SDL.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination,SDL_Rect* clip);
SDL_Surface *load_image( char* filename);
SDL_Surface *load_image_mem(void *mem, int size);
Uint32 get_pixel32( SDL_Surface *surface, int x, int y );
void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );

#endif

