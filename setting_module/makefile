lifegame: main.o setting.o
	gcc main.o setting.o -lncurses -o lifegame
main.o: main.c lifegame.h setting.h
	gcc -c main.c -o main.o
setting.o: setting.c lifegame.h setting.h
	gcc -c setting.c -o setting.o
