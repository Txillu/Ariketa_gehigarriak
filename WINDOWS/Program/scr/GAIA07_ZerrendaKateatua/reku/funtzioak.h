#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define MAX_STR 128

typedef struct {

	int	urtea;
	int hilabetea;
	int eguna;

}DATA;

typedef struct {

	int ordua;
	int minutua;

}ORDUA;

typedef struct ekintza {

	char izena[MAX_STR];
	int kostua;
	DATA eguna;
	ORDUA ordu;
	struct ekintza* hurrengoa;

}EKINTZAK;

EKINTZAK* fitxategiaEskatu(EKINTZAK* burua,int *kop);
EKINTZAK* sartuBesteEkintzBat();
EKINTZAK* berriaListanSartu(EKINTZAK* burua, EKINTZAK* ekintzaBerria);
int kostutotala(EKINTZAK* ekintza);
void fitxategiBerria(EKINTZAK* ekintza);

EKINTZAK* ekintzaSartu(EKINTZAK *ekintza,EKINTZAK*  burua);

#endif // !FUNTZIOAK_H
