#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "errealak.h"

void ERREALAK_idatzi() {
	char fitxategiak[][48]= { FITX1_IZENA, FITX2_IZENA };
	float zenbakiak[] = { 1.2, 1.1, 4 , 5, 6, 7, 8, 9 ,10};
	int kop = 9;
	int egoera = 0;
	FILE* fitx;
	int i = 0;

	fitx = fopen(fitxategiak[0] , "wb");
	float zenb = 3;
	if (fitx > 0) {
		printf("Lehen eta bizi zenbakiak banan banan idatziko ditugu\n");
		for (i = 0; i < kop; i++) {
			egoera = fwrite(&zenbakiak[i] , sizeof(float), 1, fitx);
			if (egoera <= 0) printf("Errorea: %i. zenbakia idazterakoan\n", i + 1);
		}
		fclose(fitx);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian\n", fitxategiak[0]);
	}else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", fitxategiak[0]);
	}
	/////////////////////////////////////////////////////////////////////////////
	fitx = fopen(fitxategiak[1], "wb");

	if (fitx > 0) {
		printf("Zenbaki danak write batekin idazten\n");
		egoera = fwrite(zenbakiak, sizeof(float), kop, fitx);
		
		if (egoera != kop) printf("Errorea: fitxategiak idazterakian\n");
		else printf("Datuak idatzita %s fitxategian\n", fitxategiak[1]);
		fclose(fitx);
	}
	else {
		printf("ERROR: Arazoak %sfitxategia zabaltzerakoan.\n", fitxategiak[1]);
	}

	

	


}
void ERREALAK_irakurri() {
	char fitxategiak[][48] = { FITX1_IZENA, FITX2_IZENA };
	float zenbakiak[10];
	float zenbakiak_v1[10];
	int kop = 0;
	int egoera = 0;
	FILE* fitx;
	int i = 0;
	printf("////////////////////////////////FIRAXTEGIAK IRAKURTZERA/////////////////////////////////////////////\n");
	fitx = fopen(fitxategiak[0], "rb");

	if (fitx > 0) {
		printf("Lehen eta bizi zenbakiak banan banan irakurriko  ditugu\n");
		do{
			float zenb = 3;
			egoera = fread( &zenbakiak[i], sizeof(float), 1, fitx);
			egoera = fread(&zenb, sizeof(float), 1, fitx);
			if (egoera != 1) {
				//the proper indicator is set, which can be checked with ferror and feof, 
				if (feof(fitx)) {
					printf("%s fitxatgiaren bukaera\n" , fitxategiak[0]);
					//
				}
				else {//ferror(fitx)==true
					printf("Errorea %s fitxategai irakurzretakoan\n.", fitxategiak[0]);
				}
			} 
			else {
				printf("%f zenbakia irakurrita.\n", zenbakiak[i]);
				i++;
			} 
		} while (egoera > 0);// edo while (egoera !=EOF)   // while(!feof(fitx))
		fclose(fitx);
		if (egoera > 0)	printf("%i zenbaki irakurrita %s fitxategian\n", i , fitxategiak[0]);
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
			//egoera = fread(&zenbakiak[0], sizeof(float), 9, fitx);
			egoera = fread( zenbakiak_v1+totala/* igual &zenbakiak[totala]*/, sizeof(float), 4, fitx);
			//egoera = fread( zenbakiak_v1+totala, sizeof(float), 4, fitx);
			if (egoera > 0) {
				printf("%i zenbaki irakurrita %s fitxategian\n", egoera, fitxategiak[1]);

				//for (i = blokea * 4 ; i < (blokea*4)+egoera; i++) printf("%f \n", zenbakiak_v1[i]);
				//blokea++;

				totala = totala + egoera;
			}
		} while (egoera > 0 );
		

	}else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", fitxategiak[1]);
	}



}
void ERREALAK_idatzi_Testuan() {

	FILE* fitxErakusle;
	char izena[48];
	strcpy(izena , "errealak.txt");
	fitxErakusle = fopen("errealak.txt", "w");
	float zenbakiak[] = { 1.2, 1.1, 4 , 5, 6, 7, 8, 9 ,10 };
	int kop = 9;
	int egoera = 0;
	int i = 0;
	printf("////////////TESTU ERAN IDAZTEN////////////");
	if (fitxErakusle > 0) {
		printf("Lehen eta bizi zenbakiak banan banan idatziko ditugu\n");
		for (i = 0; i < kop; i++) {
			egoera = fprintf(fitxErakusle, "%2.2f\n", zenbakiak[i]);
			if (egoera <= 0) printf("Errorea: %i. zenbakia idazterakoan\n", i + 1);
		}
		fclose(fitxErakusle);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian\n", izena);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", izena);
	}

}



void ERREALAK_irakurri_Testuan() {

	FILE* fitxErakusle;
	char izena[48];
	float zenbakiak[128];
	int kop = 0;
	int egoera = 0;
	int i = 0;

	strcpy(izena, "errealak.txt");
	fitxErakusle = fopen("errealak.txt", "r");
	printf("////////////TESTU ERAN irakurtzen////////////\n");
	if (fitxErakusle > 0) {
		do {
			egoera = fscanf(fitxErakusle , "%f\n", &zenbakiak[kop]);//hau hobeto egin genezake
			if (egoera > 0) kop++;
		} while (egoera > 0  && kop < 128 );
		fclose(fitxErakusle);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian \n", izena);
		for (i = 0; i < kop ; i++) printf("%f \n", zenbakiak[i]);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", izena);
	}

}