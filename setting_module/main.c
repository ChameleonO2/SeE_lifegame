#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"lifegame.h"
#include"setting.h"
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
		LIFE life_pt[LIFEMAXW*LIFEMAXH];
		GAMEINFO info;
		info.speed=1000000;
		info.maxh=50;
		info.maxw=100;
		rand_life(life_pt);
		initscr();
		crmode();
		noecho();
		cbreak();
		keypad(stdscr,TRUE);
		timeout(-1);
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
				if(ch=='2')setting_main(&info);
				clear();
		}
		endwin();
		return 0;
}
