#ifndef BEZEROAK_H
#define BEZEROAK_H

#define MAX_BEZERO 100
#define MAX_SALMENTA_INFO 15

typedef enum { IRTEN, BEZERO_SORTU, BEZERO_GUZTIAK_PANTAILARATU, EROSKETA_KUDEATU, HILEKO_DIRUSARRERA, FITXATEGIAN_GORDE,FITXATEGI_KARGATU, IRABAZIA,FAKTURA};

typedef struct informazioa {
	int eguna;
	int hilabete;
	int urte;
	float dirua;
} INFORMAZIOA;

typedef struct bezeroak {

	int id;
	char izena[128];
	char abizena[128];
	int adina;
	INFORMAZIOA erosi_informazio[MAX_SALMENTA_INFO];
	int kop;
} BEZEROAK;

void menua_erakutsi();
int menua_exelutatu(int aukera, BEZEROAK bezero[], int zenbat);
int bezero_sortu(BEZEROAK bezero[], int zenbat);
void bezeroak_pantailaratu(BEZEROAK bezero[],int zenbat);
int erosketa_kudeatu(BEZEROAK bezero[], int zenbat);
BEZEROAK erosle_erosketa_egin(BEZEROAK bezero);
void gorde(BEZEROAK bezero[], int zenbat);
int kargartu(BEZEROAK bezero[], int zenbat);
int kalkulatuIrabazi(BEZEROAK bezero[], int zenbat);
void faktura(BEZEROAK bezero[],int zenbat);


#endif 
