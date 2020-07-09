
#ifndef _IRUDIKARIAK_H
#define _IRUDIKARIAK_

#define FITX1_IZENA "irudikariak1.dat"
#define FITX2_IZENA "irudikariak2.dat"

typedef struct {
	int erreala;
	int irudikaria;
}IRUDIKARIA;

void IRUDIKARIAK_idatzi();
void IRUDIKARIAK_irakurri();
void IRUDIKARIAK_idatzi_Testuan();
void IRUDIKARIAK_irakurri_Testuan();

int IRUDIKARIA_fitxategianIdatzi(IRUDIKARIA zenb, FILE* fitx);

#endif