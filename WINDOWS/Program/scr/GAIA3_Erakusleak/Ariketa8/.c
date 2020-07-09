#define _CRT_SECURE_NO_WARNINGS
#define MAX_ARRAY 100

#include <stdio.h>
#include<string.h>

#include""

int main(int argc, char* argv) {

	PERTSONAK pertsona[MAX_ARRAY];
	int zenbat, aukera = 1,i;
	char str[MAX_ARRAY];

	zenbat = pertsonakSartu(pertsona);


	for (i = 0; i < zenbat; i++) {

		printf("%i", (pertsona+i)->id);
		printf("%s", (pertsona + i)->izena);
		printf("%s", (pertsona + i)->abizena->abizena1);
		printf("%s", (pertsona + i)->abizena->abizena2);
		printf("%i", (pertsona + i)->adina);
		printf("%s", (pertsona + i)->generoa);

		printf("--------------------");

	}


	return 0;
}
