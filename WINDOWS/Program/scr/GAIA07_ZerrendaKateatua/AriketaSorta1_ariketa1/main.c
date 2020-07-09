#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "funtzioak.h"


int main() {

	NODOA** lehena=NULL;
	int aukera,znb;
	char str[128];

	do
	{
		printf("Zer egin nahi duzu:\n");
		printf("1-Zenbaki bat sartu.\n");
		printf("2-Zenbaki bat kendu.\n");
		printf("3-Zenbaki bat dagoen jakin.\n");
		printf("4-Dena bistaratu.\n");
		printf("0-Irten\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);

		switch (aukera)
		{
		case 1:

			printf("Eman sartu nahi den zenbakia:\n");
			fgets(str, 128, stdin);
			sscanf(str, "%i", &znb);
			sartuZenbakia(&lehena, znb);

			break;
		case 2:

			printf("Eman kendu nahi den zenbakia:\n");
			fgets(str, 128, stdin);
			sscanf(str, "%i", &znb);
			kenduZenbakia(&lehena, znb);

			break;
		case 3:
			
			printf("Eman bilatu nahi den zenbakia:\n");
			fgets(str, 128, stdin);
			sscanf(str, "%i", &znb);
			if (bilatu(lehena, znb) != NULL) {
				printf("Badago %i zenbakia listan\n", znb);
			}
			else
			{
				printf("Ez dago %i zenbakia listan\n", znb);
			}
			break;
		case 4:

			erakutsiLista(lehena);

			break;

		default:

			break;
		}
		printf("Jo edozein tekla jarraitzeko.\n", znb);

		getchar();
		system("cls");
	} while (aukera!=0);

	return 0;
}

