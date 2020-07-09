#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int paintailaratu(int zenbat, int kokapena, int  bektorea[]);

int main() {

	int bektorea[] = { 1,2,3,4,5,6 };
	int zenbat = 6, kokapena = 0;

	int emaitza;
		emaitza=paintailaratu(zenbat, kokapena, bektorea);


	printf("%i", emaitza);

	return 0;
}

int paintailaratu(int zenbat, int kokapena, int  bektorea[]) {

	int emaitza;

	if ( kokapena==zenbat-1) {
		emaitza = bektorea[kokapena];
	}
	else {
		
		emaitza= bektorea[kokapena] + paintailaratu(zenbat, kokapena+1, bektorea);
	}

	return emaitza;
}