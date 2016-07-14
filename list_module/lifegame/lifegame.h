#ifndef LIFEGAME_H
#define LIFEGAME_H

/* lifegame.h */
#define LIFEMAXW 150
#define LIFEMAXH 50 
#define FORIGINX 1
#define FORIGINY 1
#define DENSITY 9
#define SETTING_LFS
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<locale.h>
#include<unistd.h>
#include<time.h>

typedef struct{
	int x;
	int y;
	int live;
}LIFE;
typedef struct{
	int maxh;
	int maxw;
	int speed;
}GAMEINFO;

#endif

