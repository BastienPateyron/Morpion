all: jeu_morpion

jeu_morpion: main.o action.o
	gcc -o jeu_morpion main.o action.o

main.o: main.c main.h
	gcc -c main.c

action.o: action.c action.h main.h
	gcc -c action.c

