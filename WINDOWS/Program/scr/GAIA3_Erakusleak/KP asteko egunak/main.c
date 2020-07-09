#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "funtzioak.h"


int main() {

	int eguna;
	char str[128];
	char* asteko_egunak[] = { "Astelehena","Asteartea", "Azteazkena", "Osteguna", "Ostirala", "Larunbata", "Igandea" };
	int egunaGaizki = 1;

	astekoEgunakPantailaratu(asteko_egunak);


	printf("Orain eman nahi duzun egunaren zenbakia:\n");
	
	do
	{
		fgets(str, 128, stdin);
		sscanf(str, "%i", &eguna);
		egunaGaizki = 0;
		if (eguna > 7 || eguna < 1) {
			printf("Ez dago zenbaki hori duen egunik, eman berriz:\n");
			egunaGaizki = 1;
		}
	} while (egunaGaizki==1);

	egunaPaintailaratu(eguna, asteko_egunak);

	return 0;
}
