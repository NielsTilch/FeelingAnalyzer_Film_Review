#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "fonctionHachage.h"

////////////////////////////// FONCTIONS AUXILLIAIRES ////////////////////////////////////

int psc2sup(int a){
	if (a<0){
		return(-666);
	}
	int arret=1;
	int res=0;
	while (arret<a){
		arret = arret*2 ;
		res++;
	}
	return(res);
}
char* retourne(char* mot){          
    if (!strcmp("",mot)){
    	return("");
    }
    int n = strlen(mot);
    char* nvMot = malloc(sizeof(char)*(n + 2));
    for (int i =0; i<n; i++){ 
	//printf("i=%d et n-1-i=%d\n",i,n-1-i);
        nvMot[i] = mot[n - 1 - i];
    }
    nvMot[n] = '\0';
    return(nvMot);
}

char* int2Bin(int d){  
	char* bin = malloc(sizeof(char)*10);
	for (int l=0; l<9; l++){
		bin[l]='0';
	}bin[9]='\0';
	int k=0;
	while ( d !=0 ){
		if (d % 2 == 0){
			bin[k]='0';
		}else{
			bin[k]='1';
		}
		d = (int) d/2;
		k++;
	}char* res = retourne(bin);
	free(bin);
	//printf("res=%s\n",res);
	return(res); 
}


int bin2Int(char* bin){
	if (!strcmp(bin,"")){
		return(0);
	}
	int n = strlen(bin);;
	int res=0;
	for(int k=0; k<n; k++){
		res=res+(bin[k]-48)*psc(2,n-k-1);
	}return(res);
}

char* letter2Bin(char lettre){                      
	char* res1;
	int lettreInt = (int) lettre;
	res1=int2Bin(lettreInt);
	return(res1);
}

char* mot2Bin(char* mot){
	//printf("Dans mot2Bin le mot est : '%s'\n",mot);
	int n =strlen(mot);
	char* res = (char*) malloc( sizeof(char)*(n*9+1) ); //max un mot de 25 lettres
	char* temp;
	for (int i =0; i<n; i++){
		temp=letter2Bin(mot[i]);
		//printf("mot[i] = %c et temp est : '%s'\n",mot[i],temp); 
		for (int l =0; l<(int)strlen(temp); l++){
			res[i*9+l]=temp[l];   // 9 = strlen(temp)
		}
		//printf("res='%s'\n",res);
		free(temp);
	}res[n*9]='\0';
	return(res);
}

char** decoupe(char* bloc512, int dec){           
	//printf("Le bloc de decoupe est : '%s'\n",bloc512);
	int n= strlen(bloc512);
	int nbBloc = n/dec; 
	//printf("nbBloc = %d et n =%d et dec = %d\n",nbBloc,n,dec);
	char** blocs32 = (char**) malloc(sizeof(char*)*(nbBloc));
	for (int i = 0; i < nbBloc; i++){
		//printf("i=%d\n",i);
		blocs32[i] = (char*) malloc(sizeof(char)*(dec+1));
	}
	//if (n != 512){
		//printf("La longueur de bloc512 n'est pas 512 mais : %ld\n", strlen(bloc512));
		//return(blocs32);
	//}else{
		for (int k = 0; k<nbBloc; k++){
			for (int l = dec*k; l<dec*(k+1); l++){ 
				blocs32[k][l-dec*k]=bloc512[l];
			}
			blocs32[k][dec]='\0';
			if ((int) strlen(blocs32[k]) != dec){
				printf("Problème dans la taille du découpage : %ld au lieu de %d",strlen(blocs32[k]),dec);
			}
		//}
	}return(blocs32);
}

