#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int bektorea[128], zenbakia, kont = 0;
	char str[128];


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

	int j = 0, i = 0,tmp;

	for (i = 0; i < kont; i++) {
		for (j = i; j < kont; j++) {
			if (bektorea[i] > bektorea[j]) {
				tmp = bektorea[j];
				bektorea[j] = bektorea[i];
				bektorea[i] = tmp;
			}
		}

	}
	int kop = 1,berdina,i=0;
	berdina = bektorea[i];
	for (i = 0; i < kont; i++) {
		if (berdina = bektorea[i]){
			kop++;
		}

	}



	return 0;
}
