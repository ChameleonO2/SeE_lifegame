#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"lifegame.h"
#include"setting.h"
#define NOMALSP 100000
#define FASTSP  50000
#define SLOWSP  200000

void setting_snow(GAMEINFO info){
		clear();
		if(info.speed==NOMALSP){
				mvprintw(info.maxh/2,info.maxw/2,"NOMAL SPEED");
		}else if(info.speed==FASTSP){
				mvprintw(info.maxh/2,info.maxw/2,"FAST SPEED");
		}else if(info.speed==SLOWSP){
				mvprintw(info.maxh/2,info.maxw/2,"SLOW SPEED");
		}

		refresh();
}
void setting_main(GAMEINFO* info){
		int ch;
		clear();
		mvprintw(10,10,"setting_main now");
		info->speed=NOMALSP;
		setting_snow(*info);
		while((ch=getch())!='q'){
				if(ch==' '){
						if(info->speed==NOMALSP){
								info->speed=FASTSP;
						}else if(info->speed==FASTSP){
								info->speed=SLOWSP;
						}else if(info->speed==SLOWSP){
								info->speed=NOMALSP;
						}
				}
				setting_snow(*info);
		}
		refresh();

		sleep(1);
		return;
}
