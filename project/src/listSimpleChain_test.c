#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "listSimpleChain.h"

int main(int argc, char const *argv[])
{

	ELEMENT e0, e1, e2;
	e0.clef = "a"

	Liste l0 = list_creer();

	Liste l1 = list_creer();
	list_ajoutFin(l1, e0);

	Liste l2 = list_creer();
	list_ajoutFin(l2, e1);
	list_ajoutFin(l2, e0);

	Liste l3 = list_creer();
	list_ajoutFin(l3, e0);
	list_ajoutFin(l3, e1);

	Liste l4 = list_creer();
	list_ajoutFin(l4, e2);
	list_ajoutFin(l4, e1);
	list_ajoutFin(l4, e0);

	Liste l5 = list_creer();
	list_ajoutFin(l5, e0);
	list_ajoutFin(l5, e2);
	list_ajoutFin(l5, e1);


	// test_list_estVide______________________________________________________

	assert(list_estVide(l0) == 1);
	assert(list_estVide(l1) == 0);

	// test_size______________________________________________________________

	assert(size(l0) == 0);
	assert(size(l1) == 1);
	assert(size(l4) == 3);

	// test_list_ajoutTete____________________________________________________

	// list_visualiser(list_ajoutTete(l0, e0));
	// list_visualiser(l1);

	// list_visualiser(list_ajoutTete(l1, e1));
	// list_visualiser(l2);

	// list_visualiser(list_ajoutTete(l2, e2));
	// list_visualiser(l4);

	// test_nieme_cellule_____________________________________________________

	// Liste l6 = nieme_cellule(l4, 2);
	// list_visualiser(l6);
	// list_visualiser(l1);

	// test_list_ajoutN_______________________________________________________
	
	// list_ajoutN(l1, e1, 1);
	// list_visualiser(l1);
	// list_visualiser(l3);

	// list_ajoutN(l3, e2, 1);
	// list_visualiser(l3);
	// list_visualiser(l5);

	// test_list_rechN________________________________________________________

	assert(strcmp(list_rechN(l0, "a", 1), " ") == 0);
	assert(strcmp(list_rechN(l4, "a", 3), "a") == 0);
	assert(strcmp(list_rechN(l4, "c", 2), "c") == 0);
	assert(strcmp(list_rechN(l4, "d", 1), "d") != 0);
	assert(strcmp(list_rechN(l4, "d", -1), " ") == 0);

	// test_list_rech_________________________________________________________

	assert(strcmp(list_rech(l0, "a"), " ") == 0);
	assert(strcmp(list_rech(l3, "a"), "a") == 0);
	assert(strcmp(list_rech(l4, "c"), "c") == 0);
	assert(strcmp(list_rech(l4, "d"), " ") == 0);

	// test_list_remove_______________________________________________________
	
	list_visualiser(list_remove(l0, e0));
	list_visualiser(list_remove(l1, e0));
	list_visualiser(list_remove(l4, e2));
	list_visualiser(list_remove(l3, e0));
	list_visualiser(list_remove(l3, e2));
	
	// test_list_removeN______________________________________________________

	list_visualiser(list_removeN(l0, 4));
	list_visualiser(list_removeN(l1, 0));
	list_visualiser(list_removeN(l1, 3));
	list_visualiser(list_removeN(l4, 0));
	list_visualiser(list_removeN(l4, 2));
	list_visualiser(list_removeN(l4, 8));
	list_visualiser(list_removeN(l5, 1));

	return 0;
}
