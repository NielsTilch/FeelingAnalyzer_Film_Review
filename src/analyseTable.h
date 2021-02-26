#ifndef analyseTable_h
#define analyseTable_h

#include "fonctionHachage.h"
#include "listSimpleChain_collision.h"
#include "HashProg_collision.h"
#include "tableHachage_collision.h"

float tpsRechercheMot(TableHachage tab, char* nomFichier, int numFonction);
float facteurCompression(TableHachage tab);
int getTableNumberWords(TableHachage tab);

#endif
