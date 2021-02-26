#ifndef listSimpleChain_int_h
#define listSimpleChain_int_h

typedef struct cellule {
	int val;
	struct cellule* suiv;
} cellule;

typedef cellule* ListeInt;

ListeInt listInt_creer(void);
int listInt_estVide(ListeInt L);
int listInt_size(ListeInt L);
void listInt_ajoutFin(ListeInt L, int v);
ListeInt copy(ListeInt L);
ListeInt concat(ListeInt L1, ListeInt L2);
void listInt_affiche(int v);
void listInt_visualiser(ListeInt L);
void freeList(ListeInt L);

#endif