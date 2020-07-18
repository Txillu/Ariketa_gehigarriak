#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int  txikienaBilatu(int zenbakiak[],int i);

int main() {

	int zenbakiak[128],zenbakia,i=0;
	char str[128];

	printf("Eman zenbaki bat lerroko (0 amaitzeko): \n");
	do
	{
		fgets(str, 128, stdin);
		sscanf(str, "%i", &zenbakia);
		if (zenbakia != 0) {
			zenbakiak[i] = zenbakia;
			i++;
		}

	} while (zenbakia!=0);

	int txikienaPos = txikienaBilatu(zenbakiak,i);

	int tmp;

	tmp = zenbakiak[0];

	zenbakiak[0] = zenbakiak[txikienaPos];
	zenbakiak[txikienaPos] = tmp;

	for (int j = 0; j < i; j++) {
		printf("%i ", zenbakiak[j]);
	}

	return 0;
}

int  txikienaBilatu(int zenbakiak[],int kont) {

	int i = 0, txikiena = zenbakiak[i];
	int pos=0;
	for (int j = 0; j < kont; j++) {
		if (zenbakiak[j] < txikiena) {
			txikiena = zenbakiak[j];
			pos = j;
		}
	}
	return pos;
}