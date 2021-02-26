#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "analyseFonctionsHachage.h"
#include "listSimpleChain_collision.h"
#include "fonctionHachage.h"
#include "tableHachage_collision.h"
#include "HashProg_collision.h"
#include "analyseTable.h"


char* motAleatoire(){                         //malloc
	int n = 2 + rand() % 8;
	char* mot = malloc(sizeof(char)*(n+1));
	for (int l =0; l<n; l++){
		mot[l]= (char) 97 + (rand() % 25);
	}mot[n]='\0';
	return(mot);
}

void dispersion(int tailleTable, int nbMots){
	int N=tailleTable;  //table de taille N
	int valeurSHA1ReduitModulo[N];
	for (int i=0;i<N;i++){
		valeurSHA1ReduitModulo[i]=0;
	}
	int valeurSHA1ReduitPoids[N];
	for (int i=0;i<N;i++){
		valeurSHA1ReduitPoids[i]=0;
	}
	int valeurSHA1ReduitXor[N];
	for (int i=0;i<N;i++){
		valeurSHA1ReduitXor[i]=0;
	}
	int valeurFonction1[N];
	for (int i=0;i<N;i++){
		valeurFonction1[i]=0;
	}
	int valeurFonctionRec[N];
	for (int i=0;i<N;i++){
		valeurFonctionRec[i]=0;
	}

	int valeurFonctionNaivePoids[N];
	for (int i=0;i<N;i++){
		valeurFonctionNaivePoids[i]=0;
	}
		
	int tempSHA1ReduitModulo;
	int tempSHA1ReduitPoids;
	int tempSHA1ReduitXor;
	int tempFonction1;
	int tempFonctionRec;
	int tempFonctionNaivePoids;	

	char* mot;
	
	printf("Ici ok\n");
	for (int i =0; i<nbMots; i++){
		printf("i=%d ",i);
		mot=motAleatoire();
		tempSHA1ReduitModulo = sha1ReduitModulo(mot,N);
		tempSHA1ReduitPoids = sha1ReduitPoids(mot,N);
		tempFonction1=hachageNaif(mot,N);
		tempFonctionRec=hachageRec(mot,N);
		tempFonctionNaivePoids=hachagePoids(mot,N);
		tempSHA1ReduitXor= sha1ReduitXor(mot,N);
		
		valeurFonctionNaivePoids[tempFonctionNaivePoids]+=1;
		valeurSHA1ReduitModulo[tempSHA1ReduitModulo]+=1;
		valeurSHA1ReduitPoids[tempSHA1ReduitPoids]+=1;
		valeurFonction1[tempFonction1]+=1;
		valeurFonctionRec[tempFonctionRec]+=1;
		valeurSHA1ReduitXor[tempSHA1ReduitXor]+=1;
		free(mot);
	}
	printf("Les valeurs de hash sont :\n");
	for (int l=0; l<N; l++){
		printf("%d,",l);
	}printf("\nLes valeurs de hash sha1 poids sont :\n");
	for (int l=0; l<N; l++){
		printf("%d,",valeurSHA1ReduitPoids[l]);
	}printf("\nLes valeurs de hash simple sont :\n");
	for (int l=0; l<N; l++){
		printf("%d,",valeurFonction1[l]);
	}printf("\nLes valeurs de sha1 réduit modulo sont :\n");
	for (int l=0; l<N; l++){
		printf("%d,",valeurSHA1ReduitModulo[l]);
	}printf("\nLes valeurs de sha1 réduit xor sont :\n");
	for (int l=0; l<N; l++){
		printf("%d,",valeurSHA1ReduitXor[l]);
	}printf("\nLes valeurs de hash naive poids sont :\n");
	for (int l=0; l<N; l++){
		printf("%d,",valeurFonctionNaivePoids[l]);
	}printf("\nLes valeurs de hash recursive poids sont :\n");
	for (int l=0; l<N; l++){
		printf("%d,",valeurFonctionRec[l]);
	}
}


