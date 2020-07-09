#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


main(){


	FILE* tamaina;

	int zenbakiak[128], tmp = 0, kont = 0, i = 0, j = 0, zki = 0;
	char fitx_izena[128], txt[5] = ".txt";

	printf("Sartu fitxategiaren izena: ");
	fgets(fitx_izena, 128, stdin);
	fitx_izena[strlen(fitx_izena) - 1] = '\0';

	char* ps = fitx_izena;
	char* pd = fitx_izena + strlen(fitx_izena);
	strcpy(pd, txt);

	tamaina = fopen(fitx_izena, "r");

	if (tamaina == NULL) {
		printf("Ezin da %s fitxategia ireki\n", fitx_izena);
	}
	else {
		
		fseek(tamaina, 0, SEEK_END);
		printf("%s fitxategiak %d bytes okupatzen du", fitx_izena,ftell(tamaina));
		fclose(tamaina);
	}


    return 0;
}