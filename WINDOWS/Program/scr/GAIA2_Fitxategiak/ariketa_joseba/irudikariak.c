#include <stdio.h>
#include <stdlib.h>
#include "irudikariak.h"

void IRUDIKARIA_bistaratu(IRUDIKARIA zenb);

void IRUDIKARIAK_idatzi() {
	char fitxategiak[][48] = { FITX1_IZENA, FITX2_IZENA };
	IRUDIKARIA zenbakiak[] = {	{1,2},
								{-1,-2},
								{4,5},
								{7,-3},
								{1,1},
								{0,2}
							 };
	int kop = 6;
	int egoera = 0;
	FILE* fitx;
	int i = 0;

	fitx = fopen(fitxategiak[0], "wb");

	if (fitx > 0) {
		printf("Lehen eta bizi konplxeuak zenbakiak banan banan idatziko ditugu\n");
		for (i = 0; i < kop; i++) {
			egoera = fwrite(&zenbakiak[i], sizeof(IRUDIKARIA), 1, fitx);
			if (egoera <= 0) printf("Errorea: %i. zenbakia idazterakoan\n", i + 1);
		}
		fclose(fitx);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian\n", fitxategiak[0]);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", fitxategiak[0]);
	}
	/////////////////////////////////////////////////////////////////////////////
	fitx = fopen(fitxategiak[1], "wb");

	if (fitx > 0) {
		printf("Zenbaki danak write batekin idazten\n");
		egoera = fwrite(zenbakiak, sizeof(IRUDIKARIA), kop, fitx);

		if (egoera != kop) printf("Errorea: fitxategiak idazterakian\n");
		else printf("Datuak idatzita %s fitxategian\n", fitxategiak[1]);
		fclose(fitx);
	}
	else {
		printf("ERROR: Arazoak %sfitxategia zabaltzerakoan.\n", fitxategiak[1]);
	}






}
void IRUDIKARIAK_irakurri() {
	char fitxategiak[][48] = { FITX1_IZENA, FITX2_IZENA };
	IRUDIKARIA zenbakiak[10];
	IRUDIKARIA zenbakiak_v1[10];
	int kop = 0;
	int egoera = 0;
	FILE* fitx;
	int i = 0;
	printf("////////////////////////////////KONPLEXUAK FItXATEGIAK IRAKURTZERA/////////////////////////////////////////////\n");
	fitx = fopen(fitxategiak[0], "rb");

	if (fitx > 0) {
		printf("Lehen eta bizi zenbakiak banan banan irakurriko  ditugu\n");
		do {
			egoera = fread(&zenbakiak[i], sizeof(IRUDIKARIA), 1, fitx);
			if (egoera != 1) {
				//the proper indicator is set, which can be checked with ferror and feof, 
				if (feof(fitx)) {
					printf("%s fitxatgiaren bukaera\n", fitxategiak[0]);
					//
				}
				else {//ferror(fitx)==true
					printf("Errorea %s fitxategai irakurzretakoan\n.", fitxategiak[0]);
				}
			}
			else {
				IRUDIKARIA_bistaratu(zenbakiak[i]);
				i++;
			}
		} while (egoera > 0);
		fclose(fitx);
		if (egoera > 0)	printf("%i zenbaki irakurrita %s fitxategian\n", i, fitxategiak[0]);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", fitxategiak[0]);
	}

	fitx = fopen(fitxategiak[1], "rb");
	printf("Orain danak pausu baten irakurriko ditugu...\n");
	int blokea = 0;
	int totala = 0;
	if (fitx > 0) {
		printf("Zenbaki danak 4 lanaka irakurtzen \n");
		do {
			egoera = fread(zenbakiak_v1 + totala, sizeof(IRUDIKARIA), 4, fitx);
			if (egoera > 0) {
				printf("%i zenbaki irakurrita %s fitxategian\n", egoera, fitxategiak[1]);
				for (i = blokea * 4; i < (blokea * 4) + egoera; i++) IRUDIKARIA_bistaratu(zenbakiak_v1[i]);
				blokea++;
				totala = totala + egoera;
			}
		} while (egoera > 0);


	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", fitxategiak[1]);
	}



}
void IRUDIKARIAK_idatzi_Testuan() {

	FILE* fitxErakusle;
	char izena[48];
	strcpy(izena, "irudikariak.txt");
	fitxErakusle = fopen("irudikariak.txt", "w");
	IRUDIKARIA zenbakiak[] = { {1,2},
							{-1,-2},
							{4,5},
							{7,-3},
							{1,1},
							{0,2}
	};
	int kop = 6;
	int egoera = 0;
	int i = 0;
	printf("////////////KONPLXEUAK TESTU ERAN IDAZTEN////////////");
	if (fitxErakusle > 0) {
		printf("Lehen eta bizi zenbakiak banan banan idatziko ditugu\n");
		for (i = 0; i < kop; i++) {
			egoera = IRUDIKARIA_fitxategianIdatzi(zenbakiak[i], fitxErakusle);			
		}
		fclose(fitxErakusle);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian\n", izena);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", izena);
	}

}



void IRUDIKARIAK_irakurri_Testuan() {

	FILE* fitxErakusle;
	char izena[48];
	IRUDIKARIA zenbakiak[128];
	char aux = 0;
	int kop = 0;
	int egoera = 0;
	int i = 0;

	strcpy(izena, "irudikariak.txt");
	fitxErakusle = fopen("irudikariak.txt", "r");
	printf("////////////TESTU ERAN irakurtzen////////////\n");
	if (fitxErakusle > 0) {
		do {
			egoera = fscanf(fitxErakusle, "%i%c%ij\n", &zenbakiak[kop].erreala , &aux ,&zenbakiak[kop].irudikaria);//hau hobeto egin genezake
			if (egoera > 0) {
				if (aux == '-') zenbakiak[kop].irudikaria = zenbakiak[kop].irudikaria * -1;
				kop++;
			}
		} while (egoera > 0 && kop < 128);
		fclose(fitxErakusle);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian \n", izena);
		for (i = 0; i < kop; i++) IRUDIKARIA_bistaratu( zenbakiak[i]);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", izena);
	}

}

void IRUDIKARIA_bistaratu(IRUDIKARIA zenb)
{
	char seinua = '+';
	int neg = 1;
	//Hau bisualizaziorako da soilik
	if (zenb.irudikaria < 0) {
		seinua = '-';
		neg = -1;
	}
	//Hau bisualizaziorako da soilik
	printf("%i%c%ij Zenbaki konplexuaren\n", zenb.erreala,
		seinua,
		(neg*zenb.irudikaria));
}

int IRUDIKARIA_fitxategianIdatzi(IRUDIKARIA zenb, FILE* fitx) {
	char seinua = '+';
	int neg = 1;
	int egoera = 0;
	//Hau bisualizaziorako da soilik
	if (zenb.irudikaria < 0) {
		seinua = '-';
		neg = -1;
	}
	if (fitx > 0) {
		//Hau bisualizaziorako da soilik
		egoera = fprintf( fitx, "%i%c%ij\n", zenb.erreala,
			seinua,
			(neg*zenb.irudikaria));

	}
	return egoera;
}