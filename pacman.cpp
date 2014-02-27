#include "pacman.h"
#include "timer.h"
#include "screen.h"
#include "maze.h"
#include "mainsprites.h"

//x+9,y-3
SDL_Surface *imgflp;
SDL_Surface *imgflp2;
SDL_Surface *flplft;
SDL_Surface* curtimg=NULL; //current image
enum { PACMAN_MVE_RGT,PACMAN_MVE_DWN,PACMAN_MVE_UP,PACMAN_MVE_LFT,SPRITE_PACMAN_DIE };
Timer timer1;
int sprnum=0;
Uint8 *keystates;
character* pacman;
int totalpebs=0;
SDL_RWops	*rw_out;


int delpacman()
{
	delete(pacman);
    	pacman=NULL;
	return 0;
}

SDL_Surface* loadpacman()
{
	image = load_image_mem(mainsprites,152934);

	return image;
}

bool pebcolusion()
{
	Uint32 pixel; 
    	Uint8 r,g,b;
	for (int pebcnt=0;pebcnt < 244; pebcnt++)
	{
        	if (pebble[pebcnt].x-5 == pacman->x && pebble[pebcnt].y-8 == pacman->y)
		{
			if (pebble[pebcnt].is_visible == true)
			{
				pebble[pebcnt].is_visible = false;
				totalpebs++;
			}
		}
	}

	for (int bpebcnt=0;bpebcnt < 244; bpebcnt++)
	{
		if (bigpebble[bpebcnt].x-2 == pacman->x && bigpebble[bpebcnt].y-5 == pacman->y && bigpebble[bpebcnt].is_active == true)
		{
			 if (bigpebble[bpebcnt].is_active == true)
			 {
				 bigpebble[bpebcnt].is_active = false;
				 totalpebs++;
				 
			}
			return true;
			//8 sec
		}
	}

	return false;
}

int dcolusion()
{
	Uint32 pixel; 
    	Uint8 r,g,b;
	for (int x=0;x<14;x++)
	{
		for (int y=0;y<16;y++)
		{
			pixel = get_pixel32(screen,pacman->x+x,pacman->y+y+2);
			SDL_GetRGB(pixel,screen->format,&r,&g,&b);
			if (r == 0 && g == 0 && b==0xff) return 1;
			if (r == 0 && g == 0 && b == 0) 
			{
				pixel = get_pixel32(screen,pacman->x+x,pacman->y+y+3);
				SDL_GetRGB(pixel,screen->format,&r,&g,&b);
			}
		}
	}
	return 0;
}

int ucolusion()
{
	Uint32 pixel; 
    	Uint8 r,g,b;
	for (int x=2;x<12;x++)
	{
		for (int y=0;y<12;y++)
		{
			pixel = get_pixel32(screen,pacman->x+x,pacman->y+y-1);
			SDL_GetRGB(pixel,screen->format,&r,&g,&b);
			if (r == 0 && g == 0 && b==0xff) return 1;
			if (r == 0 && g == 0 && b ==0 )
			{
				pixel = get_pixel32(screen,pacman->x+x,pacman->y+y-2);
				SDL_GetRGB(pixel,screen->format,&r,&g,&b);
				if (r == 0 && g == 0 && b==0xff) return 1;
			}
		}
	}
	return 0;
}

int bcolusion()
{
	Uint32 pixel; 
    	Uint8 r,g,b;
	for (int y=2;y<16;y++)
	{
		for (int x=0;x<12;x++)
		{
			pixel = get_pixel32(screen,pacman->x+x-2,pacman->y+y);
			SDL_GetRGB(pixel,screen->format,&r,&g,&b);
			if (r == 0 && g == 0 && b==0xff) return 1;
		}
	}
	return 0;
}

int fcolusion()
{
	Uint32 pixel; 
    	Uint8 r,g,b;
	for (int y=2;y<16;y++)
	{
		for (int x=14;x<16;x++)
		{
			pixel = get_pixel32(screen,pacman->x+x,pacman->y+y);
			SDL_GetRGB(pixel,screen->format,&r,&g,&b);
			if (r == 0 && g == 0 && b==0xff) return 1;
		}
	}
	
	return 0;
}


void go_pacman()
{

	bool doanime=true;



	pacman->show_frame(curtimg,sprnum,pacman->frame);
	if (pacman->isrunning == true)
	{
		if (timer1.get_ticks() > 60.f)
		{	
			if (curtimg == image) 
			{
				if ( fcolusion() == 0) 
				{
					pacman->move_forward();
					if (pacman->x  == 239 && pacman->y == 118)
					{
						pacman->x  = -49;
					} 
					
				} else {
					doanime = false;
				}
			} else
			if (curtimg == imgflp2)
			{
	
				if (ucolusion() == 0 ) 
				{
					pacman->move_up();
					
				} else {
					doanime = false;
				}
			} else
			if (curtimg == flplft)
			{
				if (bcolusion() == 0) 
				{
					pacman->move_left();
					
					if (pacman->x  == -49 && pacman->y == 118)
					{
						pacman->x  = 239;
					} 
				} else {
					doanime = false;
				}
			} else
			if (curtimg == imgflp)
			{
				if (dcolusion() == 0) 
				{
					pacman->move_down();
						
				} else {
					doanime = false;
				}
			}
			if (doanime==true)
			{
				pacman->anime(3);
				timer1.start();
			}

		}
	} 
	      
	key_pacman();
	

}

