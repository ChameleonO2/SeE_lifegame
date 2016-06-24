#include"lifegame.h"
#include"edit_main.h"
#include"simmain.h"
#include<ncurses.h>
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
void edit_main(LIFE life_pt[]){
	int ch,xy;
	CURSOR c;
	c.x=FORIGINX;
	c.y=FORIGINY;
	clear();
	timeout(-1);
	while(ch!='s'){
		if(ch==KEY_DOWN)c.y++;
		if(ch==KEY_UP)c.y--;
		if(ch==KEY_RIGHT)c.x++;
		if(ch==KEY_LEFT)c.x--;
		if(c.x-FORIGINX>=LIFEMAXW)c.x=FORIGINX;
		if(c.y-FORIGINY>=LIFEMAXH)c.y=FORIGINY;
		if(c.x-FORIGINX<0)c.x=LIFEMAXW;
		if(c.y-FORIGINY<0)c.y=LIFEMAXH;
		xy=(c.y-1)*LIFEMAXW+c.x-1;
		edit_show(life_pt,c);
		ch=getch();
		if(ch==' ')life_pt[xy].live=toggle_life(life_pt[xy].live);
	}
	timeout(0);
	return ;
}

