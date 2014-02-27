#include "SDL/SDL.h"
#include "screen.h"
#include "sdls.h"
#include "SDL/SDL_image.h"

#define Uint32 unsigned int

//Screen attributes
const int SCREEN_WIDTH = 240;
const int SCREEN_HEIGHT = 300;
const int SCREEN_BPP = 32;

//Frame rate
const int FRAMES_PER_SECOND = 30;
int frame = 0;
bool cap = true;
Timer fps;   
SDL_Event event;

//The surfaces
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;

const int FLIP_VERTICAL = 1;
const int FLIP_HORIZONTAL = 2;


SDL_Surface *turn_maze_white(SDL_Surface *surface)
{
	
    	Uint8 r,g,b;

	SDL_Surface *WhiteMaze = NULL;
	
    	if( surface->flags & SDL_SRCCOLORKEY )
    	{
        	WhiteMaze = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, 0 );
    	}
    	//Otherwise
    	else
    	{
        	WhiteMaze = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask );
    	
	}

	//If the surface must be locked
    	if( SDL_MUSTLOCK( surface ) )
    	{
        	//Lock the surface
        	SDL_LockSurface( surface );
    	}

 	for (int x=0; x < WhiteMaze->w; x++)
    	{
		for (int y=0;y < WhiteMaze->h;y++)
		{
			Uint32 pixel = get_pixel32( surface, x, y );

			SDL_GetRGB(pixel,screen->format,&r,&g,&b);

			if (r == 0 && g == 0 && b==0xff)
			{
				r = 0xff;
				b = 0xff;
				g = 0xff;
				pixel = SDL_MapRGB(screen->format,r,g,b);
			}

			put_pixel32( WhiteMaze,  x, y, pixel );
		}
    	}

    	//Copy color key
    	if( surface->flags & SDL_SRCCOLORKEY )
    	{
        	SDL_SetColorKey( WhiteMaze, SDL_RLEACCEL | SDL_SRCCOLORKEY, surface->format->colorkey );
    	}


	//Unlock surface
    	if( SDL_MUSTLOCK( surface ) )
   	 {
        	SDL_UnlockSurface( surface );
    	}
    

	return WhiteMaze;
}

SDL_Surface *rotate_surface( SDL_Surface *surface )
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *flipped = NULL;
    int sw=0;
    int sh=0;
    
    //If the image is color keyed
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->h, surface->w, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, 0 );
    }
    //Otherwise
    else
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->h, surface->w, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask );
    }

    sh=surface->h;
    sw=surface->w;
    
    
    //If the surface must be locked
    if( SDL_MUSTLOCK( surface ) )
    {
        //Lock the surface
        SDL_LockSurface( surface );
    }
 
 


   


    for (int x=0,y2=sh-1;x < sw;x++,y2--)
    {
	for (int y=0,x2=0;y <= sh;y++,x2++)
	{
		if (y2 > -1)
		{
			Uint32 pixel = get_pixel32( surface, x, y );
			put_pixel32( flipped,  x2, y2, pixel );
		}
	}
    }


    //Unlock surface
    if( SDL_MUSTLOCK( surface ) )
    {
        SDL_UnlockSurface( surface );
    }
    
    //Copy color key
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        SDL_SetColorKey( flipped, SDL_RLEACCEL | SDL_SRCCOLORKEY, surface->format->colorkey );
    }
    
    //Return flipped surface
    return flipped;
}



SDL_Surface *rotate_surface90( SDL_Surface *surface )
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *flipped = NULL;
    
    //If the image is color keyed
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, 0 );
    }
    //Otherwise
    else
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask );
    }
    
    //If the surface must be locked
    if( SDL_MUSTLOCK( surface ) )
    {
        //Lock the surface
        SDL_LockSurface( surface );
    }
 
 



   
    for (int y=0;y < flipped->h;y++)
    {
	for (int x=0;x < flipped->w;x++)
	{
        //x,y
		Uint32 pixel = get_pixel32( surface, y, x );
		put_pixel32( flipped,  flipped->w-1-x,y, pixel );
	}
    }

    	

    //Unlock surface
    if( SDL_MUSTLOCK( surface ) )
    {
        SDL_UnlockSurface( surface );
    }

    //flipped->w = surface->h;
    //flipped->h = surface->w;
 
    //Copy color key
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        SDL_SetColorKey( flipped, SDL_RLEACCEL | SDL_SRCCOLORKEY, surface->format->colorkey );
    }
    
    //Return flipped surface
    return flipped;
}


SDL_Surface *flip_surface( SDL_Surface *surface, int flags )
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *flipped = NULL;
    
    //If the image is color keyed
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, 0 );
    }
    //Otherwise
    else
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask );
    }
    
    //If the surface must be locked
    if( SDL_MUSTLOCK( surface ) )
    {
        //Lock the surface
        SDL_LockSurface( surface );
    }
    
    //Go through columns
    for( int x = 0, rx = flipped->w - 1; x < flipped->w; x++, rx-- )
    {
        //Go through rows
        for( int y = 0, ry = flipped->h - 1; y < flipped->h; y++, ry-- )
        {
            //Get pixel
            Uint32 pixel = get_pixel32( surface, x, y );
            
            //Copy pixel
            if( ( flags & FLIP_VERTICAL ) && ( flags & FLIP_HORIZONTAL ) )
            {
                put_pixel32( flipped, rx, ry, pixel );
            }
            else if( flags & FLIP_HORIZONTAL )
            {
                put_pixel32( flipped, rx, y, pixel );
            }
            else if( flags & FLIP_VERTICAL )
            {
                put_pixel32( flipped, x, ry, pixel );
            }
        }    
    }
    
    //Unlock surface
    if( SDL_MUSTLOCK( surface ) )
    {
        SDL_UnlockSurface( surface );
    }
    
    //Copy color key
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        SDL_SetColorKey( flipped, SDL_RLEACCEL | SDL_SRCCOLORKEY, surface->format->colorkey );
    }
    
    //Return flipped surface
    return flipped;
}



bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "bacman", NULL );
    
    //If everything initialized fine
    return true;
}

int paintbg()
{
	SDL_Rect object;
	Uint32 objcolor;
	objcolor = SDL_MapRGB(screen->format,0,0,0);
	object.w=SCREEN_WIDTH;
	object.h=SCREEN_HEIGHT;							
	object.x=0;
	object.y=0;
	SDL_FillRect(screen, &object, objcolor);
	return 0;
}
