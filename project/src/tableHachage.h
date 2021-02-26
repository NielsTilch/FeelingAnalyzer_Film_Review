#ifndef tableHachage_h
#define tableHachage_h
#include "listSimpleChain.h" /// ????


typedef struct tableHachageStruct {
	Liste tableauListe;
	int tailleTableau;
}tableHachage;


typedef tableHachage* TableHachage;

int psc(int a, int b);
int hachageNaif(char *s, int mod);
int hachagePoids(char *s, int mod);
int f4(int x);
int hachageRec(char *s, int mod);

TableHachage tableHachage_creer(int tailleTableau);
ELEMENT tableHachage_get(Clef c, TableHachage t);
void tableHachage_ajout(ELEMENT e, TableHachage t);
void tableHachage_supprime(Clef c, TableHachage t);
void tableHachage_visualiser(TableHachage t);


#endif
