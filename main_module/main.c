#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"simmain.h"
#include"lifegame.h"
#include"setting.h"
#include"helpshow.h"
#include"getsize.h"
void rand_life(LIFE life_pt[]){
		int i;
		srand((unsigned)time(NULL));
		for(i=0;i<LIFEMAXW*LIFEMAXH;i++){
				if((int)rand()%DENSITY==0)
						life_pt[i].live=1;
				else 
						life_pt[i].live=0;
				life_pt[i].x=i%LIFEMAXW+FORIGINX;
				life_pt[i].y=i/LIFEMAXW+FORIGINX;
		}

} 
void menu_show(int x,int y){
		clear();
		mvprintw(y/2-7,x/2-5,"Life Game!");
		mvprintw(y/2+5,x/2-5,"1:start simulation!");
		mvprintw(y/2+6,x/2-5,"2:settings");
		mvprintw(y/2+7,x/2-5,"3:help");
		mvprintw(y/2+8,x/2-5,"0:quit");
		refresh();

		return;
}
int main(int argc, char *argv[]){
		int MaxH,MaxW;
		int ch;
		int speed;
		FILE *fp;
		LIFE life_pt[LIFEMAXW*LIFEMAXH];
		rand_life(life_pt);
		initscr();
		crmode();
		noecho();
		cbreak();
		keypad(stdscr,TRUE);
		timeout(-1);
		speed=100000;
		clear();
		getmaxyx(stdscr,MaxH,MaxW);
		if(MaxH<LIFEMAXH||MaxW<LIFEMAXW+30){
				endwin();
				fprintf(stderr,"Run in larger size than %dColumns * %dlines\n",LIFEMAXW+30,LIFEMAXH);
				exit(1);
		}
				menu_show(MaxW,MaxH);
		while(ch!='0'){
				menu_show(MaxW,MaxH);
				ch=getch();
				if(ch=='1')simmain(life_pt,speed);
				if(ch=='2')setting_main(&speed);
				if(ch=='3')help_show();
				clear();

		}
		endwin();
		return 0;
}