void key_pacman()
{
	keystates = SDL_GetKeyState( NULL ); 
	if( keystates[ SDLK_p ] ) 
	{ 
	
		pacman->isrunning = false;
		
	} 
	if( keystates[ SDLK_u ] ) 
	{ 
	
		pacman->isrunning = true;
		
	} 
	if( keystates[ SDLK_UP ] ) 
	{
		
		if ((pacman->x > 191 && pacman->y == 118) || (pacman->x < 0 && pacman->y == 118))
		{
		} else
		if (pacman->x > 79 && pacman->x < 102 && pacman->y == 94)
		{
		} else		
		if (pacman->x > 128 && pacman->x < 151 && pacman->y == 94)
		{
		} else
		if (pacman->x > 151 && pacman->x < 173 && pacman->y == 118)
		{
		} else		
		if (pacman->x > 55 && pacman->x < 76 && pacman->y == 118)
		{
		} else
		if (pacman->x == 59 && pacman->y == 166)
		{
		} else
		if (pacman->x == 171 && pacman->y == 166)
		{
		} else
		if (pacman->x == 167 && pacman->y == 166)
		{
		} else
		if (pacman->x == 171 && pacman->y == 162)
		{
		} else
		if (pacman->x == 155 && pacman->y == 166)
		{
		} else
		if (pacman->x == 75 && pacman->y == 166)
		{
		} else
		if (ucolusion() == 0) 
		{
			curtimg = imgflp2;
			sprnum=2;
		}
	} 
	if( keystates[ SDLK_RIGHT ] ) 
	{
		if ((pacman->x == 127) && (pacman->y > 75 && pacman->y < 93))
		{ 
 		} else
		if ((pacman->x == 151 ) && (pacman->y > 100 && pacman->y < 116))
		{
		} else
		if ((pacman->x == 55 ) && (pacman->y > 160 && pacman->y < 165))
		{
		} else
		if (pacman->x == 53 && pacman->y == 114)
		{
		} else	
		if (pacman->x == 54 && pacman->y == 114)
		{
		} else	
		if (pacman->x == 55 && pacman->y == 114)
		{
		} else		
		if (pacman->x == 56 && pacman->y == 162)
		{
		} else
		if (pacman->x == 151 && pacman->y == 162)
		{
		} else
		if (fcolusion() == 0) 
		{
			curtimg = image;
			sprnum=0;
		}
	} 
	if( keystates[ SDLK_LEFT ] ) 
	{
		if ((pacman->x == 103) && (pacman->y > 78 && pacman->y < 92))
		{
		} else
		if ((pacman->x == 59 ) && (pacman->y > 160 && pacman->y < 165))
		{
		} else
		if (pacman->x == 79 && pacman->y == 114)
		{
		} else
		if (pacman->x == 79 && pacman->y == 110)
		{
		} else
		if (pacman->x == 75 && pacman->y == 144)
		{
		} else
		if (pacman->x == 79 && pacman->y == 144)
		{
		} else
		if (pacman->x == 175 && pacman->y == 162)
		{
		} else
		if (pacman->x == 171 && pacman->y == 162)
		{
		} else
		if (pacman->x == 175 && pacman->y == 158)
		{
		} else
		if (pacman->x == 155 && pacman->y == 162)
		{
		} else
		
		if (pacman->x == 79 && pacman->y == 162)
		{
		} else
		if (pacman->x == 175 && pacman->y == 114)
		{
		} else
		if (bcolusion() == 0) 
		{
			curtimg = flplft;
			sprnum=3;
		}
		
		
	}
	if( keystates[ SDLK_DOWN ] ) 
	{ 
		if ((pacman->x > 191 && pacman->y == 118) || (pacman->x < 0 && pacman->y == 118))
		{
		} else
		if (pacman->x > 108 && pacman->x < 131 && pacman->y == 94)
		{
		} else
		if (dcolusion() == 0) 
		{
			curtimg = imgflp;
			sprnum=1;
		}
	}

}

void crte_pacman_sprtes(SDL_Surface* image)
{
    pacman = new character(7);
    pacman->screen = screen;
    //pacman moves forward sprites
    pacman->create_sprites(3,69,40,16,16,0); //move right

    imgflp2 = rotate_surface(image); //move down
    //pacman->create_sprites(3,40,68,16,16,1);
    pacman->create_sprites2(3,40,168,16,16,1);

    imgflp= flip_surface(imgflp2, FLIP_VERTICAL  ); // move up
    pacman->create_sprites(3,40,76,16,16,1);

    

    flplft = flip_surface(image,FLIP_HORIZONTAL); //move left
    pacman->create_sprites2(3,175,40,16,16,0);

    //pacman dies sprites
    pacman->create_sprites(3,14,55,16,16,0); 

    pacman->create_sprites(3,14,55,16,14,0); 
    pacman->create_sprites(2,64,57,17,14,0); 
    pacman->create_sprites(5,122,54,16,14,0); 
}

void init_pacman()
{
    pacman->isrunning=true;
    pacman->mapx=0;
    pacman->mapy=0;
    pacman->x = 115;
    pacman->y = 190;
    pacman->c.r = 6;
    pacman->super=false;
    timer1.start();
}