void nbCollisionRemplissage(int tailleTable, int nbEssai){
	char* mot;
	int nbCollRemplissageSHA1ReduitModulo[51];
	int nbCollRemplissageSHA1ReduitPoids[51];
	int nbCollRemplissageFonctionRec[51];
	int nbCollRemplissageFonction1[51];
	int nbCollRemplissageHachagePoids[51];
	int nbCollRemplissageHachageXor[51];
	for (int i=0; i<51; i++){
		nbCollRemplissageFonction1[i]=0;
		nbCollRemplissageSHA1ReduitModulo[i]=0;
		nbCollRemplissageFonctionRec[i]=0;
		nbCollRemplissageSHA1ReduitPoids[i]=0;
		nbCollRemplissageHachagePoids[i]=0;
		nbCollRemplissageHachageXor[i]=0;
	}
	int passageSHA1ReduitModulo[tailleTable];
	int passageSHA1ReduitPoids[tailleTable];
	int passageFonctionRec[tailleTable];
	int passageFonction1[tailleTable];
	int passageHachage1Poids[tailleTable];
	int passageSHA1ReduitXor[tailleTable];
	for (int i=0;i<tailleTable;i++){
		passageFonction1[i]=0;
		passageSHA1ReduitModulo[i]=0;
		passageSHA1ReduitXor[i]=0;
		passageFonctionRec[i]=0;
		passageSHA1ReduitPoids[i]=0;
		passageHachage1Poids[i]=0;
	}
	
	int tempSHA1Poids;
	int tempSHA1Mod;
	int tempSHA1Xor;
	int tempRec;
	int tempNaif;
	int tempNaifPoids;
	for (int i=0; i<51; i++){
		for (int k=0;k<tailleTable;k++){  //on réinitialise la table de passage
				passageFonction1[k]=0;
				passageSHA1ReduitModulo[k]=0;
				passageFonctionRec[k]=0;
				passageSHA1ReduitPoids[k]=0;
				passageHachage1Poids[k]=0;
				passageSHA1ReduitXor[k]=0;
		}for (int k =0; k<nbEssai; k++){
			printf("On est au %d essai\n",k);
			for (int j=0; j<=(int) (i*2*tailleTable)/100; j++){
				if (j==0){
					printf("Pour i= %d on prend %d mots\n",i,1+(i*2*tailleTable)/100);
				}
				mot=motAleatoire();
				tempSHA1Poids=sha1ReduitPoids(mot,tailleTable);
				tempSHA1Mod=sha1ReduitModulo(mot,tailleTable);
				tempRec=hachageRec(mot,tailleTable);
				tempNaif=hachageNaif(mot,tailleTable);
				tempSHA1Xor=sha1ReduitXor(mot,tailleTable);
				tempNaifPoids=hachagePoids(mot,tailleTable);
				if (passageSHA1ReduitModulo[tempSHA1Mod] == 1){
					nbCollRemplissageSHA1ReduitModulo[i] += 1; 
				}else{
					passageSHA1ReduitModulo[tempSHA1Mod] =1;
				}
				if (passageSHA1ReduitPoids[tempSHA1Poids] ==1){
					nbCollRemplissageSHA1ReduitPoids[i] += 1; 
				}else{
					passageSHA1ReduitPoids[tempSHA1Poids] =1;
				}
				if (passageSHA1ReduitXor[tempSHA1Xor] == 1){
					nbCollRemplissageHachageXor[i] += 1; 
				}else{
					passageSHA1ReduitXor[tempSHA1Xor] =1;
				}
				if (passageFonctionRec[tempRec] == 1){
					nbCollRemplissageFonctionRec[i] =nbCollRemplissageFonctionRec[i] + 1; 
				}else{
					passageFonctionRec[tempRec]=1;
				}
				if (passageFonction1[tempNaif] == 1){
					nbCollRemplissageFonction1[i] = nbCollRemplissageFonction1[i]+1; 
				}else{
					passageFonction1[tempNaif]=1;
				}
				if (passageHachage1Poids[tempNaifPoids] == 1){
					nbCollRemplissageHachagePoids[i] = nbCollRemplissageHachagePoids[i]+1; 
				}else{
					passageHachage1Poids[tempNaifPoids]=1;
				}
				//free(mot);  
			}
		}nbCollRemplissageFonction1[i]=nbCollRemplissageFonction1[i]/nbEssai;
		nbCollRemplissageHachagePoids[i]=nbCollRemplissageHachagePoids[i]/nbEssai;
		nbCollRemplissageFonctionRec[i]=nbCollRemplissageFonctionRec[i]/nbEssai;
		nbCollRemplissageSHA1ReduitPoids[i]=nbCollRemplissageSHA1ReduitPoids[i]/nbEssai;
		nbCollRemplissageSHA1ReduitModulo[i]=nbCollRemplissageSHA1ReduitModulo[i]/nbEssai;
		nbCollRemplissageHachageXor[i]=nbCollRemplissageHachageXor[i]/nbEssai;
	}
	printf("Les taux de remplissages sont : ");
	for (int i=0; i<51; i++){
		printf("%d,",(int) i*2);
	}printf("\n");
	printf("Le nombre de collision pour la fonction SHA1 réduit xor est : ");
	for (int i=0; i<51; i++){
		printf("%d,",nbCollRemplissageHachageXor[i]);
	}printf("\n");
	printf("Le nombre de collision pour SHA1 réduit poids ");
	for (int i=0; i<51; i++){
		printf("%d,",nbCollRemplissageSHA1ReduitPoids[i]);
	}printf("\n");
	printf("Le nombre de collision pour SHA1 réduit modulo ");
	for (int i=0; i<51; i++){
		printf("%d,",nbCollRemplissageSHA1ReduitModulo[i]);
	}printf("\n");
	printf("Le nombre de collision pour la fonction récursive est : ");
	for (int i=0; i<51; i++){
		printf("%d,",nbCollRemplissageFonctionRec[i]);
	}printf("\n");
	printf("Le nombre de collision pour la fonction naîve est : ");
	for (int i=0; i<51; i++){
		printf("%d,",nbCollRemplissageFonction1[i]);
	}printf("\n");
	printf("Le nombre de collision pour la fonction naîve avec poids est : ");
	for (int i=0; i<51; i++){
		printf("%d,",nbCollRemplissageHachagePoids[i]);
	}printf("\n");
}


