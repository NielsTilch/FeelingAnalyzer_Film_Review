#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void decoupe(char* phrase){
	char *mot;
	int N=30;
	int i =0;
	char** sortie;
	while( phrase != NULL ){
		printf("%s",phrase);
		sortie[i]=phrase+1;
		phrase=phrase+1;
		phrase = strchr(phrase,32) ;
	}
   	//return(sortie);
}

int main ()
{
    char str[] ="Apprendre a programmer en C.n";
    char *token;
   
    printf ("La chaine '%s' en morceaux:\n", str);
 
    //Découper la chaîne selon les espaces
    token = strtok (str," ");
 
    //Afficher le résultat du découpage
 
    while (token != NULL)
    {
        printf ("%s \n", token);
        token = strtok (NULL, " ,");
 
    }
    return 0;
}
