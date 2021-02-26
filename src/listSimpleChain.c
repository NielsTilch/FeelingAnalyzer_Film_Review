#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listSimpleChain.h"


Liste list_creer(void){
	//ELEMENT val = malloc(sizeof(ELEMENT));
	Liste list = malloc(sizeof(celulle));
	list->suiv=NULL;
	list->val.clef=NULL;
	list->val.nbnote=0; 
	list->val.moy=0;   
	return(list);
}

int list_estVide(Liste L){
	if (L->val.clef == NULL && L->suiv == NULL){
		return(1);
	}else{
		return(0);
	}
}

Liste list_ajoutTete(Liste L, ELEMENT e){
	if (list_estVide(L)){
		L->val=e;
		return(L);
	}else{
		celulle* cel = malloc(sizeof(celulle));
		cel->val = e;
		cel->suiv = L;
		Liste nvListe = cel;  	
		return(nvListe);
	}
}

void list_ajoutFin(Liste L, ELEMENT e){
	if(list_estVide(L)){
		L->val = e;
		return ;
	}
	celulle* c = L;
	while(c->suiv != NULL){
		c = c->suiv;
	}celulle* nouv = malloc(sizeof(celulle));
	nouv->val = e;
	nouv->suiv = NULL;
	c->suiv = nouv;
}

void list_ajoutN(Liste L, ELEMENT e, int n){  
	celulle* c = L;
	if (n<0){
		printf("L'indice est négatif");
		return;
	}
	if (n==0){
		celulle* nouv = malloc(sizeof(celulle));
		nouv->val = c->val;
		nouv->suiv = c->suiv;
		c->val=e;
		c->suiv = nouv; 
		return;	
	}
	for (int k=0; k<n; k++){
		c=c->suiv;
		if 	(c == NULL){
			printf("L'indice est trop grand.\n");
			return;
		}
	}
	celulle* nouv = malloc(sizeof(celulle));
	nouv->val = e;
	nouv->suiv = c->suiv;
	c->suiv = nouv; 
}

int size(Liste L){
	int compteur = 0;
	celulle* liste = L;
	while (liste != NULL){
		liste = liste->suiv;
		compteur++;
	}
	return(compteur);
}

Liste list_removeN(Liste L,int n){            /// position= indice
	int compteur = 0;
	celulle* suite = L;
	while (compteur != n-1){
		suite = suite->suiv;
		compteur++;
	}
	celulle* temp = suite->suiv;
	suite->suiv = temp->suiv;
	free(temp);
	return(L);
}

void list_affiche(ELEMENT e){
	printf("(%s;Mot : %s et Nombre de note %d et Moyenne de %f)",e.clef,e.clef,e.nbnote,e.moy);
}

void list_visualiser(Liste L){
	celulle* suite = L;
	printf("[");
	while ( suite != NULL ){
		list_affiche(suite->val);
		suite=suite->suiv;
		if (suite !=  NULL){
			printf(",");
		}
	}
	printf("]\n");
}

































