#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#include "orokorrak.h"
#include"Diskak.h"
#include "Stocka.h"

#include "menua_admin.h"
#include"menua_erabil.h"


int MENUA_erabil(DISKA_MOTA carrito[], DISKA_MOTA stocka[], int zenbat, int kop){

	int aukera;
	char str[128];

	do {
		printf("************************EROSLEAREN MENUA*********\n");
		printf("|1 - Diska berri bat gehitu erosketara (Carrito de la compra) \n");
		printf("|2 - Erosketa burutu \n");
		printf("|3 - Erosketa karritoa ikusi \n");
		printf("|4 - Bistaratu stocka \n");
		printf("| a) - Estilokaka \n");
		printf("| b) - Autoreka \n");
		printf("| c) - Zigilua \n");
		printf("| d) - Datak erabiliz \n");
		printf("| e) - Bat aurkitu \n");
		printf("|0 - Irten \n");
		printf("********************************************\n");

		printf("Zer aukera egin nahi duzu?:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);

		zenbat = MENUA_ERABIL_exekutatu(aukera, carrito, stocka, zenbat, kop);
		if (aukera == 1) {
			kop++;
		}
		if (aukera >= 5) {
			printf("Ez dago aukera hori, eman berriz:\n");
		}
		if (aukera == 2) {
			return zenbat;
		}
	} while (aukera != 0);

	
	return zenbat;
}

int MENUA_ERABIL_exekutatu(int aukera, DISKA_MOTA carrito[], DISKA_MOTA stocka[], int zenbat, int kop) {

	int i = 0;
	char str[128];
	float prezioa=0;

	switch (aukera)
	{
	case DISKA_GEHITU:

		kop = MENUA_ERABIL_diskaGehitu (carrito, stocka,zenbat, kop);

		break;
	case EROSI:

		MENUA_ERABIL_erosi(carrito, kop);
		
		break;
	case KARRITO_IKUSI:

		 MENUA_ERABIL_karritoIkusi(carrito, kop);

		break;
	case BISTARATU_STOCKA:

		MENUA_ERABIL_ikusiStock(carrito,stocka,zenbat);

		break;

	default:

		break;
	}

	return zenbat;

}

int MENUA_ERABIL_diskaGehitu(DISKA_MOTA carrito[], DISKA_MOTA stocka[], int zenbat, int kop) {

	int aukera,i;
	char str[128];

	printf("Eman nahi duzun diskaren ID-a:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &aukera);

	aukera -=1;
	carrito[kop] = stocka[aukera];

	return kop;
}

void MENUA_ERABIL_ikusiStock(DISKA_MOTA carrito[], DISKA_MOTA stocka[], int zenbat) {

	printf("Honek dira stockean dauden diskak:\n");
	DISKAK_bistaratuDanak(stocka, zenbat);

}

void MENUA_ERABIL_karritoIkusi(DISKA_MOTA carrito[], int kop) {


	int i;
	for (i = 0; i < kop; i++) {
			printf("_______________DISKA  %i_________________________\n", carrito[i].id);
			printf("DISKA %d : %2.2f : %s  %i\n", carrito[i].id, carrito[i].prezioa, carrito[i].autor, carrito[i].estiloa);
			//ESTILOA: Rock
			DISKAK_bistaratuEstiloa(carrito[i].estiloa);
			printf("\n\n");
		}
	}

void MENUA_ERABIL_erosi(DISKA_MOTA carrito[], int kop) {

	int i;
	float prezioa = 0;

	for (i = 0; i < kop; i++) {

		prezioa = prezioa + carrito[i].prezioa;

	}

	printf("Honek izan dira aukerati dituzun diskak:\n");
	MENUA_ERABIL_karritoIkusi(carrito, kop);

	printf("Hau izango da disken prezioa: %f\n\n", prezioa);

}