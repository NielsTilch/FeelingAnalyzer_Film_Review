#ifndef listSimpleChain_float_h
#define listSimpleChain_float_h

typedef struct celluleFloat {
	float val;
	struct celluleFloat* suiv;
} celluleFloat;

typedef celluleFloat* ListeFloat;

ListeFloat listFloat_creer(void);
int listFloat_estVide(ListeFloat L);
int listFloat_size(ListeFloat L);
void listFloat_ajoutFin(ListeFloat L, float v);
ListeFloat listFloat_copy(ListeFloat L);
ListeFloat listFloat_concat(ListeFloat L1, ListeFloat L2);
void listFloat_affiche(float v);
void listFloat_visualiser(ListeFloat L);
void freeListFloat(ListeFloat L);

#endif