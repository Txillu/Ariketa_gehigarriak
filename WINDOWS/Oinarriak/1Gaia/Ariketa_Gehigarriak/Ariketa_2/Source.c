#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int zenbakia1, zenbakia2,tmp;
	char str[128];

	printf("Eman bi zenbaki eta ordenean erakutsiko dizut: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i %i", &zenbakia1, &zenbakia2);

	if (zenbakia1 > zenbakia2) {
		tmp = zenbakia1;
		zenbakia1 = zenbakia2;
		zenbakia2 = tmp;
	}

	printf("%i %i", zenbakia1, zenbakia2);


	return 0;
}