#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int zenbakia1, zenbakia2, zenbakia3;
	char str[128];

	printf("Eman bi zenbaki eta ordenean erakutsiko dizut: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i %i %i", &zenbakia1, &zenbakia2,&zenbakia3);

	if ((zenbakia1 * zenbakia1) + (zenbakia2 * zenbakia2) == zenbakia3 ) {
		printf("Hirukote pitagorikoa osatzen dute.");

	}
	else { 
		printf("Ez dute osatzen");
	
	}
	return 0;
}