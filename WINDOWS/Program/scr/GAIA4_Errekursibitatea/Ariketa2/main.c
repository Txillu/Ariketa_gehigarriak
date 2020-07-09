#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void paintailaratu(int zenbat,int kokapena,int  bektorea[]);

int main() {

	int bektorea[] = { 2,6,4,9,3,7,1,5 };
	int zenbat = 8, kokapena = 0;

	paintailaratu(zenbat,kokapena, bektorea);

	return 0;
}

void paintailaratu(int zenbat, int kokapena, int  bektorea[]){

	if (kokapena == zenbat-1) {
		printf("%i ", bektorea[kokapena]);
	}
	else {
		printf("%i ", bektorea[kokapena]);
		paintailaratu(zenbat, kokapena + 1, bektorea);

	}


}