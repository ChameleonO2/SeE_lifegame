#include"lifegame.h"
#include"edit_main.h"
#include"simmain.h"
#include<ncurses.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#define SPEED 100000

void edit_show(LIFE life_pt[],CURSOR c){
	simshow();
	print_life(life_pt);
	mvprintw(c.y,c.x,"X");
	return;
}
int toggle_life(int live){
	if(live==0)return 1;
	else return 0;
}
void rand_life2(LIFE life_pt[]){
		int i;
		srand((unsigned)time(NULL));
		for(i=0;i<LIFEMAXW*LIFEMAXH;i++){
				if((int)rand()%DENSITY==0)
						life_pt[i].live=1;
				else 
						life_pt[i].live=0;
		}
	return;
}
void clear_life(LIFE life_pt[]){
		int i;
		for(i=0;i<LIFEMAXW*LIFEMAXH;i++){
				life_pt[i].live=0;
		}
		return ;
}
void outlife(LIFE life_pt[]){
	char str[10];
	int i;
	for(i=0;i<LIFEMAXH*LIFEMAXW;i++){
		sprintf(str,"echo %d >> lifedate.ld",life_pt[i].live);
		system(str);
	}
}
void edit_main(LIFE life_pt[]){
	int ch,xy;
	CURSOR c;
	c.x=FORIGINX;
	c.y=FORIGINY;
	clear();
	timeout(-1);
	while(ch!='s'){
			/*cursor keys */
		if(ch==KEY_DOWN)c.y++;
		if(ch==KEY_UP)c.y--;
		if(ch==KEY_RIGHT)c.x++;
		if(ch==KEY_LEFT)c.x--;
		if(c.x-FORIGINX>=LIFEMAXW)c.x=FORIGINX;
		if(c.y-FORIGINY>=LIFEMAXH)c.y=FORIGINY;
		if(c.x-FORIGINX<0)c.x=LIFEMAXW;
		if(c.y-FORIGINY<0)c.y=LIFEMAXH;
			/*end cursor keys */
		xy=(c.y-1)*LIFEMAXW+c.x-1;
		edit_show(life_pt,c);
		mvprintw(LIFEMAXH/2-10,LIFEMAXW+5,"EDIT MODE");
		mvprintw(LIFEMAXH/2-5,LIFEMAXW+5,"LIFE STATUS");
		mvprintw(LIFEMAXH/2-4,LIFEMAXW+5,"(%3d,%2d)=%d",life_pt[xy].x,life_pt[xy].y,life_pt[xy].live);
		mvprintw(LIFEMAXH/2+1,LIFEMAXW+5,"s key :End Edit Mode and Go to Simulation!");
		mvprintw(LIFEMAXH/2+2,LIFEMAXW+5,"r key :Random set Life!");
		mvprintw(LIFEMAXH/2+3,LIFEMAXW+5,"c key :All Clear Life!");
		mvprintw(LIFEMAXH/2+4,LIFEMAXW+5,"Cursor keys :Move Cursor(X)");
		mvprintw(LIFEMAXH/2+5,LIFEMAXW+5,"Space key :toggle Life and Death");
		ch=getch();
		if(ch==' ')life_pt[xy].live=toggle_life(life_pt[xy].live); 
		if(ch=='r')rand_life2(life_pt);
		if(ch=='c')clear_life(life_pt);
		if(ch=='p')outlife(life_pt);
	}
	timeout(0);
	return ;
}

