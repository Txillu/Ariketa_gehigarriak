#define _CRT_SECURE_NO_WARNINGS

#define MAX_ZNB 15

#include <stdio.h>;
#include <math.h>
#include "konplexua.h"


int main() {

	int i=0;
	KONPLEXUA zenb;
	float mod;

		printf("--------------%i zenbakia-------------------\n",i);

		zenb = sortuKonplexua();

		bistaratuKonplexua(zenb);

		mod = modulua(zenb);

		printf("Hau da zenbaki konplexuaren moduloa: %f\n\n", mod);

		//----------------------BIGARREN ZATIA-------------------------

		printf("--------------BIGARREN ZATIA-------------------\n");


	KONPLEXUA zenbakiak[MAX_ZNB];

	zenbakiakEskatu(zenbakiak, MAX_ZNB);
	zenbaiakErakutsi(zenbakiak, MAX_ZNB);
	znbModuloaKalk(zenbakiak, MAX_ZNB);

return 0;
}