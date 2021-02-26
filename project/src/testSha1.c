#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "./../src/fonctionHachage.h"

#include <criterion/criterion.h>

void setup(void){
}

void teardown(void){
}

Test(test_bin2Int,binaireEntierStr){
	puts("Test de la fonction 'bin2Dec'");
	char* nb4 = "0100";
	char* nb5 = "0101";
	char* nbVide = "";
	cr_expect_eq(bin2Int(nb4),4);
	cr_expect_eq(bin2Int(nbVide),0);
	cr_expect_eq(bin2Int(nb5),5);
}

Test(test_int2Bin,binaireEntierStr){
	puts("Test de la fonction 'int2Bin'");
	cr_expect_eq(strcmp(int2Bin(4),"000000100"),0);
	cr_expect_eq(strcmp(int2Bin(5),"000000101"),0);
}

Test(test_letter2Bin,binaireEntierStr){
	puts("Test de la fonction 'letter2Bin'");
	cr_expect_eq(strcmp(letter2Bin('a'),"001100001"),0);
}

Test(test_pow,power){
	puts("Test de la fonction 'psc'");
	cr_expect_eq(psc(2,2),4);
	cr_expect_eq(psc(2,-1),0);
}

Test(test_retourne,retourne){
	puts("Test de la fonction 'retourne'");
	cr_expect_str_eq(retourne("abc"),"cba");
	cr_expect_str_eq(retourne(""),"");
}

