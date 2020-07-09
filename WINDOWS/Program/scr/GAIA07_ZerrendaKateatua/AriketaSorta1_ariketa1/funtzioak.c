#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include "funtzioak.h"


void sartuZenbakia(NODOA** lehena, int valor){
NODOA* aux, * cursor;

	aux = (NODOA*)malloc(sizeof(NODOA));
	aux->zbn = valor;


	if (*lehena == NULL) {
		*lehena = aux;
		aux->hurrengoa = NULL;
	}
	else {
		if ((*lehena)->zbn > valor) {
			aux->hurrengoa = *lehena;
			*lehena = aux;
		}
		else {
			cursor = *lehena;
			while (cursor->hurrengoa != NULL && cursor->hurrengoa->zbn < valor) {
				cursor = cursor->hurrengoa;
			}
			aux->hurrengoa = cursor->hurrengoa;
			cursor->hurrengoa = aux;
		}
	}

}

NODOA* bilatu(NODOA* lehena, int valor) {

	NODOA* kurtsorea;
	kurtsorea = lehena;

	while (kurtsorea != NULL && kurtsorea->zbn != valor) {
		kurtsorea = kurtsorea->hurrengoa;
	}

	return kurtsorea;
}

void kenduZenbakia(NODOA** lehena, int znb) {

	NODOA* cursor;
	NODOA* aux = NULL;
		aux=bilatu(*lehena, znb);
	if (aux != NULL) {

		if (aux == *lehena) {
			*lehena = aux->hurrengoa;
		}
		else {
			cursor = *lehena;
			while (cursor->hurrengoa != aux) {
				cursor = cursor->hurrengoa;
			}
			cursor->hurrengoa = aux->hurrengoa;
		}
		free(aux);
	}
}

void erakutsiLista(NODOA* lehena) {

	printf("Hau da oraingoz dagoen lista.\n");

	while (lehena != NULL) {

		printf("%i ", lehena->zbn);
		lehena = lehena->hurrengoa;

	}

	printf("\n");

}