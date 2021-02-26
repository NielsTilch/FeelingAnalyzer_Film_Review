#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "listSimpleChain_str.h"

ListeStr listStr_creer(void) {
	ListeStr list_vide = (ListeStr)malloc(sizeof(cell));
	list_vide->val = NULL;
	list_vide->suiv = NULL;
	return list_vide;
}

int listStr_estVide(ListeStr L) {
	if (L->val == NULL && L->suiv == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int listStr_size(ListeStr L) {
	if (listStr_estVide(L)) {
		return 0;
	} else if (L->suiv == NULL) {
		return 1;
	} else {
		return 1 + listStr_size(L->suiv);
	}
}

void listStr_ajoutFin(ListeStr L, ELMT e) {
	if (listStr_estVide(L)) {
		L->val = e;
		L->suiv = NULL;
		return;
	} 
	ListeStr cell = L;
	while (cell->suiv != NULL) {
		cell = cell->suiv;
	}
	ListeStr fin_list = listStr_creer();
	fin_list->val = e;
	cell->suiv = fin_list;
}

void listStr_affiche(ELMT e) {
	printf("%s", e);
}

void listStr_visualiser(ListeStr L) {
	ListeStr cell = L;
	while (cell != NULL) {
	 	listStr_affiche(cell->val);
	 	printf(" ");
		cell = cell->suiv;
	} 
	printf("\n");
}

void freeListStr(ListeStr L) {
	ListeStr cell = L;
	ListeStr temp;
	while (cell != NULL) {
		temp = cell;
		cell = cell->suiv;
		free(temp);
	}
}