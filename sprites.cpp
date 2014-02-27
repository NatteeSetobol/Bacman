#include "sprites.h"
#include "SDL/SDL.h"
#include "sdls.h"
#include <math.h>


void solid::show(SDL_Surface* sprite_file,SDL_Surface* screen)
{
	SDL_Rect clip;
	clip.x = frame.fos_x;
    	clip.y = frame.fos_y;
    	clip.w = frame.width;    	
    	clip.h = frame.height;
	apply_surface( x, y, sprite_file, screen,&clip );
}

double col_det::distance( double x1, double y1, double x2, double y2 ) 
{ 
	//Return the distance between the two points 
	return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
	//return y2-y1/x2 - x1;
} 

bool col_det::check_collision( Circle &A, Circle &B ) 
{ 
	if( distance( A.x, A.y, B.x, B.y ) < ( A.r + B.r ) ) 
	{ 
	
		return true; 
	} 
	return false; 
} 

animation::animation()
{
	totalnum = 0;
	frames = NULL;
	pnt2fle=NULL;
}

animation::~animation()
{
	//if (frames != NULL)
	//{
	//	delete [] frames;
	//	frames = NULL;
	//}
}

get_sprite::get_sprite()
{
	width = 0;
	height=0;
	fos_x=0;
	fos_y=0;

}

int character::setxy(int xx,int yy)
{
	x = xx;
	y = yy;
	return 0;
}

int character::show_frame(SDL_Surface* sprite_file, int sprite_number, int sprite_frame)
{
	SDL_Rect clip;
	clip.x = sprites[sprite_number].frames[sprite_frame].fos_x;
    	clip.y = sprites[sprite_number].frames[sprite_frame].fos_y;
    	clip.w = sprites[sprite_number].frames[sprite_frame].width;    	
    	clip.h = sprites[sprite_number].frames[sprite_frame].height;
	apply_surface( x, y, sprite_file, screen,&clip );
	return 0;
}

int character::anime(int sprite_number)
{
	frame++;
	if (frame == total_frames[sprite_number]) frame=0;
	return 0;
}

character::character(int num_of_spte)
{
	died=false;
	frame=0;
	//pnt2fle = sprite_file;
	sprites = NULL;
	sprite_count=0;
	total_sprites=num_of_spte;
	sprites = new animation[total_sprites];
	total_frames = new int[total_sprites];
	
		
	
}

void character::create_sprites(int sprites_frames, int start_x, int start_y, int width, int height,int horver) //horver = horizonal or vertical 
{
	//width = 0;
	//height=1

	sprites[sprite_count].frames = new get_sprite[sprites_frames];
	total_frames[sprite_count] = sprites_frames;
	

	for (int x=0;x<sprites_frames;x++)
	{
		sprites[sprite_count].frames[x].width = width;
		sprites[sprite_count].frames[x].height = height;
	        if (horver == 0)
		{
			sprites[sprite_count].frames[x].fos_y = start_y;
			sprites[sprite_count].frames[x].fos_x = start_x+(width*x);
		} else {
			sprites[sprite_count].frames[x].fos_y = start_y+(height*x);
			sprites[sprite_count].frames[x].fos_x = start_x;
		}
		
		
	}
	sprite_count++;
}


void character::create_sprites2(int sprites_frames, int start_x, int start_y, int width, int height,int horver)
{
	//width = 0;
	//height=1

	sprites[sprite_count].frames = new get_sprite[sprites_frames];
	total_frames[sprite_count] = sprites_frames;
	

	for (int x=0;x<sprites_frames;x++)
	{
		sprites[sprite_count].frames[x].width = width;
		sprites[sprite_count].frames[x].height = height;
	        if (horver == 0)
		{
			sprites[sprite_count].frames[x].fos_y = start_y;
			sprites[sprite_count].frames[x].fos_x = start_x-(width*x);
		} else {
			sprites[sprite_count].frames[x].fos_y = start_y-(height*x);
			sprites[sprite_count].frames[x].fos_x = start_x;
		}
		
		
	}
	sprite_count++;
}



character::~character()
{
	for (int i=0; i < sprite_count; i++)
	{
			
			
		delete[] sprites[i].frames;
		sprites[i].frames = NULL;			
	}

	delete[] sprites;
	sprites = NULL;
	
	delete[] total_frames;
	total_frames=NULL;

}

int object::move_down()
{
	y+=4;
}

int object::move_left()
{
	x-=4;
}

int object::move_up()
{
	y-=4;
}

int object::move_forward()
{
	x+=4;
}
