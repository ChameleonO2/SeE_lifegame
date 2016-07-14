lifegame: getsize.o helpshow.o main.o setting.o simmain.o calc_next.o edit_main.o 
	gcc main.o setting.o helpshow.o getsize.o simmain.o calc_next.o edit_main.o -lncursesw -o lifegame
getsize.o: getsize.c lifegame.h getsize.h
	gcc -c getsize.c -o getsize.o 
helpshow.o: helpshow.c lifegame.h helpshow.h
	gcc -c helpshow.c -o helpshow.o 
main.o: main.c simmain.h lifegame.h setting.h helpshow.h getsize.h
	gcc -c main.c -o main.o 

simmain.o: simmain.c lifegame.h simmain.h calc_next.h edit_main.h
	gcc -c simmain.c -o simmain.o  

calc_next.o: calc_next.c simmain.h lifegame.h calc_next.h  
	gcc -c calc_next.c -o calc_next.o

edit_main.o: edit_main.c lifegame.h edit_main.h simmain.h
	gcc -c edit_main.c -o edit_main.o

setting.o: setting.c lifegame.h setting.h
	gcc -c setting.c -o setting.o
