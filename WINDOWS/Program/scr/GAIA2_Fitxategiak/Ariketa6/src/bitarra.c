#include<stdio.h>
#include<string.h>

#include"bitarra.h"

void bitarraPasatu(float zenbakiak[],int kop) {

	FILE* bitarra;
	bitarra = fopen(FITXA,
		"wb");
	int egoera = 0;

	if (bitarra > 0) {
		egoera = fwrite(zenbakiak, sizeof(float), kop, bitarra);
		printf("Egina.");
	}
	else {
		printf("Errorea %s fitxategia sortzerakoan.\n",
			FITXA);
	}
	if (bitarra > 0) {
		fclose(bitarra);
	}
}

void konplexuBitarra(KONPLEXUA zenbaki[], int kont) {

	FILE* konBitarra;
	int egoera;
	konBitarra = fopen(FITXAKONPLEXU,
		"wb");

	if (konBitarra > 0) {
		egoera = fwrite(zenbaki, sizeof(KONPLEXUA), kont-1, konBitarra);
		printf("Egina.");
	}
	else {
		printf("Errorea %s fitxategia sortzerakoan.\n",
			FITXA);
	}
	if (konBitarra > 0) {
		fclose(konBitarra);
	}
}
