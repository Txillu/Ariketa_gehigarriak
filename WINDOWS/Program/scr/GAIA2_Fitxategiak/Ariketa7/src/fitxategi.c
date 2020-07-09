#include<stdio.h>
#include<string.h>

#include "fitxategi.h"


int zenbakiak_Irakurri(float zenbakiak[]) {

	FILE* irakurriErrealak;
	int i = 0, egoera,kop=0;

	irakurriErrealak = fopen(IRAKURRI_ERREALAK, "r");

	if (irakurriErrealak > 0) {

		do {
			egoera = fscanf(irakurriErrealak, "%f\n", &zenbakiak[kop]);//hau hobeto egin genezake
			if (egoera > 0) kop++;
		} while (egoera > 0 && kop < 128);

		fclose(irakurriErrealak);
	}
	else {
		printf("ERRORE bat egon da fitxaregia irekitzerakoan.\n");
	}
	return kop;
}
