#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int bilatu(int zenbat, int kokapen, int zbk, int bektorea[]);

int main() {

	int bektorea[] = { 2,6,4,9,3,7,1,5,7,1,9,10,65,84,99,165,74,13,12,85,65,45,349,741,658,654,25,9,72,1 };
	int zenbat = 30, kokapena = 0, zenbakia, emaitza;
	char str[128];

	printf("Honek dira array-ean dagoen zenbakia:\n");
	for (int i = 0; i < zenbat; i++) {
		printf("%i ", bektorea[i]);
	}
	printf("\nEman bilatu nahi den zenbakia eta arrayean dagoen esango dizut:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);

	emaitza=bilatu(zenbat, kokapena, zenbakia, bektorea);

	if (emaitza < 0) {
		printf("\n\n%i", emaitza);
		printf("\n\nEmandako zenbakia ez dago array - ean", emaitza);

	}
	else {
		printf("Emandako zenbakia array-ko %i posizioan dago", emaitza);
	}

	return 0;
}

int bilatu(int zenbat, int kokapen, int zbk, int bektorea[]) {

	if (zbk == bektorea[kokapen]) {

		return kokapen;
	}
	
	else {
		if(kokapen<zenbat){
				bilatu(zenbat, kokapen + 1, zbk, bektorea);
		}
		else {
			return -1;
		}
	}


}
