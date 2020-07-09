#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

typedef struct  {

	int lehena;
	int bigarrena;

}NOTAK;

typedef struct ikasle {

	int id;
	char izena[128];
	char sexua[128];
	NOTAK nota;

}IKASLE;

typedef struct nodoa {

	IKASLE* ikasleak;
	struct nodoa* hurrengoa;

}NODOA;

void menua();
IKASLE* ikasleaSortu();
NODOA* ikasleaSartu(NODOA* nodoa,IKASLE ikasle);


#endif // !FUNTZIOAK_H
