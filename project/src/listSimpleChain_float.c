#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listSimpleChain_float.h"

ListeFloat listFloat_creer(void) {
	ListeFloat list_vide = (ListeFloat)malloc(sizeof(celluleFloat));
	list_vide->val = 0;
	list_vide->suiv = NULL;
	return list_vide;
}

int listFloat_estVide(ListeFloat L) {
	if (L->val == 0 && L->suiv == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int listFloat_size(ListeFloat L) {
	if (listFloat_estVide(L)) {
		return 0;
	} else if (L->suiv == NULL) {
		return 1;
	} else {
		return 1 + listFloat_size(L->suiv);
	}
}

void listFloat_ajoutFin(ListeFloat L, float v) {
	if (listFloat_estVide(L)) {
		L->val = v;
		L->suiv = NULL;
		return;
	}
	ListeFloat cell = L;
	while (cell->suiv != NULL) {
		cell = cell->suiv;
	}
	ListeFloat new_cell = listFloat_creer();
	new_cell->val = v;
	cell->suiv = new_cell;
}

ListeFloat listFloat_copy(ListeFloat L) {
	ListeFloat new = listFloat_creer();
	ListeFloat cell = L;
	while (cell != NULL) {
		listFloat_ajoutFin(new, cell->val);
		cell = cell->suiv;
	}
	return new;
}

ListeFloat listFloat_concat(ListeFloat L1, ListeFloat L2) {
	if (listFloat_estVide(L1)) {
		return listFloat_copy(L2);
	} else if (listFloat_estVide(L2)) {
		return listFloat_copy(L1);
	}
	ListeFloat L3 = listFloat_copy(L1);
	ListeFloat L = listFloat_copy(L2);
	ListeFloat temp = L3;
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

void listFloat_affiche(float v) {
	printf("%f", v);
}

void listFloat_visualiser(ListeFloat L) {
	ListeFloat cell = L;
	while (cell != NULL) {
	 	listFloat_affiche(cell->val);
		cell = cell->suiv;
		printf(" ");
	} 
	printf("\n");
}

void freeListFloat(ListeFloat L) {
	ListeFloat cell = L;
	ListeFloat temp;
	while (cell != NULL) {
		temp = cell;
		cell = cell->suiv;
		free(temp);
	}
}