Test(test_decoupe,decoupe){
	puts("Test de la fonction 'decoupe'");
	char** dec = decoupe("00000000000000000000000001100001000000000000000000000000011000100000000000000000000000000110001110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",32);
	cr_expect_eq(strcmp(dec[0],"00000000000000000000000001100001"),0);
	cr_expect_eq(strcmp(dec[1],"00000000000000000000000001100010"),0);
	cr_expect_eq(strcmp(dec[2],"00000000000000000000000001100011"),0);
	cr_expect_eq(strcmp(dec[3],"10000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[4],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[5],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[6],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[8],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[9],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[10],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[11],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[12],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[13],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[14],"00000000000000000000000000000000"),0);
	cr_expect_eq(strcmp(dec[15],"00000000000000000000000000000000"),0);
}

Test(test_add32,operation){
	puts("Test de la fonction 'add32'");
	cr_expect_str_eq(add32_5("00000000000000000000000000000001","00000000000000000000000000000001","00000000000000000000000000000001","00000000000000000000000000000001","00000000000000000000000000000001"),"00000000000000000000000000000101");
	cr_expect_str_eq(add32_5("10000000000000000000000000000000","10000000000000000000000000000000","00000000000000000000000000000001","10000000000000000000000000000001","10000000000000000000000000000001"),"00000000000000000000000000000011");
}

Test(test_add32_5,operation){
	puts("Test de la fonction 'add32_5'");
	cr_expect_str_eq(add32_5("00000000000000000000000000000001","00000000000000000000000000000001","00000000000000000000000000000001","00000000000000000000000000000001","00000000000000000000000000000001"),"00000000000000000000000000000101");
	cr_expect_str_eq(add32_5("10000000000000000000000000000000","10000000000000000000000000000000","00000000000000000000000000000001","10000000000000000000000000000001","10000000000000000000000000000001"),"00000000000000000000000000000011");
}

Test(test_rotation,RotationBinaire){
	puts("Test de la fonction 'rotation'");
	cr_expect_eq(strcmp(rotation("000000100",0),"000000100"),0);
	cr_expect_eq(strcmp(rotation("000000100",2),"000010000"),0);
	cr_expect_eq(strcmp(rotation("",15),""),0);
	cr_expect_eq(strcmp(rotation("000000100",-5),"000000100"),0);
}


Test(test_ite,operationPhi){
	puts("Test de la fonction 'ite'");
	cr_expect_eq(ite(48,48,48),48);
	cr_expect_eq(ite(48,48,49),49);
	cr_expect_eq(ite(48,49,48),48);
	cr_expect_eq(ite(48,49,49),49);
	cr_expect_eq(ite(49,48,48),48);
	cr_expect_eq(ite(49,48,49),48);
	cr_expect_eq(ite(49,49,48),49);
	cr_expect_eq(ite(49,49,49),49);
}

Test(test_maj,operationPhi){
	puts("Test de la fonction 'maj'");
	cr_expect_eq(maj(48,48,48),48);
	cr_expect_eq(maj(48,48,49),48);
	cr_expect_eq(maj(48,49,48),48);
	cr_expect_eq(maj(49,48,48),48);
	cr_expect_eq(maj(48,49,49),49);
	cr_expect_eq(maj(49,48,49),49);
	cr_expect_eq(maj(49,49,48),49);
	cr_expect_eq(maj(49,49,49),49);
}

Test(test_xor3,operationPhi){
	puts("Test de la fonction 'xor3'");
	cr_expect_eq(xor3(48,48,48),48);
	cr_expect_eq(xor3(48,48,49),49);
	cr_expect_eq(xor3(48,49,48),49);
	cr_expect_eq(xor3(49,48,48),49);
	cr_expect_eq(xor3(48,49,49),48);
	cr_expect_eq(xor3(49,48,49),48);
	cr_expect_eq(xor3(49,49,48),48);
	cr_expect_eq(xor3(49,49,49),49);
}

Test(test_Phi,operationPhi){
	puts("Test de la fonction 'xor3'");
	cr_expect_eq(xor3(48,48,48),48);
	cr_expect_eq(xor3(48,48,49),49);
	cr_expect_eq(xor3(48,49,48),49);
	cr_expect_eq(xor3(49,48,48),49);
	cr_expect_eq(xor3(48,49,49),48);
	cr_expect_eq(xor3(49,48,49),48);
	cr_expect_eq(xor3(49,49,48),48);
	cr_expect_eq(xor3(49,49,49),49);
}

Test(test_psc2sup,operation){
	puts("Test de la fonction 'psc2sup'");
	cr_expect_eq(psc2sup(0),0);
	cr_expect_eq(psc2sup(2),1);
	cr_expect_eq(psc2sup(3),2);
	cr_expect_eq(psc2sup(-8),-666);
}


Test(test_xorStr,operation){
	puts("Test de la fonction 'xorStr'");
	cr_expect_eq(strcmp(xorStr("00000000000000000000000001100001","00000000000000001000000001100001"),"00000000000000001000000000000000"),0);
	cr_expect_eq(strcmp(xorStr("0001","0100001"),""),0);
	
}


Test(test_mot2bin,mot2bin){
	puts("Test de la fonction 'mot2Bin'");
	char* test ="abc";
	char* bin = mot2Bin(test);
	printf("Le mot en binaire est : %s\n",bin);
	int n= strlen(bin);
	cr_expect_eq(9*strlen(test),n);
	char* lettre1= int2Bin(test[0]);
	char* lettre2= int2Bin(test[1]);
	char* lettre3= int2Bin(test[2]);
	for (int i=0; i<strlen(lettre1); i++){
		cr_expect_eq((int) lettre1[i],(int) bin[i]);
	}for (int i=0; i<strlen(lettre2); i++){
		cr_expect_eq((int) lettre2[i],(int) bin[i+9]);
	}for (int i=0; i<strlen(lettre3); i++){
		cr_expect_eq((int) lettre3[i],(int) bin[i+18]);
	}
}

Test(test_dmerkleDam,MerkleDamgard){
	puts("Test de la fonction 'MD'");
	char* test ="tree";
	char* bin = mot2Bin(test);
	printf("Le mot en binaire est : %s\n",bin);
	int n= strlen(bin);
	char* MD = mot2merkleDamgard(test);
	for (int i=0; i<n; i++){
		if (MD[i] != bin[i]){
			printf("MD[%d]=%d et bin[%d]= %d\n",i,MD[i],i,bin[i]);
		}cr_expect_eq((int) MD[i],(int) bin[i]);
	}cr_expect_eq(MD[n]-48,1);
	for (int i=n+1; i<512; i++){
		cr_expect_eq(MD[i]-48,0);
	}
}

Test(test_SHA1,SHA1){
	puts("Test de la fonction 'sha1'");
	cr_expect_eq(160,strlen(sha1("tree")));
	cr_expect_eq(160,strlen(sha1("tre/e")));
	cr_expect_eq(160,strlen(sha1("")));
	cr_expect_eq(160,strlen(sha1("tree   ")));
	cr_expect_eq(160,strlen(sha1("tree...")));
	cr_expect_eq(160,strlen(sha1("tree!")));
	cr_expect_eq(160,strlen(sha1("tree?")));
	cr_expect_eq(160,strlen(sha1("52")));
	cr_expect_eq(160,strlen(sha1("'tè_éç_çéè'ç_&é)à")));
}

Test(allongeHash,SHA1){
	puts("Test de la fonction 'allongeHash'");
	cr_expect_eq(strcmp(allongeHash("",4),""),0);
	cr_expect_eq(strcmp(allongeHash("0101",-4),"0101"),0);
	cr_expect_eq(strcmp(allongeHash("1101",7),"110110"),0);
}

Test(allongeDecHash,SHA1){
	puts("Test de la fonction 'allongeDecHash'");
	char** hashDec = allongeDecHash("1101",7);
	cr_expect_eq(strcmp(hashDec[0],"110"),0);
	cr_expect_eq(strcmp(hashDec[1],"110"),0);
}













































