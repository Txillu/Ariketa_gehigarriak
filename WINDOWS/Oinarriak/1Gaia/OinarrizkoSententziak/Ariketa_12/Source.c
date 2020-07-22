#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int zenbakiaBueltaEman(int arrunta);

int main() {

	int zenbakia, arrunta;
	char str[128];

	printf("Eman zenbaki arrunt bat:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &arrunta);

	printf("Orain eman beste zenbaki bat:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);

	int i = 0, aurkituta = 0, hondarra = 0, kont = 1;

	int buelta = zenbakiaBueltaEman(arrunta);

	int kopia = buelta;

	while (aurkituta == 0 && kopia > 0) {

		hondarra = kopia % 10;
		kopia = kopia / 10;
		if (hondarra == zenbakia) {
			aurkituta = 1;
			printf("%i zenbakia, zenbaki arruntaren %i posizioan dago", zenbakia, kont);
		}
		kont++;
	}
	if (aurkituta == 0) {
		printf("Ez dago %i zenbakia hasieran emandako zenbaki arruntean.", zenbakia);
	}

	return 0;
}

int zenbakiaBueltaEman(int zenbakia) {

	int hondarra, alderantziz=0;

	while (zenbakia > 0) {

		hondarra = zenbakia % 10;
		zenbakia = zenbakia / 10;
		alderantziz = alderantziz * 10 + hondarra;
	}

	return alderantziz;
}