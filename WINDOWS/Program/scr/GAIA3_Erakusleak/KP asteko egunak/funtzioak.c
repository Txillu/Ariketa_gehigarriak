#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "funtzioak.h"



void astekoEgunakPantailaratu(char* asteko_egunak[]) {

	int i;

	printf("Honek dira asteko egunak");
	printf("\n\n");

	for (i = 0; i < 7; i++) {
		printf("%s ", (*(asteko_egunak + i)));

	}

	printf("\n\n");

}

void egunaPaintailaratu(int eguna, char* asteko_egunak[]) {

	int i = 0, aurkituta = 0;
	char aukera[128];

	while (i < 7 && aurkituta == 0) {

		if (i == eguna) {

			strcpy(aukera, *(asteko_egunak + i-1));
			aurkituta = 1;
		}
		i++;
	}

	printf("Hau da aukeratu duzun eguna: %s", aukera);

}
