#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<math.h>
#include "funtzioak.h"


int main() {


	KONPLEXUA zenbakia;
	char str[128];
	char zeinua = '+';
	float modulua;
	int emaitza;

	printf("Eman zenbaki konplexuaren zati erreala:\n");
	fgets(str, 128,stdin);
	sscanf(str, "%f", &zenbakia.reala);

	printf("Eman zenbaki konplexuaren zati irudikaria:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &zenbakia.irudikaria);

	if (zenbakia.irudikaria < 0) {
		zeinua = '-';
	}
	
	modulua= kalkulatuModulua(zenbakia);

	emaitza=alderantzizkoaKalkulatu(modulua);

	printf("%i", emaitza);



	return 0;
}
