#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void bektoreaOrdenatu(int bektorea[],int kont,int berria[]);
int txikienaBilatu(int bektorea[], int kont);

int main() {

	int bektorea[128],zenbakia,kont=0;
	char str[128];
	printf("Eman zenbaki bat lerroko (0 amaitzeko): \n");
	do
	{
		fgets(str, 128, stdin);
		sscanf(str, "%i", &zenbakia);
		if (zenbakia != 0) {
			bektorea[kont] = zenbakia;
			kont++;
		}

	} while (zenbakia!=0);

	/*int berria[128];
	bektoreaOrdenatu(bektorea, kont,berria);*/
	int tmp = 0;
	for (int i = 0; i < kont; i++) {
		for (int j = i; j < kont; j++) {

			if (bektorea[i] > bektorea[j]) {
				tmp = bektorea[i];
				bektorea[i] = bektorea[j];
				bektorea[j] = tmp;

			}

		}

	}

	for (int i = 0; i < kont; i++) {
		printf("%i ", bektorea[i]);
	}


	return 0;
}

void bektoreaOrdenatu(int bektorea[], int kont,int berria[]) {
	
	int i = 0;
	int min;
	for (i = 0; i < kont; i++) {
		min = txikienaBilatu(bektorea, kont);
		berria[i] = min;

	}
}

int txikienaBilatu(int bektorea[],int kont) {

	int i = 0;
	int min = bektorea[i];

	for(i = 0; i < kont; i++) {

		if (bektorea[i] < min) {
			min = bektorea[i];
		}

	}
	return min;
}