#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "HashProg.h" 
#include "tableHachage.h"
#include "listSimpleChain.h"
#include "fonctionHachage.h"

#define SIZE 300

char** split(char* commentaire) {

	char** mots = (char**)malloc(sizeof(char*)*SIZE);
	char* delimiters = " .!?,:;-`'#$+=	/";
	char* mot = strtok(commentaire, delimiters);

	int i = 0;
	while (mot != NULL) {
		if (i < SIZE)
		{
			mots[i] = (char*)malloc(sizeof(char)*(1+strlen(mot)));
			strcpy(mots[i], mot);
			i++;
		} else {
			break;
		}
		mot = strtok(NULL, delimiters);
	}
	return mots;
}

void ajouteAncienMots(char* mot ,TableHachage tab, int note){
	//printf("On modifie les valeurs de l'élément du mot '%s'",mot);
	ELEMENT e = tableHachage_get(mot,tab);
	//ELEMENT* e2 = (ELEMENT*) malloc(sizeof(ELEMENT)); // !! malloc type
	e.moy = (e.moy*e.nbnote + note )/(e.nbnote+1);	
	e.nbnote = e.nbnote+1;
	tableHachage_ajout(e,tab);
}

void ajouteNouveauMots(char* mot ,TableHachage tab, int note){
	//printf("On rentre pour la première fois le mot '%s'\n",mot);
	ELEMENT* e2 = (ELEMENT*) malloc(sizeof(ELEMENT));
	e2->nbnote = 1;
	e2->moy = note ;
	e2->clef = mot ;
	tableHachage_ajout(*e2,tab);
	free(e2);
}

int isIn(char* mot ,TableHachage tab){
	//printf("Dans IsIN \n");
	ELEMENT e = tableHachage_get(mot,tab);
	//printf("Clé du isIN : %s", e->clef);
	//printf("Nb Note du isIN : %d\n", e.nbnote);
	//printf("Moy du isIN : %f\n", e.moy);
	if ( e.clef == NULL && e.nbnote == 0 && e.moy == 0){
		return(0);
	}
	return(1);
}

void rentreMot(char* mot ,TableHachage tab, int note){
	//printf("Rentre mot : ok\n");
	if (isIn(mot,tab)){
		//printf("Is in : OK \n\n");
		//printf("'%s' est déjà dans la table !",mot);
		ajouteAncienMots(mot,tab,note);
	} else {
		//printf("'%s' n'est pas encore dans la table !",mot);
		ajouteNouveauMots(mot,tab,note);
	}
	return; //return(tab);
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
	char* new_str = (char*)malloc((1+strlen(str))*sizeof(char));
	int i = 0;
	while (str[i] != '\0') {
		new_str[i] = tolower(str[i]);
		i++;
	}
	return new_str;
}

TableHachage filledTab(FILE* fichier,TableHachage tab) {

	/* On vérifie que le fichier a été ouvert correctement */
	if (fichier == NULL) {
		printf("Erreur à l'ouverture du fichier");
		return 0; 
	}
	/* On parcourt le fichier ligne par ligne */
	char* ligne = (char*)malloc(sizeof(int)*9000); 
	while (fgets(ligne, 9000, fichier) != NULL) {
		ligne[strnlen(ligne, 9000)-1] = '\0';       // supprime les retours à la ligne dans la table de hachage
		char* ligneMin = maj2min(ligne);            // convertit les caractères majuscules en minuscules
		char* ligneSansNb = removeNumber(ligneMin); // supprime les nombres dans les commentaires sauf la note
		char** mots = split(ligneSansNb);           // découpe la ligne selon les séparateurs " .!?,:;-`'#$+=	"
		int note = atoi(mots[0]);                   // conversion de la note, 1er caractère de la ligne, en entier
		/* On parcourt tous les mots de la ligne */
		int i = 1;
		while (mots[i] != NULL) {
			//printf("Le mot est %s.\n", mots[i]);
			if (strcmp(mots[i], "&") == 0)
			{
				rentreMot("and", tab, note);
				i++;
			} 
			/* Si un mot est une contraction, alors on ajoute sont équivalent dans la table */
			else if (strcmp(mots[i], "m") == 0)
			{
				rentreMot("am", tab, note);
				i++;
			} else if (strcmp(mots[i], "re") == 0)
			{
				rentreMot("are", tab, note);
				i++;
			} else if (strcmp(mots[i], "ll") == 0)
			{
				rentreMot("will", tab, note);
				i++;
			} else if (strcmp(mots[i], "wo") == 0)
			{
				rentreMot("will", tab, note);
				rentreMot("not", tab, note);
				i = i + 2;
			} else if (strcmp(mots[i], "ve") == 0)
			{
				rentreMot("have", tab, note);
				i++;
			} else if (strcmp(mots[i], "ca") == 0)
			{
				rentreMot("can", tab, note);
				rentreMot("not", tab, note);
				i = i + 2;
			} else if (strcmp(mots[i], "n") == 0 && strcmp(mots[i+1], "t") == 0)
			{
				rentreMot("not", tab, note);
				i++;
			} else if (strcmp(mots[i], "d") == 0)
			{
				rentreMot("would", tab, note);
				i++;
			} else if (strcmp(mots[i], "let") == 0 && strcmp(mots[i+1], "s") == 0)
			{
				rentreMot("let", tab, note);
				rentreMot("us", tab, note);
				i = i + 2;
			} else {
				rentreMot(mots[i], tab, note);
				i++;
			}
			//free(mots[i]);
		}
		//free(mots);
		//free(ligneSansNb);
	} return tab;
}
