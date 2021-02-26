char** getFileTextExclusion(const char* link);
//Entrée : Lien du fichier.
//Sortie : La liste des mots exclus.

char** splitExclusion(char* commentaire);
//Fonction directe de HashProg_collision (pour éviter d'avoir une dépendace circulaire)
//Entrée : Un texte.
//Sortie : Retourne une liste des mots du texte en entrée.

int isMyWordsExclude(char* mot,char** liste);
//Entrée : Un mot, et une liste de mots
//Sortie : 0 -> Le mot est exclu
//         1 -> Le mot n'est pas exclu

/*
Les fichiers d'exclusion de mot sont de la forme :

mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;mot;
*/