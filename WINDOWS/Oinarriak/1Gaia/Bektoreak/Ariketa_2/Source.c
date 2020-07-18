#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int  txikienaBilatu(int zenbakiak[], int i);

int main() {

	int bektorea[128], zenbakia, i = 0, batura=0;
	char str[128];

	printf("Eman zenbaki bat lerroko (0 amaitzeko): \n");
	do
	{
		fgets(str, 128, stdin);
		sscanf(str, "%i", &zenbakia);
		if (zenbakia != 0) {
			bektorea[i] = zenbakia;
			i++;
			batura = batura + zenbakia;
		}

	} while (zenbakia != 0);

	float batazbestekoa;
	batazbestekoa= (float)batura / i;
	int kont = 0;

	printf("%f da batazbestekoa\n", batazbestekoa);

	for (int j = 0; j < i; j++) {
		if (bektorea[j] < batazbestekoa) {
			kont++;

		}
	}


	printf("%i zenbaki daude batazbeste baino txikiago direnak\n", kont);
	printf("%i zenbaki batazbeste baino handiago direnak\n", i - kont);

	return 0;
}