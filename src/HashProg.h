#ifndef HashProg_h
#define HashProg_h
#include "tableHachage.h"
#include "listSimpleChain.h"
#include <stdio.h>

char* charTab2point(char tab[]); //Entrée : un tableau de char || Sortie : char * || But : Faire une allocation mémoire avec des mallocs.

char** split(char* commentaire); //Entrée : ligne de data avec nombre puis commentaire (ie char txt[]) || Sortie : char ** || But : Découper le commentaire selon les espaces. 

void ajouteAncienMots(char* mot, TableHachage tab, int note); //Entrée : un mot, sa note et une table de hachage || Sortie : Table de hachage || But : Rentrer un mot qui était déjà dans la table.

void ajouteNouveauMots(char* mot, TableHachage tab, int note); //Entrée : un mot, sa note et une table de hachage || Sortie : Table de hachage || But : Rentrer un mot qui n'était pas encore dans la table.

int isIn(char* mot, TableHachage tab); //Entrée : un mot et une table de hachage || Sortie : 0 ou 1 (entier) || But : Regarder si le mot est déjà dans la table.

void rentreMot(char* mot, TableHachage tab, int note); //Entrée :  un mot et une table de hachage || Sortie : table de hachage || But : Rentrer le mot dans la table.

TableHachage rentrePhrase2(char** PhraseEnMot, TableHachage tab); //Première version de rentrePhrase, non décomposée.

TableHachage rentrePhrase(char** PhraseEnMot, TableHachage tab); //Entrée : tableau de tout les mots de la phrase et une table de hachage || Sortie : Table de hachage|| But : Rentrer tous les mots dans la table de hachage et modifier le nb de notes et la moyenne.

int isNumber(char c); //Entrée : un caractère || Sortie : 0 ou 1 || But : Renvoie 1 si le caractère est un chiffre, 0 sinon.

char* removeNumber(char* mot); //Entrée : un mot || Sortie : un mot || But : Supprimer les nombres dans un mot si celui-ci en contient.

char* maj2min(char* str); //Entrée : un mot || Sortie : un mot || But : Convertir les caractères majuscules du mot en minuscules.

TableHachage filledTab(FILE* fichier, TableHachage tab); //Entrée : le flot d'un fichier et une table de Hachage|| Sortie : Table de hachage contenant mots(clef) et moyennes/nb de notes/mot (element cf structure des listes || But : Rentrer tous les mots de toutes les phrases et calculer leur moyenne.

#endif
