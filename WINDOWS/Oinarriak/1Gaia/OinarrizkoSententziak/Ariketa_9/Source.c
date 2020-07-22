#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {

	int zenbakia;
	char str[128];

	printf("Eman zenbaki bat eta perfektua den esango dizut:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);

	int gorde, kont = 1,batura=0;

	while (kont < zenbakia) {

		if (zenbakia % kont == 0) {
			
			batura = batura + kont;
		}

		kont++;
	}

	if (zenbakia == batura) {
		printf("zenbakia perfektua da.");
	}
	else {
		printf("Ez da perfektua");
	}

	return 0;
}