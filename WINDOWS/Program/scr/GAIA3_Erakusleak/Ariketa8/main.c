#define _CRT_SECURE_NO_WARNINGS
#define MAX_ARRAY 10

#include <stdio.h>
#include<string.h>

#include"pertsonak.h"

int main() {

	PERTSONAK pertsona[MAX_ARRAY];
	int zenbat, aukera = 1,i;
	char str[MAX_ARRAY];


	zenbat = pertsonakSartu(pertsona);

	ordenatu(pertsona,zenbat);

	pertsonakPantailaratu(pertsona, zenbat);

	

	return 0;
}
