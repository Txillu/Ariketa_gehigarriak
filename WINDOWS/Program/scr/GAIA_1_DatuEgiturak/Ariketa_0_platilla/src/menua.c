#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


#include "orokorrak.h"
#include "diskak.h"
#include "stocka.h"
//#include "erabiltzaileak.h"
#include "menua.h"


int  MENUA_admin(DISKA_MOTA stocka[], int zenbat) {
	//TODO
	int aukera = 0;
	char str[MAX_STR];
	printf("************************ADMIN MENUA*********\n");
	printf("|1 - Diska berri bat gehitu stocka			\n");
	printf("|2 - diska bat kendu stocketik				\n"); 
	printf("|3 - Diska bat modifikatu					\n");
	printf("|4 - Bistaratu								\n");
	printf("|	a) - Estilokaka							\n");
	printf("|	b) - Autoreka 							\n"); 
	printf("|	c) - Zigilua							\n");
	printf("|	d) - Datak erabiliz 					\n");
	printf("|	e) - Bat aurkitu	 					\n");
	printf("|0 - Irten 									\n");
	printf("********************************************\n");
	printf("Admin zer nahi dozu?\n");
	fgets(str ,		MAX_STR , stdin);
	//
	sscanf(str , "%i", &aukera);
	//								!!!!!!!!!!!!!!!!!!!!!!	
	zenbat = MENUA_ADMIN_exekutatu(aukera , stocka,  zenbat);

	return zenbat;
}

int  MENUA_ADMIN_exekutatu(int aukera, DISKA_MOTA stocka[] , int zenbat) {
	//TODO
	system("clear");
	switch(aukera) {
		case SORTU_DISKA:
			zenbat = MENUA_sartuDiska(stocka, zenbat);
			break;
		case EZABATU_DISKA:
			printf("EZBAATU DISKA AUKERATU DUZU\n");
			//zenbat = MENUA_ezabatuDiska(stocka, zenbat);
			break;
		case EGUNERATI_DISKA:
			//zenbat = MENUA_eguneratu(stocka, zenbat);
			break;
		case BISTARATU:
			//MENUA_bistaratu(stocka, zenbat);
			break;
		case IRTEERA:
			//MENUA_irten();
			break;
		default:
			printf("Aukera desegokia\n");

	}

	return zenbat;
}

int	MENUA_sartuDiska(DISKA_MOTA stocka[], int zenbat) {
	DISKA_MOTA diskaBerria;
	printf("[INFO]Diska bat sortu aukeratu duzu.\n");
	diskaBerria = DISKAK_sortubat(); 
	zenbat = STOCKA_diskaBatSartu(diskaBerria, stocka, zenbat);
	//stocka = STOCKA_diskaBatSartu_v2(stocka, diskaBerria) {
	return zenbat;
}

void foo() {
	printf("************************EROSLEAREN MENUA*********\n");
	printf("|1 - Diska berri bat gehitu erosketara (Carrito de la compra)	\n");
	printf("|2 - Erosketa burutu						\n");
	printf("|3 - Erosketa karritoa ikusi				\n");
	printf("|4 - Bistaratu	stocka						\n");
	printf("|	a) - Estilokaka							\n");
	printf("|	b) - Autoreka 							\n");
	printf("|	c) - Zigilua							\n");
	printf("|	d) - Datak erabiliz 					\n");
	printf("|	e) - Bat aurkitu	 					\n");
	printf("|0 - Irten 									\n");
	printf("********************************************\n");
}



STOCKA  MENUA_admin_v2(STOCKA stocka) {
	int aukera = 0;
	char str[MAX_STR];
	printf("************************ADMIN MENUA*********\n");
	printf("|1 - Diska berri bat gehitu stocka			\n");
	printf("|2 - diska bat kendu stocketik				\n");
	printf("|3 - Diska bat modifikatu					\n");
	printf("|4 - Bistaratu								\n");
	printf("|	a) - Estilokaka							\n");
	printf("|	b) - Autoreka 							\n");
	printf("|	c) - Zigilua							\n");
	printf("|	d) - Datak erabiliz 					\n");
	printf("|	e) - Bat aurkitu	 					\n");
	printf("|0 - Irten 									\n");
	printf("********************************************\n");
	printf("Admin zer nahi dozu?\n");
	fgets(str, MAX_STR, stdin);
	//
	sscanf(str, "%i", &aukera);
	//								!!!!!!!!!!!!!!!!!!!!!!	
	//KONTUZ!!!!!!!!!!!!!!!!!!!!!!!!!
	//HAU HOBETO LEGOKE STOCKA kontzeotua erabilita , baina kodea berriro ere ez idazteko egin dut!!!!!!!!!!!!!!!!!!!!!
	stocka.zenbat = MENUA_ADMIN_exekutatu(aukera, stocka.diskak, stocka.zenbat);

	return stocka;
}



void jarraitu() {
	char aux;
	printf("Sakatu return jarraitzeko....");
	aux = getchar();
	system("clear");
}