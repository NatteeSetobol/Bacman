#!/bin/sh
clear
g++ -g -o pacman main.c font.h maze.h pacman.h screen.h sprites.h sprites.cpp timer.h timer.cpp sdls.h sdls.c -lSDL -lSDL_image -lSDL_ttf
echo "done!"
