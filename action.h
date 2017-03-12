#include <stdio.h>
#include "main.h"

void tour (int joueurActuel,int morpion[3][3]);
int finPartie(int morpion[3][3]);
int ligne(int morpion[3][3], int ligne);
int colonne(int morpion[3][3], int colonne);

int horizontal(int morpion[3][3]);
int vertical(int morpion[3][3]);
int diagonale(int morpion[3][3]);
int plein(int morpion[3][3]);
