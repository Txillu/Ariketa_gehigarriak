#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

int nire_strcmp(const char* katea1, const char* katea2);

int main() {

	char esaldi1[128];
	char esaldi2[128];

	int egoera = 0;

	printf("Eman bi karaktere kate eta bietatik zein den txikiena esango dizut\n");


	printf("Eman lehenego karatektea:\n");
	fgets(esaldi1, 128, stdin);
	esaldi1[strlen(esaldi1) - 1] = '\0';

	printf("Eman bigarren karatekte katea:\n");
	fgets(esaldi2, 128, stdin);
	esaldi2[strlen(esaldi2) - 1] = '\0';

	egoera=nire_strcmp(esaldi1, esaldi2);

	if (egoera == 0) {
		printf("Bi karaktere kateak berdinak dira.");
	}
	else if (egoera == 1) {
		printf("%s da txikiena", esaldi1);

	}
	else {
		printf("%s da txikiena", esaldi2);
	}

	return 0;
}

int nire_strcmp(const char* katea1, const char* katea2) {

	int egoera = 0,i=0;


	while (*(katea1 + i) == (*(katea2 + i)) && (*(katea1 + i) != '\0')) {

		i++;
	}

	if (*(katea1 + i) < (*(katea2 + i))) {

		egoera = 1;
	}

	else if (*(katea1 + i) > (*(katea2 + i))) {
		egoera = 2;
	}
	else {
		egoera = 0;
	}

	return egoera;
}