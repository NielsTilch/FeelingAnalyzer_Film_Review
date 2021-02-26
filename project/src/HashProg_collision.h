#ifndef HashProg_collision_h
#define HashProg_collision_h
#include "tableHachage_collision.h"
#include "listSimpleChain_collision.h"
#include "fonctionHachage.h"

char* creeNvMot(char* mot);//Entrée :  char * || Sortie : char * || But : Faire une allocation mémoire avec un malloc.

char* charTab2point(char tab[]); //Entrée : un tableau de char || Sortie : char * || But : Faire une allocation mémoire avec des mallocs.

char** split(char* commentaire); //Entrée : ligne de data avec nombre puis commentaire (ie char txt[]) || Sortie : char ** || But : Découper le commentaire selon les espaces. 

void ajouteAncienMots(char* mot ,TableHachage tab, int note,int hash); //Entrée : un mot, sa note et une table de hachage || Sortie : Table de hachage || But : Rentrer un mot qui était déjà dans la table.

void ajouteNouveauMots(char* mot, TableHachage tab, int note,int hash); //Entrée : un mot, sa note et une table de hachage || Sortie : Table de hachage || But : Rentrer un mot qui n'était pas encore dans la table.

int isIn(char* mot ,TableHachage tab,int hash); //Entrée : un mot et une table de hachage, ainsi que son hash || Sortie : 0 ou 1 (entier) || But : Regarder si le mot est déjà dans la table.

void rentreMot(char* mot ,TableHachage tab, int note, int hash); //Entrée :  un mot et une table de hachage || Sortie : table de hachage || But : Rentrer le mot dans la table.

//TableHachage rentrePhrase(char** PhraseEnMot, TableHachage tab); //Entrée : tableau de tout les mots de la phrase et une table de hachage || Sortie : Table de hachage|| But : Rentrer tous les mots dans la table de hachage et modifier le nb de notes et la moyenne.

int isNumber(char c); //Entrée : un caractère || Sortie : 0 ou 1 || But : Renvoie 1 si le caractère est un chiffre, 0 sinon.

char* removeNumber(char* mot); //Entrée : un mot || Sortie un mot || But : Supprimer les nombres dans un mot si celui-ci en contient.

char* maj2min(char* str); //Entrée : un mot || Sortie : un mot || But : Convertir les caractères majuscules du mot en minuscules.

TableHachage filledTab(FILE* fichier, TableHachage tab,int numFonction); //Entrée : le flot d'un fichier et une table de Hachage|| Sortie : Table de hachage contenant mots(clef) et moyennes/nb de notes/mot (element cf structure des listes || But : Rentrer tous les mots de toutes les phrases et calculer leur moyenne.

void ajouteNouveauMotsNIELS(char* mot ,TableHachage tab, int note,int numFonction,int hash);
void ajouteAncienMotsELISA(char* mot ,TableHachage tab, int note,int numFonction);

#endif
