#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENTU 1024
#include <stdio.h>
#include <string.h>

/*

int* kop; eta kodigoan kop jartzen badagu bere direkzioa erabiliko da
int* kop; eta *kop erabiltzen badugu kodigoan kop-ek duen integerra erabiliko du

*/

void kateaBete(int* p, int* zenbat);
void kapikuaAztertu(int* p, int* zenbat, int* egoera);
void pantailaratu(int* p, int* zenbat);

int main() {

	int zenbakia[MAX_ELEMENTU],n=0,egoera=1;
	char karaktere[MAX_ELEMENTU];
	char str[128];
	int i=0,kop=0;

	kateaBete(zenbakia, &n);

	kapikuaAztertu(zenbakia, &n, &egoera);

	if(egoera==1){
		printf("Sartu duzun zenbakia kapikua da.\n");
	}

	else {
		printf("sartu duzun zenbakia EZ da kapikua.\n");
	}

	pantailaratu(zenbakia, &n);

	return 0;
}

void kateaBete(int* p, int* zenbat){
	char str[20];
	int zbk, aukera;

	do {
	
		do {
			printf("Sartu zenbaki bat 0-tik 9-ra: ");
			fgets(str, 128, stdin);
			sscanf(str, "%i", &zbk);
			if ((zbk < 0) || (zbk > 9)) {
				printf("\n Zenbakia ez da zuzena\n");
			}
		} while ((zbk < 0) || (zbk > 9));

	
		*p = zbk;
		p++;

		(*zenbat)++;

		printf("\n1) Jarraitu");
		printf("\n2) Bukatu");

		do {
			printf("\nZer egin nahi duzu: \n");
			fgets(str, 128, stdin);
			sscanf(str, "%i", &aukera);

		} while (aukera != 1 && aukera != 2);

	} while (aukera == 1);

}

void kapikuaAztertu(int* p, int* zenbat, int* egoera) {

	int i = 0;

	do
	{
		if (*(p + i) != *((p + *zenbat - 1) - i)) {

			*egoera = 0;
		}
		i++;

	} while (i>(*zenbat/2)&&*egoera==1);

}

void pantailaratu(int* p, int* zenbat)
{
	int i;

	printf("\n\nKatea zuzenean: ");
	for (i = 0; i < *zenbat; i++) {
		printf("%d ", *(p + i));
	}

	printf("\n\nKatea alderantziz: ");
	for (i = *zenbat - 1; i >= 0; i--) {
		printf("%d ", *(p + i));
	}
}