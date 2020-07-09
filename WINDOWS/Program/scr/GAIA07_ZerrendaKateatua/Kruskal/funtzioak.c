#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"funtzioak.h"



ERTZA* ertzaSortu(ERTZA* HasierakoGrafoa) {
	int ertzKop;
	char str[128];
	int v1, v2;
	int pisua;


	printf("Eman ertz kopurua: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &ertzKop);

	printf("Eman puntuak ondorengo formatuan.\n");

	for (int i = 0; i < ertzKop; i++) {
		//	printf("hasiera puntuaren letra, bukaera puntuaren letra, ertzaren pisua (A B 7):\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i %i %i", &v1, &v2, &pisua);

		ERTZA* aux, * kurtsorea;
		aux = (ERTZA*)malloc(sizeof(ERTZA));
		aux->ptrHurrengoa = NULL;
		aux->erpinaA = v1;
		aux->erpinaB = v2;
		aux->pisua = pisua;

		if (HasierakoGrafoa == NULL) {
			HasierakoGrafoa = aux;
		}
		else {
			for (kurtsorea = HasierakoGrafoa; kurtsorea->ptrHurrengoa != NULL; kurtsorea = kurtsorea->ptrHurrengoa);
			kurtsorea->ptrHurrengoa = aux;
		}

	}

	return HasierakoGrafoa;
}

void IbilbideMinimoarenZuhaitzaSortu(ERTZA* HasierakoGrafoa,EGOERA* zuhaitza[],int* egoeraZenb) {

	EGOERA* s;
	int booleano, i = 0;
	ERTZA* n;

	s = (EGOERA*)malloc(sizeof(EGOERA));
	s->ptrHurrengoa = NULL;
	s->izena = HasierakoGrafoa->erpinaA;
	zuhaitza[(*egoeraZenb)] = s;
	(*egoeraZenb)++;
	for (n = HasierakoGrafoa; n != NULL; n = n->ptrHurrengoa) {
	

	
		booleano = 1;

		for (i = 0; i < *egoeraZenb; i++) {
			if (n->erpinaA == zuhaitza[i]->izena) {
				booleano = 0;
			}
			
		}

		if (booleano == 1) {

			s = (EGOERA*)malloc(sizeof(EGOERA));
			s->ptrHurrengoa = NULL;
			s->izena = n->erpinaA;
			zuhaitza[(*egoeraZenb)] = s;
			(*egoeraZenb)++;
		}

		booleano = 1;
		
		for (i = 0; i < *egoeraZenb; i++) {
			if (n->erpinaB == zuhaitza[i]->izena) {
				booleano = 0;
			}
			
		}

		if (booleano == 1) {

			s = (EGOERA*)malloc(sizeof(EGOERA));
			s->ptrHurrengoa = NULL;
			s->izena = n->erpinaB;
			zuhaitza[(*egoeraZenb)] = s;
			(*egoeraZenb)++;
		}
	}

}

void kruskal(ERTZA* HasierakoGrafoa,EGOERA* zuhaitza[],ERTZA* KruskalGrafoa,int egoeraZenb) {


	if (HasierakoGrafoa == NULL) {
		printf("\n\n");

		ERTZA* aux = KruskalGrafoa;
		while (aux != NULL) {
			printf("%i %i %i\n", aux->erpinaA, aux->erpinaB, aux->pisua);
			aux = aux->ptrHurrengoa;
		}
		return;
	}
	int booleano;

	ERTZA* ertzPisuTxikiena = pisuTxikiena(HasierakoGrafoa);

	int i1, i2;

	biPuntuenIndizea(ertzPisuTxikiena->erpinaA, ertzPisuTxikiena->erpinaB, &i1, &i2,egoeraZenb,zuhaitza);
	if (i2 != i1) {

		IbilbideMinimoarenZuhaitzetikKendu(i1, i2,zuhaitza);
		KruskalGrafoa=kruskalGrafoaEgin(ertzPisuTxikiena->erpinaA, ertzPisuTxikiena->erpinaB, ertzPisuTxikiena->pisua,KruskalGrafoa);
		HasierakoGrafoa=puntuaHasieratikKendu(ertzPisuTxikiena,HasierakoGrafoa);
	}
	else {
		HasierakoGrafoa = puntuaHasieratikKendu(ertzPisuTxikiena, HasierakoGrafoa);
	}

	kruskal(HasierakoGrafoa, zuhaitza, KruskalGrafoa,egoeraZenb);

}

ERTZA* pisuTxikiena(ERTZA* HasierakoGrafoa) {

	ERTZA* kurtsorea, * ertza;
	int min;

	if (HasierakoGrafoa == NULL) {

		return NULL;
	}
	else {

		ertza = HasierakoGrafoa;
		min = (*HasierakoGrafoa).pisua;
		for (kurtsorea = HasierakoGrafoa; kurtsorea != NULL; kurtsorea = (*kurtsorea).ptrHurrengoa) {

			if ((*kurtsorea).pisua < min) {
				ertza = kurtsorea;
				min = kurtsorea->pisua;
			}

		}
		return ertza;
	}
}

void biPuntuenIndizea(int erpinaA, int erpinaB, int* i1, int* i2,int egoeraZenb,EGOERA* zuhaitza[]) {

	int i = 0;
	EGOERA* kurtsorea;

	for (i = 0; i < egoeraZenb; i++) {
		for (kurtsorea = zuhaitza[i]; kurtsorea != NULL; kurtsorea = kurtsorea->ptrHurrengoa)
		{
			if (kurtsorea->izena == erpinaA) {
				*i1 = i;
			}
			if (kurtsorea->izena == erpinaB) {
				*i2 = i;
			}
		}

	}
}

void IbilbideMinimoarenZuhaitzetikKendu(int i1, int i2,EGOERA* zuhaitza[]) {

	EGOERA* e;

	for (e = zuhaitza[i1]; e->ptrHurrengoa != NULL; e = e->ptrHurrengoa);

	e->ptrHurrengoa = zuhaitza[i2];
	zuhaitza[i2] = NULL;

}

ERTZA* kruskalGrafoaEgin(int erpinaA, int erpinaB, int pisua,ERTZA* KruskalGrafoa) {

	ERTZA* aux, * kurtsorea;

	aux = (ERTZA*)malloc(sizeof(ERTZA));

	aux->erpinaA = erpinaA;
	aux->erpinaB = erpinaB;
	aux->pisua = pisua;
	aux->ptrHurrengoa = NULL;

	if (KruskalGrafoa == NULL) {
		KruskalGrafoa = aux;
		return KruskalGrafoa;
	}
	else {

		kurtsorea = KruskalGrafoa;
		while (kurtsorea->ptrHurrengoa != NULL) {
			kurtsorea = kurtsorea->ptrHurrengoa;
		}
		kurtsorea->ptrHurrengoa = aux;
		return KruskalGrafoa;
	}

}

ERTZA* puntuaHasieratikKendu(ERTZA* e,ERTZA*HasierakoGrafoa) {

	if (e == HasierakoGrafoa) {

		HasierakoGrafoa = HasierakoGrafoa->ptrHurrengoa;
		free(e);
		return HasierakoGrafoa;
	}

	else {
		ERTZA* kurtsorea;

		for (kurtsorea = HasierakoGrafoa; kurtsorea->ptrHurrengoa != e; kurtsorea = kurtsorea->ptrHurrengoa);
		kurtsorea->ptrHurrengoa = e->ptrHurrengoa;
		free(e);
		return HasierakoGrafoa;
	}
}
