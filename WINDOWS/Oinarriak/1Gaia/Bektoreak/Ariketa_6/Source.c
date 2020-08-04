#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int aurretikKonprobatu(int konprobatuBeharrekoa, int bektorea[],int kont);
int atzetikKonprobatu(int konprobatuBeharrekoa, int bektorea[], int hasiera, int amaiera);
int main() {

	int bektorea[128], zenbakia, kont = 0, errepikatuta = 0;
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
	


	
	printf("%i zenbaki daude errepikatuta", errepikatuta);


	return 0;
}

int aurretikKonprobatu(int konprobatuBeharrekoa, int bektorea[],int kont) {

	int i = 0, berdina = 0;;


	while (i < kont && berdina == 0) {

		if (bektorea[i] = konprobatuBeharrekoa) {
			berdina = 1;
		}
		i++;
	}
	return berdina;
}

int atzetikKonprobatu(int konprobatuBeharrekoa, int bektorea[], int hasiera, int amaiera) {

	int i = hasiera, berdina=0;

	while (i < amaiera&&berdina==0) {
		if (bektorea[i] = konprobatuBeharrekoa) {
			berdina = 1;
		}
	}
	return berdina;
}