#ifndef FUTZIOAK_H
#define FUTZIOAK_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct ertza {

	int erpinaA;
	int erpinaB;
	int pisua;
	struct ertza* ptrHurrengoa;

}ERTZA;


typedef struct egoera {

	int izena;
	struct egoera* ptrHurrengoa;
}EGOERA;

ERTZA* ertzaSortu(ERTZA* HasierakoGrafoa);
void puntuaListanSartu(char v1, char v2, int pisua, ERTZA* HasierakoGrafoa);
void IbilbideMinimoarenZuhaitzaSortu(ERTZA* HasierakoGrafoa,EGOERA* zuhaitza[], int egoeraZenb);
void kruskal(ERTZA* HasierakoGrafoa,EGOERA* zuhaitza[], ERTZA* KruskalGrafoa,int egoeraZenb);
ERTZA* pisuTxikiena();
void biPuntuenIndizea(int erpinaA, int erpinaB, int i1, int i2, int egoeraZenb, EGOERA* zuhaitza[]);
void IbilbideMinimoarenZuhaitzetikKendu(int i1, int i2, EGOERA* zuhaitza[]);
ERTZA* kruskalGrafoaEgin(int erpinaA, int erpinaB, int pisua, ERTZA* KruskalGrafoa);
ERTZA* puntuaHasieratikKendu(ERTZA* puntua, ERTZA* HasierakoGrafoa);



#endif

