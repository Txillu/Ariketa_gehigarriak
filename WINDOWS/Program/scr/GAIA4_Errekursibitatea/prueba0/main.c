#define _CRT_SUCURE_NO_WARNINGS

#include <stdio.h>

void funtzioa(int zenbat);

int main() {


	funtzioa(5);

	printf("Sakatu return bukatzeko...\n");
	getchar();
	return 0;

}


void funtzioa(int zenbat) {

	if (zenbat == 0) {
		printf("Bukatzen: %i \n", zenbat);
	}
	else {
		printf("EGOERA : %i\n", zenbat);
		funtzioa(zenbat - 1);
		printf("EGOERA : %i\n", zenbat);
	}

}