char* rotation(char* str,int dec){  /*une rotation de dec bits*/      
	if (!strcmp("",str)){           /*SI la chaine est vide on la retourne tout de suite*/
		return("");
	}if (dec<0){
		return(str);
	}
	int n = strlen(str);
	char* strDec = malloc(sizeof(char)*(n+1)); /*On rée une nouvelle chaîne de la mm longueur */
	for (int i=0; i<n; i++){
		strDec[i]='0';
	}strDec[n]='\0';
	int k=0;
	//char* temp= strdup(str);
	while (k != n-dec){                     /* On la remplit avec les n-dec derniers bits*/
		strDec[k]=str[k+dec];
		k++;
	}
	for (int l =0; l<dec; l++){				/* On la complète avec les dec premiers bits*/
		strDec[n-dec+l]=str[l];  //et pas str ? 
	}//free(temp);
	return(strDec);
}

char* xorStr(char* str1, char* str2){                           
	int n=strlen(str2);
	if ( (int) strlen(str1) != n ){
		printf("Les deux chaines ne sont pas de la même longueur dans xorStr ! Longueur str1=%ld et longueur str2=%d\n",strlen(str1),n );
		return("");
	}
	char* res = malloc(sizeof(char)*(n+1));
	for (int i=0; i<n; i++){
		res[i]='0';
	}res[n]='\0';

	for (int i=0; i<n; i++){     /*On fait un xor bit à bit en faisant attention au code ascii*/
		int a = str1[i] -48 ;
		int b = str2[i] -48 ;
		if ( (a != 0 && a!=1) || (b != 0 && b != 1) ){
			printf("Problème avec a ^ b, a = %d et b =%d\n dans xorStr",a,b);
		}
		res[i] = (char) ((a ^ b) + 48) ;
	}res[n]='\0';
	return(res);
}

int psc(int a, int b){
	if (b<0){
		printf("Attention, b négatif dans la fonction psc :%d",b);
		return(0);
	}
	int res=1;
	for (int k =0; k<b;k++){
		res=res*a;
	}
	return(res);
}

char* add32(char* x,char* y){ 	
	int n =strlen(x);
	char* res = malloc(sizeof(char)*(n+1));
	for (int i=0; i<(n+1);i++){
		res[i]=0;
	}res[n]='\0';
	if (strlen(x) != strlen(y) ){
		printf("Les deux chaines n'ont pas la même taille dans add32 : x = %ld et y = %ld", strlen(x),strlen(y));
		return(res);
	}
	int retenu = 0;
	for (int i=0; i<n;i++){        /*Une addition bit à bit sur la longueur de la chaine*/
		if (retenu ==0){
			if (x[n-i-1] == '0' && y[n-i-1] == '0' ){
				res[i]='0';
				retenu = 0;
			}else if (x[n-i-1] == '1' && y[n-i-1] == '1'){
				res[i]='0';
				retenu = 1;
			}else{
				res[i]='1';
				retenu=0;
			}
		}else{
			if (x[n-i-1] == '0' && y[n-i-1] == '0' ){
				res[i]='1';
				retenu = 0;
			}else if (x[n-i-1] == '1' && y[n-i-1] == '1'){
				res[i]='1';
				retenu = 1;
			}else{
				res[i]='0';
				retenu=1;
			}
		}
	}
	res[n]='\0';
	char* resFin=retourne(res);
	free(res);
	return(resFin);
}





///////////////////////////////////// FONCTIONS SECONDAIRES /////////////////////////////////

char* merkleDamgard(char* motBin){       
	//printf("motBin est :'%s'\n",motBin); 
	char* motAllonge = (char*) malloc(sizeof(char)*513);
	int n = strlen(motBin);
	for (int l =0; l<n; l++){
		motAllonge[l]=motBin[l];
	}motAllonge[n]='1';
	//strcat(motAllonge,motBin);
	int l = strlen(motBin);   // déjà définie avec n
	int k = 512-l-1;
	if (k<0){
		while (k<0){
			k=k+512;
		}
	}for (int i=0; i<k;i++){
		motAllonge[n+i+1]='0';
	}motAllonge[512]='\0';
	if (strlen(motAllonge)-512 != 0 ){
		printf("ERREUR, la longueur de la chaine n'est pas un multiple de 512 mais vaut : %ld\n", strlen(motAllonge) );
	}//printf("MD: '%s'\n", motAllonge);
	return(motAllonge);
}
 
