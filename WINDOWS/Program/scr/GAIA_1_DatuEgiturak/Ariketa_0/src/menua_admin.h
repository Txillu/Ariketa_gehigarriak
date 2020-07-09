#ifndef MENUA_ADMIN_H
#define MENUA_ADMIN_H

typedef enum { IRTEN ,SORTU_DISKA, EZABATU_DISKA, MODIFIKATU_DISKA, BISTARATU_DISKA }ADMIN_AUKERA;


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

int MENUA_admin(DISKA_MOTA stocka[], int zenbat);
int MENUA_ADMIN_exekutatu(int aukera, DISKA_MOTA stocka[], int zenbat);

int MENUA_sartuDiska(DISKA_MOTA stocka[],int zenbat,int sartu);
int MENUA_ezabatuDiska(DISKA_MOTA stocka[], int zenbat);
int MENUA_modifikatuDiska(DISKA_MOTA stocka[], int zenbat);
void MENUA_bistaratuDiska(DISKA_MOTA stocka[], int zenbat);

#endif // !MENUA_ADMIN_H
