#ifndef LIFEGAME_H
#define LIFEGAME_H

/* lifegame.h */
#define LIFEMAXW 150
#define LIFEMAXH 50 
#define FORIGINX 1
#define FORIGINY 1
#define DENSITY 9
#define SETTING_LFS

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

