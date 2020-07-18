#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int bektorea[128], zenbakia, kont = 0;
	char str[128];
	int errepikatuta = 0;

	printf("Eman zenbaki bat lerroko (0 amaitzeko): \n");
	do
	{
		fgets(str, 128, stdin);
		sscanf(str, "%i", &zenbakia);
		if (zenbakia != 0) {

			bektorea[kont] = zenbakia;
			kont++;
		}

	} while (zenbakia != 0);

	errepikatuta = bilatuTartean();




	for (int i = 0; i < kont; i++) {
		printf("%i ", bektorea[i]);

	}


	return 0;
}
