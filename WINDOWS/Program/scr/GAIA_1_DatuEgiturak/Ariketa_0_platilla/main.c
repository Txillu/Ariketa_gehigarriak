#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
/*
PROGRAMA: Disken denda
DESKRIPZIOA: Disken denda
			- Dendaria -> stock sortu eta administrau,  bezeroak kudeatu 
			- Diskoa
			- Bezeroa -> bilatu diskak eta Erosi
			0. stock-a sortu (diskak)
			1.Login (Nor zara )
			2.Bezeroarren menua
				2.1-Diska gehitu
				2.2- Bilatu (estilos , por titulo , por fecha , por autor)
				2.3- Erosketa burutu
			3.Dendariaren menua
				3.1-Diskak gehitu
				3.2- Diskak modifikatu (stock , prezioa,)
				3.3- Bezeroak kudeatu
					-gehitu
					- kendu
					- modifikatu
					- dirua emon

*/
#include "orokorrak.h"
#include "diskak.h"
#include "stocka.h"
#include "erabiltzaileak.h"

#include "menua.h"



int main() {
	int zenbatBilbo = 0;
	DISKA_MOTA stockaBilbo[10];
	//******************************
	STOCKA donostikoStocka;
	STOCKA madrilekoStocka;

	ERABILTZAILEA erabil[5];
	int kopErabil = 0;
	char aux = 0;
	MOTA mota = 0;
	char username[MAX_STR];
	int erabilIndex = 0;
	int bukatu = 0;
	
	//ERABILTZAILEAK SORTU
	kopErabil =  ERABILTZAILEAK_sortu_(erabil, kopErabil);
	
	//PROGRANA
	//0. stock - a sortu(diskak)
	printf("[INFO]->Bilboko Stocka kargetan ....\n");
	zenbatBilbo = STOCKA_sortu(stockaBilbo);
	printf("[INFO]->Bilboko Stocka kargatuta ....\n");
	printf("[INFO]...\n]");
	DISKAK_bistaratuDanak(stockaBilbo, zenbatBilbo);
	printf("\n");
	system("clear");
	DISKAK_bistaratuDanak(stockaBilbo, zenbatBilbo);
	jarraitu();
	printf("Oarin best era bate kudeatuko ditugu stocka, zenbat eta diskak elkarrekin ;-)\n");
	donostikoStocka = STOCKA_sortu_v2();
	madrilekoStocka = STOCKA_sortu_v2();

	printf("------------------donostiko stocka-----------------------------------");
	DISKAK_bistaratuDanak(donostikoStocka.diskak, donostikoStocka.zenbat);
	printf("------------------madrileko stocka-----------------------------------");
	DISKAK_bistaratuDanak(madrilekoStocka.diskak, madrilekoStocka.zenbat);
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("------------------------------------DISKA DENDA-----------------------------------------------------\n");
	
	while( bukatu != -1){
		//ESKATU USERNAME ETA PASSWORD ETA GERO PASAU FUNTZIOARI
		mota = MENUA_login(erabil, kopErabil, username);
		switch (mota) {
			case ADMIN:
				donostikoStocka = MENUA_admin_v2(donostikoStocka);
				break;
			case EROSLE:
				//AURKITU ERABITZAILEAREN POSIZIOA ARRAIAN
				erabilIndex= ERABIL_aurkitu(username, erabil, kopErabil);
				if (erabilIndex > 0) {
					donostikoStocka = MENUA_erabil(donostikoStocka, erabil, kopErabil, erabilIndex);
					//ERABILTZAILEA user;
					//user = erabil[erabilIndex];
					//donostikoStocka = MENUA_erabil(donostikoStocka, &user);
					//donostikoStocka = MENUA_erabil(donostikoStocka, &erabil[erabilIndex]);
	
				}
				break;
			case NONE:
				bukatu = -1;
				break;
			default:
				bukatu = -1;
				break;
		}
	}
	
	
	
	//BUKAERA
	printf("Agur.....\n");
	printf("Sakatu return bukatzeko....");
	aux = getchar();
	return 0;
}


/**************KENDUTAKO KODEA**************

	DISKA_MOTA diskaBerria;

	int i = 0;
	for (i = 0; i < 3; i++) {
		//********************************************************************************
		//1-DISKA bat  SORTU
		diskaBerria = DISKAK_sortubat(); //stocka[zenbat].id = diskaBerria.id;
										//stocka[zenbat] = DISKAK_sortubat();
		//stocka[zenbat] = diskaBerria;

		 zenbat = STOCKA_diskaBatSartu(diskaBerria, stocka, zenbat);
		//********************************************************************************
	}

	DISKAK_bistaratuDanak(stocka, zenbat);




*/