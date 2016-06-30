#include"lifegame.h"
#include"simmain.h"
#include"calc_next.h"
#include"edit_main.h"
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
void print_field(void){
	int i;
	for(i=0;i<=LIFEMAXH+1;i++){
			/* mvprintw(i,0,"%d",i); */
			mvaddch(i,0,'|');
			mvaddch(i,LIFEMAXW+1,'|');
	}
	for(i=1 ;i<=LIFEMAXW;i++){
		/* addstr("-"); */
		/* mvprintw(0,i,"%d",i%10); */
		mvaddch(0,i,'-');
		mvaddch(LIFEMAXH+1,i,'-');
	}
	return;

}	
void simshow(void){
	int i,j;
	print_field();
	refresh();
	return;
}
void print_life(LIFE life_pt[]){
	int i;
	for(i=0;i<LIFEMAXH*LIFEMAXW;i++){
		if(life_pt[i].live==1)mvprintw(life_pt[i].y,life_pt[i].x,"O");
		if(life_pt[i].live==0)mvprintw(life_pt[i].y,life_pt[i].x," ");
	}
}
int stopmode(LIFE life_pt[],int *cnt){
	int ch;
	simshow();
	mvprintw(LIFEMAXH/2-10,LIFEMAXW+5,"STOP SIMULATION");
	mvprintw(LIFEMAXH/2+1,LIFEMAXW+5,"e key :Go to Edit mode!");
	mvprintw(LIFEMAXH/2+2,LIFEMAXW+5,"q key :End Simulation!");
	while(1){
		ch=getch();
		if(ch=='s'){
			clear();
				return 0;
		}
		if(ch=='q')return 1;
		if(ch=='e'){
			edit_main(life_pt);
			clear();
			simshow();
			mvprintw(LIFEMAXH/2-10,LIFEMAXW+5,"STOP SIMULATION");
			mvprintw(LIFEMAXH/2,LIFEMAXW+5,"s key :toggle stop simulation!");
			mvprintw(LIFEMAXH/2+1,LIFEMAXW+5,"e key :Go Edit mode!");
			mvprintw(LIFEMAXH/2+2,LIFEMAXW+5,"q key :End Simulation");
			print_life(life_pt);
			*cnt=0;
			mvprintw(LIFEMAXH/2-1,LIFEMAXW+5,"%d generation",*cnt);
		}
		usleep(1);
	}
}
void simmain(LIFE life_pt[],GAMEINFO info){
	int cntgn=0;
	int remode;
	int ch;
	clear();
	while(1){	
		ch = getch();
		simshow();
		print_life(life_pt);
		cntgn++;
		mvprintw(LIFEMAXH/2-10,LIFEMAXW+5,"     SIMULATION");
		mvprintw(LIFEMAXH/2,LIFEMAXW+5,"s key :toggle stop simulation!");
		mvprintw(LIFEMAXH/2-1,LIFEMAXW+5,"%d generation",cntgn);
		refresh();
		if(ch == 's'){
			if(stopmode(life_pt,&cntgn)==1){
				return;
			}

		}else{
			calc_nextGN(life_pt);

		}
		usleep(info.speed); /* speed */
	}
	refresh();
	return;
}
