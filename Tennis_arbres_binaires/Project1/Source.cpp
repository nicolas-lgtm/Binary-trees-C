#include "header.h"

void main() {
	srand(time(NULL));
	noeud* arbre = NULL;
	int nbMatchs;

	do {
		printf("Combien de matchs jouer ? (doit etre une puissance de 2)\n");
		scanf("%d", &nbMatchs);
		system("cls");
	} while (!EstPuissanceDe2(nbMatchs));

	for (size_t i = 0; i < nbMatchs; i++)
	{
		int genre;
		int matchIndex = i + 1;

		do {
			printf("Choisir si le match %d est feminin (taper 1) ou masculin (taper 2) :\n", matchIndex);
			scanf("%d", &genre);
			AjouterNoeud(&arbre, genre, matchIndex, nbMatchs);
			system("cls");
		} while (genre < 1 || genre > 2);
	}

	printf("Appuyez sur \"ENTREE\" pour generer les matchs\n");
	system("pause");

	AfficheArbre(arbre);
}

void AjouterNoeud(noeud** a_arbre, int a_genre, int index, int nbMatchs) {
	noeud* tempNoeud;
	noeud* tempArbre = *a_arbre;
	noeud* elem = (noeud*)malloc(sizeof(noeud));
	elem->genre = a_genre;
	elem->index = index;
	elem->droit = NULL;
	elem->gauche = NULL;

	if (tempArbre) //Si l'arbre a bien un noeud racine 
	{
		do {
			tempNoeud = tempArbre; // tmpNoeud permettra de rester au niveau juste au-dessus (parent) de ce qu'on parcours avec tmpArbre, comme ça si un fils est vide on a toujours la référence du parent existant et on peut insérer dans un nœud fils vide si besoin.
			if (index <= nbMatchs / 2)
			{
				tempArbre = tempArbre->gauche; // Si oui alors on va dans le fils gauche du noeud actuel
				if (!tempArbre)
				{
					tempNoeud->gauche = elem;// Maintenant qu'on s'est déplacé dans son fils gauche, si il n'y a rien, on place notre nouveau noeud ici.

				}
			}
			else //Si ce n'est pas plus grand que la valeur du noeud actuel alors on part vers la gauche
			{
				tempArbre = tempArbre->droit;
				if (!tempArbre) tempNoeud->droit = elem;
			}
		} while (tempArbre);
	}
	else *a_arbre = elem;
}

int EstPuissanceDe2(int x) {
	return (x != 0) && ((x & (x - 1)) == 0); //https://stackoverflow.com/questions/600293/how-to-check-if-a-number-is-a-power-of-2
}

void AfficheArbre(noeud* Arbre)
{
	if (!Arbre) return;

	if (Arbre->droit)  AfficheArbre(Arbre->droit);

	system("cls");

	if (Arbre->genre == 1) {
		printf("Match feminin:\n");
	}
	else {
		printf("Match masculin:\n");
	}

	GenrerScores(Arbre);

	if (Arbre->gauche) AfficheArbre(Arbre->gauche);
}

void GenrerScores(noeud* Arbre) {

	int _setJ1 = Arbre->setJ1;
	int _setJ2 = Arbre->setJ2;

	_setJ1 = 0;
	_setJ2 = 0;

	int _jeuJ1 = Arbre->jeuJ1;
	int _jeuJ2 = Arbre->jeuJ2;

	_jeuJ1 = 0;
	_jeuJ2 = 0;

	do {
		int r = (rand() % 2) + 1;

		if (r == 1) {
			_jeuJ1++;
		}
		else {
			_jeuJ2++;
		}

		if (_jeuJ1 >= 6 && (_jeuJ1 - _jeuJ2 >= 2)) {
			_setJ1++;
			printf("Jeux J1 = %d ; Jeux J2 = %d\n\n", _jeuJ1, _jeuJ2);
			_jeuJ1 = 0;
			_jeuJ2 = 0;
		}
		else if (_jeuJ2 >= 6 && (_jeuJ2 - _jeuJ1 >= 2)) {
			_setJ2++;
			printf("Jeux J1 = %d ; Jeux J2 = %d\n\n", _jeuJ1, _jeuJ2);
			_jeuJ2 = 0;
			_jeuJ1 = 0;
		}

	} while (_setJ1 < (Arbre->genre) + 1 && _setJ2 < (Arbre->genre) + 1);
	//Tant que le nombre de sets remportés n'est pas au moins égal à 6 et qu'il n'y a pas 2 de différence entre les deux joueurs, on continue la "partie"

	printf("Sets J1 = %d\nSets J2 = %d\n\n", _setJ1, _setJ2);
	if (_setJ1 > _setJ2) {
		printf("Joueur 1 remporte la partie !\n\n\n");
	}
	else {
		printf("Joueur 2 remporte la partie !\n\n\n");
	}
	system("pause");
}