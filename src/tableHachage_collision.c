#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listSimpleChain_collision.h"
#include "tableHachage_collision.h"
#include "fonctionHachage.h"

int hachageFinal(char* mot, int tailleTable,int numFonction){
	if (numFonction == 1){
		return(hachageNaif(mot,tailleTable));
	}else if(numFonction == 2){
		return(hachagePoids(mot,tailleTable));
	}else if(numFonction == 3 ){
		return(hachageRec(mot,tailleTable));
	}else if (numFonction == 4){
		return(sha1ReduitModulo(mot,tailleTable));
	}else if (numFonction == 5){
		return(sha1ReduitPoids(mot,tailleTable));
	}else if (numFonction == 6){
		return(sha1ReduitXor(mot,tailleTable));
	}
	else{
		return(-1);
	}
}

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
    int n =(int) strlen(s);
    while (s[i] != '\0'){
        cpt += (int)s[i]*psc(5,(int)(n-i)/2);
        i++;
    }
    cpt += n;
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
	int n = strlen(s);
    while (s[i] != '\0'){
        cpt += (int)s[i]*psc(5,(int)(n-i)/2);
        i++;
    }
    cpt += n;
	cpt=f4(cpt);
    cpt = cpt % mod;
    return cpt;
}


TableHachage tableHachage_creer(int tailleTableau){ //malloc
	if (tailleTableau <=0){
		return(NULL);
	}
	TableHachage table = (TableHachage)malloc(sizeof(tableHachage)); //On alloue pour initialiser la table de hachage
	table->tailleTableau=tailleTableau;
	table->tableauListe=list_creer();
	celulle *cel = table->tableauListe;
	cel->nextWord = NULL; //ICI
	for (int i=0; i<tailleTableau; i++){
		cel->suiv = (celulle*)malloc(sizeof(celulle)); //On alloue pour créer une case de la table
		cel = cel->suiv;
		cel->val =(ELEMENT*)malloc(sizeof(ELEMENT)); //On alloue pour pouvoir enregistrer les informations d'un mot
		cel->val->clef = (char*)malloc(sizeof(char)*80);
		cel->val->nbnote = 0;
		cel->val->moy = 0;
		cel->nextWord = NULL; //ICI
	}
	cel->suiv=NULL;
	return(table);
}

void tableHachage_visualiser(TableHachage t){
	list_visualiser(t->tableauListe);
} 

void freeTable(TableHachage table){
    if (table->tailleTableau <=0){
        return;
    }
    celulle* cel = table->tableauListe;
    celulle* tempCel;
    nextWord* tempNextword;
    nextWord* next;
    while (cel != NULL){
        next= cel -> nextWord;
        while (next != NULL){
            free(next->val->clef);
            free(next->val);
            tempNextword=next;
            free(tempNextword);
            next=next->nextWord;
        }
        free(cel->val->clef);
        free(cel->val);
        tempCel = cel;
        free(tempCel);
        cel=cel->suiv;
    }
    free(table);
}

ELEMENT* tableHachage_get(Clef c, TableHachage t,int numFonction){ // ELEMENT = CLEF VALEUR
	//Liste liste = t->tableauListe;
	celulle* cel=t->tableauListe;
	int hachcode = hachageFinal(c, t->tailleTableau,numFonction);
	for (int i = 0; i < hachcode; i++){
		cel=cel->suiv;
	}
	if (cel->val->clef != NULL){ //On a un problème de collision, on va jusqu'à la fin de la sous-table pour ajouter l'element e
		if (!strcmp(cel->val->clef,c)){
			return cel->val;
		}
		if(cel->nextWord!=NULL){ //Sous-table de couche 1
			next* nextW=cel->nextWord;
			if (!strcmp(nextW->val->clef,c)){
				return nextW->val;
			}
			while (nextW->nextWord != NULL){ //Sous-table de couche n
				nextW = nextW->nextWord;
				if (!strcmp(nextW->val->clef,c)){
					return nextW->val;
				}
			}
		}
	}
	ELEMENT* nul = (ELEMENT*) malloc(sizeof(ELEMENT));
	nul->clef = NULL;
	nul->nbnote = 0;
	nul->moy=0;
	return(nul);
}

ELEMENT* tableHachage_getHash(Clef c, TableHachage t,int hash){ // ELEMENT = CLEF VALEUR
	//Liste liste = t->tableauListe;
	celulle* cel=t->tableauListe;
	int hachcode = hash;
	for (int i = 0; i < hachcode; i++){
		cel=cel->suiv;
	}
	if (cel->val->clef != NULL){ //On a un problème de collision, on va jusqu'à la fin de la sous-table pour ajouter l'element e
		if (!strcmp(cel->val->clef,c)){
			return cel->val;
		}
		if(cel->nextWord!=NULL){ //Sous-table de couche 1
			next* nextW=cel->nextWord;
			if (!strcmp(nextW->val->clef,c)){
				return nextW->val;
			}
			while (nextW->nextWord != NULL){ //Sous-table de couche n
				nextW = nextW->nextWord;
				if ((nextW->val) != NULL){
					if (!strcmp(nextW->val->clef,c)){
						return nextW->val;
					}
				}
			}
		}
	}
	ELEMENT* nul = (ELEMENT*) malloc(sizeof(ELEMENT));
	nul->clef = NULL;
	nul->nbnote = 0;
	nul->moy=0;
	return(nul);
}



void tableHachage_supprime(Clef clef, TableHachage t,int numFonction){ 
	celulle* cel = t->tableauListe;
	for (int i=0; i<hachageFinal(clef, t->tailleTableau,numFonction); i++)
		cel=cel->suiv;
	cel->val->clef = NULL;
	cel->val->nbnote = 0;
	cel->val->moy = 0;
}

void nombre_soustable(TableHachage t){
	celulle* suite = t->tableauListe;
	next* sous_suite;
	int i;
	while ( suite != NULL ){
		i=0;
		if (suite->val->nbnote !=0){
			i =1;
		}
		sous_suite = suite ->nextWord;
		while (sous_suite != NULL){
			sous_suite = sous_suite->nextWord;
			i++;
		}
		printf("%d\n",i);
		suite=suite->suiv;
	}
}













































