#define _CRT_SECURE_NO_WARNINGS

#include "orokorrak.h" //MAX_STR

#include "diskak.h" //DISKA_MOTA -> [MAX_STR]

#include "stocka.h" //->DISKA_MOTA

int  STOCKA_diskaBatSartu(DISKA_MOTA diska, DISKA_MOTA stocka[], int zenbat) {
if (zenbat < 10) {
		stocka[zenbat] = diska;
		zenbat++;
	}
	else {
		printf("Ezin da sartu diska stocka (Limitean gauz).\n");
	}
	return zenbat;
}

/*STOC SORTU*/
int STOCKA_sortu(DISKA_MOTA diskak[10]) {
	printf("stocka-sortzen\n");

	diskak[0].id = 1;
	diskak[0].prezioa = 7;
	strcpy(diskak[0].autor, "Robert Johnson");
	diskak[0].estiloa = BLUES;

	diskak[1].id = 2;
	diskak[1].prezioa = 5;
	strcpy(diskak[1].autor, "Jimi Hendrix");
	diskak[1].estiloa = ROCK;

	diskak[2].id = 3;
	diskak[2].prezioa = 8.95;
	strcpy(diskak[2].autor, "Nirvana");
	diskak[2].estiloa = ROCK;

	diskak[3].id = 4;
	diskak[3].prezioa = 10.5;
	strcpy(diskak[3].autor, "Hysteria");
	diskak[3].estiloa = ROCK;


	return 4;
}