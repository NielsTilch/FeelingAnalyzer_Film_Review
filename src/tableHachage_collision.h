#ifndef tableHachage_collision_h
#define tableHachage_collision_h
#include "listSimpleChain_collision.h"


typedef struct tableHachageStruct {
	Liste tableauListe;
	int tailleTableau;
}tableHachage;


typedef tableHachage* TableHachage;


//Les différentes fonctions de hachage.

int hachageFinal(char* mot, int tailleTable, int numFonction);
int psc(int a, int b);
int hachageNaif(char *s, int mod);
int hachagePoids(char *s, int mod);
int f4(int x);
int hachageRec(char *s, int mod);


TableHachage tableHachage_creer(int tailleTableau);
//Entrée : Un entier correspondant à la taille du tableau de hachage
//Sortie : Une table de Hachage de taille 'tailleTableau'.

ELEMENT* tableHachage_get(Clef c, TableHachage t,int numFonction);
//Fonction qui cherche le mot s'il existe ou non.
/* Entrée : 
	- Une cle représentant le mot
	- La table de Haschage
	- Un entier, visant à dire quelle fonction de hachage utilisée.

Sortie : Un pointeur vers les informations du mot (si elles existent)
*/

ELEMENT* tableHachage_getHash(Clef c, TableHachage t,int hash);

void tableHachage_supprime(Clef clef, TableHachage t,int numFonction);
//La fonction permet de supprimer le mot voulu dans la table de Hachage.
/* Entrée : 
	- Une cle représentant le mot
	- La table de Haschage
	- Un entier, visant à dire quelle fonction de hachage utilisée.
*/

void tableHachage_visualiser(TableHachage t);
//Le fonction permet d'afficher l'ensemble des mots et des informations de la table de hachage.
//Entrée : Une table de hachage

void nombre_soustable(TableHachage t);
//La fonction permet de calcule la nombre de sous-table (évaluation des collisions)
//Entrée : Une table de hachage

void freeTable(TableHachage t);
//La fonction permet de supprimer une table de hachageet sa place mémoire.
//Entrée : Une table de hachage


ELEMENT* tableHachage_getELISA(Clef c, TableHachage t,int numFonction);

#endif
