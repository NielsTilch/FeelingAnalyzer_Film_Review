#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** decoupeMot(char* phrase){
	char *mot;
	int i = 0;
	int ibis=0;
	int ksauv=0;
	int isauv=0;
	int k = 0;
	int N=20;
   	char** sortie = (char**)malloc(sizeof(char*)*N);
   	for(int i=0; i<N; i++){
    	sortie[i] = (char*)malloc(50 * sizeof(char));
	}
	while (phrase[i+k] != '\0'){
		printf("Le tour %d\n",i);
		ksauv=k;
		isauv=i;
		while (phrase[k+i] != ' '){
			printf("ibis vaut : %d\n", ibis);
			printf("Le caractère dans phrase %d : %c\n",i+k,phrase[i+k]);
			sortie[ibis][k]=phrase[i+k];
			printf("Le caractère dans sortie %d : %c\n",ibis,sortie[ibis][k]);
			printf("Le mot  du tour %d : A%sA \n ",ibis,sortie[ibis]);
			k++;
		}
		if (phrase[ksauv+isauv] != 'c'){
			ibis++;
		}
		//printf("Le mot  du tour %d : A%sA \n ",i,sortie[i]);
		i++;
	}
	return(sortie);
}

int main (){
	int k = 0;
    char* str = "Ceci est un premier test .";
    const char* del = "c";
	//decoupe(str);
	char** res = decoupeMot(str);
	//while (res[k] != NULL)
		printf("%s",res[1]);
		//k++;
    return 0;
}
