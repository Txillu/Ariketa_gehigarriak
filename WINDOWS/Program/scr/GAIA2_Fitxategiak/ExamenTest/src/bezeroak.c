#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bezeroak.h"


void menua_erakutsi() {
	int zenbat = 0;
	int j = 0;
	BEZEROAK bezero[MAX_BEZERO];
	int aukera;
	char str[128];

	do {
		printf("Zer egin nahi duzu:\n");
		printf("1- Bezero berri bat sortu\n");
		printf("2- Bezero guztiak pantailaratu\n");
		printf("3- Erosketa berri bat kudeatu.\n");
		printf("4- Hile konkretu bateko diru sarrera kalkulatu eta pantailaratu\n");
		printf("5- Orainartekoa fitxategian gorde\n");
		printf("6- Fitxategian dagoena kargatu\n");
		printf("7- Hileko irabazia\n");
		printf("8- Faktura\n");
		printf("0- Irtetzeko\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);

		zenbat = menua_exelutatu(aukera, bezero, zenbat, j);

	} while (aukera != 0);

	system("pause");
	system("cls");

}

int menua_exelutatu(int aukera, BEZEROAK bezero[], int zenbat) {

	float irabazi = 0;
	switch (aukera)
	{
	case BEZERO_SORTU:

		zenbat = bezero_sortu(bezero, zenbat);

		break;
	case BEZERO_GUZTIAK_PANTAILARATU:

		bezeroak_pantailaratu(bezero, zenbat);

		break;
	case EROSKETA_KUDEATU:

		zenbat = erosketa_kudeatu(bezero, zenbat);

		break;
	case HILEKO_DIRUSARRERA:


		break;
	case FITXATEGIAN_GORDE:

		gorde(bezero, zenbat);

		break;
	case FITXATEGI_KARGATU:

		zenbat = kargartu(bezero, zenbat);

		break;
	case IRABAZIA:

		irabazi = kalkulatuIrabazi(bezero, zenbat);
		printf("Aukeratutako hilabetean %f irabazi duzu.", irabazi);
		break;

	case FAKTURA:

		faktura(bezero, zenbat);

		break;

	default:

		break;
	}

	return zenbat;
}

int bezero_sortu(BEZEROAK bezero[], int zenbat) {

	int i, id;
	char str[128];

	printf("Eman bezereoaren id-a:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &bezero[zenbat].id);

	id = bezero[zenbat].id;
	for (i = 0; i < zenbat; i++) {
		if (id == bezero[i].id) {
			printf("ID hori erabilita dago.\n");
			return zenbat;
		}
	}

	printf("Eman bezereoaren izena:\n");
	fgets(bezero[zenbat].izena, 128, stdin);
	bezero[zenbat].izena[strlen(bezero[zenbat].izena) - 1] = '\0';

	printf("Eman bezereoaren abizea:\n");
	fgets(bezero[zenbat].abizena, 128, stdin);
	bezero[zenbat].abizena[strlen(bezero[zenbat].abizena) - 1] = '\0';

	printf("Eman bezereoaren adina:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &bezero[zenbat].adina);

	bezero[zenbat].kop = 0;

	printf("Datuak ondo burutu dira.\n");

	zenbat++;

	system("pause");
	system("cls");
	return zenbat;
}

void bezeroak_pantailaratu(BEZEROAK bezero[], int zenbat) {

	int i = 0, j = 0;
	if (zenbat <= 0) {
		printf("Oraindik ez daude bezerorik.\n");
	}

	else {

		for (i = 0; i < zenbat; i++) {
			printf("ID:%i\n", bezero[i].id);
			printf("Izena: %s\tAbizena: %s\tAdina:%i\n", bezero[i].izena, bezero[i].abizena, bezero[i].adina);
			for (j = 0; j < bezero[i].kop; j++) {
				printf("Erosketaren data:\n");
				printf("%i/%i/%i egindako erosketa\t %.2f€ gastatu du\n", bezero[i].erosi_informazio[j].eguna, bezero[i].erosi_informazio[j].hilabete, bezero[i].erosi_informazio[j].urte, bezero[i].erosi_informazio[j].dirua);
			}

			printf("\n");
		}
	}

	system("pause");
	system("cls");

}

BEZEROAK erosle_erosketa_egin(BEZEROAK bezero) {

	char aux, str[128];

	printf("Idatzi noiz egin duen erosketa (dd/mm/aaaa):\n");
	fgets(str, 128, stdin);
	aux = sscanf(str, "%i/%i/%i", &bezero.erosi_informazio[bezero.kop].eguna, &bezero.erosi_informazio[bezero.kop].hilabete, &bezero.erosi_informazio[bezero.kop].urte);

	printf("Erosleak gastatutako dirua:\n");
	fgets(str, 128, stdin);
	aux = sscanf(str, "%f", &bezero.erosi_informazio[bezero.kop].dirua);

	bezero.kop++;

	return bezero;
}

int erosketa_kudeatu(BEZEROAK bezero[], int zenbat) {

	int i = 0, id, aurkitu = 0, j = 0;
	char str[128];
	printf("Eman bezeroaren id-a:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &id);

	if (zenbat <= 0) {
		printf("Oraindik ez daude bezerorik.\n");
	}
	else {
		while (i < zenbat && !aurkitu) {

			if (id == bezero[i].id) {

				bezero[i] = erosle_erosketa_egin(bezero[i]);

				aurkitu = 1;
			}
			i++;

		}
		if (aurkitu == 0) {
			printf("Ez dago bezero hori.\n");
		}
	}

	system("pause");
	system("cls");
	return zenbat;
}

void gorde(BEZEROAK bezero[], int zenbat) {


	FILE* fitx;
	fitx = fopen("bezeroak.dat", "wb");
	if (fitx > 0) {

		fwrite(bezero, sizeof(BEZEROAK), zenbat, fitx);
		printf("Egina\n");
		fclose(fitx);
	}
	else {
		printf("Errore bat egon da fitxategia zabaltzerakoan\n");
	}
	system("pause");
	system("cls");
}

int kargartu(BEZEROAK bezero[], int zenbat) {


	FILE* fitx;
	int egoera, i = 0;
	fitx = fopen("bezeroak.dat", "rb");
	if (fitx > 0) {

		do {
			egoera = fread(&bezero[i], sizeof(BEZEROAK), 1, fitx);
			zenbat++;
			if (egoera != 1) {
				zenbat--;
				if (feof(fitx)) {
					printf("fitxatgiaren bukaera\n");

				}
				else {
					printf("Errorea %s fitxategai irakurzretakoan\n.", fitx);
				}
			}


		} while (egoera > 0);

	}
	else {

		printf("Errore bat egon da fitxategia zabaltzerakoan\n");

	}
	system("pause");
	system("cls");
	return zenbat;
}

int kalkulatuIrabazi(BEZEROAK bezero[], int zenbat) {

	int  i = 0,j=0, hilabete;
	float irabazi = 0;
	char str[128];
	printf("Eman jakin nahi den hilabetearen zenbakia:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &hilabete);

	//int hil;
	//hil = bezero[i].erosi_informazio[i].hilabete;

	for (i = 0; i < zenbat; i++) {
		for (j = 0; j < bezero[i].kop; j++) {
			if (bezero[i].erosi_informazio[j].hilabete == hilabete) {

				irabazi = irabazi + bezero[i].erosi_informazio[j].dirua;

			}
		}
	}
	system("pause");
	system("cls");
	return irabazi;
}

void faktura(BEZEROAK bezero[], int zenbat) {

	FILE* fakt;
	
	int i = 0,j=0,aurkitu=0;
	char faktura[128];

	printf("Eman bezeroaren izena:\n");
	fgets(faktura, 128, stdin);
	faktura[strlen(faktura) - 1] = '\0';

	fakt = fopen("faktura.txt", "w");
	if (fakt > 0) {
		for (i = 0; i < zenbat; i++) {
		//	strcmp(faktura, bezero[i].izena)
			if (strcmp(faktura, bezero[i].izena)==0) {

				fprintf(fakt, "%s %s-ren faktura\n", bezero[i].izena, bezero[i].abizena);
				for (j = 0; j < bezero[i].kop; j++) {

					fprintf(fakt, "%i/%i/%i egindako erosketa\t %.2f€ gastatu du\n", bezero[i].erosi_informazio[j].eguna, bezero[i].erosi_informazio[j].hilabete, bezero[i].erosi_informazio[j].urte, bezero[i].erosi_informazio[j].dirua);

				}
			}
			
		}
		fclose(fakt);
	}
	else {
		printf("Arazoa egon da.");
	}
	system("pause");
	system("cls");
}