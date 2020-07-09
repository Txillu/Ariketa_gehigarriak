#ifndef PERTSONAK_H
#define PERTSONAK_H

#define MAX_STR 128


typedef struct {

	char abizena1[MAX_STR];
	char abizena2[MAX_STR];


}ABIZENAK;


typedef struct {

	int id;
	char izena[MAX_STR];
	ABIZENAK abizena[MAX_STR];
	int adina;
	char generoa[MAX_STR];

}PERTSONAK;

int  pertsonakSartu(PERTSONAK pertsona[]);
void pertsonaBatSartu(PERTSONAK *pertsona);
int  aukeraMenu();
void ordenatu(PERTSONAK pertsona[],int zenbat);
void pertsonakPantailaratu(PERTSONAK pertsona[], int zenbat);

#endif // !PERTSINAK_H
