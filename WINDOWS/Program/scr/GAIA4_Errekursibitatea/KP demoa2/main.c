#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int  nirestrlen(const char*);

int main() {

	int luzera = 0;
	char esaldia[128];

	printf("Eman hitz bat eta bere luzera esango dizut:\n");
	fgets(esaldia, 128, stdin);

	luzera = nirestrlen(esaldia);

	printf("%i da luzera", luzera);

	return 0;
}

int nirestrlen(const char* esaldia) {

	int luzera;

	if (*(esaldia)=='\0') {

		return 0;
	}
	else {
		
		luzera= 1+ nirestrlen(esaldia + 1);

	}
	return luzera;

}