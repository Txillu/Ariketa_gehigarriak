#ifndef IKASLEAK_H
#define IKASLEAK_H

#define MAX_IKAS 30

#define IKASLEA_BATEN_NOTA "ikasleBat.txt"
#define IKASLE_GUZTIEN_NOTA "ikasleGuztiak.txt"
#define IKASLE_IRAKURRI "ikasleIrakurri.txt"

/*
	============================================
	Menu
	============================================
	1. Gehitu ikasle baten notak
	2. Borratu ikasle baten notak
	3. Eguneratu ikasle baten notak
	4. Bistaratu ikasle guztien notak
	5. Kalkulatu aukeratutako ikasleen noten batazbestekoa
	6. Bistaratu bukaerako nota finalik altuena duen ikaslearen informazioa
	7. Bistaratu bukaerako nota finalik baxuena duen ikaslearen informazioa
	8. ID bidez ikasle bat bilatu
	9. Informazioa nota finalaren arabera ordenaturik bistaratu
	Sartu aukera bat:
	Oharra: Ikasle guztien datuak egituraz osatutako array batean goredeko
	dira.
	*/


typedef enum {GEHITU_NOTA=1, BORRATU_NOTA, EGUNERATU_NOTA, BISTARATU_DANAK,BATAZBESTE_IKASLE_BAT, NOTA_ALTU_IKASLE, NOTA_BAXU_IKASLE, BILATU_IKASLE,BISTARATU_FINALA,IKASLEA_BAT_FITXATEGI,IKASLE_GUZTIAK_FITXATEGI,IRAKURRI_FIXTATEGI } MENUA;

typedef struct nota {
	float exam1;
	float exam2;
}NOTA;

typedef struct notapartzi {
	NOTA otsaila;
	NOTA ekaina;
}NOTAPARTZI;

typedef struct Ikasle {
	int id;
	char izena[30];
	char genero[10];
	NOTAPARTZI partziNota;
	float final;
}IKASLE;


void MENUA_erakutsi();
int MENUA_exekutatu(int aukera, IKASLE ikasleak[MAX_IKAS], int zenbat);
int ikasle_notaGehitu(IKASLE ikasleak[MAX_IKAS],int zenbat); // IKASLEAK SORTU ETA NOTAK JARRIKO DIO
void ikasle_notaKendu(IKASLE ikasleak[MAX_IKAS],int zenbat); // IKASLEAREN NOTAK KENDUKO DU =0 EGINEZ
void ikasle_notaEguneratu(IKASLE ikasleak[MAX_IKAS],int zenbat); // NOTEN DATU BERRIA ESKATUKO DU
void bistaratu_guztiak(IKASLE ikasleak[MAX_IKAS],int zenbat); // IKASLE GUZTIEN NOTAK
void ikasle_batazbeste(IKASLE ikasleak[MAX_IKAS],int zenbat); // NAHI DEN IKASLEAREN OTSAILEKO ETA EKAINEKO NOTA PARTZIALA ETA FINALA
void ikasle_notaAltuInfo(IKASLE ikasleak[MAX_IKAS],int zenbat); // NOTA FINALIK ALTUENAREN INFORMAZIOA (IZENA, ID, GENEROA, OTSAILEKO NOTA , EKAINEKO NOTA ETA FINALA)
void ikasle_notaBaxuInfo(IKASLE ikasleak[MAX_IKAS], int zenbat);// NOTA FINALIK BAXUENAREN INFORMAZIOA (IZENA, ID, GENEROA, OTSAILEKO NOTA , EKAINEKO NOTA ETA FINALA)
void bilatu(IKASLE ikasleak[MAX_IKAS], int zenbat); // NAHI DE IKASLEAREN INFORMAZIOA ERAKUTSIKO DU ID-REN BIDEZ.
void bistaratu_final(IKASLE ikasleak[MAX_IKAS], int zenbat); // NOTA FINALA ORDENEAN ERAKUTSIKO DU 
void ordenatuHandiTxiki(IKASLE ikasleak[], int zenbat);// FINALA HANDITIK TXIKIRA
void ordenatuTxikiHandi(IKASLE ikasleak[], int zenbat);// FINALA TXIKITIK HANDIRA

void fitxategi_ikasle(IKASLE ikasleak[], int zenbat);
void fitxategi_ikasle_guztiak(IKASLE ikasleak[], int zenbat);
void fitxategi_ikasle_irakurri(IKASLE ikasleak[], int zenbat);


#endif // !IKASLEAK_H
