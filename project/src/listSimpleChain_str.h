#ifndef listSimpleChain_str_h
#define listSimpleChain_str_h

typedef char* ELMT;

typedef struct cell {
	ELMT val;
	struct cell* suiv;
} cell;

typedef cell* ListeStr;

ListeStr listStr_creer(void);
int listStr_estVide(ListeStr L);
int listStr_size(ListeStr L);
void listStr_ajoutFin(ListeStr L, ELMT e);
void listStr_affiche(ELMT e);
void listStr_visualiser(ListeStr L);
void freeListStr(ListeStr L);

#endif