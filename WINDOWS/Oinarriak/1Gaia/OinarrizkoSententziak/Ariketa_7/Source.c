#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {

	int zenbakia;
	char str[128];

	printf("Eman zenbaki bat eta bere faktoriala kalkulatuko dizut: ");
	fgets(str,128, stdin);
	sscanf(str, "%i", &zenbakia);

	int emaitza = 1;
	while (zenbakia > 1) {
		emaitza = emaitza *zenbakia;
		zenbakia--;
	}
	printf("%i da emaitza.", emaitza);


	return 0;
}