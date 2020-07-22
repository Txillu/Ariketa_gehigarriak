#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {

	int kopurua;
	char str[128];


	printf("Ze tamainako karratua:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &kopurua);

	for (int i = 0; i < kopurua; i++) {

		for (int j = 0; j < kopurua; j++) {
			printf("* ");
		}
		printf("\n");
	}


	return 0;
}