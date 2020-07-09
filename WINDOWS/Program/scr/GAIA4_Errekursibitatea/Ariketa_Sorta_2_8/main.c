#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void ordenatu(int bektorea[], int tam,int max);

int main() {

	int bektorea[] = {1,9,4,3,6,10,7,5,2,8};
	char str[128];
	int tam = 10,max=0;

	ordenatu(bektorea, tam,max);

	for (int i = 0; i < 10; i++) {

		printf("%i ", bektorea[i]);
	}
	return 0;
}

void ordenatu(int bektorea[], int tam,int max) {

	if (tam <= 1) {
		return bektorea[tam];
	}
	else {
		max = bektorea[tam - 1];

		for (int i = tam-1; i >= 0; i--) {
			if (bektorea[i] > max) {
				max = bektorea[i];
				bektorea[i] = bektorea[tam-1];
				bektorea[tam-1] = max;

			}
		}
		ordenatu(bektorea, tam - 1, max);
	}

}
