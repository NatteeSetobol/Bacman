#include "gameini.h"

Timer music_pause;
Timer GhostSwitchMode;
Timer mazeblinktmr;

int whichswitchmode = 0;

enum { sw_corner, sw_attack };

float die_pause=3000.f; /* 3 seconds */
bool quit = false;
bool isstop=false;
int game_state;
int in_game_state;
int d_frame=5;
bool blink_maze=false;
bool is_maze_white=false;
int blink_count=0;
unsigned int blink_time=2000.f;

enum { TITLE,GAME };
enum { BEGIN,PLAY,PAUSE,DIE_PAUSE,DIED,RESTART,FINISHED,GAME_OVER,WINNER };


bool load_files()
{
    if ( loadpacman() == 0 ) return false; 
    lndmzeimg(); /* load map */
    curtimg = image;
    crte_pacman_sprtes(image);  
    
    return true;    
}

void clean_up()
{
    delpebs();
   // delpacman();
    del_ghosts();
    deletemap();
    SDL_FreeSurface( image ); 
    SDL_Quit();    
}

bool events(SDL_Event event)
{
        while( SDL_PollEvent( &event ) )
        {
		if( event.type == SDL_QUIT ) quit = true;
        }
	return false;
}

int framerate()
{
    	if( SDL_Flip( screen ) == -1 ) return 1;

	frame++;

       	if( ( cap == true ) && ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) ) 
	{
		SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );          
	}
	return 0;
}

int intro_music_pause()
{
	if (music_pause.is_started()== false)
	{
		music_pause.start();
	}
	if (music_pause.get_ticks() > 3000.f)
	{
		change_game_state(PLAY);
	}
	return 0;
}

int game_ini()
{
	if (plyrtmer.is_started() == true)
	{
		print("PLAYER",100,95);
	}
	if (plyrtmer.get_ticks() > 2500.f)
	{
		plyrtmer.stop();
		pacman->setxy(115,190);
		red->setxy(114,95);
		pink->setxy(114,119);
		blue->setxy(98,119);
		orange->setxy(130,119);
		
		blue->speed = 75;
		red->speed = 60;
		pink->speed = 75;
		orange->speed = 75;
		d_frame=5;

		blue->doanime = true;
		red->doanime = true;
		pink->doanime = true;
		orange->doanime = true;

		blue->boxmovement = 1;
		red->boxmovement = 1;
		pink->boxmovement = 1;
		orange->boxmovement = 1;
	
		
		red->is_out_of_box = true;
		pink->is_out_of_box = false;
		blue->is_out_of_box = false;
		orange->is_out_of_box = false;
		
		GhostSwitchMode.start();
	}
	if (plyrtmer.is_started() == false)
	{
		pacman->show_frame(image,0,0);
		red->show_frame(image,0,0);
		blue->show_frame(image,0,0);
		orange->show_frame(image,0,0);

		pink->change_sprite(LOOK_UP);
		pink->show_frame(image,pink->sprt2use,pink->frame);

		blue->change_sprite(LOOK_DWN);
		blue->show_frame(image,blue->sprt2use,blue->frame);

		orange->change_sprite(LOOK_UP);
		orange->show_frame(image,orange->sprt2use,orange->frame);
	}
	if (redytmer.get_ticks() > 2*2300.f)
	{
		clroclst(*red);
		clroclst(*pink);
		clroclst(*blue);
		clroclst(*orange);
		redytmer.stop();		
		pacman->died = false;
		curtimg = image;
		sprnum=0;
		pacman->frame=0;
		change_game_state(PLAY);
	}
	if (redytmer.is_started() == true)
	{
		print("READY!",100,142);
	}
	return 0;
}

int collusion_chk()
{
	if (pebcolusion() == true)
	{
		
		if (red->has_been_eaten == true) red->has_been_eaten = false;
		if (pink->has_been_eaten == true) pink->has_been_eaten = false;
		if (blue->has_been_eaten == true) blue->has_been_eaten = false;
		if (orange->has_been_eaten == true) orange->has_been_eaten = false;

		red->turn();
		pink->turn();
		blue->turn();
		orange->turn();

		blue->is_eatable = true;
		orange->is_eatable = true;
	
		
		pacman->super=true;

	}

	red->chgetmer();
	pink->chgetmer();
	blue->chgetmer();
	orange->chgetmer();

	if (pacman->died == true) 
	{
		die_pause = 3000.f;
		change_game_state(DIE_PAUSE);
	} 

	if (red->chkifeaten() == true)
	{
		die_pause = 1000.f;
		change_game_state(DIE_PAUSE);
	} 
	if (pink->chkifeaten() == true)
	{
		die_pause = 1000.f;
		change_game_state(DIE_PAUSE);
	}
	if (blue->chkifeaten() == true)
	{
		die_pause = 1000.f;
		change_game_state(DIE_PAUSE);
	}
	if (orange->chkifeaten() == true)
	{
		die_pause = 1000.f;
		change_game_state(DIE_PAUSE);
	}
		 
	return 0;
}

int change_game_state(int state)
{
	in_game_state = state;
	return 0;
}
