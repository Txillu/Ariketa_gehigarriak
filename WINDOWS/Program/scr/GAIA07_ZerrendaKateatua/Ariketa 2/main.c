#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_STR 128
typedef enum { WESTERN, DRAMA, THRILLER, COMEDIA } GENEROA;



typedef struct Pelikula {
	int id;
	char izenburua[MAX_STR];
	GENEROA gen;
	char zuzendaria[MAX_STR];
	int urtea;
	struct Pelikula* ptrHurrengoa;
}PELIKULA;


void bistaratuPelikulenZerrenda(PELIKULA* ptr);
void bistaratuPelikulaBat(PELIKULA* ptrPelikula);




int main() {

	PELIKULA* ptrLehena = NULL;
	PELIKULA* ptrElementua = NULL;


	//1.pelikula sortuta eta hasieratuta
	ptrElementua = (PELIKULA*)malloc(sizeof(PELIKULA));//pelikula baten datuak gordetzeko memoria  zatia sortuta
														//buletau memoria horren helbidea
	ptrElementua->id = 1;
	strcpy(ptrElementua->izenburua, "la vida de brian");
	ptrElementua->ptrHurrengoa = NULL;
	//ptrElementua  Lehenengo posizioan jarri
	ptrLehena = ptrElementua;


	//2.pelikula sortu eta buruan sartu
	ptrElementua = (PELIKULA*)malloc(sizeof(PELIKULA));//beste helbidea ,
	ptrElementua->id = 2;
	strcpy(ptrElementua->izenburua, "Un funeral de muerte");
	ptrElementua->ptrHurrengoa = NULL;
	//Kateatu zerrenadako beste elementuekin lehenengo posizioan kokatuz 
	ptrElementua->ptrHurrengoa = ptrLehena;//null
	//ptrLehena zerrendako lehen elementu berriari apuntetan jarri
	ptrLehena = ptrElementua;

	//3. pelikula sortu pelikula bat eta jarri ezazu 2.pelikualrem hurrengo moduan 
	ptrElementua = (PELIKULA*)malloc(sizeof(PELIKULA));//beste helbidea ,
	ptrElementua->id = 3;
	strcpy(ptrElementua->izenburua, "Seven");
	ptrElementua->ptrHurrengoa = NULL;
	//Kateatu zerrenadako beste elementuekin lehenengo posizioan kokatuz 
	ptrElementua->ptrHurrengoa = ptrLehena;//null
	//ptrLehena zerrendako lehen elementu berriari apuntetan jarri
	ptrLehena = ptrElementua;


	//. pelikula sortu pelikula bat eta jarri ezazu 3.pelikualrem hurrengo moduan 
	ptrElementua = (PELIKULA*)malloc(sizeof(PELIKULA));//beste helbidea ,
	ptrElementua->id = 4;
	strcpy(ptrElementua->izenburua, "American pie");
	ptrElementua->ptrHurrengoa = NULL;
	//Kateatu zerrenadako beste elementuekin lehenengo posizioan kokatuz 
	ptrElementua->ptrHurrengoa = ptrLehena;//null
	//ptrLehena zerrendako lehen elementu berriari apuntetan jarri
	ptrLehena = ptrElementua;

	bistaratuPelikulenZerrenda(ptrLehena);
	//azkenik azaldu zer bistaratzen dan pantailan eta zergaitik 

	//Eta orain laugarren pelikula bat sartu burualdean


	getchar();
	return 0;
}

void bistaratuPelikulenZerrenda(PELIKULA* ptr) {
	//zerrenda muguit ub ehar gara azkenengo elementuraiano eta joan bistaratzen

	//1. zerrenda hutsik dago , arraiekin if (kop == 0) ez bistaratu 

	if (ptr != NULL) {
		do {
			bistaratuPelikulaBat(ptr);
			//hurrengo elementu ahartu i++ pelikulak[i]
			ptr = ptr->ptrHurrengoa;
		} while (ptr != NULL); //i < kop 

	}
	else {
		printf("Ez dago pelikualrik zerrednaª!!!!!\n");
	}




}

void bistaratuPelikulaBat(PELIKULA* ptrPelikula) {

	printf("---------------%i--------------------\n", ptrPelikula->id);
	printf("IZENBURUA:%s (%i)\n", ptrPelikula->izenburua, ptrPelikula->urtea);
}