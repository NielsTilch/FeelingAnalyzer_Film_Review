#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "statistics.h"
#include "fonctionHachage.h"
#include "HashProg_collision.h"
#include "tableHachage_collision.h"
#include "listSimpleChain_collision.h"
#include "listSimpleChain_float.h"
#include "listSimpleChain_int.h"
#include "listSimpleChain_str.h"
#include "arbresFloat.h"
#include "arbres.h"


node* avl_sortedOccurrence(TableHachage tab) {
	int N = tab->tailleTableau;
	Liste list = tab->tableauListe;
	ELEMENT* elmt = list->val;
	next* nextW = list->nextWord;
	node* avl = new_binary_tree(elmt->nbnote);
	node* temp;
	for (int i = 0; i < N; i++){
		if (elmt->nbnote != 0){
			temp = AVL_add(avl, elmt->nbnote);
			avl = temp;
		}
		while (nextW != NULL && nextW->val->nbnote != 0){
			temp = AVL_add(avl, nextW->val->nbnote);
			avl = temp;
			nextW = nextW->nextWord;
		}
		list = list->suiv;
		elmt = list->val;
	}		
	return avl;
}

ListeInt list_sortedOccurrence(node* bst) {
	ListeInt list = listInt_creer();
	if (isEmpty(bst)){
		return list;
	} else if (!hasLeft(bst) && !hasRight(bst)){
		list->val = bst->value;
		return list;
	} else {
		ListeInt L1 = list_sortedOccurrence(bst->son_l);
		listInt_ajoutFin(L1, bst->value);
		ListeInt L2 = list_sortedOccurrence(bst->son_r);
		return concat(L1, L2);
	}
}

ListeStr getSameOcurrenceWords(TableHachage tab, int occurrence) {
	ListeStr words = listStr_creer();
	int N = tab->tailleTableau;
	Liste list = tab->tableauListe;
	ELEMENT* elmt = list->val;
	next* nextW = list->nextWord;
	for (int i = 0; i < N; i++){
		if (elmt->nbnote == occurrence) {
			listStr_ajoutFin(words, elmt->clef);
		}
		while (nextW != NULL){
			if ((nextW->val)->nbnote == occurrence) {
				listStr_ajoutFin(words, (nextW->val)->clef);	
			}
			nextW = nextW->nextWord;
		}
		list = list->suiv;
		elmt = list->val;
	}	
	return words;	
}

int getTableNumberWords(TableHachage tab) {
	int N = tab->tailleTableau;
	Liste list = tab->tableauListe;
	ELEMENT* elmt;
	next* nextW;
	int res = 0;
	//int sum = 0;
	elmt = list->val;
	for (int i = 0; i < N; i++){
		if (elmt->nbnote != 0){
			res++;
			//sum = sum + elmt->nbnote;
		} nextW = list->nextWord;
		while (nextW != NULL){
			//sum = sum + (nextW->val)->nbnote;
			res++;
			nextW = nextW->nextWord;
		}
		list=list->suiv;
		elmt = list->val;
		
	}
	//printf("Le nombre de note est : %d\n",sum);	
	return res;	
}

char** orderedWords(TableHachage tab) {
	//int N = getTableNumberWords(tab);
	char** array = (char**)malloc(getTableNumberWords(tab)*sizeof(char*));
	int k = 0;
	node* avl = avl_sortedOccurrence(tab);
	ListeInt list_occurrences = list_sortedOccurrence(avl); // liste des occurrences triées
	int n = listInt_size(list_occurrences); // nombre d'occurrences différentes
	//printf("n = %d\n", n);
	int m;
	int cpt = 0;
	ListeStr list_words;
	for (int i = 0; i < n; i++){
		list_words = getSameOcurrenceWords(tab, list_occurrences->val);
		m = listStr_size(list_words);
		//printf("m = %d\n", m);
		cpt = cpt + m;
		for (int j = 0; j < m; j++){
			array[k] = (char*)malloc(sizeof(char)*(1+strlen(list_words->val)));
			strcpy(array[k], list_words->val);
			k++;
			list_words = list_words->suiv;
		}
		list_occurrences = list_occurrences->suiv;
	} //printf("Le compteur est de %d\n", cpt);
	return array;
}

