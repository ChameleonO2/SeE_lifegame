#include"lifegame.h"
#include"list.h"



void list_main(LIFE life_pt[]){
	int cnt;//count files
	FILE *list;
	system("ls ./list/*.lf>>tmp.lft");
	if((list=fopen("tmp.lft","r"))==NULL){ 
		endwin();
		fprintf(stderr,"tmp.lfファイルが見つかりません．\n");
		exit(1);
	}
	fclose(list);
}
int main(){
		system("ls");
		return 0;
}
