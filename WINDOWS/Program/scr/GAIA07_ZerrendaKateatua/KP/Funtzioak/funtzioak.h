#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define MAX_STR 128

typedef struct ikaslea {

	char izena[MAX_STR];
	int batazbeste;
	int susKop;
	int matriKop;
	int jarrera;
	int hiruBehera;
	struct ikaslea* hurrengoa;

}IKASLEA;

void ikasleakSartu(IKASLEA** burua);
IKASLEA* ikasleBatSortu();
void pantailaratu(IKASLEA* burua);
void ikasleBatPantaiaratu(IKASLEA aux);
void konpentsazio(IKASLEA*  burua);


#endif // !FUNTZIOAK_H
