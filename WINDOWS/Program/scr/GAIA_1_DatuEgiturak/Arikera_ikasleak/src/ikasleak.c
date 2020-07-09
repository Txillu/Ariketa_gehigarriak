#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ikasleak.h"

void MENUA_erakutsi() {

	int zenbat = 0;

	IKASLE ikasleak[MAX_IKAS];

	int aukera;
	char str[128];
	do {

		printf("============================================\n");
		printf("		   Menu\n");
		printf("============================================\n");
		printf("1. Gehitu ikasle baten notak\n");
		printf("2. Borratu ikasle baten notak\n");
		printf("3. Eguneratu ikasle baten notak\n");
		printf("4. Bistaratu ikasle guztien notak\n");
		printf("5. Kalkulatu aukeratutako ikasleen noten batazbestekoa\n");
		printf("6. Bistaratu bukaerako nota finalik altuena duen ikaslearen informazioa\n");
		printf("7. Bistaratu bukaerako nota finalik baxuena duen ikaslearen informazioa\n");
		printf("8. ID bidez ikasle bat bilatu\n");
		printf("9. Informazioa nota finalaren arabera ordenaturik bistaratu\n");
		printf("0. Aplikazioa itxi\n");
		printf("Sartu aukera bat:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);
		zenbat = MENUA_exekutatu(aukera, ikasleak, zenbat);
	} while (aukera != 0);
	
}

int MENUA_exekutatu(int aukera, IKASLE ikasleak[], int zenbat){
	
	switch (aukera)
	{
	case GEHITU_NOTA:

		zenbat= ikasle_notaGehitu(ikasleak,zenbat);

		break;
	case BORRATU_NOTA:

		ikasle_notaKendu(ikasleak,zenbat);
		break;

	case  EGUNERATU_NOTA :

		ikasle_notaEguneratu(ikasleak, zenbat);
		break;

	case BISTARATU_DANAK:

		bistaratu_guztiak(ikasleak, zenbat);
		break;

	case BATAZBESTE_IKASLE_BAT:

		ikasle_batazbeste(ikasleak, zenbat);
		break;

	case NOTA_ALTU_IKASLE:
		ikasle_notaAltuInfo(ikasleak, zenbat);
		break;

	case NOTA_BAXU_IKASLE:
		ikasle_notaBaxuInfo(ikasleak, zenbat);
		break;

	case BILATU_IKASLE:

		bilatu(ikasleak, zenbat);

		break;
	case BISTARATU_FINALA:
		bistaratu_final(ikasleak, zenbat);
		break;

	default:

		break;
	}

	return zenbat;
}

int ikasle_notaGehitu(IKASLE ikasleak[],int zenbat) {

	int i,id;
	char str[128];

	printf("Eman ikaslearen ID-a:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &ikasleak[zenbat].id);

	//------HURRENGO ZATIA ID-A LIBRE DAGOEN KONPROBATUKO DU-------------
	id = ikasleak[zenbat].id;
	for (i = 0; i < zenbat; i++) {
		if (id == ikasleak[i].id) {
			printf("ID hori erabilita dago.\n");
			return zenbat;
		}
	}
	//-----------------------------------------------------------

	printf("Eman ikaslearen izena:\n");
	fgets(ikasleak[zenbat].izena, 128, stdin);
	ikasleak[zenbat].izena[strlen(ikasleak[zenbat].izena)-1]='\0';

	printf("Eman ikaslearen generoa:\n");
	fgets(ikasleak[zenbat].genero, 128, stdin);
	ikasleak[zenbat].genero[strlen(ikasleak[zenbat].genero) - 1] = '\0';

	//----------IKASLEAREN OSATILEKO LEHENGO ETA BIGARRENEKO KONTROLEKO NOTA

	printf("Eman ikaslearen otsaileko lehenengo kontrolaren nota:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &ikasleak[zenbat].partziNota.otsaila.exam1);

	printf("Eman ikaslearen otsaileko bigarren kontrolaren nota:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &ikasleak[zenbat].partziNota.otsaila.exam2);

	//-------------IKASLEAREN EKAINEKO LEHENENGO ETA BIGARREN KONTROLAK----------
	printf("Eman ikaslearen ekaineko lehenengo kontrolaren nota:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &ikasleak[zenbat].partziNota.ekaina.exam1);
	
	printf("Eman ikaslearen ekaineko bigarren kontrolaren nota:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &ikasleak[zenbat].partziNota.ekaina.exam2);

	//------------IKASLEAREN NOTA FINALA= KONTROL GUZTIEN BATURA ZATI 4---------------
	
	ikasleak[zenbat].final = ((ikasleak[zenbat].partziNota.otsaila.exam1 + ikasleak[zenbat].partziNota.otsaila.exam2 )+ (ikasleak[zenbat].partziNota.ekaina.exam1 + ikasleak[zenbat].partziNota.ekaina.exam2))/4;

	printf("Datuak ondo burutu dira.\n");

	zenbat++;
	system("pause");
	system("cls");
	return zenbat;
}

void ikasle_notaKendu(IKASLE ikasleak[],int zenbat) {

	int i = 0,id,aurkitu=0;
	char str[128];
	if (zenbat <= 0) {
		printf("Oraindik ez daude ikaslerik.\n");
	}
	else {
		printf("Eman ikaslearen ID-a:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &id);
		while (i < zenbat && aurkitu == 0) {
			if (id == ikasleak[i].id) {
				ikasleak[i].partziNota.otsaila.exam1 = 0;
				ikasleak[i].partziNota.otsaila.exam2 = 0;
				ikasleak[i].partziNota.ekaina.exam1 = 0;
				ikasleak[i].partziNota.ekaina.exam2 = 0;
				ikasleak[i].final = 0;
				printf("%i ikaslearen notak kendu dira.\n", ikasleak[i].id);
				aurkitu = 1;
			}
			i++;
		}
		if(aurkitu==0) {
			printf("Ez dago ikasle hori duen iD-rik\n");
		}
	}
	system("pause");
	system("cls");
}

void ikasle_notaEguneratu(IKASLE ikasleak[], int zenbat) {

	int i = 0,id,aurkitu=0;
	char str[128];

	if (zenbat <= 0) {
		printf("Oraindik ez daude ikaslerik.\n");
	}
	else {
		printf("Eman ikaslearen ID-a:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &id);
		while (i < zenbat && aurkitu==0) {
			if (id == ikasleak[i].id) {

				printf("Eman ikaslearen otsaileko lehenengo kontrolaren nota BERRIA:\n");
				fgets(str, 128, stdin);
				sscanf(str, "%f", &ikasleak[i].partziNota.otsaila.exam1);

				printf("Eman ikaslearen otsaileko bigarren kontrolaren nota BERRIA:\n");
				fgets(str, 128, stdin);
				sscanf(str, "%f", &ikasleak[i].partziNota.otsaila.exam2);

				//-------------IKASLEAREN EKAINEKO LEHENENGO ETA BIGARREN KONTROLAK----------
				printf("Eman ikaslearen ekaineko lehenengo kontrolaren nota BERRIA:\n");
				fgets(str, 128, stdin);
				sscanf(str, "%f", &ikasleak[i].partziNota.ekaina.exam1);

				printf("Eman ikaslearen ekaineko bigarren kontrolaren nota BERRIA:\n");
				fgets(str, 128, stdin);
				sscanf(str, "%f", &ikasleak[i].partziNota.ekaina.exam2);

				ikasleak[i].final = ((ikasleak[i].partziNota.otsaila.exam1 + ikasleak[i].partziNota.otsaila.exam2) + (ikasleak[i].partziNota.ekaina.exam1 + ikasleak[i].partziNota.ekaina.exam2)) / 4;
				printf("Datuak ondo burutu dira.\n");
				aurkitu = 1;
			}
			i++;
		}
		if (aurkitu == 0) {
			printf("Ez dago ID hori duen ikaslerik.\n");
		}
		
	}
	system("pause");
	system("cls");
}

void bistaratu_guztiak(IKASLE ikasleak[], int zenbat) {

	int i = 0;
	if (zenbat <= 0) {
		printf("Oraindik ez daude ikaslerik.\n");
	}
	for (i = 0; i < zenbat; i++) {
		printf("Izena:%s\n", ikasleak[i].izena);
		printf("ID:%i\n", ikasleak[i].id);
		printf("Generoa:%s\n", ikasleak[i].genero);
		printf("Kontrolen notak:\nOtsailekoak: 1-%.2f 2-%.2f\nEkainekoak: 1-%.2f 2-%.2f\n", ikasleak[i].partziNota.otsaila.exam1, ikasleak[i].partziNota.otsaila.exam2, ikasleak[i].partziNota.ekaina.exam1, ikasleak[i].partziNota.ekaina.exam2);
		printf("Finala:%.2f\n", ikasleak[i].final);
		printf("\n");
	}
	system("pause");
	system("cls");
}

void ikasle_batazbeste(IKASLE ikasleak[], int zenbat) {

	int i=0,id,aurkitu=0;
	char str[128];
	float notaOtsaila, notaEkaina;
	if (zenbat <= 0) {
		printf("Oraindik ez daude ikaslerik.\n");
	}
	else {
		printf("Eman nahi den ikaslearen ID-a:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &id);

		while (i < zenbat&&aurkitu==0) {
			if (id == ikasleak[i].id) {
				notaOtsaila = (ikasleak[i].partziNota.otsaila.exam1 + ikasleak[i].partziNota.otsaila.exam2) / 2;
				notaEkaina = (ikasleak[i].partziNota.ekaina.exam1 + ikasleak[i].partziNota.ekaina.exam2) / 2;
				printf("Hau da %s ikaslearen otsaileko batazbesteko nota:%.2f", ikasleak[i].izena, notaOtsaila);
				printf("Hau da %s ikaslearen ekaineko batazbesteko nota:%.2f", ikasleak[i].izena, notaEkaina);
				printf("Hau da %s ikaslearen nota finala:%.2f", ikasleak[i].izena, ikasleak[i].final);
				aurkitu = 1;
			}
			i++;
		}
		if (aurkitu==0) {
		printf("Ez dago ID hori duen ikaslerik.\n");
		}
	}
	system("pause");
	system("cls");
}

void ikasle_notaAltuInfo(IKASLE ikasleak[], int zenbat) {

	int i=0;
	IKASLE max;
	if (zenbat <= 0) {
		printf("Oraindik ez daude ikaslerik.\n");
	}
	else {
		max.final = ikasleak[i].final;
		for (i = 0; i < zenbat; i++) {
			if (ikasleak[i].final > max.final) {
				max = ikasleak[i];
			}
		}
		i--;
		printf("-------------------------------------------\n");
		printf("-------%s ikaslea du notarik altuena-------\n", max.izena);
		printf("----------------[INFO]---------------------\n");
		printf("%s", max.genero);
		printf("%i\n", ikasleak[i].id);
		printf("Kontrolen notak:\nOtsailekoak: 1-%.2f 2-%.2f\nEkainekoak: 1-%.2f 2-%.2f\n", ikasleak[i].partziNota.otsaila.exam1, ikasleak[i].partziNota.otsaila.exam2, ikasleak[i].partziNota.ekaina.exam1, ikasleak[i].partziNota.ekaina.exam2);
		printf("%.2f\n", max.final);
	}
	
	system("pause");
	system("cls");
}

void ikasle_notaBaxuInfo(IKASLE ikasleak[MAX_IKAS], int zenbat) {
	int i = 0;
	IKASLE min;
	if (zenbat <= 0) {
		printf("Oraindik ez daude ikaslerik.\n");
	}
	else {
		min.final = ikasleak[i].final;
		for (i = 0; i < zenbat; i++) {
			if (ikasleak[i].final < min.final) {
				min = ikasleak[i];
			}
		}
		printf("-------------------------------------------\n");
		printf("-------%s ikaslea du notarik baxuena-------\n", min.izena);
		printf("----------------[INFO]---------------------\n");
		printf("%s", min.genero);
		printf("%i\n", min.id);
		printf("Kontrolen notak:\nOtsailekoak: 1-%.2f 2-%.2f\nEkainekoak: 1-%.2f 2-%.2f\n", ikasleak[i].partziNota.otsaila.exam1, ikasleak[i].partziNota.otsaila.exam2, ikasleak[i].partziNota.ekaina.exam1, ikasleak[i].partziNota.ekaina.exam2);
		printf("%.2f\n", min.final);
	}
	
	system("pause");
	system("cls");
}

void bilatu(IKASLE ikasleak[MAX_IKAS], int zenbat){
	
	int id, i = 0, aurkitu = 0;
	char str[128];
	if (zenbat <= 0) {
		printf("Oraindik ez daude ikaslerik.\n");
	}
	else {
		printf("Eman bilatu nahi den ikaslearen ID-a:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &id);

		while (i < zenbat&&aurkitu==0) {

			if (id == ikasleak[i].id) {
				printf("--------------Hemen %s ikaslearen informazioa-----------", ikasleak[i].izena);
				printf("%s\n", ikasleak[i].izena);
				printf("ID:%i\n", ikasleak[i].id);
				printf("Generoa:%s", ikasleak[i].genero);
				printf("Kontrolen notak:\nOtsailekoak: 1-%.2f 2-%.2f\nEkainekoak: 1-%.2f 2-%.2f\n", ikasleak[i].partziNota.otsaila.exam1, ikasleak[i].partziNota.otsaila.exam2, ikasleak[i].partziNota.ekaina.exam1, ikasleak[i].partziNota.ekaina.exam2);
				printf("Finala:%.2f\n", ikasleak[i].final);
				aurkitu = 1;
			}
			i++;
		}
		if (aurkitu == 0) {
			printf("Ez dago ikasle hori duen iD-rik\n");

		}
		
	}
	
	system("pause");
	system("cls");
}

void bistaratu_final(IKASLE ikasleak[MAX_IKAS], int zenbat) {

	int aukera = 0,i,j;
	char str[128];

	if (zenbat <= 0) {
		printf("Oraindik ez daude ikaslerik");
	}
	else {
		printf("Nola ikusi nahi duzu ikasleen notak? Handitik txikira(1) edo txikitik handira(2):\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);

		if (aukera == 1) {
			ordenatuHandiTxiki(ikasleak, zenbat);
			bistaratu_guztiak(ikasleak, zenbat);
		}
		if (aukera == 2) {
			ordenatuTxikiHandi(ikasleak, zenbat);
			bistaratu_guztiak(ikasleak, zenbat);
		}
	}
}

void ordenatuHandiTxiki(IKASLE ikasleak[], int zenbat) {
	int i, j;
	IKASLE maxtmp;

	for (i = 0; i < zenbat; i++) {
		maxtmp = ikasleak[i];
		for (j = i + 1; j < zenbat; j++) {
			if (ikasleak[i].final < ikasleak[j].final) {
				maxtmp = ikasleak[i];
				ikasleak[i] = ikasleak[j];
				ikasleak[j] = maxtmp;
			}
		}
	}
}

void ordenatuTxikiHandi(IKASLE ikasleak[], int zenbat) {

	int i, j;
	IKASLE mintmp;

	for (i = 0; i < zenbat; i++) {
		mintmp = ikasleak[i];
		for (j = i + 1; j < zenbat; j++) {
			if (ikasleak[i].final > ikasleak[j].final) {
				mintmp = ikasleak[i];
				ikasleak[i] = ikasleak[j];
				ikasleak[j] = mintmp;
			}
		}
	}

}

