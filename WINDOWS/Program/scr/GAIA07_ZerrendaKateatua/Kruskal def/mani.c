#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "funtzioak.h"


int main() {

	int i = 0;
	int ertzKop;
	int erpinKop;
	char str[128];
	char letra = 'A';

	printf("Kruskal prueba");

	printf("Eman erpin kopurua: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &erpinKop);

	ertzaSortu(&ertzKop);


	do
	{
		grafoaEgin();
		i++;
	} while (i<erpinKop-1);

	getchar();
}