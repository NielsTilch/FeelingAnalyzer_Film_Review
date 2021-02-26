#ifndef fonctionHachage_h
#define fonctionHachage_h

char* retourne(char* mot);

char* letter2Bin(char lettre);//Entrée : char || Sortie : char* || But : Convertir une lettre en chaine de caractère la représentant en binaire.

char* mot2Bin(char* mot);//Entrée : char* || Sortie : char* || But : Convertir un mot en chaine de caractère le représentant en binaire.

int bin2Int(char* bin);//Entrée : chaine de caractère représentant un binaire || Sortie :entier || But : Convertir un bainaire en entier

char* int2Bin(int d);//Entrée : entier || Sortie : binaire dans une chaine d ecarctère || But : Convertir un entier en binaire

int psc(int a, int b); //Entrée : 2 entiers a et b  || Sortie : entier || But : calculer a puissance b 
int psc2sup(int a);  //Entrée : entier  || Sortie : entier || But : calculer la puissance de 2 supérieur de l'entree.

char* add32(char* x,char* y);//Entrée : 2 chaines de caractère représentant un binaire || Sortie : chaine de caractère représentant un binaire || But : faire une addition modulo 2^32 de ces deux chaines.



char** decoupe(char* bloc512, int dec);//Entrée :chaine de caractère représentant un binaire de taille 512 et entier représentant la longueur de découpage || Sortie : 512/dec chaines de caarctères || But : faire 512/dec chaines de caractère de longueur dec

char* rotation(char* str,int dec);//Entrée :chaine de caractère représentant un binaire et entier || Sortie : chaine de caractères || But : faire une roattion de dec bits sur la chaines d'entrée

char* xorStr(char* str1, char* str2);//Entrée : 2 chaine de caractère représentant un binaire et entier || Sortie : chaine de caractères || But : faire un xor bit a bit sur les chaines d'entrée

char* add32_5(char* x,char* y, char* z, char* t, char* v);//Entrée : 5 chaines de caractère représentant un binaire || Sortie : chaine de caractère représentant un binaire || But : faire une addition modulo 2^32 de ces cinq chaines.

char* merkleDamgard(char* motBin);//Entrée : chaine de caractère représentant un binaire || Sortie : chaine de caractère représentant un binaire || But : Allonger le bloc d'entré en un bloc de taille 512

char* mot2merkleDamgard(char* mot);//Entrée : chaine de caractère représentant un mot || Sortie : chaine de caractère représentant un binaire || But : Convertir le mot et l'allonger le bloc d'entré en un bloc de taille 512

int ite(int x, int y , int z);//Entrée : 3 entiers codé en ascii || Sortie : 1 entier  || But : résultat de la fonction ite de sha1

int xor3(int x, int y , int z);//Entrée : 3 entiers codé en ascii || Sortie : 1 entier  || But : résultat du xor sur 3 entier

int maj(int x, int y , int z);//Entrée : 3 entiers codé en ascii || Sortie : 1 entier  || But : résultat de la fonction maj de sha1

char* phi(char* x, char* y , char* z, int i);//Entrée : 3 chaine de caractère représentant un binaire et un indice|| Sortie : chaine de caractère  || But : faire bit a bit la fonction ite,maj ou xor 3 selon l'indice i

char** Wdec(char** blocs32Bits_16);//Entrée : suite de chaine de caractère représentant un binaire (16 normalement) || Sortie : 79 chaine de caractère  || But : créer des chaine de caractère à partir de celle passé en entrée

char* K(int i);//Entrée :indice i || Sortie : chaine de caractère représentant un binaire || But : donner une constante ne fonction de l'indice i


char* sha1(char* mot);//Entrée : chaine de caractère (un mot) || Sortie : chaine de caractère représentant un binaire || But : avoir le hash du mot en binaire
int sha1ReduitModulo(char* mot,int tailleTable);//Entrée : chaine de caractère (un mot) || Sortie : entier || But : avoir le hash du mot en entier
int sha1ReduitPoids(char* mot,int tailleTable);//Entrée : chaine de caractère (un mot) || Sortie : entier || But : avoir le hash du mot en entier

char* allongeHash(char* mot, int tailleTable, int pscSup);
int sha1ReduitXor(char* mot,int tailleTable);


























#endif
