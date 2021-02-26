#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "listSimpleChain.h"
#include "tableHachage.h"
#include "fonctionHachage.h"

int hachageNaif(char *s, int mod){
    int i = 0, cpt = 0;
    while (s[i] != '\0'){
        cpt += (int)s[i];
        i++;
    }
    cpt += strlen(s);
    cpt = cpt % mod;
    return cpt;
}

int hachagePoids(char *s, int mod){
    int i = 0, cpt = 0; 
    int n =strlen(s);
    while (s[i] != '\0'){
        cpt += (int)s[i]*psc(5,n-i);
        i++;
    }
    cpt += strlen(s);
    cpt = cpt % mod;
    return cpt;
}

int hachage2(char *s, int mod){
    int i = 0, cpt = 0;
    while (s[i] != '\0'){
        cpt += (int)s[i]*(int)s[i]+i;
        i++;
    }
    cpt += strlen(s);
    cpt = cpt % mod;
    return cpt;
}

int f4(int x){
	if (x==0){
		return(0);
	}else{
		return(8*f4(x/2)+x);
	}
}

int hachageRec(char *s, int mod){
    int i = 0, cpt = 0;
    while (s[i] != '\0'){
        cpt +=f4(s[i]);
        i++;
    }
    cpt += strlen(s);
    cpt = cpt % mod;
    return cpt;
}


TableHachage tableHachage_creer(int tailleTableau){ //malloc
	if (tailleTableau <=0){
		return(NULL);
	}
	TableHachage table = malloc(sizeof(tableHachage));
	table->tailleTableau=tailleTableau;
	table->tableauListe=list_creer();
	celulle *cel = table->tableauListe;
	for (int i=0; i<tailleTableau; i++){
		cel->suiv = malloc(sizeof(celulle));
		cel = cel->suiv;
		cel->val.clef = NULL;
		cel->val.nbnote = 0;
		cel->val.moy = 0;
	}
	cel->suiv=NULL;
	return(table);
}

void tableHachage_visualiser(TableHachage t){
	list_visualiser(t->tableauListe);
} 

ELEMENT tableHachage_get(Clef c, TableHachage t){ // ELEMENT = CLEF VALEUR
	Liste liste = t->tableauListe;
	ELEMENT* nul = (ELEMENT*) malloc(sizeof(ELEMENT));
	nul->clef = NULL;
	nul->nbnote = 0;
	nul->moy=0;
	if (c==NULL){
		return(*nul);
	}
	while (liste != NULL ){
		if (liste->val.clef != NULL){
			if (!strcmp(liste->val.clef,c)){
				return(liste->val);
			}
		}liste=liste->suiv;
	}
	//free(nul);
	return(*nul);
}

void tableHachage_ajout(ELEMENT e, TableHachage t){
	if (e.clef==NULL){
		return;
	}
	celulle* cel=t->tableauListe;
	for (int i =0; i<hachage2(e.clef, t->tailleTableau);i++){
			cel=cel->suiv;
	}
	if (cel->val.nbnote != 0)
	{
		if (strcmp(cel->val.clef, e.clef) != 0)
		{
			//printf("Collision entre '%s' et '%s'\n", cel->val.clef, e.clef);
		}
	}
	cel->val = e;	
}

void tableHachage_supprime(Clef clef, TableHachage t){ 
	celulle* cel = t->tableauListe;
	for (int i=0; i<hachage2(clef, t->tailleTableau); i++)
		cel=cel->suiv;
	cel->val.clef = NULL;
	cel->val.nbnote = 0;
	cel->val.moy = 0;
}











































