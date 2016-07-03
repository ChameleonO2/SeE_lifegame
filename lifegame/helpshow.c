#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"lifegame.h"
#include"helpshow.h"

void help_show(void){
				clear();
		mvprintw(10,10,"help_show now");
		refresh();

		sleep(1);
		return;
}
