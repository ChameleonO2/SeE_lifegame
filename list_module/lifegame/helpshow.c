#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"lifegame.h"
#include"helpshow.h"

void help_show(void){
		FILE *fp2;
		char msg[200];
		int ch;
		int i;
		clear();
		if((fp2=fopen("help.lfg","r"))==NULL){
				endwin();
				fprintf(stderr,"help.lfg is not found.\n");
				exit(1);
		}
		while(fgets(msg,100,fp2)!=NULL){
				mvprintw(5+i,10,"%s",msg);
				i++;
				refresh();
				if(msg[0]=='#'){
						while((ch=getch())!=' ');
						clear();
						i=0;
				}
		}
		fclose(fp2);
		while((ch=getch())!=' ');
		refresh();
		return;
}
