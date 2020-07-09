/*
	int id;
	float prezioa;
	int stock;
	char izenburua[MAX_STR];
	char autor[MAX_STR];//taldea , solista
	int estiloa;
	char data[MAX_STR];
*/


#ifndef _DISKAK_H
#define _DISKAK_H

#define MAX 10



typedef enum { BLUES, ROCK, JAZZ, POP, ELECTRONICA, SOUL }ESTILOAK;

typedef struct Pertsona {
	int erabili;
	float prezioa;
	int stock;

}PERTSONA;


typedef struct Diska_Mota {
	int id;
	float prezioa;
	int stock;
	char izenburua[MAX_STR];
	char autor[MAX_STR];//taldea , solista
	ESTILOAK estiloa;
	char data[MAX_STR];

}DISKA_MOTA;

void DISKAK_bistaratuDanak(DISKA_MOTA diskak[10], int zenbat);
/*
Sarrera: estiloa mota int lez
Irteera:
Deskripzioa: ESTILOA: Rock
*/
void DISKAK_bistaratuEstiloa(int estiloa);

void DISKA_modifikatu(DISKA_MOTA stocka[], int zenbat, int i);


DISKA_MOTA DISKAK_sortubat();
#endif










