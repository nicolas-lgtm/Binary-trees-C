#pragma once
#pragma warning(disable:4996)
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct res {
	int setJ1;//remporter 2 ou 3 sets pour gagner le match
	int jeuJ1;//gagner 2 jeux de plus que son adversaire avec au moins 6 jeux au total pour remporter le set

	int setJ2;
	int jeuJ2;
} res;

typedef struct noeud {
	int genre;
	noeud* gauche;
	noeud* droit;
	int index; //Permet de différencier les différentes branches de l'arbre


	int setJ1;//remporter 2 ou 3 sets pour gagner le match
	int jeuJ1;//gagner 2 jeux de plus que son adversaire avec au moins 6 jeux au total pour remporter le set

	int setJ2;
	int jeuJ2;
	int branche;
} noeud;



int EstPuissanceDe2(int v);
void AjouterNoeud(noeud** a_arbre, int a_genre, int index, int nbMatchs);
	void AfficheArbre(noeud* Arbre);
void GenrerScores(noeud* arbre);