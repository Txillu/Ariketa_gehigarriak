#ifndef DISKAK_H
#define DISKAK_H

typedef struct {

	int id;
	char izenburua[128];
	char autore[128];
	int urte;
	char estiloa[128];

}DISKA;

typedef enum {  BAT_IRAKURRI,GORDE };

void menuaErakutsi();

void menuaExekutatu(int aukera, DISKA* diskak, int* diskKop);

void diskaBatIrakurri(DISKA* diska); // Funtzio honek diska baten datuak irakurriko ditu

void diskaGorde(DISKA*  diskak);


#endif