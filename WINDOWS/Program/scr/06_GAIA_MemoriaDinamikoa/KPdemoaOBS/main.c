#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void jasoZenbKop(int* kop);
int* erreserbaBurutu(int kop);
void jasoZenbakiak(int kop, int* bektorea);
void bistaratu(int kop, int* bektorea);

int main() {

	
	int* kop=0, * erreserba = 0;
	int* bektorea=0;


	jasoZenbKop(&kop);

	bektorea = erreserbaBurutu(kop);

	jasoZenbakiak(kop, bektorea);

	 bistaratu(kop, bektorea);

	 free(bektorea);

	return 0;
}

void jasoZenbKop(int* kop) {

	char str[128];

	printf("Eman zenbat zenbaki sartu nahi duzun:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", kop);

}

int* erreserbaBurutu(int kop) {

	int* erreserba;

	
	erreserba=(int*)malloc(kop*sizeof(int));

	if(erreserba==NULL){
		printf("Error.\n");
	}

	return erreserba;
}

void jasoZenbakiak(int kop, int* bektorea) {
	
	int i = 0,zenb;
	char str[128];

	for (i = 0; i < kop; i++) {
		printf("Eman zenbakia:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &zenb);

		*(bektorea + i) = zenb;
	}

}
void bistaratu(int kop, int* bektorea) {

	for (int i = 0; i < kop; i++) {
		printf("%i, ", *(bektorea + i));
	}

}

