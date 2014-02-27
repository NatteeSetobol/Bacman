#ifndef sprites_H
#define sprites_H
#include "SDL/SDL.h"
#include <math.h>
#include "timer.h"

struct Circle { 
	int x, y; 
	int r; 
}; 

class col_det
{
	public:
		Circle c;
		double distance( double x1, double y1, double x2, double y2 );
		bool check_collision( Circle &A, Circle &B );
};

class get_sprite
{
	public:
		int width;
		int height;
		int fos_x;
		int fos_y;
		SDL_Surface* pnt2fle;
		get_sprite();
	private:

};



class animation
{
	public:
		int totalnum;
		get_sprite* frames;
		SDL_Surface* pnt2fle;
		animation();
		~animation();
	private:
};

class object
{
	public:
		int x;
		int y;
		int move_forward();
		int move_down();
		int move_up();
		int move_left();
	private:
};

class solid:public object,public col_det
{
	public:
		bool is_visible;
		bool is_active;
		get_sprite frame;
		void show(SDL_Surface* sprite_file,SDL_Surface* screen);	
};

class character:public object,public col_det
{
	public:
		int setxy(int xx,int yy);
		Timer diepause;
		Timer diedtimer;
		bool super;
		bool died;
		SDL_Surface *screen;
		int mapx;
		int mapy;
		bool isrunning;
		int total_sprites;
		int frame;
		animation* sprites;
		int* total_frames;
		SDL_Surface* pnt2fle;
		void create_sprites(int sprites_frames, int start_x, int start_y, int width, int height,int horver);
		void create_sprites2(int sprites_frames, int start_x, int start_y, int width, int height,int horver);
		int sprite_count;
		int anime(int sprite_number);
	        int show_frame(SDL_Surface* sprite_file, int sprite_number, int sprite_frame);
		character(int num_of_spte);
		~character();
};


#endif
