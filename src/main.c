#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "main_sub.h"


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

int main (){
	printf("!! Bienvenue sur la commande automatique !!\n");
	printf("Veuillez choisir une fonction de la liste affiché\n");



	int T=0;
	int response;
	int responseAccord;

	while (T==0){
		response = 0;
		responseAccord=0;

		printf("_______________Partie obligatoire_______________\n\n");

        printf("Observer le poids de chaque mot de la table, tapez 1\n");
        printf("Saisie d'une phrase pour prédire le score,tapez 2\n");

        printf("_________________________________________________\n\n");

        printf("Pour la partie complémentaire, tapez 3 :\n");

        printf("Les Tests, tapez 4\n\n");

		while (responseAccord == 0){
			scanf(">>> %d \n",&response);

			//Regarder si les réponses sont ok
			if (response == 1 || response == 2 || response == 3 || response==4){
				responseAccord=1;
			}


			//Erreur d'entrée
			else{
				printf("Erreur d'entrée :(");
			}
		}

		if(response==1){
		    //Fonction observer chaque mot de la table (doit demander de la créer avec quelle fonction
		}

		else if (response == 2){
		    //Fonction de demande de saisie de la phrase
		}

		//On veut regarde l'étude des table
		else if (response==3){
			int rep1=etudeTable();
			if (rep1==1){
			    //Fonction Etude Statistiques
			}
			else if(rep1==2 ){
                //Fonction Facteur de compression
			}
			else if(rep1== 3){
                //Temps d'excecution de la table
            }
		}

		//On veut regarder les tests
		else if(response==4){
			int rep2=etudeTest();
			if (rep2==1){
            	//Fonction Tests fonctions de hachage
            }
            else if(rep2==2 ){
                //Fonction Tests Listes
            }
            else if(rep2== 3){
                //Fonction tests des statistiques
            }
            else if(rep2== 4){
                //Fonction Tests arbres tris
            }
            else if(rep2== 5){
                //Fonction Test decoupage de mots
            }
		}
	}
	return 0;
}