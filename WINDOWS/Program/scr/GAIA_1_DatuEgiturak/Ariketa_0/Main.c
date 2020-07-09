#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
#include"Stocka.h"
#include "menua_admin.h"
#include"menua_erabil.h"
#include "Erabiltzaileak.h"

/*
	PROGRAMA HAU EZ DAGO GUZTIZ BUKATUTA, HAU DA, BAI ADMIN BAI EROSLE MENUAN STOCKA BISTARATZEKO ORDUAN DENAK BISTARATZEN DITUT, EZ DITUT BESTE SUB-BLOKEETAN
	BANATU,
	
*/

int main() {
	int zenbat = 0;
	char aux = 0;

	ERABILTZAILEA erabiltzailea;

	DISKA_MOTA stocka[10];
	DISKA_MOTA carrito[10];

	printf("---------DISKA DENDA---------\n");
	//PROGRANA
	printf("Zure identifikazioa:\n");
	printf("Izena:");
	fgets(erabiltzailea.izena, 128, stdin);
	erabiltzailea.izena[strlen(erabiltzailea.izena) - 1] = '\0';

	printf("Pasahitza:");
	fgets(erabiltzailea.password, 128, stdin);
	erabiltzailea.password[strlen(erabiltzailea.password) - 1] = '\0';
	
	int mota;
	mota = ERABILTZAILE_MotaKonprobatu(erabiltzailea);

	if (mota == 1) {

		printf("\n\n");
		printf("Honek dira stockean dauden diskak:\n");
		//0. stock - a sortu(diskak)
		zenbat = STOCKA_sortu(stocka);

		DISKAK_bistaratuDanak(stocka, zenbat);

		zenbat = MENUA_admin(stocka, zenbat);
	
	}

	else if (mota==2){
		printf("\n\n");

		printf("Honek dira stockean dauden diskak:\n");
		zenbat = STOCKA_sortu(stocka);
		DISKAK_bistaratuDanak(stocka, zenbat);
		int kop = 0;
		MENUA_erabil(carrito,stocka, zenbat,kop);
	}

	else {

		printf("Pasahitza edo izen gaizki dago, sahiatu berriro.\n");
		
	}
	

	/***** ADMIN MENUA (CRUD, Create Read, Update, delete)

			- Diska berri bat gehitu stocka (CREATE)
			- Diska bat kendu stocketik (DELETE)
			- Diska bat modifikati (UPDATE)
			- Bistaratu
				- Estiloka
				- Autoreka
				- Zigilua
				- Datak erabiliz
			- Irten

	*****/
	//LOGIN
	//IF  eroslea
		//MENUA EROSLEA
	//IF ADMIN
		//MENUA ADMIN
		//Sarrera: stcka, zenbat
		//Irteera: zenbat stoxka


	//BUKAERA
	printf("Sakatu return bukatzeko....");
	aux = getchar();
	return 0;
}
