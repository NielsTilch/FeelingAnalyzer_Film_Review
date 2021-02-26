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


TableHachage creer_HashageAvecCollision();
//Création de la table de Hashage en gérant les collision


int etudeTable();
//Etude des tables de hachages

int etudeTest();
//Etude des tests