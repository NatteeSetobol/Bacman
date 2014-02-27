#include "maze.h"
//maze pieces
#include "maze1.h"
#include "maze2.h"
#include "maze3.h"
#include "maze6.h"
#include "maze7.h"
#include "maze8.h"
#include "maze9.h"
#include "maze10.h"
#include "maze11.h"
#include "maze12.h"
#include "maze13.h"
#include "maze14.h"
#include "maze15.h"
#include "maze18.h"
#include "maze23.h"
#include "maze24.h"
#include "maze26.h"
#include "maze27.h"
#include "maze28.h"
#include "maze29.h"
#include "maze30.h"
#include "maze31.h"
#include "maze32.h"
#include "maze37.h"
#include "maze38.h"
#include "maze39.h"
#include "maze40.h"
#include "maze41.h"
#include "maze42.h"
#include "maze43.h"
#include "maze44.h"
#include "maze45.h"
#include "maze46.h"
#include "maze47.h"
#include "maze48.h"
#include "maze49.h"
#include "maze50.h"
#include "maze51.h"
#include "maze52.h"
#include "maze53.h"
#include "maze54.h"
#include "maze55.h"
#include "maze56.h"
#include "maze57.h"
#include "maze58.h"
#include "maze59.h"
#include "maze60.h"
#include "maze61.h"
#include "maze62.h"
#include "maze63.h"
#include "maze64.h"
#include "maze65.h"
#include "maze66.h"
#include "maze67.h"
#include "maze68.h"
#include "maze69.h"
#include "maze70.h"
#include "maze71.h"
#include "maze72.h"
#include "maze73.h"
#include "maze74.h"
#include "maze75.h"
#include "maze76.h"
#include "maze77.h"
#include "maze78.h"
#include "maze79.h"

SDL_Surface* maze[140];
SDL_Surface* mazewhite[140];

solid pebble[245];
solid bigpebble[245];

Timer peb_tmer;
int pacp_map_x=13;
int pacp_map_y=22;
int total_peb=244;
bool shwpeb=true;

int map[16][14] = { 
	1,2,2,2,2,2,3,4,2,2,2,2,2,5, 
	6,23,24,26,27,28,29,30,31,27,32,23,24,33,
	6,25,34,35,36,38,39,40,41,36,42,25,34,33,
	6,43,44,45,46,43,47,48,44,45,46,43,44,33,
	7,49,50,51,52,53,54,55,56,57,58,59,49,61,
	8,62,63,51,64,65,66,67,68,69,70,71,62,72,
	9,9,73,74,75,76,77,78,79,80,81,82,9,9,
	10,10,50,83,84,85,0,0,86,83,84,87,10,10,
        11,11,88,51,89,90,91,91,92,51,89,93,11,11,
	12,9,73,94,95,43,47,48,44,74,75,96,9,97,
	6,98,53,99,100,101,51,55,102,100,103,104,105,33,
	6,106,107,108,109,110,111,112,113,109,114,115,116,33,
	117,118,119,45,46,43,47,48,44,45,46,119,120,121,
	6,122,123,124,125,126,127,128,129,130,131,123,132,33,
	6,134,136,136,136,137,111,112,138,136,136,136,137,33,
	14,15,15,15,15,15,15,15,15,15,15,15,15,16
};

int pebmap[29][26] = {
          1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	  1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,
	  2,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,2,
	  1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,
	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	  1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,
	  1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,
	  1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	  1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	  1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,
	  1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,
	  2,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,2,
	  0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,
	  0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,
	  1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,
	  1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
	  1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
	  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};


int draw_map(bool turnwhite=false)
{
	int mapx=10,mapy=10;
        for (int y=0;y<14;y++)
        {
		for (int x=0;x<16;x++)
		{
			if (turnwhite == true)
			{
				shw_whte_map_pce(map[x][y],mapx,mapy);
			} else {
        			shw_map_pce( map[x][y],mapx,mapy);
			}
			mapy += 16;
			
		}
		mapy = 10;
		mapx += 16;
		
		
	}

	return 0;
}

