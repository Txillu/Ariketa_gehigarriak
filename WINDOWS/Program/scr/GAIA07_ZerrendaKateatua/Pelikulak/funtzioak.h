#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define MAX_KAR 120

typedef struct Pelikula {
	int id;
	char izenburua[MAX_KAR];
	int alokatua;
}PELIKULA;
//c
typedef struct Nodo_Pelikula{
	PELIKULA* pelikula; //edukia
	struct Nodo_Pelikula* ptrHurrengoa;
}NODO_PELIKULA,*PNODO_PELIKULA;


/* A ETA b
typedef struct Nodo_Pelikula {
	int id;
	char izenburua[MAX_KAR];
	int alokatua;
	struct Nodo_Pelikula* ptrHurrengoa;
}NODO_PELIKULA, *PNODO_PELIKULA;

*/


PELIKULA* sortuPelikulaBat();//malloc,pelikula heap-ean sortzen dau
void sartuPelikulaBuruan(NODO_PELIKULA ** ppBurua, PELIKULA*  ptrPelikula);
void sartuPelikulakZerrendan(NODO_PELIKULA ** ppBurua);
void bistaratuPelikulak(NODO_PELIKULA* burua);
void bistaratuPelikulaBat(PELIKULA pel);
int pelikulaBatAlokatu(NODO_PELIKULA* pBurua, char str[], NODO_PELIKULA** ppEstilokoak);
int pelikulaBatBueltatu( char str[], NODO_PELIKULA** ppEstilokoak);
void hustuZerrenda(PNODO_PELIKULA* ppBurua, int edukia);


int pelikulenMenua();
char menua();
void aukeraExekutatu(char aukera, NODO_PELIKULA ** ppBurua, NODO_PELIKULA** estilokoak);
#endif