char* mot2merkleDamgard(char* mot){
	char* motbin = mot2Bin(mot);
	char* bloc = merkleDamgard(motbin);
	free(motbin);
	return(bloc);
}

int ite(int x, int y , int z){   
	if ( (x!= 48 && x!= 49) || (y!= 48 && y!= 49) || (z!= 48 && z!= 49)){
		printf("Attention, ce ne sont pas des 0 et des 1 dans ite\n");
		return(-666);
	}  
	int res;
	int nonX;
	if ( x==48){
		nonX=1;
	}else{
		nonX=0;
	}
	res= ((x-48)*(y-48))^(nonX*(z-48));
	return(res+48);
}

int xor3(int x, int y , int z){
	if ( (x!= 48 && x!= 49) || (y!= 48 && y!= 49) || (z!= 48 && z!= 49)){
		printf("Attention, ce ne sont pas des 0 et des 1 dans xor3\n");
		return(-666);
	}
	int res;
	res = (x-48)^(y-48)^(z-48);
	return(res+48);
}

int maj(int x, int y , int z){
	if ( (x!= 48 && x!= 49) || (y!= 48 && y!= 49) || (z!= 48 && z!= 49)){
		printf("Attention, ce ne sont pas des 0 et des 1 dans MAJ\n");
		return(-666);
	}
	int res = ( (x-48)*(y-48) ^ (x-48)*(z-48) ) ^ (y-48)*(z-48);
	return(res+48);
}

char* phi(char* x, char* y , char* z, int i){    ///malloc
	char* res =malloc(sizeof(char)*33);
	for (int i=0; i<32; i++){
		res[i]='0';
	}res[32]='\0';
	//printf("Au début phi=%s",res);
	if (strlen(x) != strlen(y) || strlen(y) != strlen(z)){
		printf("Problème de taille dans phi strlen(x)=%ld,strlen(y)=%ld,strlen(z)=%ld",strlen(x),strlen(y),strlen(z));
		return(res);
	}for (int l=0; l<(int)strlen(x); l++){
		if (i<=19 && i>=0){
			res[l]=ite(x[l],y[l],z[l]);
		}else if( (i<=39 && i>=20) || (i<= 79 && i>=60) ){
			res[l]=xor3(x[l],y[l],z[l]);
		}else if (i<=40 && i<= 59){
			res[l]=maj(x[l],y[l],z[l]);
		}
	}res[32]='\0';
	return(res);
}

 char** Wdec(char** blocs32Bits_16){                        //double malloc
 	char** listeW= (char**) malloc(sizeof(char*)*80);
 	for (int i =0; i<15; i++){
 		//printf("blocs32Bits_16[%d] = '%s' et taille de %ld\n",i,blocs32Bits_16[i],strlen(blocs32Bits_16[i]));
 	}
 	for (int i =0; i<80; i++){
 		listeW[i] = (char*) malloc(sizeof(char)*33);
 	}
 	char* intXorStr1;
 	char* intXorStr2;
 	char* intXorStr3;
 	char* intRotation;
 	
 	for (int k=0; k<=15; k++){
 		for (int i=0;i<32;i++){
 			listeW[k][i]= blocs32Bits_16[k][i];
 		}listeW[k][32]='\0';
 	}for (int k=0; k<=15; k++){
 		//printf("\nW[%d] = '%s' de taille %ld\n",k,listeW[k],strlen(listeW[k]));
 	}
 	for (int k=16; k<=79; k++){
 		intXorStr1=xorStr(listeW[k-3],listeW[k-8]);
 		//printf("intXorStr1 : %ld\n",strlen(intXorStr1));
 		intXorStr2=xorStr(intXorStr1,listeW[k-14]);
 		//printf("intXorStr2 : %ld\n",strlen(intXorStr2));
 		free(intXorStr1);
 		intXorStr3=xorStr(intXorStr2,listeW[k-16]);
 		//printf("intXorStr3 : %ld\n",strlen(intXorStr3));
 		free(intXorStr2);
 		
 		intRotation=rotation(intXorStr3,1);
 		free(intXorStr3);
 		
 		for (int i=0; i<(int)strlen(intRotation);i++){
 			listeW[k][i]=intRotation[i];
 		}listeW[k][strlen(intRotation)]='\0';
 		//printf("\nlisteW[%d]='%s' et la taille de listeW[%d]=%ld\n",k,listeW[k],k,strlen(listeW[k]));
 		free(intRotation);	
 	}return(listeW);
 }
 
 char* K(int i){ //constantes dépendant du tour.
 	if (i<19 && i>0){
 		return("01011010100000100111100110011001");
 	}else if (i<39 && i>20){
 		return("11101110110110011110101110100001");
 	}else if (i<59 && i>40){
 		return("10001111000110111011110011011100");
 	}else{
 		return("11001010011000101100000111010110");
 	}
 }

