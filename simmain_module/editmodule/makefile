test: main_e.o simmain.o edit_main.o
	gcc  main_e.o simmain.o edit_main.o -lncurses -o test 
main_e.o: main_e.c lifegame.h simmain.h edit_main.h
	gcc -lncurses -c main_e.c -o main_e.o 
edit_main.o: edit_main.c lifegame.h simmain.h
	gcc -c edit_main.c -o edit_main.o -lncurses

simmain.o: simmain.c lifegame.h simmain.h
	gcc -c simmain.c -o simmain.o -lncurses


