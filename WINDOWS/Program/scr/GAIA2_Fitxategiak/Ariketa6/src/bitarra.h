#ifndef BITARRA_H
#define BITARRA_H

#define FITXA "errealBitarra.dat"
#define FITXAKONPLEXU "konplexuBitarra.dat"

typedef struct Konplexua{
	int erreala;
	int imaginarioa;

}KONPLEXUA;

void bitarraPasatu(float zenbakiak[], int kop);

void konplexuBitarra(KONPLEXUA zenbaki[],int kont);


#endif // !BITARRA_H
