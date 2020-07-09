#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"funtzioak.h"

ERTZA* grafoa = NULL;
ERTZA* kruskalGrafoa = NULL;


void ertzaSortu(int* ertzKop) {

	char str[128];
	char v1, v2;
	int pisua;



	printf("\nEman ertz kopurua: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &ertzKop);

	printf("Eman puntuak ondorengo formatuan.\n");


	for (int i = 0; i < ertzKop; i++) {
		//	printf("hasiera puntuaren letra, bukaera puntuaren letra, ertzaren pisua (A B 7):\n");
		fgets(str, 128, stdin);
		sscanf(str, "%c %c %i", &v1, &v2, &pisua);
		puntuaListanSartu(v1, v2, pisua);
	}


}

void puntuaListanSartu(char v1, char v2, int pisua) {

	ERTZA* aux, * kurtsorea;
	static int lehena = 1;
	aux = (ERTZA*)malloc(sizeof(ERTZA));
	aux->ptrHurrengoa = NULL;
	aux->erpinaA = v1;
	aux->erpinaB = v2;
	aux->pisua = pisua;



	if (grafoa == NULL) {
		grafoa = aux;
		aux->ptrHurrengoa = NULL;
	}
	else {
		kurtsorea = grafoa;
		if (lehena == 1) {
			aux->ptrHurrengoa = kurtsorea;
			lehena = 0;
			grafoa = aux;
		}
		else {
			while (kurtsorea->ptrHurrengoa != NULL && kurtsorea->ptrHurrengoa->pisua < aux->pisua) {
				kurtsorea = kurtsorea->ptrHurrengoa;
			}
			aux->ptrHurrengoa = kurtsorea->ptrHurrengoa;
			kurtsorea->ptrHurrengoa = aux;



		}

	}
}


void grafoaEgin() {

	ERTZA* aux = NULL;
	ERTZA* puntuBat=NULL;
	ERTZA* kurtsorea=NULL;
	int zikloa;

	puntuBat = (ERTZA*)malloc(sizeof(ERTZA));

	puntuBat->erpinaA = grafoa->erpinaA;
	puntuBat->erpinaB = grafoa->erpinaB;
	puntuBat->pisua = grafoa->pisua;
	puntuBat->ptrHurrengoa = NULL;


	if (kruskalGrafoa == NULL) {
		kruskalGrafoa = puntuBat;
		grafoa = grafoa->ptrHurrengoa;
	}
	else {
		kurtsorea = kruskalGrafoa;
		while (kurtsorea != NULL) {
			kurtsorea = kurtsorea->ptrHurrengoa;
		}
		zikloa=zikloaDa(puntuBat);
		//zikloa=zikloaSortzenDu(kruskalGrafoa,puntuBat);
		printf("%i",zikloa);

		if (zikloa == 0) {
			kurtsorea->ptrHurrengoa = puntuBat;
		}
	}


}

int zikloaSortzenDu(ERTZA* burua,ERTZA* puntua) {

	int zikloa=1;

	if (puntua == NULL) // list does not exist..so no loop either
		return zikloa= 0;

	ERTZA* slow=NULL, *fast=NULL; // create two references.

	slow = (ERTZA*)malloc(sizeof(ERTZA));
	fast = (ERTZA*)malloc(sizeof(ERTZA));


	slow = fast = burua; // make both refer to the start of the list

	while (zikloa==1) {

		slow = slow->ptrHurrengoa;        // 1 hop

		if (fast->ptrHurrengoa != NULL)
			fast = fast->ptrHurrengoa->ptrHurrengoa; // 2 hops
		else
			return zikloa=0;          // next node null => no loop

		if (slow == NULL || fast == NULL) // if either hits null..no loop
			return zikloa=0;

		if (slow == fast) // if the two ever meet...we must have a loop
			return zikloa=1;
	}

}

int zikloaDa(ERTZA* puntua) {

	ERTZA* kruskalKopia = NULL,*kurtsorea=NULL;
//	kruskalKopia = (ERTZA*)malloc(sizeof(ERTZA));

	kruskalKopia = kruskalGrafoa;
	kurtsorea = kruskalKopia;
	while (kurtsorea != NULL) {
		kurtsorea = kurtsorea->ptrHurrengoa;
	}
	kurtsorea = puntua;
	kruskalKopia = kurtsorea;

	



}