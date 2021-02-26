#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fonctionHachage.h"
#include "listSimpleChain_collision.h"
#include "HashProg_collision.h"
#include "tableHachage_collision.h"
#include "analyseTable.h"

float tpsRechercheMot(TableHachage tab, char* nomFichier, int numFonction){
	double tmax,tmin;
	printf("On rentre dans tempsRemplissageTable avec les paramêtres suivant, nomFichier ='%s', numéro de fonction = %d\n",nomFichier,numFonction);
	///ELEMENT* eget;
	FILE* fichier = fopen(nomFichier,"r");
	clock_t t1,t2;
	float res =0;
	char ligne[500];
	int k =1;
	int hash;
	char* retourLigne;
	int nbMot=0;
	while (fgets(ligne, 500, fichier) != NULL) {
		retourLigne = strchr(ligne,'\n');
		if (retourLigne != NULL){
			*retourLigne='\0';
		}
		k++;
		ligne[strnlen(ligne, 500)] = '\0';
		char* ligneMin = maj2min(ligne);
		char* ligneSansNb = removeNumber(ligneMin);
		char** mots = split(ligneSansNb);                       
		int i = 1;
		while (mots[i] != NULL) {
			if (strcmp(mots[i], "&") == 0){
				hash=hachageFinal("and",tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash(mots[i],tab,hash);
				tableHachage_getHash(mots[i],tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				nbMot++;
				i++;
			}else if ( strcmp(mots[i],"") == 0 || (int)mots[i][0] == 10 ){
				i++;
			}
			/* Si un mot est un symbol mathématique, on ne l'ajoute pas dans la table */
			else if (strcmp(mots[i], "+") == 0 || strcmp(mots[i], "=") == 0){
				i++;
			} 
			/* Si un mot est une contraction, alors on ajoute sont équivalent dans la table */
			else if (strcmp(mots[i], "m") == 0){
				hash=hachageFinal("am",tab->tailleTableau,numFonction);
				t1= clock();
				//eget=tableHachage_getHash("am",tab,hash);
				tableHachage_getHash("am",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				nbMot++;
				i++;
			} 
			else if (strcmp(mots[i], "re") == 0){
				hash=hachageFinal("are",tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash("are",tab,hash);
				tableHachage_getHash("are",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				nbMot++;
				i++;
			} 
			else if (strcmp(mots[i], "ll") == 0){
				hash=hachageFinal("will",tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash("will",tab,hash);
				tableHachage_getHash("will",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				nbMot++;
				i++;
			} 
			else if (strcmp(mots[i], "wo") == 0){
				hash=hachageFinal("will",tab->tailleTableau,numFonction);
				t1= clock();
				//eget=tableHachage_getHash("will",tab,hash);
				tableHachage_getHash("will",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;

				hash=hachageFinal("not",tab->tailleTableau,numFonction);
				t1= clock();
				tableHachage_getHash("not",tab,hash);
				//eget=tableHachage_getHash("not",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				i = i + 2;	
				nbMot=nbMot+2;
			} 
			else if (strcmp(mots[i], "ve") == 0){
				hash=hachageFinal("have",tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash("have",tab,hash);
				tableHachage_getHash("have",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				nbMot++;
				i++;
			} 
			else if (strcmp(mots[i], "ca") == 0){
				hash=hachageFinal("can",tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash("can",tab,hash);
				tableHachage_getHash("can",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;


				hash=hachageFinal("not",tab->tailleTableau,numFonction);
				t1= clock();
				//eget=tableHachage_getHash("not",tab,hash);
				tableHachage_getHash("not",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				
				i = i + 2;	
				nbMot=nbMot+2;
			} 
			else if (strcmp(mots[i], "n") == 0 && strcmp(mots[i+1], "t") == 0){
				hash=hachageFinal("not",tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash("not",tab,hash);
				tableHachage_getHash("not",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				i=i+2;
				nbMot=nbMot+2;
			} 
			else if (strcmp(mots[i], "d") == 0){
				hash=hachageFinal("would",tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash("would",tab,hash);
				tableHachage_getHash("would",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				nbMot++;
				i++;
			} 
			else if (strcmp(mots[i], "let") == 0 && strcmp(mots[i+1], "s") == 0){
				hash=hachageFinal("let",tab->tailleTableau,numFonction);
				t1= clock();
				tableHachage_getHash("let",tab,hash);
				//eget=tableHachage_getHash("let",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;


				hash=hachageFinal("us",tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash("us",tab,hash);
				tableHachage_getHash("us",tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				
				i = i + 2;	
				nbMot=nbMot+2;
			} 
			else {
				hash=hachageFinal(mots[i],tab->tailleTableau,numFonction);
				t1= clock();
				///eget=tableHachage_getHash(mots[i],tab,hash);
				tableHachage_getHash(mots[i],tab,hash);
				t2=clock();
				res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
				nbMot++;
				i++;
			}

			if (tmax < (double)(t2-t1)/(double)CLOCKS_PER_SEC){
				tmax = (double)(t2-t1)/(double)CLOCKS_PER_SEC;
			}if (tmin > (double)(t2-t1)/(double)CLOCKS_PER_SEC){
				tmin = (double)(t2-t1)*10000/(double)CLOCKS_PER_SEC;
			}
		}
	}printf("Le minimum pris pour rentrer un mot est = %f\n",tmin);
	printf("Le maximum pris pour rentrer un mot est  = %f\n",tmax);
	printf("Le nombre de mot non distinct dans la table est : = %d\n",nbMot);
	res=res/(float)nbMot;
	return(res);
}

int getTableNumberWords(TableHachage tab) {   // Fonction de statistique.c
	int N = tab->tailleTableau;
	Liste list = tab->tableauListe;
	ELEMENT* elmt;
	next* nextW;

	int res =0;
	//int sum = 0;
	elmt = list->val;
	for (int i = 0; i < N; i++) {
		if (elmt->nbnote != 0) {
			res++;
			//sum = sum + elmt->nbnote;
		}nextW = list->nextWord;
		while (nextW != NULL) {
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

float facteurCompression(TableHachage tab){
	float fcomp = 0.0;
	if (tab == NULL){
		printf("Erreur la table est NULL");
		return(fcomp);
	}
	int n = tab->tailleTableau;
	celulle* cel = tab->tableauListe;
	int k =0;
	while (k<n){
		if (cel->val->nbnote != 0){
			fcomp=fcomp+1;
		}
		cel = cel->suiv;
		k++;
	}return(fcomp/(float)n);
}













