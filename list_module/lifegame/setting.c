#include"lifegame.h"
#include"setting.h"
#define NOMALSP 100000
#define FASTSP  50000
#define SLOWSP  200000

void setting_snow(GAMEINFO info){
	clear();
	mvprintw(info.maxh/2-10,info.maxw/2,"SETTING MODE");
	mvprintw(info.maxh/2-9,info.maxw/2,"space key: chage speed");
	mvprintw(info.maxh/2-8,info.maxw/2,"q key: eixt Setting mode and return title.");
	
	if(info.speed==NOMALSP){
		mvprintw(info.maxh/2,info.maxw/2,"NOMAL SPEED");
	}else if(info.speed==FASTSP){
		mvprintw(info.maxh/2,info.maxw/2,"FAST SPEED");
	}else if(info.speed==SLOWSP){
		mvprintw(info.maxh/2,info.maxw/2,"SLOW SPEED");
	}else if(info.speed>SLOWSP){
		mvprintw(info.maxh/2,info.maxw/2,"-SLOW SPEED");
	}else if(info.speed<FASTSP){
		mvprintw(info.maxh/2,info.maxw/2,"+FAST SPEED");
	}

	mvprintw(info.maxh/2+2,info.maxw/2,"%d",info.speed);
	refresh();
}
void setting_main(GAMEINFO* info){
	int ch;
	clear();
	setting_snow(*info);
	while((ch=getch())!='q'){
		if(ch==' '){
			if(info->speed==NOMALSP){
				info->speed=FASTSP;
				system("echo 50000>setting.lfs");
			}else if(info->speed==FASTSP){
				info->speed=SLOWSP;
				system("echo 200000>setting.lfs");
			}else if(info->speed==SLOWSP){
				info->speed=NOMALSP;
				system("echo 100000>setting.lfs");
			}else if(info->speed>SLOWSP){
				info->speed=SLOWSP;
				system("echo 200000>setting.lfs");
			}else if(info->speed<FASTSP){
				info->speed=FASTSP;
				system("echo 50000>setting.lfs");
			}
		}
		setting_snow(*info);
	}
	refresh();

	sleep(1);
	return;
}
