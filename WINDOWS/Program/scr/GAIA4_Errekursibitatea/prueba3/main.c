#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void paintailaratu(int );

int main() {

	int zenbakia;
	char str[128];

	printf("EMan zenbaki bat:\n");
	fgets(str,128, stdin);
	sscanf(str, "%i", &zenbakia);

	paintailaratu(zenbakia);

	return 0;
}

void paintailaratu(int n) {


	if (n==1) {
		printf("%i ", n);

	}
	else {

		printf("%i ", n);
		paintailaratu(n - 1);
		printf("%i ", n);
	}

}