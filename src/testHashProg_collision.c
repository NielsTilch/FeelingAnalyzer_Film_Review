#include <stdlib.h>
#include <stdio.h>

#include "./../src/HashProg_collision.h"
#include "./../src/tableHachage_collision.h"
#include "./../src/listSimpleChain_collision.h"

#include <criterion/criterion.h>

void setup(void){
TableHachage tab = tableHachage_creer(10)
}

void teardown(void){
}

Test(test_ajouteNouveauMots,test_RemplissageNouveauMot){

	puts("Test de la fonction 'ajouteNouveauMots' en gerant les collisions");

	char* mot1 ="ABC";
	char* mot2 ="ACB";
	char* mot3 ="CBA";
	char* mot4 ="AAA";
	char* mot5 = NULL;
	char* mot6 ="";
	int note = 4;

	ajouteNouveauMots(mot1 ,tab, note);
	ELEMENT rec1=tableHachage_get(mot1,tab);
	cr_expect_str_eq(rec1.clef, mot1);

	ajouteNouveauMots(mot2 ,tab, note);
	ajouteNouveauMots(mot3 ,tab, note);
	ELEMENT rec2=tableHachage_get(mot2,tab);
	cr_expect_str_eq(rec2.clef,mot2);

	ELEMENT rec3=tableHachage_get(mot3,tab);
	cr_expect_str_eq(rec3.clef,mot3);

	ajouteNouveauMots(mot5 ,tab, note);
	ELEMENT rec4=tableHachage_get(mot5,tab);
	cr_expect_str_eq(rec4.clef,NULL);

	//Test mot6
}

Test(test_ajouteAncienMots,test_RemplissageAncienMot){
	puts("Test de la fonction 'ajouteAncienMots' avec gestion des collisions");

    char* mot1 ="ABC";
    int note11 = 4;
    ajouteNouveauMots(mot1 ,tab, note11);

    int note12 = 3;
    ajouteAncienMots(mot1,tab,note12);
    ELEMENT rec1 = tableHachage_get(mot2,tab);
    cr_expect_eq(rec1.moy, 3.5);

    int note13 = 2;
    ajouteAncienMots(mot1,tab,note12);
    cr_expect_eq(rec1.nbnote, 3);
    cr_expect_eq(rec1.moy, 3);


    char* mot2 ="ACB";
    int note21 = 1;
    int note22 = 4;

    ajouteNouveauMots(mot2 ,tab, note21);
    ajouteAncienMots(mot2,tab,note22);

    cr_expect_eq(rec1.nbnote, 2.5);
    cr_expect_eq(rec1.moy, 2);

}


Test(test_filledTab,test_RemplissageAvecFichier_Mot){
	puts("Test de la fonction 'filledTab' uniquemet les mots");
	TableHachage tab = tableHachage_creer(400);
	FILE* fichier = fopen("./../data/dataHashProgTest.txt","r");
	tab = filledTab(fichier,tab);
	ELEMENT eRecupCeci = tableHachage_get("Ceci",tab);
	cr_expect_eq(eRecupCeci.nbnote, 1);
	cr_expect_eq(eRecupCeci.moy, 5.0);

	ELEMENT eRecupEst = tableHachage_get("est",tab);
	cr_expect_eq(eRecupEst.nbnote, 2);
	cr_expect_eq(eRecupEst.moy, 5.5);

	ELEMENT eRecupUn = tableHachage_get("un",tab);
	cr_expect_eq(eRecupUn.nbnote, 1);
	cr_expect_eq(eRecupUn.moy, 5);

	ELEMENT eRecupTest = tableHachage_get("test",tab);
	cr_expect_eq(eRecupTest.nbnote, 1);
	cr_expect_eq(eRecupTest.moy, 5);

	ELEMENT eRecup_and = tableHachage_get("and",tab);
	cr_expect_eq(eRecup_and.nbnote,1);
	cr_expect_eq(eRecup_and.moy,5.0);

	ELEMENT eRecupAnd = tableHachage_get("And",tab);
	cr_expect_eq(eRecupAnd.nbnote, 1);
	cr_expect_eq(eRecupAnd.moy,3);

	ELEMENT eRecupYoupi = tableHachage_get("a",tab);
	cr_expect_eq(eRecupYoupi.nbnote, 1);
	cr_expect_eq(eRecupYoupi.moy,1);

	ELEMENT eRecupI = tableHachage_get("I",tab);
	cr_expect_eq(eRecupI.nbnote, 4);
	cr_expect_eq(eRecupI.moy,3);

	ELEMENT eRecupBe = tableHachage_get("be",tab);
	cr_expect_eq(eRecupBe.nbnote, 2);
	cr_expect_eq(eRecupBe.moy,5);

	ELEMENT eRecupCan = tableHachage_get("can",tab);
	cr_expect_eq(eRecupCan.nbnote, 2);
	cr_expect_eq(eRecupCan.moy,2.5);

	ELEMENT eRecupNot = tableHachage_get("not",tab);
	cr_expect_eq(eRecupNot.nbnote, 2);
	cr_expect_eq(eRecupNot.moy,2.5);

	ELEMENT eRecupHave = tableHachage_get("have",tab);
	cr_expect_eq(eRecupHave.nbnote, 1);
	cr_expect_eq(eRecupHave.moy,2);

	ELEMENT eRecupLet = tableHachage_get("let",tab);
	cr_expect_eq(eRecupLet.nbnote, 1);
	cr_expect_eq(eRecupLet.moy,2);

	ELEMENT eRecupUs = tableHachage_get("us",tab);
	cr_expect_eq(eRecupUs.nbnote, 1);
	cr_expect_eq(eRecupUs.moy,2);

	ELEMENT eRecupAWould = tableHachage_get("would",tab);
	cr_expect_eq(eRecupAWould.nbnote, 1);
	cr_expect_eq(eRecupAWould.moy, 2);
}

