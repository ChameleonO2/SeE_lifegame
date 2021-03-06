#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"simmain.h"
#include"lifegame.h"
#include"setting.h"
#include"helpshow.h"
#include"getsize.h"
void rand_life(LIFE life_pt[]){
		int i;
		srand((unsigned)time(NULL));
		for(i=0;i<LIFEMAXW*LIFEMAXH;i++){
				if((int)rand()%DENSITY==0)
						life_pt[i].live=1;
				else 
						life_pt[i].live=0;
				life_pt[i].x=i%LIFEMAXW+FORIGINX;
				life_pt[i].y=i/LIFEMAXW+FORIGINX;
		}

} 
void menu_show(GAMEINFO dsp){
		clear();
		mvprintw(dsp.maxh/2-7,dsp.maxw/2-5,"Life Game!");
		mvprintw(dsp.maxh/2+5,dsp.maxw/2-5,"1:start simulation!");
		mvprintw(dsp.maxh/2+6,dsp.maxw/2-5,"2:settings");
		mvprintw(dsp.maxh/2+7,dsp.maxw/2-5,"3:help");
		mvprintw(dsp.maxh/2+8,dsp.maxw/2-5,"0:quit");
		refresh();
		return;
}
int main(int argc, char *argv[]){
		int MaxH,MaxW;
		int ch;
		FILE *fp;
		char tmp[100];
		GAMEINFO info;
		LIFE life_pt[LIFEMAXW*LIFEMAXH];


		/* error and read file */
		if(argc>1){
			fprintf(stderr,"引数を指定せずに実行してください．\n");
			exit(1);
		}
		if((fp=fopen("setting.lfs","r"))==NULL){
			fprintf(stderr,"setting.lfsファイルが見つかりません．自動生成します．\n");
			system("echo \"100000\">setting.lfs ");
			exit(1);
		}
		if(fgets(tmp,100,fp)!=NULL){
			printf("setting.lfs = %s\n",tmp);
			info.speed=atoi(tmp);
		}else{
			fclose(fp);
			fprintf(stderr,"setting.lfsファイルに異常があります．自動修正します．\n");
			system("echo \"100000\">setting.lfs ");
			exit(1);
		}
		fclose(fp);
		if(info.speed<5000||info.speed>600000){
			fprintf(stderr,"setting.lfsファイルに異常があります．自動修正します．\n");
			system("echo \"100000\">setting.lfs ");
			exit(1);
		}
		/* end of error and read file */
		rand_life(life_pt);
		initscr();
		crmode();
		noecho();
		cbreak();
		keypad(stdscr,TRUE);
		timeout(-1);
		clear();
		getmaxyx(stdscr,info.maxh,info.maxw);
		if(info.maxh < LIFEMAXH || info.maxw < LIFEMAXW+30){
				endwin();
				fprintf(stderr,"Run in larger size than %dColumns * %dlines\n",LIFEMAXW+30,LIFEMAXH);
				exit(1);
		}
		menu_show(info);
		while(ch!='0'){
				menu_show(info);
				ch=getch();
				if(ch=='1')simmain(life_pt,info);
				if(ch=='2')setting_main(&info);
				if(ch=='3')help_show();
				clear();

		}
		endwin();
		return 0;
}
