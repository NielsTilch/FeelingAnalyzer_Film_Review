#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "HashProg_collision.h" 
#include "tableHachage_collision.h"
#include "listSimpleChain_collision.h"
#include "fonctionHachage.h"

#define SIZE 300

char* creeNvMot(char* mot){
	int n = (int) strlen(mot);
	char* nvMot = malloc(sizeof(char)*(n+1));
	for (int i =0; i<n; i++){
		nvMot[i]=mot[i];
	}nvMot[n]='\0';
	return(nvMot);
}

char** split(char* commentaire) {
	char** mots = (char**)calloc(SIZE,sizeof(char*));
	char* delimiters = " .!?,:;-`'/*#$^+=	";
	char* mot = strtok(commentaire, delimiters);
	int i = 0;
	while (mot != NULL) {
		if (i < SIZE){
				mots[i] = (char*)malloc((1+strlen(mot))*sizeof(char));
				strcpy(mots[i], mot);
				i++;
		} else {
			break;
		}
		mot = strtok(NULL, delimiters);
	}
	return mots;
}

void ajouteAncienMots(char* mot ,TableHachage tab, int note,int hash){
	ELEMENT* e = tableHachage_getHash(mot,tab,hash);
	e->moy = (e->moy*e->nbnote + note )/(e->nbnote+1);	
	e->nbnote = e->nbnote+1;
	celulle* cel=tab->tableauListe;
	//int Hachcode = hachageFinal(e->clef, tab->tailleTableau,numFonction);
	int Hachcode = hash;
	for (int i = 0; i < Hachcode; i++){
			cel=cel->suiv;
	}
	if (!strcmp(cel->val->clef,mot)){
		cel->val=e;
	}
	else{
		next* nextW = cel->nextWord;
		while(strcmp(nextW->val->clef,mot)){
			nextW=nextW->nextWord;
		}
		nextW->val=e;
	}
}

void ajouteNouveauMots(char* mot ,TableHachage tab, int note, int hash){
	ELEMENT* e = (ELEMENT*) malloc(sizeof(ELEMENT));
	e->nbnote = 1;
	e->moy = note ;
	e->clef = mot ;
	celulle* cel=tab->tableauListe;
	int k =0;
	for (int i = 0; i < hash; i++){
			cel=cel->suiv;
			k++;
	}
	if (cel->val->nbnote == 0){
		cel->val=e;
		cel->nextWord = NULL;
		return;
	}else if (cel->nextWord == NULL){
		nextWord* next = malloc(sizeof(nextWord));
		next->val = e;
		next->nextWord = NULL;
		cel->nextWord = next;
		return;
	}else if (cel->nextWord != NULL){
		nextWord* next = cel->nextWord;
		while (next->nextWord != NULL){
			next = next->nextWord;
		}
		nextWord* nvNext = malloc(sizeof(nextWord));
		nvNext->val = e;
		next->nextWord = nvNext;
		nvNext->nextWord = NULL;
		return;
	}
}

int isIn(char* mot ,TableHachage tab,int hash){
	ELEMENT* e = tableHachage_getHash(mot,tab,hash);
	if ( e->clef ==NULL){ //Si le mot n'existe pas
		free(e);
		return(0);
	}
	//Si le mot existe
	return(1);
}

void rentreMot(char* mot ,TableHachage tab, int note,int hash){
	//fprintf(stderr,"On est dans rentre mot\n");
	if (isIn(mot,tab,hash)){ // Si le mot existe, on met à jour un ancien mot
		//fprintf(stderr,"On est dans le if\n");
		ajouteAncienMots(mot,tab,note,hash);
	}
	else{ //Le mot n'existant pas, on ajoute un nouveau dans la table.
		//fprintf(stderr,"On est dans le else\n");
		ajouteNouveauMots(mot,tab,note,hash);
	}
	return;
}

int isNumber(char c) {
	if (c >= '0' && c <= '9') { //On vérifie si le caractère est un chiffre
		return 1;
	} 
	return 0;
}

char* removeNumber(char* mot) {
	char* res = (char*)malloc(sizeof(char)*(1+strlen(mot)));
	res[0] = mot[0]; // on ne supprime pas la note du commentaire
	int k = 1;
	int n = strlen(mot);
	for (int i = 1; i < n; i++) {
		if (!isNumber(mot[i])) {
			res[k] = mot[i];
			k++;
		}
	}
	res[k] = '\0';
	return res;
}