void print_leastRecurrentWords(TableHachage tab, int n) {
	char** motsTries = orderedWords(tab);
	printf("Les mots les moins présents sont :\n");
	for (int i = 0; i < n; i++){
		printf("%s\n", motsTries[i]);
	}
}

int size_orderedWords(TableHachage tab) {
	char** motsTries = orderedWords(tab);
	int k = 0;
	while (motsTries[k] != NULL) {
		k++;
	}
	return k-1;
}

void print_mostRecurrentWords(TableHachage tab, int n) {
	int N = size_orderedWords(tab);
	printf("N = %d\n", N);
	char** motsTries = orderedWords(tab);
	printf("Les mots les plus présents sont :\n");
	for (int i = 0; i < n; i++){
		printf("%s\n", motsTries[N-i]);
	}	
}

nodeFloat* avl_sortedScore(TableHachage tab) {
	int N = tab->tailleTableau;
	Liste list = tab->tableauListe;
	ELEMENT* elmt = list->val;
	next* nextW = list->nextWord;
	nodeFloat* avl = new_binary_tree_float(elmt->moy);
	nodeFloat* temp;
	for (int i = 0; i < N; i++) {
		if (elmt->nbnote != 0){
			temp = AVL_addFloat(avl, elmt->moy);
			avl = temp;
		}
		while (nextW != NULL && nextW->val->nbnote != 0) {
			temp = AVL_addFloat(avl, (nextW->val)->moy);
			avl = temp;
			nextW = nextW->nextWord;
		}
		list = list->suiv;
		elmt = list->val;
	}		
	return avl;
}

ListeFloat list_sortedScore(nodeFloat* bst) {
	ListeFloat list = listFloat_creer();
	if (isEmptyFloat(bst)) {
		return list;
	} else if (!hasLeftFloat(bst) && !hasRightFloat(bst)) {
		list->val = bst->value;
		return list;
	} else {
		ListeFloat L1 = list_sortedScore(bst->son_l);
		listFloat_ajoutFin(L1, bst->value);
		ListeFloat L2 = list_sortedScore(bst->son_r);
		return listFloat_concat(L1, L2);
	}
}

char** getWords(TableHachage tab, float min, float max) {
	char** words = (char**)malloc(getTableNumberWords(tab)*sizeof(char*));
	int k = 0;
	int N = tab->tailleTableau;
	nodeFloat* avl = avl_sortedScore(tab);
	ListeFloat listScores = list_sortedScore(avl); // liste des scores triées
	while (listScores->val < min && listScores != NULL) {
		listScores = listScores->suiv;
	}
	while (listScores->val < max && listScores != NULL) {
		Liste list = tab->tableauListe;
		ELEMENT* elmt = list->val;
		next* nextW = list->nextWord;
		for (int i = 0; i < N; i++) {
			if (elmt->moy == listScores->val) {
				words[k] = (char*)malloc(sizeof(char)*(1+strlen(elmt->clef)));
				strcpy(words[k], elmt->clef);
				k++;
			}
			while (nextW != NULL) {
				if ((nextW->val)->moy == listScores->val) {
					words[k] = (char*)malloc(sizeof(char)*(1+strlen((nextW->val)->clef)));
					strcpy(words[k], (nextW->val)->clef);
					k++;
				}
				nextW = nextW->nextWord;
			} 
			list = list->suiv;
			elmt = list->val;
		}
		listScores = listScores->suiv;
	}
	return words;
}

void print_words(TableHachage tab, float min, float max) {
	char** words = getWords(tab, min, max);
	int k = 0;
	while (words[k] != NULL) {
		printf("%s\n", words[k]);
		k++;
	}
}

float averageScore(TableHachage tab) {
	int N = tab->tailleTableau;
	Liste list = tab->tableauListe;
	ELEMENT* elmt = list->val;
	next* nextW;
	float sum = 0;
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (elmt->nbnote != 0) {
			sum += elmt->nbnote * elmt->moy;
			res += elmt->nbnote;
		} nextW = list->nextWord;
		while (nextW != NULL) {
			sum += nextW->val->nbnote * nextW->val->moy;
			res += nextW->val->nbnote;
			nextW = nextW->nextWord;
		}
		list = list->suiv;
		elmt = list->val;
	}
	return sum/res;
}