int shw_map_pce(int mapnum, int xx,int yy)
{
	
	

	apply_surface( xx, yy, maze[mapnum], screen,NULL );
	
	return 0;
}

int shw_whte_map_pce(int mapnum, int xx,int yy)
{
	apply_surface( xx, yy, mazewhite[mapnum], screen,NULL );	
	return 0;
}

int lndmzeimg()
{
    maze[0] = NULL;
    maze[1] = load_image_mem(maze1,822);//load_image( "maze/maze1.bmp" );

    maze[2] = load_image_mem(maze2,822);//load_image( "maze/maze2.bmp" );  

    maze[3] = load_image_mem(maze3,1078);//load_image( "maze/maze3.bmp" );

    maze[4] = flip_surface(maze[3],FLIP_HORIZONTAL);
    maze[5] = flip_surface(maze[1],FLIP_HORIZONTAL);


    maze[6] = load_image_mem(maze6,1078);//load_image( "maze/maze6.bmp" );

    maze[7] = load_image_mem(maze7,1078);//load_image( "maze/maze7.bmp" );
    maze[8] = load_image_mem(maze8,1078);//load_image( "maze/maze8.bmp" );
    maze[9] = load_image_mem(maze9,1078);//load_image( "maze/maze9.bmp" );
    maze[10] = load_image_mem(maze10,1078);//load_image( "maze/maze10.bmp" );
    maze[11] = load_image_mem(maze11,1078);//load_image( "maze/maze11.bmp" );
    maze[12] = load_image_mem(maze12,1078);//load_image( "maze/maze12.bmp" );
    maze[13] = load_image_mem(maze13,1078);//load_image( "maze/maze13.bmp" );
    maze[14] = load_image_mem(maze14,1078);//load_image( "maze/maze14.bmp" );
    maze[15] = load_image_mem(maze15,1078);//load_image( "maze/maze15.bmp" );
    maze[16] = flip_surface(maze[14],FLIP_HORIZONTAL);
    maze[17] = flip_surface(maze[6],FLIP_HORIZONTAL);
    maze[18] = load_image_mem(maze18,1078);//load_image( "maze/maze18.bmp" );
    maze[19] = flip_surface(maze[12],FLIP_HORIZONTAL);
    maze[20] = flip_surface(maze[8], FLIP_HORIZONTAL);
    maze[21] = flip_surface(maze[7], FLIP_HORIZONTAL);
    maze[22] = flip_surface(maze[6], FLIP_HORIZONTAL);
    maze[23] = load_image_mem(maze23,1078);//load_image( "maze/maze23.bmp" );
    maze[24] = flip_surface(maze[23], FLIP_HORIZONTAL);
    maze[25] = load_image_mem(maze24,1078);//load_image( "maze/maze24.bmp" );
    maze[26] = load_image_mem(maze26,1078);//load_image("maze/maze26.bmp");
    maze[27] = load_image_mem(maze27,1078);//load_image("maze/maze27.bmp");
    maze[28] = load_image_mem(maze28,1078);//load_image("maze/maze28.bmp");
    maze[29] = load_image_mem(maze29,1078);//load_image("maze/maze29.bmp");
    maze[30] = load_image_mem(maze30,1078);//load_image("maze/maze30.bmp");
    maze[31] = flip_surface(maze[28], FLIP_HORIZONTAL);
    maze[32] = flip_surface(maze[26], FLIP_HORIZONTAL);
    maze[33] = flip_surface(maze[6], FLIP_HORIZONTAL);
    maze[34] = flip_surface(maze[25], FLIP_HORIZONTAL);
    maze[35] = load_image_mem(maze31,1078);//load_image("maze/maze31.bmp");
    maze[36] = load_image_mem(maze32,1078);//load_image("maze/maze32.bmp");
    maze[37] = load_image_mem(maze32,1078);//load_image("maze/maze32.bmp");
    maze[38] = load_image_mem(maze37,1078);//load_image("maze/maze37.bmp");
    maze[39] = load_image_mem(maze38,1078);//load_image("maze/maze38.bmp");
    maze[40] = flip_surface(maze[39], FLIP_HORIZONTAL);
    maze[41] = flip_surface(maze[38], FLIP_HORIZONTAL);
    maze[42] = flip_surface(maze[35], FLIP_HORIZONTAL);
    maze[43] = load_image_mem(maze39,1078);//load_image("maze/maze39.bmp");
    maze[44] = flip_surface(maze[43], FLIP_HORIZONTAL);
    maze[45] = load_image_mem(maze40,1078);//load_image("maze/maze40.bmp");
    maze[46] = flip_surface(maze[45],FLIP_HORIZONTAL);
    maze[47] = load_image_mem(maze41,1078);//load_image("maze/maze41.bmp");
    maze[48] = flip_surface(maze[47],FLIP_HORIZONTAL);   
    maze[49] = load_image_mem(maze42,1078);//load_image("maze/maze42.bmp");
    maze[50] = load_image_mem(maze43,1078);//load_image("maze/maze43.bmp");
    maze[51] = load_image_mem(maze44,1078);//load_image("maze/maze44.bmp");
    maze[52] = load_image_mem(maze45,1078);//load_image("maze/maze45.bmp");
    maze[53] = load_image_mem(maze46,1078);//load_image("maze/maze46.bmp");
    maze[54] = load_image_mem(maze47,1078);//load_image("maze/maze47.bmp");
    maze[55] = flip_surface(maze[54],FLIP_HORIZONTAL);   
    maze[56] = flip_surface(maze[53],FLIP_HORIZONTAL); 
    maze[57] = flip_surface(maze[52],FLIP_HORIZONTAL); 
    maze[58] = flip_surface(maze[51],FLIP_HORIZONTAL);  
    maze[59] = flip_surface(maze[50],FLIP_HORIZONTAL);  
    maze[60] = flip_surface(maze[49],FLIP_HORIZONTAL);  
    maze[61] = flip_surface(maze[7],FLIP_HORIZONTAL); 
    maze[62] = load_image_mem(maze48,1078);//load_image("maze/maze48.bmp"); 
    maze[63] = load_image_mem(maze49,1078);//load_image("maze/maze49.bmp"); 
    maze[64] = flip_surface(maze[52],FLIP_VERTICAL); 
    maze[65] = flip_surface(maze[53],FLIP_VERTICAL); 
    maze[66] = load_image_mem(maze50,1078);//load_image("maze/maze50.bmp");
    maze[67] = flip_surface(maze[66],FLIP_HORIZONTAL); 
    maze[68] = flip_surface(maze[65],FLIP_HORIZONTAL); 
    maze[69] = flip_surface(maze[64],FLIP_HORIZONTAL); 
    maze[70] = flip_surface(maze[51],FLIP_HORIZONTAL); 
    maze[71] = flip_surface(maze[63],FLIP_HORIZONTAL); 
    maze[72] = flip_surface(maze[8],FLIP_HORIZONTAL); 
    maze[73] = load_image_mem(maze51,1078);//load_image("maze/maze51.bmp");
    maze[74] = flip_surface(maze[45],FLIP_VERTICAL); 
    maze[75] = flip_surface(maze[46],FLIP_VERTICAL);
    maze[76] = load_image_mem(maze52,1078);//load_image("maze/maze52.bmp");
    maze[77] = load_image_mem(maze53,1078);//load_image("maze/maze53.bmp");
    maze[78] = flip_surface(maze[77],FLIP_HORIZONTAL);
    maze[79] = flip_surface(maze[76],FLIP_HORIZONTAL);
    maze[80] = flip_surface(maze[75],FLIP_HORIZONTAL);
    maze[81] = flip_surface(maze[74],FLIP_HORIZONTAL);
    maze[82] = flip_surface(maze[73],FLIP_HORIZONTAL);
    maze[83] = load_image_mem(maze55,1078);//load_image("maze/maze55.bmp");
    maze[84] = flip_surface(maze[83],FLIP_HORIZONTAL);
    maze[85] = load_image_mem(maze56,1078);//load_image("maze/maze56.bmp");
    maze[86] = flip_surface(maze[85],FLIP_HORIZONTAL);
    maze[87] = flip_surface(maze[50],FLIP_HORIZONTAL);
    maze[88] = load_image_mem(maze58,1078);//load_image("maze/maze58.bmp");
    maze[89] = flip_surface(maze[51],FLIP_HORIZONTAL);
    maze[90] = load_image_mem(maze59,1078);//load_image("maze/maze59.bmp");
    maze[91] = load_image_mem(maze60,1078);//load_image("maze/maze60.bmp");
    maze[92] = flip_surface(maze[90],FLIP_HORIZONTAL);
    maze[93] = flip_surface(maze[88],FLIP_HORIZONTAL);
    maze[94] = flip_surface(maze[45],FLIP_VERTICAL);
    maze[95] = flip_surface(maze[46],FLIP_VERTICAL);
    maze[96] = flip_surface(maze[73],FLIP_HORIZONTAL);
    maze[97] = flip_surface(maze[12],FLIP_HORIZONTAL);
    maze[98] = flip_surface(maze[53],FLIP_HORIZONTAL);
    maze[99] = load_image_mem(maze61,1078);//load_image("maze/maze61.bmp");
    maze[100] = load_image_mem(maze62,1078);//load_image("maze/maze62.bmp");
    maze[101] = load_image_mem(maze63,1078);//load_image("maze/maze63.bmp");
    maze[102] = flip_surface(maze[101],FLIP_HORIZONTAL);
    maze[103] = flip_surface(maze[99],FLIP_HORIZONTAL);
    maze[104] = flip_surface(maze[53],FLIP_HORIZONTAL);
    maze[105] = flip_surface(maze[98],FLIP_HORIZONTAL);
    maze[106] = load_image_mem(maze64,1078);//load_image("maze/maze64.bmp");
    maze[107] = load_image_mem(maze65,1078);//load_image("maze/maze65.bmp");
    maze[108] = load_image_mem(maze66,1078);//load_image("maze/maze66.bmp");
    maze[109] = load_image_mem(maze67,1078);//load_image("maze/maze67.bmp");
    maze[110] = load_image_mem(maze68,1078);//load_image("maze/maze68.bmp");
    maze[111] = load_image_mem(maze69,1078);//load_image("maze/maze69.bmp");
    maze[112] = flip_surface(maze[111],FLIP_HORIZONTAL);
    maze[113] = flip_surface(maze[110],FLIP_HORIZONTAL);
    maze[114] = flip_surface(maze[108],FLIP_HORIZONTAL);
    maze[115] = flip_surface(maze[107],FLIP_HORIZONTAL);
    maze[116] = flip_surface(maze[106],FLIP_HORIZONTAL);
    maze[117] = load_image_mem(maze70,1078);//load_image("maze/maze70.bmp");
    maze[118] = load_image_mem(maze71,1078);//load_image("maze/maze71.bmp");
    maze[119] = load_image_mem(maze72,1078);//load_image("maze/maze72.bmp");
    maze[120] = flip_surface(maze[118],FLIP_HORIZONTAL);
    maze[121] = flip_surface(maze[117],FLIP_HORIZONTAL);
    maze[122] = load_image_mem(maze73,1078);//load_image("maze/maze73.bmp");
    maze[123] = load_image_mem(maze74,1078);//load_image("maze/maze74.bmp");
    maze[124] = load_image_mem(maze75,1078);//load_image("maze/maze75.bmp");
    maze[125] = flip_surface(maze[124],FLIP_HORIZONTAL);
    maze[126] = flip_surface(maze[122],FLIP_HORIZONTAL);
    maze[127] = load_image_mem(maze76,1078);//load_image("maze/maze76.bmp");
    maze[128] = flip_surface(maze[127],FLIP_HORIZONTAL);
    maze[129] = flip_surface(maze[126],FLIP_HORIZONTAL);
    maze[130] = flip_surface(maze[125],FLIP_HORIZONTAL);
    maze[131] = flip_surface(maze[124],FLIP_HORIZONTAL);
    maze[132] = flip_surface(maze[122],FLIP_HORIZONTAL);
    maze[133] = flip_surface(maze[123],FLIP_HORIZONTAL);
    maze[134] = load_image_mem(maze78,1078);//load_image("maze/maze78.bmp");
    maze[135] = flip_surface(maze[123],FLIP_VERTICAL);
    maze[136] = load_image_mem(maze79,1078);//load_image("maze/maze79.bmp");
    maze[137] = flip_surface(maze[134],FLIP_HORIZONTAL);
    maze[138] = flip_surface(maze[137],FLIP_HORIZONTAL);
    maze[139] = flip_surface(maze[134],FLIP_HORIZONTAL);

    for (int i=1;i< 139;i++)
    {
        if (maze[i] == NULL) return 0;
    }

    //maze[137] = turn_maze_white(maze[137]);
   
    for (int j=1;j < 139;j++)
    {
	mazewhite[j] = turn_maze_white(maze[j]);
    }

    return 1;
}

