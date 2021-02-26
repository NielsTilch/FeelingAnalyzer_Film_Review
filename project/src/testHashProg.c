#include <stdlib.h>
#include <stdio.h>

#include "./../src/HashProg.h"
#include "./../src/tableHachage.h"
#include "./../src/listSimpleChain.h"

#include <criterion/criterion.h>

void setup(void){
}

void teardown(void){
}

Test(test_str2ValEntier,test_conversion){
	puts("Test de la fonction 'str2ValEntier'");
	char* nbValide = "4";
	char* vide ="";
	char* nbInvalide ="15";
	cr_expect_eq(str2ValEntier(nbValide),4);
	cr_expect_eq(str2ValEntier(nbInvalide),1);
	cr_expect_eq(str2ValEntier(vide),-666);
}

Test(test_IsIn,test_Presence){
	puts("Test de la fonction 'isIn'");
	TableHachage tab = tableHachage_creer(10);
	ELEMENT e1;
	e1.nbnote=1;
	e1.moy=1;
	e1.clef="clef1";
	cr_expect_eq(isIn(e1.clef,tab),0);
	tableHachage_ajout(e1,tab);
	cr_expect_eq(isIn(e1.clef,tab),1);
}

Test(test_ajouteNouveauMots,test_RemplissageNouveauMot){
	puts("Test de la fonction 'ajouteNouveauMots'");
	TableHachage tab = tableHachage_creer(10);
	char* mot1 = "Mot";
	int note = 4 ;
	ajouteNouveauMots(mot1 ,tab, note);
	ELEMENT eRecup = tableHachage_get(mot1,tab);
	cr_expect_str_eq(eRecup.clef, mot1);
	ajouteNouveauMots(NULL ,tab, note-1);
	//Vérifier qu'on fasse un return de suite. Comment faire !?
}

Test(test_ajouteAncienMots,test_RemplissageAncienMot){
	puts("Test de la fonction 'ajouteAncienMots'");
	TableHachage tab = tableHachage_creer(10);
	ELEMENT e1;
	e1.nbnote = 1;
	e1.moy=4;
	e1.clef="clef1";
	tableHachage_ajout(e1,tab);
	ajouteAncienMots("clef1",tab,2);
	ELEMENT eRecup = tableHachage_get("clef1",tab);
	cr_expect_eq(eRecup.nbnote, 2);
	cr_expect_eq(eRecup.moy, 3.0);
	ajouteAncienMots(NULL ,tab, 2);
	//Vérifier qu'on fasse un return de suite. Comment faire !?
}

Test(test_split,test_decoupageMot){
	puts("Test de la fonction 'split'");
	char* commentaire = "Le petit chat est heureux et vivant. Super.ab";
	char** commentaireDecoupe = split(commentaire);
	cr_expect_str_eq(commentaireDecoupe[0], "Le");
	cr_expect_str_eq(commentaireDecoupe[1], "petit");
	cr_expect_str_eq(commentaireDecoupe[2], "chat");
	cr_expect_str_eq(commentaireDecoupe[3], "est");
	cr_expect_str_eq(commentaireDecoupe[4], "heureux");
	cr_expect_str_eq(commentaireDecoupe[5], "et");
	cr_expect_str_eq(commentaireDecoupe[6], "vivant.");
	cr_expect_str_eq(commentaireDecoupe[7], "Super.ab");
	cr_expect_str_eq(commentaireDecoupe[9], NULL);
}

Test(test_rentreMot,test_RemplissageMot){
	puts("Test de la fonction 'RentreMot'");
	TableHachage tab = tableHachage_creer(50);
	rentreMot("clef1",tab,4);
	rentreMot("clef2",tab,5);
	rentreMot("clef1",tab,2);
	ELEMENT eRecup1 = tableHachage_get("clef1",tab);
	ELEMENT eRecup2 = tableHachage_get("clef2",tab);
	cr_expect_eq(eRecup1.nbnote, 2);
	cr_expect_eq(eRecup1.moy, 3.0);
	cr_expect_eq(eRecup2.nbnote, 1);
	cr_expect_eq(eRecup2.moy, 5.0);
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








































