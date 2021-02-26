#ifndef analyseFonctionsHachage_h
#define analyseFonctionsHachage_h

#include "listSimpleChain_collision.h"
#include "fonctionHachage.h"
#include "tableHachage_collision.h"
#include "HashProg_collision.h"
#include "analyseTable.h"

void dispersion(int tailleTable, int nbMots);
char* motAleatoire();
void nbCollisionRemplissage(int tailleTable,int nbEssai);
float tpsRentreMot(char* nomFichier,int tailleTable, int numFonction);
float* compressionTable(int tailleTable);
void moyenneCompression(int tailleMin, int tailleMax, int nbExp);

#endif
