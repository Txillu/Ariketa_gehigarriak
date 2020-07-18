#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int bilatuTartean(int bektorea[], int kont, int zenbakia);

int main() {

	int bektorea[128], zenbakia,kont=0;
	char str[128];
	int errepikatuta = 0;

	printf("Eman zenbaki bat lerroko (0 amaitzeko): \n");
	do
	{
		fgets(str, 128, stdin);
		sscanf(str, "%i", &zenbakia);
		if (zenbakia != 0) {
			errepikatuta = bilatuTartean(bektorea, kont,zenbakia);
			if (errepikatuta == 0) {

				bektorea[kont] = zenbakia;

			}
			else {
				kont--;
			}
			kont++;
		}

	} while (zenbakia != 0);


	for (int i = 0; i < kont; i++) {
		printf("%i ", bektorea[i]);

	}


	return 0;
}

int bilatuTartean(int bektorea[], int kont,int zenbakia) {
	int i = 0;
	int berdina = 0;
	while (berdina == 0 && i < kont) {

		if (bektorea[i] == zenbakia) {
			berdina = 1;
		}
		i++;
	}
	return berdina;
}