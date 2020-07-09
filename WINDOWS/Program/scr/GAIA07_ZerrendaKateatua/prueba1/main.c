#define _CRT_SECURE_NO_WARNINGS
#define MAX_STR 128
#define MAX	100

#include<stdio.h>
#include<string.h>

typedef enum { WESTER, DRAMA, THRILLER, COMEDIA } GENEROA;

typedef struct pelikula {

	int id;
	char izenburua[MAX_STR];
	GENEROA gen;
	char zuzendaria[MAX_STR];
	int urtea;
	struct Pelikula* ptrHurrengua;

}PELIKULA;

int pelikulakHasieratu(PELIKULA* pelikulak, int kop);
void bistaratuPelikulenZerrenda(PELIKULA* ptrPelikula1);
void bistaratuBat(PELIKULA* ptrpelikula);
void estilokaBistaratu(PELIKULA *burua);
void bistaratuEstil(PELIKULA* burua);


int main() {

	printf("---------------ZERRENDA KATEATUA-----------\n");

	PELIKULA pelikulak[MAX];

	int kop = 0;
	PELIKULA* ptrPelikula1 = NULL;
	PELIKULA* burua = NULL;
	PELIKULA* ptrPelikula2 = NULL;
	PELIKULA* ptrPelikula3 = NULL;
	PELIKULA* ptrPelikula4 = NULL;

	//Modu hau estatikoki dago, array batekin
	kop = pelikulakHasieratu(pelikulak, kop);


	//dinamikoki
	ptrPelikula1 = (PELIKULA*)malloc(sizeof(PELIKULA));
	ptrPelikula1->id = 8;
	strcpy(ptrPelikula1->izenburua, "Horizontes de grandeza");
	strcpy(ptrPelikula1->zuzendaria, " William Wyler");
	ptrPelikula1->urtea = 1955;
	ptrPelikula1->gen = 3;
	ptrPelikula1->ptrHurrengua = NULL;//HEMN¡EN AMAITZEN DA ZERRENDA
	bistaratuPelikulenZerrenda(ptrPelikula1);

	printf("\n-------------------------------------\n\n");

	//SORTU BIGARREN PELI
	ptrPelikula2 = (PELIKULA*)malloc(sizeof(PELIKULA));
	ptrPelikula2->id = 10;
	strcpy(ptrPelikula2->izenburua, "kimi no na wa");
	strcpy(ptrPelikula2->zuzendaria, "Makoto Shinkai");
	ptrPelikula2->gen = 1;
	ptrPelikula2->urtea = 2016;
	ptrPelikula2->ptrHurrengua = NULL;//HEMN¡EN AMAITZEN DA ZERRENDA

	ptrPelikula3 = (PELIKULA*)malloc(sizeof(PELIKULA));
	ptrPelikula3->id = 15;
	strcpy(ptrPelikula3->izenburua, "Titanic");
	strcpy(ptrPelikula3->zuzendaria, " James Cameron");
	ptrPelikula3->gen = 1;
	ptrPelikula3->urtea = 1998;
	ptrPelikula3->ptrHurrengua = NULL;

	ptrPelikula4 = (PELIKULA*)malloc(sizeof(PELIKULA));
	ptrPelikula4->id = 65;
	strcpy(ptrPelikula4->izenburua, "nose");
	strcpy(ptrPelikula4->zuzendaria, " ezdakit");
	ptrPelikula4->gen = 2;
	ptrPelikula4->urtea = 2019;
	ptrPelikula4->ptrHurrengua = NULL;

	//BI PELIKULAK ZERRENDA BATEN LOTU

	ptrPelikula1->ptrHurrengua = ptrPelikula2;
	ptrPelikula2->ptrHurrengua = ptrPelikula3;
	ptrPelikula3->ptrHurrengua = ptrPelikula4;

	burua = ptrPelikula1;


	bistaratuPelikulenZerrenda(burua);

	//estilokaBistaratu(burua);


	return 0;
}

int pelikulakHasieratu(PELIKULA* pelikulak, int kop) {

	strcpy(pelikulak[kop].izenburua, "la vida de brian");
	pelikulak[kop].urtea = 19734;
	kop++;
	strcpy(pelikulak[kop].izenburua, "un funeral de muerte");
	pelikulak[kop].urtea = 2015;
	kop++;

	return kop;
}

void bistaratuPelikulenZerrenda(PELIKULA* ptr) {


	if (ptr != NULL) {
		do
		{
			bistaratuBat(ptr);

			ptr = ptr->ptrHurrengua;
		} while (ptr != NULL);

	}
	else {
		printf("Zerrenda hutsik");
	}

}

void bistaratuBat(PELIKULA* ptrpelikula) {

	printf("-----------%i--------------\n", ptrpelikula->id);
	printf("IZENBURUA:%s (%i)\n", ptrpelikula->izenburua, ptrpelikula->urtea);
	printf("ZUZENDARIA:%s\n", ptrpelikula->zuzendaria);
	printf("GENEROA:%s\n", ptrpelikula->gen);


}

/*
void estilokaBistaratu(PELIKULA* burua) {

	int aukera = 0;
	char str[128];

	printf("Zer estilo bistaratu nahi duzu:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &aukera);

	switch (aukera)
	{

	case 0:

		do
		{
			if (burua->gen == 0) {

				printf("-----------%i--------------\n", burua->id);
				printf("IZENBURUA:%s (%i)\n", burua->izenburua, burua->urtea);
				printf("ZUZENDARIA:%s\n", burua->zuzendaria);
				printf("GENEROA:%s\n", burua->gen);


			}
			burua = burua->ptrHurrengua;
		} while (burua!=NULL);

		break;

	case 1:

		do
		{
			if (burua->gen == 1) {

				printf("-----------%i--------------\n", burua->id);
				printf("IZENBURUA:%s (%i)\n", burua->izenburua, burua->urtea);
				printf("ZUZENDARIA:%s\n", burua->zuzendaria);
				printf("GENEROA:%s\n", burua->gen);


			}
			burua = burua->ptrHurrengua;
		} while (burua != NULL);


		break;

	case 2:

		do
		{
			if (burua->gen == 2) {

				printf("-----------%i--------------\n", burua->id);
				printf("IZENBURUA:%s (%i)\n", burua->izenburua, burua->urtea);
				printf("ZUZENDARIA:%s\n", burua->zuzendaria);
				printf("GENEROA:%s\n", burua->gen);


			}
			burua = burua->ptrHurrengua;
		} while (burua != NULL);


		break;

	case 3:

		do
		{
			if (burua->gen == 3) {

				printf("-----------%i--------------\n", burua->id);
				printf("IZENBURUA:%s (%i)\n", burua->izenburua, burua->urtea);
				printf("ZUZENDARIA:%s\n", burua->zuzendaria);
				printf("GENEROA:%s\n", burua->gen);


			}
			burua = burua->ptrHurrengua;
		} while (burua != NULL);

		break;


	default:

		printf("Ez dago aukera hori.");
		break;
	}

}

*/

