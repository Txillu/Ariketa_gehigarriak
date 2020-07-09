#ifndef KONPLEXUA_H
#define KONPLEXUA_H

#define MAX_ZNB 15

typedef struct KONPLEXUA {

	int erreala;
	int imaginarioa;

}KONPLEXUA;

KONPLEXUA sortuKonplexua();
void bistaratuKonplexua(KONPLEXUA zenb);
float modulua(KONPLEXUA zenb);

void zenbakiakEskatu(KONPLEXUA zenb[], int kop);
void zenbaiakErakutsi(KONPLEXUA zenb[], int kop);
void znbModuloaKalk(KONPLEXUA zenb[], int kop);


#endif
