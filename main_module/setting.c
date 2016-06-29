#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"lifegame.h"
#include"setting.h"

void setting_main(GAMEINFO* info){
		clear();
		mvprintw(10,10,"setting_main now");
		info->speed=200000;
		refresh();

		sleep(1);
		return;
}
