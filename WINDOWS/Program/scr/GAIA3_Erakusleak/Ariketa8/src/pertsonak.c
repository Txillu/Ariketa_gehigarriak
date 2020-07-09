#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

#include"pertsonak.h"


int  pertsonakSartu(PERTSONAK pertsona[]) {
	int aukera, i, zenbat=0;
	char str[128];

	do
	{
		pertsonaBatSartu(pertsona+zenbat);

		zenbat++;

		aukera = aukeraMenu();

	} while (aukera == 1);

	return zenbat;
}

void pertsonaBatSartu(PERTSONAK* pertsona) {
	
	char str[128];

	printf("Eman pertsonaren ID-a:");
	fgets(str, 128, stdin);
	sscanf(str, "%i",&pertsona->id);

	printf("Eman pertsonaren Izena:");
	fgets(pertsona->izena, MAX_STR, stdin);
	pertsona->izena[strlen(pertsona->izena) - 1] = '\0';

	printf("Eman pertsonaren LEHENENGO abizena:");
	fgets(pertsona->abizena->abizena1, MAX_STR, stdin);
	pertsona->abizena->abizena1[strlen(pertsona->abizena->abizena1) - 1] = '\0';

	printf("Eman pertsonaren BIGARREN abizena:");
	fgets(pertsona->abizena->abizena2, MAX_STR, stdin);
	pertsona->abizena->abizena2[strlen(pertsona->abizena->abizena2) - 1] = '\0';

	printf("Eman pertsonaren adina:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &pertsona->adina);

	printf("Eman pertsonaren generoa:");
	fgets(pertsona->generoa, MAX_STR, stdin);
	pertsona->generoa[strlen(pertsona->generoa) - 1] = '\0';
}

int  aukeraMenu() {

	int aukera, okerra;
	char str[128];

	do {
		printf("Pertsonak sartzen jarraitu nahi duzu? (1-BAI 0-EZ)\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);
		okerra = 1;
		if (aukera < 0 || aukera>1) {
			printf("Mesedez eman aukera egokia:\n");
			okerra = 0;
		}
	} while (okerra==0);

	system("cls");
	return aukera;
}

void ordenatu(PERTSONAK pertsona[], int zenbat){

	PERTSONAK tmp;
	int i,j;

	for (i = 0; i < zenbat; i++)
	{
		for (j = i + 1; j < zenbat; j++) {
			if (*(pertsona + j)->izena < *(pertsona + i)->izena) {
				tmp = *(pertsona + i);
				*(pertsona + i) = *(pertsona + j);
				*(pertsona + j) = tmp;
			}
		}
	}

}

void pertsonakPantailaratu(PERTSONAK pertsona[], int zenbat) {

	int i;

	printf("Hemen pertsonak izenaren arabera ordenaturik:(A-Z)\n\n");

	for (i = 0; i < zenbat; i++) {

		printf("ID: %i ", (pertsona + i)->id);
		printf("Izena: %s ", (pertsona + i)->izena);
		printf("abizenak: %s %s", (pertsona + i)->abizena->abizena1, (pertsona + i)->abizena->abizena2);
		printf("Adina: %i ", (pertsona + i)->adina);
		printf("Generoa: %s ", (pertsona + i)->generoa);
		printf("\n----------------------------------------------------------------------\n");

	}


}
