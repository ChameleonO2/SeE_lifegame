lifegame: getsize.o helpshow.o main.o setting.o simmain.o 
	gcc main.o setting.o helpshow.o getsize.o simmain.o -lncurses -o lifegame
getsize.o: getsize.c lifegame.h getsize.h
	gcc -c getsize.c -o getsize.o 
helpshow.o: helpshow.c lifegame.h helpshow.h
	gcc -c helpshow.c -o helpshow.o 
main.o: main.c simmain.h lifegame.h setting.h helpshow.h getsize.h
	gcc -c main.c -o main.o 
setting.o: setting.c lifegame.h setting.h
	gcc -c setting.c -o setting.o
simmain.o: simmain.c simmain.h lifegame.h
	gcc -c simmain.c -o simmain.o 
