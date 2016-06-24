
life: main.o simmain.o calc_next.o edit_main.o 
	gcc main.o simmain.o calc_next.o edit_main.o -lncurses -o lifegame
	
main.o: main.c simmain.h lifegame.h
	gcc -c main.c -o main.o 

simmain.o: simmain.c lifegame.h simmain.h calc_next.h edit_main.h
	gcc -c simmain.c -o simmain.o  

calc_next.o: calc_next.c simmain.h lifegame.h calc_next.h  
	gcc -c calc_next.c -o calc_next.o

edit_main.o: edit_main.c lifegame.h edit_main.h simmain.h
	gcc -c edit_main.c -o edit_main.o