char* maj2min(char* str) {
	int n = strlen(str);
	char* new_str = (char*)malloc((1+n)*sizeof(char));
	for (int k =0; k<n; k++){
		new_str[k]=tolower(str[k]);
	}new_str[n]='\0';
	return new_str;
}

TableHachage filledTab(FILE* fichier,TableHachage tab, int numFonction) {
	clock_t t1,t2; //début de mesure de temps du remplissage de la table
	t1 = clock();
	/* On vérifie que le fichier a été ouvert correctement */
	if (fichier == NULL) {
		printf("Erreur à l'ouverture du fichier");
		return 0; 
	}
	/* On parcourt le fichier ligne par ligne */ 
	int hash;
	//char* ligneNorm;
	int k =1;
	//int c;
	char ligne[500];
	char* retourLigne;
	while (fgets(ligne, 500, fichier) != NULL) {
		retourLigne = strchr(ligne,'\n');
		if (retourLigne != NULL){
			*retourLigne='\0';
		}
		//printf("\n\nLigne %d : '%s'\n", k,ligne);
		k++;
		//printf("strnlen(ligne, 500)=%ld\n",strnlen(ligne, 500));
		ligne[strnlen(ligne, 500)] = '\0';          // supprime les retours à la ligne dans la table de hachage
		char* ligneMin = maj2min(ligne);            // convertit les caractères majuscules en minuscules
		char* ligneSansNb = removeNumber(ligneMin); // supprime les nombres dans les commentaires sauf la note
		char** mots = split(ligneSansNb);           // découpe la ligne selon les séparateurs " .!?,:;-`'#$+=	"
		int note = atoi(mots[0]);                   // conversion de la note, 1er caractère de la ligne, en entier
		/* On parcourt tous les mots de la ligne */
		int i = 1;

		while (mots[i] != NULL) {
			//printf("Le mot %d est '%s' son hash est : %d\n",i,mots[i],hachageFinal(mots[i],tab->tailleTableau,numFonction));
			if (strcmp(mots[i], "&") == 0){
				hash=hachageFinal("and",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("and"), tab, note,hash);
				i++;
			}else if ( strcmp(mots[i],"") == 0 || (int)mots[i][0] == 10 ){
				i++;
			}
			else if (strcmp(mots[i], "m") == 0){
				hash=hachageFinal("am",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("am"), tab, note,hash);
				i++;
			} 
			else if (strcmp(mots[i], "re") == 0){
				hash=hachageFinal("are",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("are"), tab, note,hash);
				i++;
			} 
			else if (strcmp(mots[i], "ll") == 0){
				hash=hachageFinal("will",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("will"), tab, note,hash);
				i++;
			} 
			else if (strcmp(mots[i], "wo") == 0){
				hash=hachageFinal("will",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("will"), tab, note,hash);
				hash=hachageFinal("not",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("not"), tab, note,hash);
				i = i + 2;		} 
			else if (strcmp(mots[i], "ve") == 0){
				hash=hachageFinal("have",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("have"), tab, note,hash);
				i++;
			} 
			else if (strcmp(mots[i], "ca") == 0){
				hash=hachageFinal("can",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("can"), tab, note,hash);
				hash=hachageFinal("not",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("not"), tab, note,hash);
				i = i + 2;
			} 
			else if (strcmp(mots[i], "n") == 0 && strcmp(mots[i+1], "t") == 0){
				hash=hachageFinal("not",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("not"), tab, note,hash);
				i=i+2;
			} 
			else if (strcmp(mots[i], "d") == 0){
				hash=hachageFinal("would",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("would"), tab, note,hash);
				i++;
			} 
			else if (strcmp(mots[i], "let") == 0 && strcmp(mots[i+1], "s") == 0){
				hash=hachageFinal("let",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("let"), tab, note,hash);
				hash=hachageFinal("us",tab->tailleTableau,numFonction);
				rentreMot(creeNvMot("us"), tab, note,hash);
				i = i + 2;
			} 
			else {
				//fprintf(stderr,"TOUT VZ BIEN\n");
				hash=hachageFinal(mots[i],tab->tailleTableau,numFonction);
				//fprintf(stderr,"TOUT VZ BIEN\n");
				rentreMot(mots[i], tab, note,hash);
				i++;
			}//fprintf(stderr,"TOUT VZ BIEN\n");
		}
	}
	t2 = clock();
	printf("Le temps de remplissage de la table est : %f secondes \n",(double)(t2-t1)/(double)CLOCKS_PER_SEC);
	return tab;
}
