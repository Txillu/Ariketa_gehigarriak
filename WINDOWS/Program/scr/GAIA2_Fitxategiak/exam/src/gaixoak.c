#define _CRT_SECURE_NO_WARNINGS
#define MAX_GAIXO 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"gaixoak.h"


int gaixoakIrakurri(GAIXOA gaixo[], int kop){


	int i = 0;
	FILE* fitx;
	int irakurri;
	fitx = fopen(GAIXOAK, "r");
	if (fitx > 0) {

		do {
			//irakurri=fread(&gaixo[i], sizeof(int), 1, egoera);
			irakurri = fscanf(fitx, "%i %s %s %i %s", &gaixo[i].id, &gaixo[i].izena, &gaixo[i].abizena, &gaixo[i].adina, &gaixo[i].herria);
			i++;
			kop++;

		} while (irakurri != EOF);
		fclose(fitx);
	}
	else {
		printf("Arazoa egon da fitxategia irekitzerakoan");
	}
	return kop;
}

void egoeraIrakurri(GAIXOA gaixo[]){

	int i = 0;
	FILE* fitx;
	int irakurri;
	fitx = fopen(EMAITZA, "r");
	if (fitx > 0) {

		do {
			//irakurri=fread(&gaixo[i], sizeof(int), 1, egoera);
			irakurri = fscanf(fitx, "%c", &gaixo[i].egoera);
			i++;
		} while (irakurri==1);
		fclose(fitx);
	}
	else {
		printf("Arazoa egon da fitxategia irekitzerakoan");
	}

}

void positibo(GAIXOA gaixo[],int kop) {
	int i = 0;
	char positibo = 'p';

	for (i = 0; i <= kop; i++) {
		if (positibo == gaixo[i].egoera){

			printf("%s %s positiboa eman birusaren tesean dute\n", gaixo[i].izena, gaixo[i].abizena);

		}

	}
}

void fitxategiPasatu(GAIXOA gaixo[], int zenbat) {


	int i = 0;
	FILE* fitx;
	int idatzi;
	fitx = fopen("lotura.txt", "w");
	if (fitx > 0) {

		for (i = 0; i < zenbat-1; i++) {
			idatzi = fprintf(fitx, "%i,%c\n", gaixo[i].id, gaixo[i].egoera);
		}
		fclose(fitx);
	}
	else {
		printf("Arazoa egon da fitxategia irekitzerakoan");
	}

}