
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#include "orokorrak.h"
#include"Diskak.h"
#include "Stocka.h"


#include"menua_admin.h"

/***** ADMIN MENUA (CRUD, Create Read, Update, delete)

		- Diska berri bat gehitu stocka (CREATE)
		- Diska bat kendu stocketik (DELETE)
		- Diska bat modifikati (UPDATE)
		- Bistaratu
			- Estiloka
			- Autoreka
			- Zigilua
			- Datak erabiliz
		- Irten

*****/
//LOGIN
//IF  eroslea
	//MENUA EROSLEA
//IF ADMIN
	//MENUA ADMIN
	//Sarrera: stcka, zenbat
	//Irteera: zenbat stoxka

int MENUA_admin(DISKA_MOTA stocka[], int zenbat) {

	//to do
	int aukera;
	char str[128];

	do {
		printf("************************ ADMIN MENUA *************************\n");

		printf("	1-Diska berri bat gehitu stocka(CREATE)\n");
		printf("	2- Diska bat kendu stocketik(DELETE)\n");
		printf("	3- Diska bat modifikati(UPDATE)\n");
		printf("	4- Bistaratu\n");
		printf("		4.1- Estiloka\n");
		printf("		4.2- Autoreka\n");
		printf("		4.3- Zigilua\n");
		printf("		4.4- Datak erabiliz\n");
		printf("	5- Irten\n");


		printf("Zer aukera egin nahi duzu?:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);
		printf("\n\n");
		//                     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	zenbat=	 MENUA_ADMIN_exekutatu(aukera, stocka, zenbat);
	} while (aukera != 5);


	return zenbat;
}

int MENUA_ADMIN_exekutatu(int aukera, DISKA_MOTA stocka[] , int zenbat) {

	char str[128];
	int sartu;

	switch (aukera)
	{
	case SORTU_DISKA:
		printf("Zenbat disk sartu nahi duzu?\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &sartu);
		zenbat=MENUA_sartuDiska(stocka, zenbat, sartu);
		break;
	case EZABATU_DISKA:
		zenbat = MENUA_ezabatuDiska(stocka, zenbat);

		break;
	case MODIFIKATU_DISKA:
		zenbat = MENUA_modifikatuDiska(stocka, zenbat);

		break;
	case BISTARATU_DISKA:
		 MENUA_bistaratuDiska(stocka, zenbat);

		break;
	
	default:

		break;
	}
	return zenbat;
}

int MENUA_sartuDiska(DISKA_MOTA stocka[], int zenbat, int sartu){

	DISKA_MOTA diskaBerria;

	int i = 0;
	for (i = 0; i < sartu; i++) {
		//********************************************************************************
		//1-DISKA bat  SORTU
		diskaBerria = DISKAK_sortubat(); //stocka[zenbat].id = diskaBerria.id;
										//stocka[zenbat] = DISKAK_sortubat();
		//stocka[zenbat] = diskaBerria;

		zenbat = STOCKA_diskaBatSartu(diskaBerria, stocka, zenbat);
		//********************************************************************************
	}

	return zenbat;
}

int MENUA_ezabatuDiska(DISKA_MOTA stocka[], int zenbat) {

	int i = 0;
	char str[128];
	DISKA_MOTA diska;
	printf("Eman diskaren ID-a:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &diska.id);

	for (i = 0; i < zenbat; i++) {

		if (stocka[i].id == diska.id) {

			stocka[i].id = -1;
			zenbat--;
		}

	}
	

	return zenbat;
}

void MENUA_bistaratuDiska(DISKA_MOTA stocka[], int zenbat) {

	DISKAK_bistaratuDanak(stocka, zenbat);

}

int MENUA_modifikatuDiska(DISKA_MOTA stocka[], int zenbat) {

	int i = 0;
	char str[128];
	DISKA_MOTA diska;

	printf("Honek dira stcokean dauden diskak:\n");
	MENUA_bistaratuDiska(stocka, zenbat);

	printf("Eman modifikatu nahi duzun diskaren ID-a:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &diska.id);

	for (i = 0; i < zenbat; i++) {

		if (stocka[i].id == diska.id) {

			DISKA_modifikatu(stocka, zenbat,i);
			
		}

	}

	return zenbat;
}

