#define _CRT_SECURE_NO_WARNINGS	

#include<stdio.h>

int main() {

	int zenbakia, karratua, batura=0;
	char str[128];

	printf("Eman zenbaki bat: \n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);

	karratua = zenbakia * zenbakia;
	int znb;

	while (karratua>0) {
		znb = karratua % 10;
		karratua = karratua / 10;
		batura = batura + znb;
	}

	printf("%i da emaitza", batura);
	return 0;
}