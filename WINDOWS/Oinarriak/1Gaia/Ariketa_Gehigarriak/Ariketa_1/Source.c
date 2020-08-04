#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int zenbakia1, zenbakia2;
	char str[128];

	printf("Eman bi zenbaki eta handiena erakutsiko dizut: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i %i", &zenbakia1, &zenbakia2);

	if (zenbakia1 < zenbakia2) {
		printf("%i da handiena", zenbakia2);
	}

	else if (zenbakia1 > zenbakia2) {
		printf("%i da handiena", zenbakia1);
	}

	else {
		printf("Bi zenbakiak berdinak dira.");
	}


	return 0;
}