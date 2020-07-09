#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "funtzioak.h"


void fitxategiaEskatu() {

	FILE* fitx;
	char str[MAX_STR];

	printf("Zer fitxategi ireki nahi duzu: ");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';

	fitx = fopen("bidaia.txt", "r");
	if (fitx > 0) {

		printf("ondo");

	}
	else{
		printf("Errorea fitxategia irakurtzerakoan.");

	}
}