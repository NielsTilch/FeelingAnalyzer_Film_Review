#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "HashProg_collision.h"

char** getFileText(const char* link){
	FILE* file=fopen(link,"r");
	char* text;
	fgets(text,100000,file);
	split
	return text
}


char** getFileText(const char* link){
	FILE* file=fopen(link,"r");
	if (file == NULL){
	    printf("Fichier non-trouvé");
	    return NULL;
	}
	char* text;
	char** listText;
	fgets(text,100000,file);
	listText = splitExclusion(text);
	return listText;
}

char** splitExclusion(char* commentaire) {
    int size = sizeof(commentaire);
	char** mots = (char**)calloc(size,sizeof(char*));
	char* delimiters = ";";
	char* mot = strtok(commentaire, delimiters);
	int i = 0;
	while (mot != NULL) {
		if (i < size){
				mots[i] = (char*)malloc((1+strlen(mot))*sizeof(char));
				strcpy(mots[i], mot);
				i++;
		}
		else {
			break;
		}
		mot = strtok(NULL, delimiters);
	}
	return mots;

int isMyWordsExclude(char* mot,char** liste){
    if (mot==NULL || liste==NULL){
        printf("Problème d'insertion de paramètres");
        return 0;
    }
    int i=0;
    while (liste[i]!=NULL){
        if (!strcmp(liste[i],mot)){
            return 0;
        }
        i++;
    }
    return 1;
}
