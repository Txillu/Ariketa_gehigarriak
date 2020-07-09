#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

typedef struct ertza {

	char erpinaA;
	char erpinaB;
	int pisua;
	struct ertza* ptrHurrengoa;

}ERTZA;

typedef struct egoera {

	char izena;
	struct egoera* ptrHurrengoa;
}EGOERA;


EGOERA* zuhaitza[100];


void ertzaSortu(int*);
void puntuaListanSartu(char v1, char v2, int pisua);
void grafoaEgin();
int zikloaSortzenDu(ERTZA* burua,ERTZA* puntua);
int zikloaDa(ERTZA* puntua);
#endif // !FUNTZIOAK_H
