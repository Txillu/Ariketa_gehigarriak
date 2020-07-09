#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include"diskak.h"

void menuaErakutsi() {
	DISKA* diskak;
	int* diskKop = 5;
	int aukera;
	char str[128];
	do
	{
		printf("|1 - Diska irakurri\n");
		printf("|2 - Diska gorde \n");
		printf("|0 - Irten\n");
		printf("Zer egin nahi duzu?\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);
		menuaExekutatu(aukera, &diskak, &diskKop);
	} while (aukera != 0);

}

void menuaExekutatu(int aukera, DISKA* diskak, int* diskKop) {

	char* izenburua = 0;

	switch (aukera)
	{


	case  BAT_IRAKURRI:

		diskaBatIrakurri(diskak);	// Funtzio honek diska baten datuak irakurriko ditu


		break;

	case  GORDE:

		diskaGorde(diskak);

		break;


	default:

		break;
	}

}

void diskaDanakIrakurri(DISKA* diskak, int* diskKop) {

	int i, aux;

	for (i = 0; i < *diskKop; i++) {

		printf("Bere ID-a: %i\n", (*(diskak + i)).id);
		printf("Diskaren izenburua: %s\n", (*(diskak + i)).izenburua);
		printf("Diskaren taldea: %s\n", (*(diskak + i)).autore);
		printf("\n");

	}
	aux = getchar();
	system("cls");


}

void diskaBatIrakurri(DISKA* diska) {	// Funtzio honek diska baten datuak irakurriko ditu

	FILE* fitx;
	int irakurri, i = 0, kop = 0;
	fitx = fopen("adibide.txt", "r");

	if (fitx > 0) {

		do {

			irakurri = fscanf(fitx, "%i %s %s %i %s", (*(diska + i)).izenburua, &(diska + i)->izenburua, &(diska + i)->autore, &(diska + i)->urte, &(diska+i)->estiloa);
			i++;
			kop++;

		} while (irakurri != EOF);
		
		fclose(fitx);
	}
	else {

		printf("errorea fitxategia irekitzerakoan.");
	}

}
void diskaGorde(DISKA* diskak) {


	int i = 0;
	FILE* fitx;
	int idatzi;
	fitx = fopen("gorde.txt", "w");
	if (fitx > 0) {

		for (i = 0; i < 2; i++) {
			idatzi = fprintf(fitx, "%i %s %s %i %s", (*(diskak + i)).izenburua, (*(diskak + i)).izenburua, (*(diskak + i)).autore, (*(diskak + i)).urte, (*(diskak + i)).estiloa);
		}
		fclose(fitx);
	}
	else {
		printf("Arazoa egon da fitxategia irekitzerakoan");
	}


}