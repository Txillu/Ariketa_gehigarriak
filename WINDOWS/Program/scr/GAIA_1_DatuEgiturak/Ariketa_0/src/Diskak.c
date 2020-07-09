/*
	int id;
	float prezioa;
	int stock;
	char izenburua[MAX_STR];
	char autor[MAX_STR];//taldea , solista
	int estiloa;
	char data[MAX_STR];
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "orokorrak.h"


#include "diskak.h"



void DISKAK_bistaratuEstiloa(int estiloa) {
	printf("Estiloa:");
	switch (estiloa) {
	case ROCK:
		printf("Rock\n");
		break;
	case BLUES:
		printf("Blues\n");
		break;
	default:
		printf("Ezezaguna\n");
		break;
	}

}


void DISKAK_bistaratuDanak(DISKA_MOTA diskak[10], int zenbat) {
	//BISTARATU ARRAYA
	int i;
	for (i = 0; i < zenbat; i++) {
		if (diskak[i].id >= 0) {
			printf("_______________DISKA  %i_________________________\n", diskak[i].id);
			printf("DISKA %d : %2.2f : %s  %i\n", diskak[i].id, diskak[i].prezioa, diskak[i].autor, diskak[i].estiloa);
			//ESTILOA: Rock
			DISKAK_bistaratuEstiloa(diskak[i].estiloa);
			printf("\n\n");
		}
	}

}

DISKA_MOTA DISKAK_sortubat() {
	
	//DISKA BAT SORTU
	DISKA_MOTA diska;
	char str[128];
	ESTILOAK estiloa;
	//DISKARI BALOREAK EMAN, FGETS, PRINRTF, SSCANSF

	//----Hemen bere ID-------

	printf("Eman diskaren ID-a:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &diska.id);

	//----Hemen bere izenburua----
	printf("Eman diskaren izenburua:");
	fgets(diska.izenburua, 128, stdin);
	diska.izenburua[strlen(diska.izenburua) - 1] = '\0';

	//---Hemen bere prezioa----
	printf("Eman diskaren prezioa:");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &diska.prezioa);

	//----Hemen bere autorea-----
	printf("Eman diskaren autorea:");
	fgets(diska.autor, 128, stdin);
	diska.autor[strlen(diska.autor) - 1] = '\0';

	//----Hemen  bere estiloa----
	printf("Estiloaren zenbakiak: 0-BLUES, 1-ROCK, 2-JAZZ, 3-POP, 4-ELECTRONICA, 5-SOUL\n");
	printf("Eman diskaren estiloaren zenbakia:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &diska.estiloa);

	//DISKA BUELTATU

	return diska;
}

void DISKA_modifikatu(DISKA_MOTA stocka[], int zenbat, int i) {

	char str[128];
	
	printf("Eman diskaren ID berria:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &stocka[i].id);

	//----Hemen bere izenburua----
	printf("Eman diskaren izenburu berria:");
	fgets(stocka[i].izenburua, 128, stdin);
	stocka[i].izenburua[strlen(stocka[i].izenburua) - 1] = '\0';

	//---Hemen bere prezioa----
	printf("Eman diskaren prezio berria:");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &stocka[i].prezioa);

	//----Hemen bere autorea-----
	printf("Eman diskaren autore berria:");
	fgets(stocka[i].autor, 128, stdin);
	stocka[i].autor[strlen(stocka[i].autor) - 1] = '\0';

	//----Hemen  bere estiloa----
	printf("Estiloaren zenbakiak: 0-BLUES, 1-ROCK, 2-JAZZ, 3-POP, 4-ELECTRONICA, 5-SOUL\n");
	printf("Eman diskaren estiloaren zenbaki berria:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &stocka[i].estiloa);


}
