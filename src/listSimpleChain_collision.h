#ifndef DIRECTORY_h
#define DIRECTORY_h

typedef char* Clef;

//-------------------------------------------------------------------

//Structure permettant de stocker les informations d'un mot.

/*Initialement sans un mot, la structure est :
	Clef = NULL
	nbnote=0
	moy=0
*/

typedef struct ELEMENTTable{
	Clef clef; //Le mot
	int  nbnote; //Le nombre de fois où le mot a été repéré
	float moy; //La moyenne du mot calculé
}ELEMENT;

typedef struct _next next;

//-------------------------------------------------------------------

//Structure permettant de stocker une "case" mémoire contenant un pointeur vers les informations d'un mot
//et les sous-tables (s'il plusieurs mots ont un hachcode).
//Cette structure concerne les sous-tables.

/*Initialement sans un mot ayant ce hachcode, on a :
	val = (pointe une structure ELEMENT avec un mot)
	nextWord = NULL
*/

typedef struct _next{
	ELEMENT* val;
	next* nextWord;
}nextWord;

//-------------------------------------------------------------------

//Structure permettant de stocker une "case" mémoire contenant un pointeur vers les informations d'un mot
//et les sous-tables (s'il plusieurs mots ont un hachcode).

/*Initialement sans un mot ayant ce hachcode, on a :
	val = (pointe une structure ELEMENT sans mot)
	suiv = |pointe vers le prochain hachcode (Si n'est pas en bout de table)
		   |NULL (Sinon)
	nextWord = NULL
*/

typedef struct celulle{
	ELEMENT* val;
	struct celulle* suiv;
	next* nextWord;
}celulle;

//-------------------------------------------------------------------

typedef celulle* Liste;

Liste list_creer(void);
//Créer une structure renvoyant le début d'une table de hachcode

int list_estVide(Liste L);
Liste list_ajoutTete(Liste L, ELEMENT* e);
void list_ajoutFin(Liste L, ELEMENT* e);
void list_ajoutN(Liste L, ELEMENT* e, int n);
ELEMENT list_rechN(Liste L, ELEMENT* e, int n);
ELEMENT list_rech(Liste L, ELEMENT* e);
Liste list_remove(Liste L, ELEMENT* e);
Liste list_removeN(Liste L,int n);
void list_affiche(ELEMENT* e);
void list_visualiser(Liste L);
//La fonction permet de visualiser une table de hachage
//Entrée : Une talbe de hachage

int size(Liste L);
//Permet de connaitre la taille de la table de hachage
//Entrée : Une table de hachage
//Sortie : Un entier, la taille de la table de hachage

void freeListe(Liste L);



#endif
