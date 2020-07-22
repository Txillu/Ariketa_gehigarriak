#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {

	int kopurua;
	char str[128];

	printf("Ze tamainako piramidea:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &kopurua);

	int i = 1;
	for (i = 1; i <= kopurua; i++) {
		for (int j = 1; j <= kopurua - i; j++) {
			printf(" ");
		}

		for (int j = 1; j <= 2 * i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}