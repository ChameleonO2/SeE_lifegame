#include"simmain.h"
#include"calc_next.h"
#include"lifegame.h"
#include<ncurses.h>
#include<unistd.h>

void calc_nextGN(LIFE []);
int cnt_life(LIFE[] ,int);


void calc_nextGN(LIFE life_pt[]){
	int i;
	LIFE next_pt[LIFEMAXH*LIFEMAXW];
	for(i=0;i<LIFEMAXW*LIFEMAXH;i++){
	if(cnt_life(life_pt,i)<2)next_pt[i].live=0;
	else if(cnt_life(life_pt,i)==3)next_pt[i].live=1;
	else if(cnt_life(life_pt,i)==2)next_pt[i].live=life_pt[i].live;
	else if(cnt_life(life_pt,i)>3)next_pt[i].live=0;
	}
	for(i=0;i<LIFEMAXW*LIFEMAXH;i++){
		life_pt[i].live=next_pt[i].live;
	}
	
}


int cnt_life(LIFE life_pt[],int pt){
	int cnt=0;
	int i;
	int line;
	int explorer;
	/* search up */
	explorer=pt-LIFEMAXW;
	if(explorer < 0)explorer+=LIFEMAXW*LIFEMAXH;
	if(explorer%LIFEMAXW != 0 && explorer % LIFEMAXW != (LIFEMAXW-1)%LIFEMAXW){
		for(i=0;i<3;i++){
			if(life_pt[explorer-1+i].live == 1)cnt++;
		}
	}
	else if(explorer%LIFEMAXW == 0){
		if(life_pt[explorer-1+LIFEMAXW].live ==1)cnt++;
		for(i=0;i<2;i++){
			if(life_pt[explorer+i].live == 1)cnt++;
		}
	}
	else if(explorer%LIFEMAXW == (LIFEMAXW-1)%LIFEMAXW){
		if(life_pt[explorer+1-LIFEMAXW].live ==1)cnt++;
		for(i=0;i<2;i++){
			if(life_pt[explorer-1+i].live == 1)cnt++;
		}
	}
	/* serch mid */
	explorer=pt;
	if(explorer%LIFEMAXW != 0 && explorer % LIFEMAXW != (LIFEMAXW-1)%LIFEMAXW){
			if(life_pt[explorer-1].live == 1)cnt++;
			if(life_pt[explorer+1].live == 1)cnt++;
	}
	else if(explorer%LIFEMAXW == 0){
		if(life_pt[explorer-1+LIFEMAXW].live ==1)cnt++;
			if(life_pt[explorer+1].live == 1)cnt++;
	}
	else if(explorer%LIFEMAXW == (LIFEMAXW-1)%LIFEMAXW){
		if(life_pt[explorer+1-LIFEMAXW].live ==1)cnt++;
		if(life_pt[explorer-1].live == 1)cnt++;
	}

	/* serch down */
	explorer=pt+LIFEMAXW;
	if(explorer >= LIFEMAXW*LIFEMAXH )explorer-=LIFEMAXW*LIFEMAXH;
	if(explorer%LIFEMAXW != 0 && explorer % LIFEMAXW != (LIFEMAXW-1)%LIFEMAXW){
		for(i=0;i<3;i++){
			if(life_pt[explorer-1+i].live == 1)cnt++;
		}
	}
	else if(explorer%LIFEMAXW == 0){
		if(life_pt[explorer-1+LIFEMAXW].live ==1)cnt++;
		for(i=0;i<2;i++){
			if(life_pt[explorer+i].live == 1)cnt++;
		}
	}
	else if(explorer%LIFEMAXW == (LIFEMAXW-1)%LIFEMAXW){
		if(life_pt[explorer+1-LIFEMAXW].live ==1)cnt++;
		for(i=0;i<2;i++){
			if(life_pt[explorer-1+i].live == 1)cnt++;
		}
	}
	return cnt;
}