void tempsHachageNbLettre(int tailleTable, int tailleMaxMot, int nbEssai){
	if (nbEssai ==0){
		return;
	}
	clock_t t1,t2;
	double tempsSHA1Poids[tailleMaxMot];
	double tempsSHA1Mod[tailleMaxMot];
	double tempsSHA1Xor[tailleMaxMot];
	double tempsNaif[tailleMaxMot];
	double tempsNaifPoids[tailleMaxMot];
	double tempsRec[tailleMaxMot];
	for (int i=0; i<tailleMaxMot; i++){
		tempsSHA1Poids[i]=0.0;
		tempsSHA1Mod[i]=0.0;
		tempsRec[i]=0.0;
		tempsNaifPoids[i]=0.0;
		tempsNaif[i]=0.0;
		tempsSHA1Xor[i]=0.0;
	}
	
	char* mot=malloc(sizeof(char)*(1));
	int res;
	
	for (int k=0; k<nbEssai; k++){
		for (int i=1; i<=tailleMaxMot; i++){
			mot = malloc(sizeof(char)*(i+1));
			for (int l =0; l<i; l++){
				mot[l]= (char) 97 + (rand() % 25);
			}mot[i]='\0';
			
			t1 = clock();
			res = sha1ReduitModulo(mot,tailleTable);
			t2 = clock();
			tempsSHA1Mod[i-1]+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
			
			t1 = clock();
			res = sha1ReduitXor(mot,tailleTable);
			t2 = clock();
			tempsSHA1Xor[i-1]+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
			
			t1 = clock();
			res = sha1ReduitPoids(mot,tailleTable);
			t2 = clock();
			tempsSHA1Poids[i-1]+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
			
			t1 = clock();
			res = hachageRec(mot,tailleTable);
			t2 = clock();
			tempsRec[i-1]+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
			
			t1 = clock();
			res = hachageNaif(mot,tailleTable);
			t2 = clock();
			tempsNaif[i-1]+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
			
			t1 = clock();
			res = hachagePoids(mot,tailleTable);
			t2 = clock();
			tempsNaifPoids[i-1]+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
			
			free(mot);
		}
	}
	printf("Pour un mot de longueur : ");
	for (int i=1; i<=tailleMaxMot; i++){
		printf("%d,",i);
	}printf("\n");
	printf("Le temps d'execution pour SHA1 réduit poids ");
	for (int i=0; i<tailleMaxMot; i++){
		printf("%f,",tempsSHA1Poids[i]*10000/(double) nbEssai);
	}printf("\n");
	printf("Le temps d'execution pour SHA1 réduit modulo ");
	for (int i=0; i<tailleMaxMot; i++){
		printf("%f,",tempsSHA1Mod[i]*10000/(double) nbEssai);
	}printf("\n");
	printf("Le temps d'execution pour  SHA1 réduit xor est : ");
	for (int i=0; i<tailleMaxMot; i++){
		printf("%f,",tempsSHA1Xor[i]*10000/(double) nbEssai);
	}printf("\n");
	printf("Le temps d'execution pour la fonction récursive est : ");
	for (int i=0; i<tailleMaxMot; i++){
		printf("%f,",tempsRec[i]*10000/(double) nbEssai);
	}printf("\n");
	printf("Le temps d'execution pour la fonction naîve est : ");
	for (int i=0; i<tailleMaxMot; i++){
		printf("%f,",tempsNaif[i]*10000/(double) nbEssai);
	}printf("\n");
	printf("Le temps d'execution pour la fonction naïve avec poids est : ");
	for (int i=0; i<tailleMaxMot; i++){
		printf("%f,",tempsNaifPoids[i]*10000/(double) nbEssai);
	}printf("\n");
}

