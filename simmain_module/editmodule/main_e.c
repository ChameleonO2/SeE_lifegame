#include"lifegame.h"
#include"simmain.h"
#include"edit_main.h"
#include<ncurses.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#define LIFEMAXW 150
#define LIFEMAXH 50 
#define FORIGINX 1
#define FORIGINY 1
#define SPEED 100000
#define DENSITY 10
extern void edit_main(LIFE []);


int main(int argc, char *argv[]){
	int MaxH,MaxW;						/*max high and width*/
	int i;
	LIFE life_pt[LIFEMAXW*LIFEMAXH];

	srand((unsigned)time(NULL));
	for(i=0;i<LIFEMAXW*LIFEMAXH;i++){
		if((int)rand()%DENSITY==0)
		life_pt[i].live=1;
		else 
		life_pt[i].live=0;
		life_pt[i].x=i%LIFEMAXW+FORIGINX;
		life_pt[i].y=i/LIFEMAXW+FORIGINX;
	}
	initscr();
	crmode();
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
	clear();
	if(argc>1){
		fprintf(stderr,"Don't use arguments\n");
		return 1;
	}
	timeout(0);
	clear();
	edit_main(life_pt);
	refresh();
	endwin();
	return 0;
}
