
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<math.h>
#include "funtzioak.h"



float	kalkulatuModulua(KONPLEXUA zenbakia) {

	float mod;

	mod = sqrt((zenbakia.reala * zenbakia.reala) + (zenbakia.irudikaria * zenbakia.irudikaria));

	return mod;
}

float alderantzizkoaKalkulatu(float modulua) {

	int emaitza;
	float alderantzizkoa;

	if (modulua <= 0) {
		printf("Ezin da alderatzizkoa kalkulatu\n");

		emaitza = -1;
	}
	else {

		alderantzizkoa = 1 / modulua;
		printf("hau da aldearntzizkoa: %f\n", alderantzizkoa);
		emaitza = 0;

	}

	return emaitza;
}