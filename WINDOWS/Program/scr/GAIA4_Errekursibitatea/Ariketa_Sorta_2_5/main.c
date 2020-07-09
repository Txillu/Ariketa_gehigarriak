#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void izarra(int x,int linea,int azkena);

int main() {

	int x, linea = 1,azkena=0;
	char str[128];

	printf("Eman zenbaki bat:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &x);

	izarra(x,linea,azkena);


	return 0;
}

void izarra(int x,int linea,int azkena) {
	
	if (azkena == x) {
		for (int i = 0; i < x; i++) {
			printf("*");
		}
	}
	else {
		for (int i = 0; i < linea-1; i++) {
			printf("*");
		}
		printf("\n");

		izarra(x, linea + 1, azkena+1);
	}
	
	
}