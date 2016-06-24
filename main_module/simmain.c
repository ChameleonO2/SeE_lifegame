#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include"simmain.h"
#include"lifegame.h"

void simmain(LIFE life_pt[],int SPEED){
		mvprintw(10,10,"simmain now%d",SPEED);
		simshow();
		print_life(life_pt);
		refresh();
		sleep(1);
		return;
}
void simshow(){

		mvprintw(11,10,"simshow now");
		return;
}
void print_life(LIFE life_pt[]){
		mvprintw(12,10,"print_life now");
		
		return;

}
