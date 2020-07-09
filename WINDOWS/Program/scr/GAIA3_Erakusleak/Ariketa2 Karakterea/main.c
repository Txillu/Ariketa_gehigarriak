#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENTU 1024

#include <stdio.h>
#include <string.h>

void kateaBete(char* katea);
void kapikuaAztertu(char* p, int zenbat, int* egoera);
void pantailaratu(char* p, int luzeera);

int main(){
	int egoera = 1, luzeera;
	char katea[128];

	kateaBete(katea);

	luzeera = strlen(katea) - 1;

	kapikuaAztertu(katea, luzeera, &egoera);

	if (egoera == 1) {

		printf("\nSartutako katea kapikua da");
	}
	else {

		printf("\nSartutako katea EZ da kapikua");
	}

	pantailaratu(katea, luzeera);

	return 0;
}

/* Funtzioak */
void kateaBete(char* katea)
{
	printf("Sartu karaktere katea bat:\n");
	fgets(katea, MAX_ELEMENTU, stdin);

}

void kapikuaAztertu(char* p, int luzeera, int* egoera)
{
	int i = 0;

	do {

		if (*(p + i) != *((p + luzeera - 1) - i)) {

			*egoera = 0;
		}

		i++;

	} while (i < (luzeera / 2) && *egoera == 1);
}

void pantailaratu(char* p, int luzeera)
{
	int i;

	printf("\nKatea zuzenean: %s", p);

	printf("Katea alderantziz: ");
	for (i = luzeera - 1; i >= 0; i--) {

		printf("%c", *(p + i));

	}
}
