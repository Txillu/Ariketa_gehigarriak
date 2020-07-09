#include <stdio.h>
#include <string.h>

#include"a_kopuru.h"

int kontatu() {

	int i = 0, kont=0,tam;
	FILE* fitxa;
	fitxa = fopen("zenbat_A.txt", "r");
	int a;
	if (fitxa > 0) {
		//ondo zabaldu dau
		do {
			a = fgetc(fitxa);
			if (a == 'a'||a=='A') {
				kont++;
			}
		} while (a!=EOF); //----------EOF= END OF FILE-------------
	
	}
	else {
		printf("Errorea %s fitxategia sortzerakoan.\n",
			FITXATEGIA);
	}

	if (fitxa > 0) {
		fclose(fitxa);
	}
	return kont;
}


