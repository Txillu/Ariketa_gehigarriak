#include <stdio.h>
#include <stdlib.h>
#include  "orokorrak.h"
#include "fitxTestua.h"

void FITX_TESTUA_adibidea() {
	int zenb = 0;
	FILE* fitx_erakuslea;
	fitx_erakuslea = fopen("froga.txt" , 
							"w");
	char kar = 'a';
	char matriz[2][20];
	char izen_abizena[][20] = { "joseba","agirre" };
	char izena[] = "joseba";
	char str[20];
	strcpy(str, "joseba");
	printf("*********%i ZENBAKI TESU FITXATEGI BATEN TESTU LEZ GORDETZEN********\n", MAX_NUMBER);

	if (fitx_erakuslea > 0) {
		//ondo zabaldu dau
		for (zenb = 0; zenb < MAX_NUMBER; zenb++) {
			fputc('X', fitx_erakuslea);
			fputc( kar + zenb, fitx_erakuslea);
			fprintf(fitx_erakuslea, "%d\n", zenb);
			fprintf(fitx_erakuslea, "Kaixo %s!\n", izena);
			fprintf(fitx_erakuslea, "Kaixo %s %s!", izen_abizena[0], izen_abizena[1]);


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
	
	//1- zabaldu fitxategia
	//2-iarkurri lehengo lerroko izena eta gorde arraian
	//3- Bistaratu pertsonak
	FILE* fitx_erakuslea;
	int i = 0;
	ERABILTZAILEA erabil[MAX_ERABIL];
	int irakurritakoak = 1;
	fitx_erakuslea = fopen("erabiltzaileak.txt",
		"r");
	if (fitx_erakuslea > 0) {
		char str[20];
		//fscanf(fitx_erakuslea, "%s", str);
		while ( irakurritakoak >= 1  && i < MAX_ERABIL) {
			irakurritakoak = fscanf(fitx_erakuslea, "%s\n", erabil[i].izena);
			if (irakurritakoak >= 1) {
				printf("%i. erabiltzailea: %s\n", i + 1, erabil[i].izena);
				i++;
			}
			
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









