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
	PELIKULA* ptrBigarrena = NULL;
	PELIKULA* ptrHirugarrena = NULL;

	//1.pelikula sortuta eta hasieratuta
	ptrLehena = (PELIKULA*)malloc(sizeof(PELIKULA));//pelikula baten datuak gordetzeko memoria  zatia sortuta
														//buletau memoria horren helbidea
	ptrLehena->id = 1;
	strcpy(ptrLehena->izenburua, "la vida de brian");
	ptrLehena->ptrHurrengoa = NULL;

	//2.pelikula
	ptrBigarrena = (PELIKULA*)malloc(sizeof(PELIKULA));//beste helbidea ,
	ptrBigarrena->id = 2;
	strcpy(ptrBigarrena->izenburua, "Un funeral de muerte");
	ptrBigarrena->ptrHurrengoa = NULL;
	//bi elementuak kateatzeko
	ptrLehena->ptrHurrengoa = ptrBigarrena;//null

	//3. pelikula sortu  eta jarri ezazu 2.pelikuale hurrengo lez. Ondoren bistaratu zerrenda guztia.
	ptrHirugarrena = (PELIKULA*)malloc(sizeof(PELIKULA));//beste helbidea ,
	ptrHirugarrena->id = 3;
	strcpy(ptrHirugarrena->izenburua, "American Pie");
	ptrHirugarrena->ptrHurrengoa = NULL;
	ptrBigarrena->ptrHurrengoa = ptrHirugarrena;

	bistaratuPelikulenZerrenda(ptrLehena);

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