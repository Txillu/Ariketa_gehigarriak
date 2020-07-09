#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "Funtzioak.h"

void menua() {

	IKASLE* ikaslea;
	NODOA* nodoa;

	int aukera;
	char str[128];

	do
	{
		printf("Zer egin nahi duzu: ");
		printf("1- Ikaslea gehitu.\n");
		printf("2- Borratu ikaslea.\n");
		printf("3- Ikasle bat bilatu.\n");
		printf("4- Ikasle bat bistaratu.\n");
		printf("5- Danak bistaratu.\n");
		printf("0- Irten.\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);

		switch (aukera)
		{

		case 1:
			ikaslea=ikasleaSortu();
			nodoa = ikasleaSartu(&nodoa, ikaslea);
			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;

		case 5:

			break;

		default:
			break;
		}


	} while (aukera!=0);

}

IKASLE* ikasleaSortu() {

	IKASLE* sortu=NULL;
	char str[128];

	sortu = (IKASLE*)malloc(sizeof(IKASLE));

	printf("Eman bere ID-a: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &sortu->id);


	printf("Eman bere izena: ");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';

	printf("Eman bere lenengo nota: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &sortu->nota.lehena);

	printf("Eman bere bigarren nota: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &sortu->nota.bigarrena);

	return sortu;
}

NODOA* ikasleaSartu(NODOA* nodoa, IKASLE ikasle) {

	NODOA* burua;

	burua = (NODOA*)malloc(sizeof(NODOA));

	burua = nodoa;

	if (burua == NULL) {

		burua->ikasleak = ikasle;


	}

}
