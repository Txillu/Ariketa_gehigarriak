#ifndef  GAIXOAK_H
#define GAIXOAK_H

#define MAX_STR 128


#define GAIXOAK "gaixoak.txt"
#define EMAITZA "emaitza.txt"

typedef struct {

	int id;
	int adina;
	char izena[MAX_STR];	
	char abizena[MAX_STR];
	char herria[MAX_STR];
	char egoera;

}GAIXOA;

int gaixoakIrakurri(GAIXOA gaixo[], int kop);
void egoeraIrakurri(GAIXOA gaixo[]);
void positibo(GAIXOA gaixo[],int kop);
void fitxategiPasatu(GAIXOA gaixo[],int zenbat);

#endif 
