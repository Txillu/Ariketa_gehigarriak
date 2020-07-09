#include <stdio.h>
#include <stdlib.h>
#include  "orokorrak.h"
#include "fitxTestua.h"

void FITX_TESTUA_adibidea() {
	int zenb = 0;
	FILE* fitx_erakuslea;
	fitx_erakuslea = fopen("froga.txt" , 
							"w");

	//w sortu
	//a gehitu
	char kar = 'a';
	char izena[] = { "Qing Yu" };
	char saludo[] = "Kaixo";

	printf("*********%i ZENBAKI TESU FITXATEGI BATEN TESTU LEZ GORDETZEN********\n", MAX_NUMBER);

	//ondo zabaldu du
	if (fitx_erakuslea > 0) {
		for (zenb = 0; zenb < MAX_NUMBER; zenb++) {
			fputc('X', fitx_erakuslea);
			fputc(kar+zenb, fitx_erakuslea);
			fprintf(fitx_erakuslea, "%s", saludo);
			fprintf(fitx_erakuslea, "%s", izena);


			fprintf(fitx_erakuslea, "%d\n", zenb);
		}
	}
	else {
		printf("Errorea %s fitxategia sortzerakoan.\n",
				FILE_IZENA_TESTUA);
	}

	if (fitx_erakuslea > 0) {
		fclose(fitx_erakuslea);
	}
	


}

void FITX_TESTUA_irakurriErabiltzaileak() {

	ERABILTZAILEA erabil[10];

	//1-zabaldu fitx
	//2-irakurri fitx
	//3-bistaratu pertsonak

	int i = 0;

	FILE* fitx_erakuslea;
	fitx_erakuslea = fopen("erabiltzaileak.txt", "r");

	if (fitx_erakuslea > 0) {
		
		fscanf(fitx_erakuslea, "%s", erabil[i].izena);
		printf("Lehenengo erabiltzailea: %s\n");
	}
	else {
		printf("Errorea %s fitxategia sortzerakoan.\n",
			FILE_IZENA_TESTUA);
	}

	if (fitx_erakuslea > 0) {
		fclose(fitx_erakuslea);
	}

}