#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	float *ptrerreala=0;
	int *ptrarraya=0;
	char *izena=0;

	printf("////////////////////5.5/////////////////////////////////\n");

	ptrerreala = (float*)malloc(sizeof(float));
	*ptrerreala = 5.5;
	printf("\n\n");
	printf("%.2f", *ptrerreala);
	printf("\n\n");

	printf("/////////////////////1,2,3,4,5,6////////////////////////////////\n");

	ptrarraya = (int*)malloc(sizeof(int) * 6);

	int i = 0,kont=1;

	for (i = 0; i < 6; i++) {
		*(ptrarraya + i) = kont;
		kont++;
	}
	printf("\n\n");

	for (i = 0; i < 6; i++) {
		printf("%i", *(ptrarraya + i));
	}
	printf("\n\n");
	printf("//////////////////////////joseba///////////////////////////\n");

	izena = (char*)malloc(sizeof(char) * 6);
	strcpy(izena, "joseba");
	printf("\n\n");
	printf("%s", izena);
	printf("\n\n");

	free(izena);
	free(ptrarraya);
	free(ptrerreala);

	getchar();
	return 0;
}
