#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {

	int kopurua;
	char str[128];

	printf("Ze tamainako hirukia:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &kopurua);
	int kont = 1;
	for (int i = 0; i < kopurua; i++) {
		for (int j = 0; j < kont; j++) {
			printf("*");
		}
		kont++;
		printf("\n");
	}


	return 0;
}