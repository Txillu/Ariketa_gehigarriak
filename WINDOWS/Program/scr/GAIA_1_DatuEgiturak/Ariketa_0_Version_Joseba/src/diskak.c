/*
	int id;
	float prezioa;
	int stock;
	char izenburua[MAX_STR];
	char autor[MAX_STR];//taldea , solista
	int estiloa;
	char data[MAX_STR];
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "orokorrak.h"


#include "diskak.h"

 /*STOC SORTU*/


void DISKAK_bistaratuEstiloa(int estiloa) {
	switch (estiloa) {
		case ROCK: 
			printf("Rock\n");
			break;
		case BLUES:
			printf("Blues\n");
			break;
		case ELECTRONICA:
			printf("Electronica\n");
			break;
		case JAZZ:
			printf("Jazz\n");
			break;
		case POP:
			printf("Pop\n");
			break;
		case PUNK:
			printf("Punk\n");
			break;
		default:
			printf("Ezezaguna\n");
			break;
	}

}


void DISKAK_bistaratuDanak(DISKA_MOTA diskak[10], int zenbat) {
	//BISTARATU ARRAYA
	int i = 0;
	printf("[INFO]Diska danak bistaratzen\n");
	for (i = 0; i < zenbat; i++) {
		printf("_______________DISKA  %i_________________________\n", diskak[i].id);
		printf("DISKA %s \( %s \) \n%2.2f euro ,  %s \t  stock:%i\n", diskak[i].izenburua, 
															diskak[i].autor , diskak[i].prezioa, 
															diskak[i].data,
															diskak[i].stock);
		DISKAK_bistaratuEstiloa(diskak[i].estiloa);
		//ESTILOA: Rock
		
	}

}

DISKA_MOTA DISKAK_sortubat() {
	//1-DISKA BAT SORTU
	DISKA_MOTA diska;
	char str[128];
	//diskari baloreak emon fgets , printf sscanf
	printf("Idatzi diska berriaren ida:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &diska.id);
	//1- Izneburua 
	printf("Idatzi diska berriaren izenburua:");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(diska.izenburua , str);
	//2-autorea
	printf("Idatzi diska berriaren autorea/taldea:");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(diska.autor, str);
	//3-data 
	printf("Idatzi diska berriaren data(2020/2/7):");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(diska.data, str);
	//4-estiloa
	printf("Idatzi diska berriaren estiloa (BLUES=0, ROCK=1, JAZZ=2, POP=3 , ELECTRONICA=4, PUNK=5):");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &diska.estiloa);
	//5-prezioa
	printf("Idatzi diska berriaren prezioa:");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &diska.prezioa);
	//diska bueltatu
	return diska;
}















