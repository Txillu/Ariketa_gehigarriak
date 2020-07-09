#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define MAX_STR 128

typedef struct  {

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

void fitxategiaEskatu();

#endif // !FUNTZIOAK_H