int deletemap()
{
    for (int i=1;i<139;i++)
    {
    	SDL_FreeSurface( maze[i] );
	if (mazewhite[i] == NULL) SDL_FreeSurface( mazewhite[i] );
    } 
    return 0;
}

int inipebbles()
{

    	//bigpebble = new solid();
	for (int bpbl=0;bpbl < 4;bpbl++)
	{
    		bigpebble[bpbl].frame.width =9;  
    		bigpebble[bpbl].frame.height=9; 
    		bigpebble[bpbl].frame.fos_x = 22;
    		bigpebble[bpbl].frame.fos_y = 74;
		bigpebble[bpbl].is_active = true;
	}

    	//pebble = new solid();
	for (int pbl=0;pbl < 244;pbl++)
	{
    		pebble[pbl].frame.width = 3;  
    		pebble[pbl].frame.height=3; 
    		pebble[pbl].frame.fos_x = 33;
    		pebble[pbl].frame.fos_y = 77;
    		pebble[pbl].x = 20;
   		pebble[pbl].y = 22;
	}
        for (int u=0;u<244;u++)
        {
   		pebble[u].is_visible = true;
    	}

    	for (int u2=0;u2<4;u2++)
    	{
   		bigpebble[u2].is_visible = true;
		bigpebble[u2].is_active = true;
    	}
	return 1;
}

