#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

typedef struct {

	char abizena1[128];
	char abizena2[128];


}ABIZENAK;


typedef struct {

	int id;
	char izena[128];
	ABIZENAK abizena[128];

}PERTSONAK;

int pertsonakSartu(PERTSONAK pertsona[]);
#endif // !FUNTZIOAK_H