char* add32_5(char* x,char* y, char* z, char* t, char* v){  //malloc
	char* xy = add32(x,y);
	char* xyz = add32(xy,z);
	free(xy);
	char* xyzt =add32(xyz,t) ;
	free(xyz);
	char* xyztv = add32(xyzt,v);
	free(xyzt);
	return(xyztv);
}

 ///////////////////////////////////////// FONCTION PRINCIPALE /////////////////////////////////

char* sha1(char* mot){

 	char* A="01100111010001010010001100000001"; //initialisation des constantes de longueur 32
 	char* B="11101111110011011010101110001001";
 	char* C="10011000101110101101110011111110";
 	char* D="00010000001100100101010001110110";
 	char* E="11000011110100101110000111110000";
 	
 	char* hash0="01100111010001010010001100000001"; //initialisation des hash avec les cst
 	char* hash1="11101111110011011010101110001001";
 	char* hash2="10011000101110101101110011111110";
 	char* hash3="00010000001100100101010001110110";
 	char* hash4="11000011110100101110000111110000";
 	
 	char cpyA[33];
 	char cpyB[33];
 	char cpyC[33];
 	char cpyD[33];
 	char cpyE[33];
 	
 	char* phiRes;
 	char* rotCpyB;
 	
 	char* hash = malloc(sizeof(char)*161);
 	
 	char* blocFin= mot2merkleDamgard(mot);
 	if (strlen(blocFin) != 512){
 		printf("Surprise ! Ma taille est de : %ld", strlen(blocFin));
 	}
 	char** blocDecoupe = decoupe(blocFin,32);
 	free(blocFin);
 	char** W=Wdec(blocDecoupe);
 	
 	for (int i =0; i<80; i++){
 	
 		//printf("\n----On est au tour %d\n",i);
 		
 		strcpy(cpyA,A);
 		strcpy(cpyB,B);
 		strcpy(cpyC,C);
 		strcpy(cpyD,D);
 		strcpy(cpyE,E);
 		
 		if (i>0){
 			free(A);
 			free(C);
 		}
 		//printf("On a free A et B au tour %d\n",i);
 		E=cpyD;
 		//printf("Check point 5!");
 		D=cpyC;
 		//printf("Check point 4!");
 		C=rotation(cpyB,30);;
 		//printf("Check point 3!");
 		
 		B=cpyA;
 		phiRes = phi(cpyB,cpyC,cpyD,i);
 		rotCpyB = rotation(cpyB,5);
 		//printf("Check point 2!");
 		A=add32_5(rotCpyB,phiRes,cpyE,W[i],K(i));
 		//printf("Check point 1 !");
 		free(rotCpyB);
 		free(phiRes);
 	}
 	for (int k=0; k<16;k++){
 		//printf("Le resultat %d est : '%s'\n",k,blocDecoupe[k]);
		free(blocDecoupe[k]);
	}
 	free(blocDecoupe);
 	for (int i =0; i<80; i++){
 			free(W[i]);
 	}
 	free(W);
 	hash0=add32(hash0,A);
 	hash1=add32(hash1,B);
 	hash2=add32(hash2,C);
 	hash3=add32(hash3,D);
 	hash4=add32(hash4,E);
 	for (int i=0; i<32;i++){
 		hash[i]=hash0[i];
 	}
 	for (int i=32; i<64;i++){
 		hash[i]=hash1[i-32];
 	}
 	for (int i=64; i<96;i++){
 		hash[i]=hash2[i-64];
 	}
 	for (int i=96; i<128;i++){
 		hash[i]=hash3[i-96];
 	}
 	for (int i=128; i<160;i++){
 		hash[i]=hash4[i-128];
 	}
 	hash[160]='\0';
 	free(hash4);
 	free(hash3);
 	free(hash2);
 	free(hash1);
 	free(hash0);
 	free(A);
 	free(C);
 	return(hash);
 }

