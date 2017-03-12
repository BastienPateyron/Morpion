#include <stdio.h>
#include "main.h"
#include "action.h"

void tour(int joueurActuel,int morpion[3][3]){
  int ligne;
  int colonne;
  int saisieValide = 0;
  while(!saisieValide){
    if (joueurActuel == ROND){
      printf("Au tour des RONDS de jouer: (ligne colonne) \n");
      scanf("%d%d", &ligne, &colonne);
      if(morpion[ligne-1][colonne-1]==VIDE){
	saisieValide = 1;
	morpion[ligne-1][colonne-1]=ROND;
      }
    }
    else if (joueurActuel == CROIX){
      printf("Au tour des CROIX de jouer: (ligne colonne)\n");
      scanf("%d%d", &ligne, &colonne);
      if(morpion[ligne-1][colonne-1]==VIDE){
	saisieValide = 1;
	morpion[ligne-1][colonne-1]=CROIX;
      }
    }
  }
}

int ligne(int morpion[3][3],int ligne ){ // Prend un tableau et un indce de ligne puis retourne 0, 1 ou 2 // TODO .h
  
  int TLigne[3];// Tableau caractéristique
  int j;
  int gagnant=0;
  int cell=0;
  
  for(j=0; j<3; j++){
    TLigne[j]=0; // initialisation des cases du tableau a 0
  }
  for(j=0; j<3; j++){ // Parcours de la ligne du morpion
    TLigne[morpion[ligne][j]]++; // On compte le nombre d'elem de la ligne
  }

  for(j=0; j<3; j++){
    if(TLigne[j]==3) gagnant = j; // On affecte le numero du joueur
  }
  return gagnant; 
}


int colonne(int morpion[3][3], int colonne){ // TODO - update .h

  
  int TColonne[3];// Tableau caractéristique
  int i;
  int gagnant=0;
  
  for(i=0; i<3; i++){
    TColonne[i]=0; // initialisation des cases du tableau a 0
  }
  for(i=0; i<3; i++){ // Parcours de la colonne du morpion
    TColonne[morpion[i][colonne]]++; // On compte le nombre d'elem de la col
  }
  
  i=0;
  while(gagnant == 0 && i<3){
    if(TColonne[i]==3) gagnant = i; // Si on a 3 elements, retourne le joueur
    i++;
  }

  return gagnant;  
}


int horizontal(int morpion[3][3]){ // Retourne le nb du gagnant horizontal
  int i=0;
  int gagnant =0;
  
  while(gagnant==0 && i<3){
    gagnant = ligne(morpion,i); // Cherche gagnant ligne i
    i++;
  }
  
  return gagnant; 
}

int vertical(int morpion[3][3]){ // Retourne le nb du gagnant vertical
  int j=0;
  int gagnant=0;
  
  while(gagnant==0 && j<3){
    gagnant = colonne(morpion,j); // Cherche gagnant colonne j
    j++;
  }
  
  return gagnant; 
}


// A Ameliorer !!!! -----
int diagonale(int morpion[3][3]){ // Retourne 0 si il n'y en a pas, ou 1/2 si il y en a
  int dg=morpion[0][0]; // droite a gauche
  int gd=morpion[0][2]; // gauche a droite
  int resultat=0;
  int i;
  
  //Droite à gauche
  for(i=1; i<3; i++){ 
    if(dg != morpion[i][i]){
      dg = 0;
      break; // on sort de la boucle
    }
  }

  // Gauche à droite
  for(i=1; i<3; i++){ 
    if(gd != morpion[i][2-i]){
      gd = 0;
      break; 
    }
  }
  
  // Test des resultats
  if(dg != 0) resultat = dg;
  else if(gd != 0) resultat = gd;

  return resultat;
}

// Devrait marcher mais peut etre amélioré avec ligne() et colonne()
int plein(int morpion[3][3]){// retourne 1 si plein, 0 sinon -- todo
  int i=0;
  int j;
  int plein=1; // On dit que le morpion est plein
  
  while (i<3 && plein != 0){ // TQ on a pas fait tt les lignes et que le morpion est plein
    j=0; // Réinitilasition de J a chaque passage dans i
    while (j<3 && plein != 0){
      if(morpion[i][j] == VIDE) plein = 0; // Si case vide, plein recoit 0
      j++;
    }
    i++;
  }
  return plein;
}


int finPartie(int morpion[3][3]){ // Teste les conditions de fin de partie et retourne le gagnant
  // Déterminer la fin du jeu ? 3 symbole aligné || toute case remplie
  int i;
  int j;
  int gagnant = 0; // 0, jeu continue, 1 Rond gagne, 2 Croix gagne, 3 Plein
  int line=0;
  int col=0;
  int diag=0;
  int full = 0;
  // Vérifier avec horizontal(), vert() et diag()
  
  line = horizontal(morpion);
  col = vertical(morpion);
  diag = diagonale(morpion);
  full = plein(morpion);
  
  // printf(" line: %d\n col: %d\n diag: %d\n full: %d\n", line, col, diag, full);

  if(line != 0) gagnant = line;
  else if(col != 0) gagnant = col;
  else if(diag != 0) gagnant = diag;
  else if(full == 1) gagnant = 3;
  else gagnant = 0;
  

  return gagnant;
}