float tpsRentreMot(char* nomFichier,int tailleTable, int numFonction){
	clock_t t1,t2;
	int nbMot=0;
	TableHachage tab = tableHachage_creer(tailleTable);
	double res;
	FILE* fichier = fopen(nomFichier,"r");
	if (fichier == NULL) {
		printf("Erreur à l'ouverture du fichier");
		return 0;
	}
	char ligne[500]; 
	while (fgets(ligne, 500, fichier) != NULL) {
		ligne[strnlen(ligne, 500)-1] = '\0';        
		char* ligneMin = maj2min(ligne);           
		char* ligneSansNb = removeNumber(ligneMin); 
		char** mots = split(ligneSansNb);       
		int i = 1;
		int hash;
		while (mots[i] != NULL) {
			printf("Le mot est : %s\n", mots[i]);
			hash=hachageFinal(mots[i],tab->tailleTableau,numFonction);
			t1=clock();
			rentreMot(mots[i], tab, 1,hash); //la note n'est pas importante, on met 1
			t2=clock();
			nbMot++;
			i++;
			res+=(double)(t2-t1)/(double)CLOCKS_PER_SEC;
		}
	}
	freeTable(tab);
	printf("Le nombre de mot est : %d\n",nbMot);
	return(res*10000000/nbMot);
}

float* compressionTable(int tailleTable){
	int nbMots=tailleTable;
	int N=tailleTable;  //table de taille N
	int valeurSHA1ReduitModulo[N];
	for (int i=0;i<N;i++){
		valeurSHA1ReduitModulo[i]=0;
	}
	int valeurSHA1ReduitPoids[N];
	for (int i=0;i<N;i++){
		valeurSHA1ReduitPoids[i]=0;
	}
	int valeurSHA1ReduitXor[N];
	for (int i=0;i<N;i++){
		valeurSHA1ReduitXor[i]=0;
	}
	int valeurFonction1[N];
	for (int i=0;i<N;i++){
		valeurFonction1[i]=0;
	}
	int valeurFonctionRec[N];
	for (int i=0;i<N;i++){
		valeurFonctionRec[i]=0;
	}

	int valeurFonctionNaivePoids[N];
	for (int i=0;i<N;i++){
		valeurFonctionNaivePoids[i]=0;
	}
		
	int tempSHA1ReduitModulo;
	int tempSHA1ReduitPoids;
	int tempSHA1ReduitXor;
	int tempFonction1;
	int tempFonctionRec;
	int tempFonctionNaivePoids;	

	float compressionSHA1ReduitModulo=0.0;
	float compressionSHA1ReduitPoids=0.0;
	float compressionSHA1ReduitXor=0.0;
	float compressionFonction1=0.0;
	float compressionFonctionRec=0.0;
	float compressionFonctionNaivePoids=0.0;	

	char* mot;
	
	fprintf(stderr,"Ici ok\n");
	for (int i =0; i<nbMots; i++){
		fprintf(stderr,"\n\n\ni=%d ",i);
		mot=motAleatoire();
		tempSHA1ReduitModulo = sha1ReduitModulo(mot,N);
		fprintf(stderr,"FONCTION 1\n");
		tempSHA1ReduitPoids = sha1ReduitPoids(mot,N);
		fprintf(stderr,"FONCTION 2\n");
		tempFonction1=hachageNaif(mot,N);
		fprintf(stderr,"FONCTION 3\n");
		tempFonctionRec=hachageRec(mot,N);
		fprintf(stderr,"FONCTION 4\n");
		tempFonctionNaivePoids=hachagePoids(mot,N);
		fprintf(stderr,"FONCTION 5\n");
		tempSHA1ReduitXor= sha1ReduitXor(mot,N);
		fprintf(stderr,"Ok fonction\n");
		valeurFonctionNaivePoids[tempFonctionNaivePoids]+=1;
		valeurSHA1ReduitModulo[tempSHA1ReduitModulo]+=1;
		valeurSHA1ReduitPoids[tempSHA1ReduitPoids]+=1;
		valeurFonction1[tempFonction1]+=1;
		valeurFonctionRec[tempFonctionRec]+=1;
		valeurSHA1ReduitXor[tempSHA1ReduitXor]+=1;
		
		free(mot);
	}fprintf(stderr,"Ici ok\n");
	for (int i=0; i<tailleTable; i++){
		if (valeurFonctionNaivePoids[i] != 0.0){
			compressionFonctionNaivePoids=compressionFonctionNaivePoids+1.0;
		}if (valeurSHA1ReduitModulo[i] != 0.0){
			compressionSHA1ReduitModulo=compressionSHA1ReduitModulo+1.0;
		}if (valeurSHA1ReduitPoids[i] != 0.0){
			compressionSHA1ReduitPoids=compressionSHA1ReduitPoids+1.0;
		}if (valeurFonction1[i] != 0.0){
			compressionFonction1=compressionFonction1+1.0;
		}if (valeurFonctionRec[i] != 0.0){
			compressionFonctionRec=compressionFonctionRec+1.0;
		}if (valeurSHA1ReduitXor[i] != 0.0){
			compressionSHA1ReduitXor=compressionSHA1ReduitXor+1.0;
		}
	}
	float* resCompression = malloc(sizeof(float)*6);
	resCompression[0]=compressionFonction1/(float)tailleTable;
	printf("0: %f\n",resCompression[0]);
	resCompression[1]=compressionFonctionNaivePoids/(float)tailleTable;
	printf("1: %f\n",resCompression[1]);
	resCompression[2]=compressionFonctionRec/(float)tailleTable;
	printf("2: %f\n",resCompression[2]);
	resCompression[3]=compressionSHA1ReduitModulo/(float)tailleTable;
	printf("3: %f\n",resCompression[3]);
	resCompression[4]=compressionSHA1ReduitPoids/(float)tailleTable;
	printf("4: %f\n",resCompression[4]);
	resCompression[5]=compressionSHA1ReduitXor/(float)tailleTable;
	printf("5: %f\n",resCompression[5]);
	return(resCompression);
}

