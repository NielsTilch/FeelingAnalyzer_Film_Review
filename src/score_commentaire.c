#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "listSimpleChain_collision.h"
#include "tableHachage_collision.h"
#include "HashProg_collision.h" 
#include "score_commentaire.h"
#include "fonctionHachage.h"
#include "analyseTable.h"

float score(char commentaire[], TableHachage table, int numFonction) {
	
	char* comMin = maj2min(commentaire);
	//printf("Le commentaire est : '%s'\n", comMin);
	char* comSansNb = removeNumber(comMin);
	//printf("Le commentaire après remove number est : %s \n",comSansNb);
	char** mots = split(comSansNb);
	float score = 0;
	int i = 0; 
	while (mots[i] != NULL) {

		if (strcmp(mots[i], "&") == 0)
		{
			score += tableHachage_get("and", table, numFonction)->moy;
			i++;
		} 
		/* Si un mot est une contraction, alors on cherche sont équivalent dans la table */
		else if (strcmp(mots[i], "m") == 0)
		{
			score += tableHachage_get("am", table, numFonction)->moy;
			i++;
		} else if (strcmp(mots[i], "re") == 0)
		{
			score += tableHachage_get("are", table, numFonction)->moy;
			i++;
		} else if (strcmp(mots[i], "ll") == 0)
		{
			score += tableHachage_get("will", table, numFonction)->moy;
			i++;
		} else if (strcmp(mots[i], "wo") == 0)
		{
			score += tableHachage_get("will", table, numFonction)->moy;
			score += tableHachage_get("not", table, numFonction)->moy;
			i++;
		} else if (strcmp(mots[i], "ve") == 0)
		{
			score += tableHachage_get("have", table, numFonction)->moy;
			i++;
		} else if (strcmp(mots[i], "ca") == 0)
		{
			score += tableHachage_get("can", table, numFonction)->moy;
			score += tableHachage_get("not", table, numFonction)->moy;
			i++;
		} else if (strcmp(mots[i], "n") == 0 && strcmp(mots[i+1], "t") == 0)
		{
			score += tableHachage_get("not", table, numFonction)->moy;
			i = i + 2;
		} else if (strcmp(mots[i], "d") == 0)
		{
			score += tableHachage_get("would", table, numFonction)->moy;
			i++;
		} else if (strcmp(mots[i], "let") == 0 && strcmp(mots[i+1], "s") == 0)
		{
			score += tableHachage_get("let", table, numFonction)->moy;
			score += tableHachage_get("us", table, numFonction)->moy;
			i = i + 2;
		} else {
			printf("Le mot numéro %d est = '%s'\n",i,tableHachage_get(mots[i], table,numFonction)->clef);
			score += tableHachage_get(mots[i], table, numFonction)->moy;
			i++;
		}		
	}
	//free(mots);
	return score/i;
}

void saisieAffichageScore(TableHachage tabRemplie, int numFonction){
	
	/* demande de saisie par l'utilisateur sur l'entrée standard du terminal 
	d'un nouveau commentaire */
	printf("Enter a review -- Press return to exit:\n");
	char commentaire[255];
	fgets(commentaire, 255, stdin);
	commentaire[strnlen(commentaire, 255)-1] = '\0';
	fprintf(stderr,"Commentaire lu \n");
	/* calcul du score prédit pour ce nouveau commentaire */
	float score_com = score(commentaire, tabRemplie, numFonction);
	//printf("Score calculé\n");
	printf("The review has an average value of %f\n", score_com);
	
	/* affichage du score et du qualificatif */
	if (score_com >= 0 && score_com < 1){
		printf("Negative Sentiment\n");
		return;
	}
	if (score_com >= 1 && score_com < 1.99){
		printf("Somewhat Negative Sentiment\n");
		return;
	}
	if (score_com >= 1.99 && score_com < 2.01){
		printf("Neutral Sentiment\n");
		return;
	}
	if (score_com >= 2.01 && score_com < 3){
		printf("Somewhat Positive Sentiment\n");
		return;
	}
	printf("Positive Sentiment\n");
	printf("\n");
}

void lancementFonction(){
	char quitter[255];
	char visu[255];
	strcpy(quitter,"n");
	printf("   Bienvenue ! Vous avez choisi d'évaluer un commentaire ! Choisissez le numéro de fonction avec laquelle la table sera remplie : \n   1 : Fonction naïve\n   2 : Fonction naïve avec poids\n   3 : Fonction récursive\n   4 : SHA-1 réduit modulo\n   5 : SHA-1 avec poids\n   6 : SHA-1 réduit xor\nIl est conseillé de remplir la table avec la fonction 5 et déconseillé de la remplir avec la fonction 1.\n\nNuméro de fonction choisie : ");
	char numFonction[255];
	fgets(numFonction,255,stdin);
	numFonction[strnlen(numFonction, 255)-1] = '\0';
	//printf("Le num de la fonction est : %s\n",numFonction);
	//printf("Le num de la fonction est : %d\n",atoi(numFonction));
	
	while (( atoi(numFonction)<=0 || atoi(numFonction) >= 7) && strcmp("n",quitter) ==0 ){
		printf("ERREUR : Le numéro de fonction doit être compris entre 1 et 6.\nVoulez vous quittez le programme ? (y/n) : ");
		fgets(quitter,255,stdin);
		numFonction[strnlen(quitter, 255)-1] = '\0';
		printf("char quitte= %s\n",quitter);
		if ((int) quitter[0] == 121){
			printf("Vous quittez le programme. A bientôt !\n");
			return;
		}
		printf("Choisissez le numéro de fonction avec laquelle la table sera remplie : \n   1 :Fonction naïve\n   2: Fonction naïve avec poids\n   3: Fonction récursive\n   4: SHA-1 réduit modulo\n   5: SHA-1 avec poids\n\n");
		fgets(numFonction,10,stdin);
		printf("Le num de la fonction dans le while est : %s\n",numFonction);
	}
	if (atoi(numFonction) == 4 || atoi(numFonction) ==5 || atoi(numFonction) ==6 ){
		printf("Attention, avec cette fonction, le temps de remplissage de la table est long, en moyenne 1min30.\n");
	}
	int numFonctionEntier = atoi(numFonction);
	TableHachage tab = tableHachage_creer(15085);
	
	FILE* fichier = fopen("./../data/movie_reviews.txt","r");

	printf("Table créée\n");
	TableHachage tabRemplie = filledTab(fichier, tab, numFonctionEntier);
	printf("Le facteur de compression  de la table est :%f\n", facteurCompression(tabRemplie));
	printf("Voulez vous visualiser la table (y/n) : ");
	fgets(visu,255,stdin);
	if ((int) visu[0] == 121){
		tableHachage_visualiser(tabRemplie);
	}
	printf("\n\n");
	while (! strcmp("n",quitter) ){
		saisieAffichageScore(tabRemplie,numFonctionEntier);
		printf("\nVoulez vous quitter le programme ou évaluer un autre commentaire ? \nQuitter (y/n) : ");
		fgets(quitter,255,stdin);
		quitter[strnlen(quitter, 255)-1] = '\0';
		printf("\n\n");
	}
	printf("Vous quittez le programme. A bientôt !\n");
	freeTable(tabRemplie);
	fclose (fichier);
	return;

}


