Test(test_filledTab,test_RemplissageAvecFichier_Ponctuation){
	puts("Test de la fonction 'filledTab' uniquemet les ponctuations");
	TableHachage tab = tableHachage_creer(400);
	FILE* fichier = fopen("./../data/dataHashProgTest.txt","r");
	tab = filledTab(fichier,tab);

	ELEMENT eRecupExclamation = tableHachage_get("!",tab);
	cr_expect_eq(eRecupExclamation.nbnote, 0);
	cr_expect_eq(eRecupExclamation.moy, 0);

	ELEMENT eRecupApostrophe = tableHachage_get("'",tab);
	cr_expect_eq(eRecupApostrophe.nbnote, 0);
	cr_expect_eq(eRecupApostrophe.moy, 0);

	ELEMENT eRecupApostropheBack = tableHachage_get("`",tab);
	cr_expect_eq(eRecupApostropheBack.nbnote, 0);
	cr_expect_eq(eRecupApostropheBack.moy, 0);

	ELEMENT eRecupPoint = tableHachage_get(".",tab);
	cr_expect_eq(eRecupPoint.nbnote, 0);
	cr_expect_eq(eRecupPoint.moy, 0);

	ELEMENT eRecupEsperluette = tableHachage_get("&",tab);
	cr_expect_eq(eRecupEsperluette.nbnote, 0);
	cr_expect_eq(eRecupEsperluette.moy, 0);

	ELEMENT eRecupDies = tableHachage_get("#",tab);
	cr_expect_eq(eRecupDies.nbnote, 0);
	cr_expect_eq(eRecupDies.moy, 0);

	ELEMENT eRecupSuspension = tableHachage_get("...",tab);
	cr_expect_eq(eRecupSuspension.nbnote, 0);
	cr_expect_eq(eRecupSuspension.moy, 0);

	ELEMENT eRecupDeuxPts = tableHachage_get(":",tab);
	cr_expect_eq(eRecupDeuxPts.nbnote, 0);
	cr_expect_eq(eRecupDeuxPts.moy, 0);
}

Test(test_filledTab,test_RemplissageAvecFichier_Abreviation){
	puts("Test de la fonction 'filledTab' uniquemet les abréviations");
	TableHachage tab = tableHachage_creer(400);
	FILE* fichier = fopen("./../data/dataHashProgTest.txt","r");
	tab = filledTab(fichier,tab);

	ELEMENT eRecupAbreviation_Would = tableHachage_get(" 'd ",tab);
	cr_expect_eq(eRecupAbreviation_Would.nbnote, 0);
	cr_expect_eq(eRecupAbreviation_Would.moy, 0);


	ELEMENT eRecupAbreviation_am = tableHachage_get("'m",tab);
	cr_expect_eq(eRecupAbreviation_am.nbnote, 0);
	cr_expect_eq(eRecupAbreviation_am.moy, 0);

	ELEMENT eRecupAbreviation_have = tableHachage_get("'ve",tab);
	cr_expect_eq(eRecupAbreviation_have.nbnote, 0);
	cr_expect_eq(eRecupAbreviation_have.moy, 0);

	ELEMENT eRecupAbreviation_us = tableHachage_get("'s",tab);
	cr_expect_eq(eRecupAbreviation_us.nbnote, 0);
	cr_expect_eq(eRecupAbreviation_us.moy, 0);

	ELEMENT eRecupAbreviation_will = tableHachage_get("'ll",tab);
	cr_expect_eq(eRecupAbreviation_will.nbnote, 0);
	cr_expect_eq(eRecupAbreviation_will.moy, 0);
}