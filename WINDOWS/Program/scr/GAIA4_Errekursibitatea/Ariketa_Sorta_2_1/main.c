#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int pantailaratu(int bektore[],int tam);

int main() {

	int bektore[] = { 1,5,45,32,9,45,61,0,75,55,10,64,2,3,52 };
	int tam = 15, max;
	char str[128];

	max= pantailaratu(bektore, tam);

	printf("%i da balio handiena", max);

	return 0;
}

int pantailaratu(int bektore[], int tam) {
	int max;

	if (tam <= 1) {
		return bektore[tam];
	}
	else {
		max = pantailaratu(bektore, tam - 1);

		if (max < bektore[tam]) {
			max = bektore[tam];
		}

	}

	return max;
}