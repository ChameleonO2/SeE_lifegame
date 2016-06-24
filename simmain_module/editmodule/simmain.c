#include"lifegame.h"
#include"simmain.h"
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#define LIFEMAXW 150
#define LIFEMAXH 50 
#define FORIGINX 1
#define FORIGINY 1
#define SPEED 100000
void print_life (LIFE []);
void simshow(void);
void simmain(LIFE []);
void print_field(void){
	int i;
	for(i=0;i<=LIFEMAXH+2;i++){
		/* mvprintw(i,0,"%d",i); */
		mvaddch(i,0,'|');
		mvaddch(i,LIFEMAXW+2,'|');
	}
	for(i=1 ;i<LIFEMAXW+2;i++){
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
int stopmode(void){
	int ch;
	simshow();
	while(1){
		ch=getch();
		if(ch=='s')return 0;
		if(ch=='q')return 1;
		usleep(1);
	}
}
void print_life(LIFE life_pt[]){
	int i;
	for(i=0;i<LIFEMAXH*LIFEMAXW;i++){
		if(life_pt[i].live==1)mvprintw(life_pt[i].y,life_pt[i].x,"O");
		if(life_pt[i].live==0)mvprintw(life_pt[i].y,life_pt[i].x," ");
	}
}
void simmain(LIFE life_pt[]){
	int cntgn=0;
	int ch;
	clear();
	simshow();
	/* while(1){	 */
	/* 	ch = getch(); */
	/* 	simshow(); */
	/* 	print_life(life_pt); */
	/* 	cntgn++; */
	/* 	mvprintw(14,156,"s key : you can stop simlation!",cntgn); */
	/* 	mvprintw(25,156,"%d generation",cntgn); */
	/* 	refresh(); */
	/* 	if(ch == 's'){ */
	/* 		if(stopmode()==1)return; */
	/* 	}else{ */
	/* 		calc_nextGN(life_pt); */
        /*  */
	/* 	} */
	/* 	usleep(SPEED); #<{(| speed |)}># */
	/* } */
	refresh();
	return;
}
