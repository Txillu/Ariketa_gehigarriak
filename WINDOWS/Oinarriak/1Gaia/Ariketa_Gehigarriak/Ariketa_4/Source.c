#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int kopurua;
	char str[128];

	printf("Eman zenbaki bat eta A pintatuko dizut: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &kopurua);

	for (int i = 0; i < kopurua; i++){
		printf("A ");
	}

	return 0;
}