#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>;
#include <math.h>

#include "konplexua.h";

KONPLEXUA sortuKonplexua() {

	KONPLEXUA zenbakia;
	char str[128];
	printf("Eman zenbaki konplexuaren zati erreala:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia.erreala);

	printf("Orain eman zenbakiaren zati imaginarioa:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia.imaginarioa);



	return zenbakia;
}

void bistaratuKonplexua(KONPLEXUA zenb) {

	printf("Hau da sartu duzun zenbakia: %i + %i j\n", zenb.erreala, zenb.imaginarioa);

}
float modulua(KONPLEXUA zenb) {

	float modulo = 0;

	modulo = sqrt(zenb.erreala * zenb.erreala + zenb.imaginarioa * zenb.imaginarioa);

	return modulo;
}

void zenbakiakEskatu(KONPLEXUA zenb[], int kop) {

	int i = 0;

	for (i = 0; i < kop; i++) {

		printf("Eman %i. zenbakia\n", i);

		zenb[i] = sortuKonplexua();

	}

}

void zenbaiakErakutsi(KONPLEXUA zenb[], int kop) {

	int i;

	for (i = 0; i < kop; i++) {
		printf("Hau da %i zenbaki konplexua\n", i);
		bistaratuKonplexua(zenb[i]);
	}

}

void znbModuloaKalk(KONPLEXUA zenb[], int kop) {

	int i;
	float mod;

	for (i = 0; i < kop; i++) {

		mod = modulua(zenb[i]);


		printf("Hau da %i zenbaki konplexuaren moduloa: %f\n\n", i, mod);

	}

}
