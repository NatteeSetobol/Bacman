#ifndef gameini_H
#define gameini_H



bool load_files();
void clean_up();
bool events(SDL_Event event);
int framerate();
int intro_music_pause();
int game_ini();
int collusion_chk();
int change_game_state(int state);

#include "gameini.cpp"

#endif
