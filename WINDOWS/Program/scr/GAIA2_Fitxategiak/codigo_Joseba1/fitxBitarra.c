#include <stdio.h>
#include  "orokorrak.h"
#include "fitxBitarra.h"

void FITX_BITARRA_adibidea() {
		int zenb = 0;
		FILE* fitx_erakuslea;
		fitx_erakuslea = fopen(FILE_IZENA_BITARRA,
			"wb");

		printf("*********%i ZENBAKI FITXATEGI BATEN ERA BITARREAN GORDETZEN********\n", MAX_NUMBER);

		if (fitx_erakuslea > 0) {
			for (zenb = 0; zenb < MAX_NUMBER; zenb++) {
				fwrite(&zenb, sizeof(int), 1 ,fitx_erakuslea);
			}
		}
		else {
			printf("Errorea %s fitxategia sortzerakoan.\n",
				FILE_IZENA_BITARRA);
		}

		if (fitx_erakuslea > 0) {
			fclose(fitx_erakuslea);
		}
}