int drawpebbles()
{
	int px=20,py=22;
	int pebcnt=0;
	int bpebcnt=0;

	if (peb_tmer.is_started() == false)
	{
		peb_tmer.start();
	}

	for (int yy=0;yy < 29; yy++)
	{
		for (int xx=0;xx < 26;xx++)
		{
			if (pebmap[yy][xx] == 1)
			{
				
				if (pebble[pebcnt].is_visible == true)
				{
					pebble[pebcnt].x = px;
					pebble[pebcnt].y = py;
					pebble[pebcnt].show(image,screen);
				}
				pebcnt++;
			
			}
			if (pebmap[yy][xx] == 2)
			{
				if (bigpebble[bpebcnt].is_active == true)
				{
				
					if (shwpeb == true)
					{				
						bigpebble[bpebcnt].x = px-3;
						bigpebble[bpebcnt].y = py-3;
						bigpebble[bpebcnt].show(image,screen);
					}
				}
				bpebcnt++;
				
			}
		
			px+=8;
		}
		px=20;
		py+=8;
	}
	if (peb_tmer.get_ticks() > 300.f)
	{
		if (shwpeb == false)
		{
			shwpeb=true;	
		} else {
			shwpeb=false;
		}
		peb_tmer.stop();
	}
	return 0;
}


int delpebs()
{
    	//delete(pebble);
    	//pebble=NULL;
    	//delete(bigpebble);
    	//bigpebble=NULL;
	return 0;
}
