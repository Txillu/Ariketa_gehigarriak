#include <stdio.h>
#include <string.h>

#include"ordenatu.h"

void ordena() {

	FILE* orden;
	int i = 0;
	int zenbakiak[MAX_NUMBER];
	
	int j = 0, aux,kont=0;

	int zenbaki;

	char str[128];
	orden = fopen("ordena.txt", "r");
	if (orden > 0) {
		//FITXATEGIAN DAGOEN ZENBAKIAK ARRAYAN SARTU
	
		while (!feof(orden)) {//Zenbakiak array batera pasatu
			zenbakiak[i] = 0;
			fscanf(orden, "%i", &zenbaki);
			zenbakiak[i] = zenbaki;
			i++;
			kont++;
		}
		printf("Honek dira fitxategiko zenbakiak:\n");
		for (i = 0; i < kont; i++) {
			printf("%i ", zenbakiak[i]);
		}

		while (i != (kont - 1)) { //-------------Zenbakiak ordenatu---------------
			i = 0;
			for (j = 0; j < (kont - 1); j++) {
				if (zenbakiak[j] <= zenbakiak[j + 1]) {
					i++;
				}
				else {
					aux = zenbakiak[j];
					zenbakiak[j] = zenbakiak[j + 1];
					zenbakiak[j + 1] = aux;
				}
			}
		}

		printf("\nFitxategiko zenbakiak ordenaturik:\n");
		for (i = 0; i < kont; i++) {
			printf("%i ", zenbakiak[i]);
		}

		//----------ORDENATURIKO ZENBAKIAK FITXATEGIRA PASATZEN----------

		orden = fopen("ordena.txt", "w");
		for (i = 0; i < kont; i++) {
			fprintf(orden, "%d\n", zenbakiak[i]);
		}
	}
	else {

		printf("Errorea %s fitxategia sortzerakoan.\n",
			FITXATEGIA);
	}

	if (orden > 0) {
		fclose(orden);
	}

}