void moyenneCompression(int tailleMin, int tailleMax, int nbExp){
	if ( (tailleMax-tailleMin) % 100 !=0){
		printf("La différence entre taille max et la taille min n'est pas de 100\n");
	}
	float comp0[tailleMax-tailleMin];
	float comp1[tailleMax-tailleMin];
	float comp2[tailleMax-tailleMin];
	float comp3[tailleMax-tailleMin];
	float comp4[tailleMax-tailleMin];
	float comp5[tailleMax-tailleMin];
	
	float* resComp;
	for (int j=tailleMin; j<tailleMax; j=j+500){
		for (int n=0; n<nbExp; n++){
			resComp = compressionTable(j);
			comp0[j-tailleMin]+=resComp[0];
			comp1[j-tailleMin]+=resComp[1];
			comp2[j-tailleMin]+=resComp[2];
			comp3[j-tailleMin]+=resComp[3];
			comp4[j-tailleMin]+=resComp[4];
			comp5[j-tailleMin]+=resComp[5];
			free(resComp);
		}
		comp0[j-tailleMin]=comp0[j-tailleMin]/nbExp;
		comp1[j-tailleMin]=comp1[j-tailleMin]/nbExp;
		comp2[j-tailleMin]=comp2[j-tailleMin]/nbExp;
		comp3[j-tailleMin]=comp3[j-tailleMin]/nbExp;
		comp4[j-tailleMin]=comp4[j-tailleMin]/nbExp;
		comp5[j-tailleMin]=comp5[j-tailleMin]/nbExp;;
	}
	printf("\nFonction 0, ");
	for (int j=tailleMin; j<tailleMax; j=j+500){
		printf("%f, ",comp0[j-tailleMin]);
	}
	printf("\nFonction 1, ");
	for (int j=tailleMin; j<tailleMax; j=j+500){
		printf("%f, ",comp1[j-tailleMin]);
	}
	printf("\nFonction 2, ");
	for (int j=tailleMin; j<tailleMax; j=j+500){
		printf("%f, ",comp2[j-tailleMin]);
	}
	printf("\nFonction 3, ");
	for (int j=tailleMin; j<tailleMax; j=j+500){
		printf("%f, ",comp3[j-tailleMin]);
	}
	printf("\nFonction 4, ");
	for (int j=tailleMin; j<tailleMax; j=j+500){
		printf("%f, ",comp4[j-tailleMin]);
	}
	printf("\nFonction 5, ");
	for (int j=tailleMin; j<tailleMax; j=j+500){
		printf("%f, ",comp5[j-tailleMin]);
	}
}












