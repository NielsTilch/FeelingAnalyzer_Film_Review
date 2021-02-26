#include <stdio.h>
#include <stdlib.h>


#include "HashProg_collision.h"
#include "score_commentaire.h"
#include "arbresFloat.h"
#include "listSimpleChain_str.h"
#include "listSimpleChain_collision.h"
#include "tableHachage_collision.h"
#include "analyseFonctionsHachage.h"
#include "listSimpleChain_float.h"


/*
Création du tableau de commande pour les tests principaux.
Menu : Dans l'ordre d'exéctution
--
1/ Création d'une table de hashage
--
>>Créer d'abord les varibles puis voir si elle sont NULL pour éviter de les recréer.


1.0/Créer toutes les tables de hachage
1.1/Table Normal sans gérer les collsions (HashProg)
1.2/Table Normal en gérant les collisions (HashProg_collision)
1.3/Table SHA-1


--
2/Etude des table
--

2.0/Tous
2.1/Etude statistiques des tables :
	> Les mots les plus positifs/négatifs
	> Les mots les plus/moins récurrents
	> Moyenne, Ecart-type,... (les fondamentaux des statistiques)
2.2/Facteur de compression de la table
2.3/Temps d'exécution de :
	>Foramtion de la table
	>Chercher un mot (faire la moyenne lorsque l'on met une phrase)
	>Mise à jour
	>Consultation des valeurs 
2.4/Pourcentage d'erreur fiabilité des table (créer 2 tables avec n% des commentaires pour la première table et (100-n)% pour la 2e table.
*/


TableHachage creer_HashageAvecCollision(){
	//Création de la table de Hashage avec collision

	TableHachage tab = tableHachage_creer(1000);
	FILE* fichier = fopen("./../data/movie_reviews.txt","r");
	tab = filledTab(fichier, tab,1); 
	fclose (fichier);
	return tab;
}

int etudeTable(){
	printf("Vous avez choisi l'étude des Table ! \n");
	printf("Voici la liste des choix :\n\n\n");

	int T=0;
	int response=0;
	while(T==0){
		printf("|--> Etude statistiques de la table : Tapez 1\n");
		printf("|--> Facteur de compression : Tapez 2\n");
		printf("|--> Temps d'execution : Tapez 3");
		printf("|--> ??? ");
		scanf(">>> %d",&response);
		if (response==1 ||response==2 ||response==3){
			
		}
		else{
			printf("Mauvaise insertion :(");
		}
	}
	return 0;
}

int etudeTest(){
    printf("Quel test voulez-vous utiliser ?\n");
    printf("Tester les fonctions principales de hachage, Tape 1\n");
    printf("Tester les listes , Tapez 2\n");
    printf("Tester la foncion des statistiques, Tapez 3\n");
    printf("Tester les arbres de tris, Tapez 4\n");
    printf("Tester le decoupage des mots, Tapez 5\n");
    int Test=0;
    int response=-1;
    while(Test==0){
    		scanf(">>> %d",&response);
    		if (response==0 ||response==1 ||response==2 ||response==3 ||response==4 ||response==5){
    			return response;
    		}
    		else{
    			printf("Mauvaise insertion :(");
    		}
    }
	return 0;
}

int choisirTable(){
	printf("Quelle Table de Hachge veux-tu choisir ?\n\n");
	printf("|--> Tout , Tapez 0\n");
	printf("|--> Naïve , Tapez 1\n");
	printf("|--> Naïve avec poids, Tapez 2\n");
	printf("|--> Récursive, Tapez 3\n");
	printf("|--> Sha-1 réduit modulo, Tapez 4\n");
	printf("|--> Sha-1 réduit poids, Tapez 5\n");
	printf("|--> Sha-1 réduit xor, Tapez 6\n");
	printf("\n");
	int Test=0;
	int response=-1;
	while(Test==0){
		scanf(">>> %d",&response);
		if (response==0 ||response==1 ||response==2 ||response==3 ||response==4 ||response==5 ||response==6){
			return response;
		}
		else{
			printf("Mauvaise insertion :(\n\n");
		}
	}
	return -1;
}