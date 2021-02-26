#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listSimpleChain_int.h"

ListeInt listInt_creer(void) {
	cellule* list_vide = (cellule*)malloc(sizeof(cellule));
	list_vide->val = 0;
	list_vide->suiv = NULL;
	return list_vide;
}

int listInt_estVide(ListeInt L) {
	if (L->val == 0 && L->suiv == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int listInt_size(ListeInt L) {
	if (listInt_estVide(L)) {
		return 0;
	} else if (L->suiv == NULL) {
		return 1;
	} else {
		return 1 + listInt_size(L->suiv);
	}
}

void listInt_ajoutFin(ListeInt L, int v) {
	if (listInt_estVide(L)) {
		L->val = v;
		return;
	} 
	ListeInt cell = L;
	while (cell->suiv != NULL) {
		cell = cell->suiv;
	}
	ListeInt new_cell = listInt_creer();
	new_cell->val = v;
	cell->suiv = new_cell;
}

ListeInt copy(ListeInt L) {
	ListeInt new = listInt_creer();
	ListeInt cell = L;
	while (cell != NULL) {
		listInt_ajoutFin(new, cell->val);
		cell = cell->suiv;
	}
	return new;
}

ListeInt concat(ListeInt L1, ListeInt L2) {
	if (listInt_estVide(L1)) {
		return copy(L2);
	} else if (listInt_estVide(L2)) {
		return copy(L1);
	}
	ListeInt L3 = copy(L1);
	ListeInt L = copy(L2);
	ListeInt temp = L3;
	while (temp->suiv != NULL) {
		temp = temp->suiv;
	}
	while (L != NULL) {
		temp->suiv = L;
		L = L->suiv;
		temp = temp->suiv;
	}
	temp->suiv = NULL;
	return L3;
}

void listInt_affiche(int v) {
	printf("%d", v);
}

void listInt_visualiser(ListeInt L) {
	ListeInt cell = L;
	while (cell != NULL) {
	 	listInt_affiche(cell->val);
		cell = cell->suiv;
		printf(" ");
	} 
	printf("\n");
}

void freeList(ListeInt L) {
	ListeInt cell = L;
	ListeInt temp;
	while (cell != NULL) {
		temp = cell;
		cell = cell->suiv;
		free(temp);
	}
}