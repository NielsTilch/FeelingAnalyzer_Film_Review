#ifndef statistics_h
#define statistics_h

#include "fonctionHachage.h"
#include "HashProg_collision.h"
#include "tableHachage_collision.h"
#include "listSimpleChain_collision.h"
#include "listSimpleChain_float.h"
#include "listSimpleChain_int.h"
#include "listSimpleChain_str.h"
#include "arbresFloat.h"
#include "arbres.h"

node* avl_sortedOccurrence(TableHachage tab);
ListeInt list_sortedOccurrence(node* bst);
ListeStr getSameOcurrenceWords(TableHachage tab, int occurrence);
int getTableNumberWords(TableHachage tab);
char** orderedWords(TableHachage tab);
void print_leastRecurrentWords(TableHachage tab, int n);
int size_orderedWords(TableHachage tab);
void print_mostRecurrentWords(TableHachage tab, int n);
nodeFloat* avl_sortedScore(TableHachage tab);
ListeFloat list_sortedScore(nodeFloat* bst);
char** getWords(TableHachage tab, float min, float max);
void print_words(TableHachage tab, float min, float max);
float averageScore(TableHachage tab);

#endif