#include <stdio.h>
#include <stdlib.h>
#include "erabiltzaileak.h"


void ERABIL_bistaratu(ERABIL zenb);

void ERABIL_idatzi() {
	char fitxategiak[][48] = { FITX1_IZENA};
	ERABIL zenbakiak[] = { { 1 , "admin" , "qwerty" , ADMIN},
						   { 2 , "joseba" , "123456" , EROSLE}
	};
	int kop = 2;
	int egoera = 0;
	FILE* fitx;
	int i = 0;

	fitx = fopen(fitxategiak[0], "wb");

	if (fitx > 0) {
		printf("Lehen eta bizi perstonak zenbakiak banan banan idatziko ditugu\n");
		for (i = 0; i < kop; i++) {
			egoera = fwrite(&zenbakiak[i], sizeof(ERABIL), 1, fitx);
			if (egoera <= 0) printf("Errorea: %i. zenbakia idazterakoan\n", i + 1);
		}
		fclose(fitx);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian\n", fitxategiak[0]);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", fitxategiak[0]);
	}
	/////////////////////////////////////////////////////////////////////////////
	



}
void ERABIL_irakurri() {
	char fitxategiak[][48] = { FITX1_IZENA };
	ERABIL zenbakiak[10];
	int kop = 0;
	int egoera = 0;
	FILE* fitx;
	int i = 0;
	printf("////////////////////////////////PERTSONAK FItXATEGIAK IRAKURTZERA/////////////////////////////////////////////\n");
	fitx = fopen(fitxategiak[0], "rb");

	if (fitx > 0) {
		printf("Lehen eta bizi zenbakiak banan banan irakurriko  ditugu\n");
		do {
			//-----------------FREAD Y FREAD SALTA AUTOMATICAMENTE------------------
			egoera = fread(&zenbakiak[i], sizeof(ERABIL), 1, fitx);
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
				ERABIL_bistaratu(zenbakiak[i]);
				i++;
			}
		} while (egoera > 0);
		fclose(fitx);
		if (egoera > 0)	printf("%i zenbaki irakurrita %s fitxategian\n", i, fitxategiak[0]);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", fitxategiak[0]);
	}

	

}
void ERABIL_idatzi_Testuan() {

	FILE* fitxErakusle;
	char izena[48];
	strcpy(izena, "erabil.txt");
	fitxErakusle = fopen("erabil.txt", "w");
	ERABIL zenbakiak[] = { { 1 , "admin" , "qwerty" , ADMIN},
					   { 2 , "joseba" , "123456" , EROSLE}
	};
	int kop = 2;
	int egoera = 0;
	int i = 0;
	printf("////////////PERSTONAK TESTU ERAN IDAZTEN////////////\n");
	if (fitxErakusle > 0) {
		printf("Lehen eta bizi zenbakiak banan banan idatziko ditugu\n");
		for (i = 0; i < kop; i++) {
			egoera = ERABIL_fitxategianIdatzi(zenbakiak[i], fitxErakusle); //------HAU PRINTEATZEKO 
		//	egoera = ERABIL_fitxategianIdatzi(zenbakiak, i, fitxErakusle); --------HAU MODIFIKATZEKO (return)
		}
		fclose(fitxErakusle);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian\n", izena);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", izena);
	}

}

void ERABIL_irakurri_Testuan() {

	FILE* fitxErakusle;
	char izena[48];
	ERABIL zenbakiak[128];
	char aux = 0;
	int kop = 0;
	int egoera = 0;
	int i = 0;

	strcpy(izena, "erabil_froga.txt");
	fitxErakusle = fopen("erabil.txt", "r");
	printf("////////////PERTOSNAK TESTU  ERAN irakurtzen////////////\n");
	if (fitxErakusle > 0) {
		do {
			egoera = fscanf(fitxErakusle, "%i\t%s\n", &zenbakiak[kop].id,			
																zenbakiak[kop].username);
			egoera = fscanf(fitxErakusle, "%s\t%i\n",		zenbakiak[kop].password, 
																&zenbakiak[kop].mota);//hau hobeto egin genezake
			if (egoera > 0) {
				kop++;
			}
		} while (egoera > 0 && kop < 128);
		fclose(fitxErakusle);
		if (egoera > 0)	printf("Datuak idatzita %s fitxategian \n", izena);
		for (i = 0; i < kop; i++) ERABIL_bistaratu(zenbakiak[i]);
	}
	else {
		printf("ERROR: Arazoak %s fitxategia zabaltzerakoan.\n", izena);
	}

}

void ERABIL_bistaratu(ERABIL per)
{
	
	//Hau bisualizaziorako da soilik
	printf("%i\t%s\t%s\t%i\n", per.id , per.username , per.password , per.mota);
}

int ERABIL_fitxategianIdatzi(ERABIL per, FILE* fitx) {

	int egoera = 0;
	//Hau bisualizaziorako da soilik
	
	if (fitx > 0) {
		//Hau bisualizaziorako da soilik------------------ '\t' tabulatzeko erabiltzen da 
		egoera = fprintf(fitx , "%i\t%s\t%s\t%i\n", per.id, per.username, per.password, per.mota);
	}
	return egoera;
}