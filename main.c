#include <stdio.h>
#include "main.h"
#include "action.h"

void initialisation(int morpion[3][3]){
  int i=0;
  int j=0;
  for (i=0; i<3; i++){ // 
    for (j=0; j<3; j++){
	morpion[i][j]=VIDE;
    }
  }
}

  // afficher la grille

void affichage(int morpion[3][3]){
  int i;
  int j=0;
  for (i=0; i<3; i++){ // Tableau 3x3 Avec affichage ligne colonnes séparé
    printf("\n%d | ", i+1); // Affichage de la ligne
    for (j=0; j<3; j++){
      switch(morpion[i][j]){
	
      case VIDE:
	printf("  | ");
	break;
      case CROIX:
	printf("X | ");
	break;
      case ROND:
	printf("O | ");
	break;
      }
    }
  }
  printf("\n    ");
  for(j=0; j<3; j++){ // Affichage des colonnes
    printf("%d   ",j+1); 
  }
  printf("\n\n"); // Retour de fin d'affichage
}

int main(){
  int morpion[3][3];
  int joueurActuel = ROND;
  int finDuJeu = 0;
  printf("\n**************************\n* On va faire un morpion *\n**************************\n");
  
  initialisation(morpion);
  while (finDuJeu == 0){
    affichage(morpion);
    tour(joueurActuel, morpion);
    if (joueurActuel == ROND) joueurActuel = CROIX;
    else if(joueurActuel == CROIX) joueurActuel = ROND;

    finDuJeu = finPartie(morpion); // On regarde si le jeu est terminé
  }

  printf("\n ** Coup gagnant ** \n");
  affichage(morpion);

  switch(finDuJeu){ // Affichage du vainqueur 
    
  case 1: 
    printf("Les RONDS gagnent !\n");
    break;
 
  case 2:
    printf("Les CROIX gagnent !\n");
    break;
   
  case 3:
    printf("Egalite: le morpion est plein !\n");
    break;
  }
 
  printf("\n \n *** FIN DE LA PARTIE ***\n \n");
  return 0;
}

