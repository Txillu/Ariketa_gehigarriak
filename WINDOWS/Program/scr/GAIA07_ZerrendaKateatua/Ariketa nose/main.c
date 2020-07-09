#define _cRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef struct nodo {
	int zenbaki;
	struct nodo* hurrengoa;
}NODO;

void sartuZenbakia(NODO* burua);


int main() {

	int aukera;
	char str[128];
	NODO* burua;

	printf("Zer egin nahi duzu: ");
	printf("1-Zebaki bat sartu.");
	printf("2-Zenbaki bat kendu.");
	printf("3-Denak erakutsi.");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &aukera);

	switch (aukera)
	{
	case 1:
		sartuZenbakia(&burua);

		break;
	case 2:

		break;

	case 3:

		break;


	default:
		break;
	}

	return 0;
}

void sartuZenbakia(NODO* burua) {

	int zenbakia;
	char str[128];

	NODO

	printf("Eman zenbakia: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);



}