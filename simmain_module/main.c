#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"simmain.h"
#include"lifegame.h"


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
	/* life_pt[320].live=0;life_pt[321].live=1;life_pt[322].live=0; */
	/* life_pt[470].live=0;life_pt[471].live=1;life_pt[473].live=0; */
	/* life_pt[620].live=0;life_pt[621].live=1;life_pt[623].live=0; */
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
	simmain(life_pt,100000);
	getmaxyx(stdscr,MaxH,MaxW);
	clear();
	mvprintw(0,0,"h%d :w%d\n",MaxH,MaxW);
	refresh();
	sleep(1);
	endwin();
	return 0;
}
