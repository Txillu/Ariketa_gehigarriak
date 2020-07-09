#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

void pantailaratu(int luzera, int kokapena,char esaldia[]);


int main() {

	char esaldia[128];
	int luzera,kokapena=0;

	printf("Eman esaldi bat eta alderantziz pantailaratuko diuzt:\n");
	fgets(esaldia, 128, stdin);
	esaldia[strlen(esaldia) - 1] = '\0';

	luzera = strlen(esaldia);

	pantailaratu(luzera, kokapena, esaldia);

	return 0;
}

void pantailaratu(int luzera, int kokapena, char esaldia[]) {

	if (luzera==kokapena) {
		printf("%c", esaldia[luzera]);
	}
	else {
		printf("%c", esaldia[luzera]);
		pantailaratu(luzera-1, kokapena, esaldia);

	}


}