#ifndef DISKAK_H
#define DISKAK_H

typedef struct {

	int id;
	char izenburua[128];
	char taldea[128];
	float prezioa;

}DISKA;

typedef enum { DANAK_IRAKURRI=1,BAT_IRAKURRI,AURKIUT,MODIFIKATU};

void menuaErakutsi();

void menuaExekutatu(int aukera, DISKA* diskak, int* diskKop);

void diskakSortu(DISKA *diskak);

void diskaDanakIrakurri(DISKA* diskak, int* diskKop);

void diskaBatIrakurri(DISKA* diska); // Funtzio honek diska baten datuak irakurriko ditu

int diskaBatAurkitu(DISKA* diskak, int diskKop, char* izenburua);

void diskaBatModifikatu(DISKA* diska);

#endif