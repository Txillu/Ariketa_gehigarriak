#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fitx1, * fitx2, * fitxBukaera;
	char c;
	char fitx1Izena[200], fitx2Izena[200], fitxIrteera[200];
	printf("Eman lehenengo fitxategiaren izena: ");
	scanf("%s", &fitx1Izena);
	printf("Eman bigarren fitxategiaren izena: ");
	scanf("%s", &fitx2Izena);
	printf("Eman fitxategi berriaren izena");
	scanf("%s", &fitxIrteera);

	fitx1 = fopen(fitx1Izena, "r+");
	fitx2 = fopen(fitx2Izena, "r+");
	fitxBukaera = fopen(fitxIrteera, "w");
	if (fitx1 > 0 && fitx2 > 0 && fitxBukaera > 0) {
		while (!feof(fitx1))
		{
			fscanf(fitx1, "%c", &c);
			fprintf(fitxBukaera, "%c", c);
		}
		fprintf(fitxBukaera, "\n");
		fclose(fitx1);
		while (!feof(fitx2))
		{
			fscanf(fitx2, "%c", &c);
			fprintf(fitxBukaera, "%c", c);
		}
		fclose(fitx2);
		fclose(fitxBukaera);
	}
	else {
		printf("Errore bat fitxategiarekin");
	}
	
	return 0;
}