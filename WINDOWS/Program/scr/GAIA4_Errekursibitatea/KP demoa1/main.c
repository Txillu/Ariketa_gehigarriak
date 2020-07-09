#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int palindromoaDa(const char* ini);

int main() {

	int egoera = 0;
	char esaldia[128];

	printf("Eman hitz bat eta palindromoa den esango dizut:\n");
	fgets(esaldia, 128, stdin);
	esaldia[strlen(esaldia) - 1] = '\0';

	egoera = palindromoaDa(esaldia);
	

	return 0;
}

int palindromoaDa(const char* ini) {

	int egoera = 0;
	char aux[128];

	strlen(ini);




}