#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {

	int posizioa;
	char str[128];

	printf("Eman zenbaki bat eta fibonacci segidako zenbaki hori esango dizut:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &posizioa);

	int lehena = 0, bigarrena = 1;

	int emaitza = 0,i;

	if (posizioa == 0) {
		printf("%i da %i posizioan dagoen zenbakia.", lehena, posizioa);
	}
	else if (posizioa == 1) {
		printf("%i da %i posizioan dagoen zenbakia.", bigarrena, posizioa);
	}
	else {

		for (i = 0; i < posizioa; i++) {
			emaitza = emaitza + lehena;
			lehena = bigarrena;
			bigarrena = emaitza;
		}

	}
	
	printf("%i da %i posizioan dagoen zenbakia.", emaitza, posizioa);
	return 0;
}