int sha1ReduitPoids(char* mot,int tailleTable){
	if (tailleTable <= 0){
		printf("La taille du tableau est de %d !!!",tailleTable);
		return(-1);
	}
	char* resBin = sha1(mot);
	int res=0;
	int pscInf=psc2sup(tailleTable)-1;
	for (int i=0; i<160; i++){
		//printf("(i*pscInf)/160=%d",(int)(i*pscInf)/160);
		res+=resBin[i]*psc(2,(int)(i*pscInf)/160);
	}res=res%tailleTable;
	free(resBin);
	return(res);
}

int sha1ReduitModulo(char* mot,int tailleTable){
	if (tailleTable <= 0){
		printf("La taille du tableau est de %d !!!",tailleTable);
		return(-1);
	}
	char* resBin = sha1(mot);
	int res=0;
	int pscSup=psc2sup(tailleTable); //entier codé jusqu'a 2^32
	char* res1modulo= malloc(sizeof(char)*(pscSup+1));
	for (int i=0;i<pscSup; i++){
		res1modulo[i]=resBin[i];
	}res1modulo[pscSup]='\0';
	res=bin2Int(res1modulo)%tailleTable;
	free(res1modulo);
	free(resBin);
	return(res);
}


char* allongeHash(char* mot, int tailleTable, int pscSup){ //mot=hash
	int n = strlen(mot);
	if (!strcmp(mot,"") || tailleTable<= 0 || n % pscSup == 0){
		return(mot);
	}
	int tailleFinale=n;
	while (tailleFinale % pscSup != 0 ){
			tailleFinale++;
	}
	char* motAllonge = malloc( sizeof(char) * (tailleFinale+1) );
	for (int i=0; i<n; i++){
		motAllonge[i]=mot[i];
	}for (int i=n; i<tailleFinale; i++){
		if (i%2){
			motAllonge[i]='0';
		}else{
			motAllonge[i]='1';
		}
	}motAllonge[tailleFinale]='\0';
	return(motAllonge);
}


int sha1ReduitXor(char* mot,int tailleTable){
	char* hash = sha1(mot);
	int i=1;
	int pscSup = psc2sup(tailleTable);
	char* hashAllonge = allongeHash(hash,tailleTable,pscSup);
	char** hahsAllongeDec = decoupe(hashAllonge,pscSup);
	char* nvHash = hahsAllongeDec[0];
	int n = (int) strlen(hashAllonge);
	while (i != n/pscSup){
		strcpy(nvHash,xorStr(nvHash,hahsAllongeDec[i]));
		i++;
	}int res = bin2Int(nvHash) % tailleTable;
	i=1;
	while ( i != n/pscSup ){
		free(hahsAllongeDec[i]);
		i++;
	}free(hahsAllongeDec);
	free(hashAllonge);
	free(hash);
	return(res);
}








