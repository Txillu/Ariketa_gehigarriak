#include <stdio.h>
#include <string.h>

#include"a_kopuru.h"
#include "abezedarioa.h"
#include "ordenatu.h"

int main() {

	int aukera;
	char str[128];

	printf("Zer egin nahi duzu: 1-testu bateko a kopurua kontatu 2- abezedarioa ikusi 3- zenbakiak ordenatu.\n");
	fgets(str, 128, stdin);
	sscanf(str,"%i", &aukera);

	if (aukera == 1) {
		int zenbat;
		zenbat = kontatu();
		printf("Fitxeroan %i 'a' daude", zenbat);
	}
	else if (aukera == 2) {

		abc();
	}
	else {
		 ordena();

	}

	return 0;
}