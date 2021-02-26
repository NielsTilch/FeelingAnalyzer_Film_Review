#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listSimpleChain.h"
#include "tableHachage.h"


int main(){
	int taille1 = 5;
	TableHachage t = tableHachage_creer(taille1);
	
	ELEMENT e1;
	e1.nbnote=1;
	e1.moy=1;
	e1.clef="clef1";
	ELEMENT e2;
	e2.nbnote=2;
	e2.moy=2;
	e2.clef="clef2";
	ELEMENT* e3 = malloc(sizeof(ELEMENT));
	e3->nbnote=3;
	e3->moy=3;
	e3->clef="clef3";
	ELEMENT resultat;
	int note = 16;
	
	
	
	//printf("L'élément 1 est écrasé car à l'indice %d,l'élément 2 doit être à l'indice %d,l'élément 3 doit être à l'indice :%d \n", hachage(e1.clef,taille1), hachage(e2.clef,taille1), hachage(e3.clef,taille1));
	tableHachage_ajout(e1,t);
	tableHachage_ajout(e2,t);
	tableHachage_ajout(*e3,t);
	//tableHachage_ajout(eR,t);
	tableHachage_visualiser(t);
	
	//printf("On supprime l'élément 2, à l'indice %d",hachage(e2.clef,taille1));
	//tableHachage_supprime(e2.clef,t);
	//tableHachage_visualiser(t);	
	//printf("On supprime un element qui n'existe pas, rien ne doit changer : ");
	//tableHachage_supprime(e5.clef,t);
	//tableHachage_visualiser(t);
	
	//resultat = tableHachage_get(e3.clef,t);
	//printf("On affiche l'élément 3, ie : ('valeur3';'clef3') = ");
	//list_affiche(resultat);
	//printf("\n");
	//resultat = tableHachage_get("test",t);
	//printf("On cherche un element qui n'est pas  dans la liste on attends :((null);(null)) =  ");
	//list_affiche(resultat);
	
	
	return(1);
}
