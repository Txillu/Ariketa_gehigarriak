#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"funtzioak.h"



int pertsonakSartu(PERTSONAK pertsona[]) {

	int zenbat = 0,i;
	char str[128];

	printf("Eman pertsonaren ID-a:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", pertsona[i].id);



	return zenbat;
}
