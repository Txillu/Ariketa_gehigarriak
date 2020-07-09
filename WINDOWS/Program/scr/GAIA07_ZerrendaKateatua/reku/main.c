#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "funtzioak.h"

int main() {

	EKINTZAK* ekintza = NULL;
	int jarraitu = 0;
	char str[MAX_STR];
	EKINTZAK* ekintzaBerria = NULL;

		int kop = 0;

	ekintza=fitxategiaEskatu(ekintza,&kop);

	if (ekintza!=NULL) {
		do {

			printf("Ekintza gehiago? (1-bai 0-ez)");
			fgets(str, 128, stdin);
			sscanf(str, "%i", &jarraitu);
			if (jarraitu == 1) {
				ekintzaBerria = sartuBesteEkintzBat();
				ekintza = berriaListanSartu(ekintza, ekintzaBerria);
				kop++;
			}

		} while (jarraitu == 1);

		int kostuTotala;
		kostuTotala = kostutotala(ekintza);
		printf("%i da ekintzen kostu totala\n", kostuTotala);

		int kostuBB;
		kostuBB = kostuTotala / kop;
		printf("%i da ekintzen natazbesteko kostua\n", kostuBB);

		fitxategiBerria(ekintza);

	}

	printf("Jo edozein tekla bukatzeko.\n");
	getchar();
	return 0;
}