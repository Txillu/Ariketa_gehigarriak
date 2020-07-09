#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include "funtzioak.h"


EKINTZAK* fitxategiaEskatu(EKINTZAK* burua,int *kop){

	FILE* fitx;
	char fitxategiarenIzena[MAX_STR];
	EKINTZAK* irakurritakoEkintza=NULL,*kurtsorea=NULL;
	int irakurri;


	printf("Zer fitxategi ireki nahi duzu: ");
	fgets(fitxategiarenIzena, 128, stdin);
	fitxategiarenIzena[strlen(fitxategiarenIzena) - 1] = '\0';

	irakurritakoEkintza = (EKINTZAK*)malloc(sizeof(EKINTZAK));
	//kurtsorea = burua;


	fitx = fopen(fitxategiarenIzena, "r");
	if (fitx > 0) {


		do {


			irakurri = fscanf(fitx, "%s %i %i/%i/%i %i:%i", &irakurritakoEkintza->izena, &irakurritakoEkintza->kostua, &irakurritakoEkintza->eguna.urtea, &irakurritakoEkintza->eguna.hilabetea, &irakurritakoEkintza->eguna.eguna, &irakurritakoEkintza->ordu.ordua, &irakurritakoEkintza->ordu.minutua);
			//irakurri = fscanf(fitx, "%s\t%i\t%i/%i/%i\t%i:%i", &ekintza->izena, &ekintza->kostua, &ekintza->eguna.urtea, &ekintza->eguna.hilabetea, &ekintza->eguna.eguna, &ekintza->ordu.ordua, &ekintza->ordu.minutua);

			if (irakurri > 0) {

				burua = ekintzaSartu(irakurritakoEkintza, burua);
				*kop = *kop + 1;
			}

			/*if (burua == NULL) {
				burua = ekintza;
				ekintza->hurrengoa = NULL;

			}
			else {
				kurtsorea = burua;
				while (kurtsorea != NULL) {
					kurtsorea = kurtsorea->hurrengoa;
				}
				kurtsorea = ekintza;
				ekintza->hurrengoa = NULL;
			}*/

		} while (irakurri != EOF);

		fclose(fitx);
	}
	else {
		printf("Errorea fitxategia irakurtzerakoan.");
		return NULL;
	}
	return burua;
}

EKINTZAK* sartuBesteEkintzBat() {

	EKINTZAK* ekintzaBerria;
	char str[128];

	ekintzaBerria = (EKINTZAK*)malloc(sizeof(EKINTZAK));

	printf("Eman ekintzaren izena:");
	fgets(ekintzaBerria->izena, 128, stdin);
	ekintzaBerria->izena[strlen(ekintzaBerria->izena) - 1] = '\0';

	printf("Eman ekintzaren kostua:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &ekintzaBerria->kostua);

	printf("Eman ekintza egin den data (UUUU/HH/EE):");
	fgets(str, 128, stdin);
	sscanf(str, "%i/%i/%i", &ekintzaBerria->eguna.urtea,&ekintzaBerria->eguna.hilabetea,&ekintzaBerria->eguna.eguna);

	printf("Eman ekintza egin den ordua (HH:MM):");
	fgets(str, 128, stdin);
	sscanf(str, "%i:%i", &ekintzaBerria->ordu.ordua,&ekintzaBerria->ordu.minutua);

	ekintzaBerria->hurrengoa = NULL;

	return ekintzaBerria;

}

EKINTZAK* berriaListanSartu(EKINTZAK* burua, EKINTZAK* ekintzaBerria) {

	EKINTZAK *kurtsorea;

	kurtsorea = burua;

	while (kurtsorea != NULL) {
		kurtsorea = kurtsorea->hurrengoa;
	}
	kurtsorea = ekintzaBerria;
	ekintzaBerria->hurrengoa = NULL;

	return burua;
}

int kostutotala(EKINTZAK* ekintza) {

	int kostuTotala=0;

	EKINTZAK* kurtsorea=ekintza;

	for (kurtsorea = ekintza; kurtsorea != NULL; kurtsorea = kurtsorea->hurrengoa) {
		kostuTotala = kostuTotala + kurtsorea->kostua;
	}

	return kostuTotala;
}

void fitxategiBerria(EKINTZAK* ekintza) {

	char fitxategiarenIzenBerria[128];

	printf("Zer izenarekin gorde nahi duzu fitxategi berria (izenean .txt ere jarri beharko da): ");
	fgets(fitxategiarenIzenBerria, 128, stdin);
	fitxategiarenIzenBerria[strlen(fitxategiarenIzenBerria) - 1] = '\0';

	FILE* fitx;
	fitx = fopen(fitxategiarenIzenBerria, "w");

	EKINTZAK* kurtsorea=ekintza;
	
	if(fitx>0){

		for (kurtsorea = ekintza; kurtsorea != NULL; kurtsorea = kurtsorea->hurrengoa) {

			fprintf(fitx, "%s\t%i\t%i/%i/%i\t%i:%i\n", ekintza->izena, ekintza->kostua, ekintza->eguna.urtea, ekintza->eguna.hilabetea, ekintza->eguna.eguna, ekintza->ordu.ordua, ekintza->ordu.minutua);
		}

		fclose(fitx);
	}
	else {
		printf("errorea fitxategia irekitzerakoan");
	}

}

EKINTZAK* ekintzaSartu(EKINTZAK* ekintza, EKINTZAK* burua) {

	EKINTZAK* kurtsorea;

	if (burua == NULL) {
		burua = ekintza;
		ekintza->hurrengoa = NULL;

	}
	else {
		kurtsorea = burua;
		while (kurtsorea != NULL) {
			kurtsorea = kurtsorea->hurrengoa;
		}
		kurtsorea = ekintza;
		ekintza->hurrengoa = NULL;
	}
	return burua;
}