#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include"diskak.h"

void menuaErakutsi() {
	DISKA* diskak;
	int* diskKop = 5;
	int aukera;
	char str[128];
	do
	{
		printf("|1 - Diska denak erakutsi\n");
		printf("|2 - Diska bat erakutsi \n");
		printf("|3 - Diska bat aurkitu\n");
		printf("|4 - Diska bat modifikatu\n");
		printf("|0 - Irten\n");
		printf("Zer egin nahi duzu?\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);
		menuaExekutatu(aukera, &diskak,&diskKop);
	} while (aukera!=0);

}

void menuaExekutatu(int aukera, DISKA* diskak,int* diskKop) {

	char* izenburua=0;

	switch (aukera)
	{
	
	case DANAK_IRAKURRI:
		diskakSortu(diskak);

		diskaDanakIrakurri(diskak,diskKop);

		break;

	case  BAT_IRAKURRI:

		break;

	case  AURKIUT:
		printf("Eman nahi den diskaren izenburua:\n");
		fgets(&izenburua, 128, stdin);
		//izenburua[strlen(&izenburua) - 1] = '\0';
		diskaBatAurkitu(diskak, diskKop, &izenburua);
		break;

	case MODIFIKATU:

		diskaBatModifikatu(diskak);

		break;

	default:

		break;
	}

}

//diskakSortu(&diskak);
//
//diskKop = 5;
//diskaDanakIrakurri(&diskak, &diskKop);

void diskakSortu(DISKA *diskak) {

	int *kop;

	(*diskak).id= 1;
	strcpy((*diskak).izenburua,"x\n");
	(*diskak).prezioa = 5.65;
	strcpy((*diskak).taldea, "a");

	(*(diskak+1)).id = 2;
	strcpy((*(diskak+1)).izenburua, "y\n");
	(*(diskak+1)).prezioa = 10.95;
	strcpy((*(diskak+1)).taldea, "b");

	(*(diskak + 2)).id = 3;
	strcpy((*(diskak + 2)).izenburua, "z\n");
	(*(diskak + 2)).prezioa = 15.6;
	strcpy((*(diskak + 2)).taldea, "c");

	(*(diskak + 3)).id = 4;
	strcpy((*(diskak + 3)).izenburua, "i\n");
	(*(diskak + 3)).prezioa = 9.75;
	strcpy((*(diskak + 3)).taldea, "d");

	(*(diskak + 4)).id = 5;
	strcpy((*(diskak + 4)).izenburua, "j\n");
	(*(diskak + 4)).prezioa = 5.25;
	strcpy((*(diskak + 4)).taldea, "e");
}

void diskaDanakIrakurri(DISKA* diskak, int* diskKop) {

	int i,aux;

	for (i = 0; i < *diskKop; i++){

		printf("Bere ID-a: %i\n",(*(diskak + i)).id);
		printf("Diskaren izenburua: %s\n",(*(diskak + i)).izenburua);
		printf("Diskaren taldea: %s\n", (*(diskak + i)).taldea);
		printf("Diskaren prezioa: %.2f\n", (*(diskak + i)).prezioa);
		printf("\n");

	}
	aux = getchar();
	system("cls");


}

void diskaBatIrakurri(DISKA* diska) {	// Funtzio honek diska baten datuak irakurriko ditu



}
int diskaBatAurkitu(DISKA* diskak, int *diskKop, char* izenburua) {

	int i = 0, aurkitu = 0,aux;


	while (i < *diskKop&& aurkitu==0) {

		if (strcmp(izenburua, (*(diskak + i)).izenburua) == 0) {
			printf("Bere ID-a: %i\n", (*(diskak + i)).id);
			printf("Diskaren izenburua: %s\n", (*(diskak + i)).izenburua);
			printf("Diskaren taldea: %s\n", (*(diskak + i)).taldea);
			printf("Diskaren prezioa: %.2f\n", (*(diskak + i)).prezioa);
			aurkitu = 1;
		}

		i++;
	}
	if (aurkitu == 0) {
		printf("Ez dago disko hori.");
	}
	aux = getchar();
	system("cls");

}

void diskaBatModifikatu(DISKA* diska) {
	
	int id, i = 0,aurkitu=0,aux;
	char str[128];

	printf("Eman diskaren ID-a:\n");
	fgets(str, 128,stdin);
	sscanf(str, "%i", &id);

	while (i < 5 && aurkitu == 0) {

		if (id==(*(diska+i)).id) {
			printf("Hau da orainarteko informazioa.\n");
			printf("Bere ID-a: %i\n", (*(diska + i)).id);
			printf("Diskaren izenburua: %s\n", (*(diska + i)).izenburua);
			printf("Diskaren taldea: %s\n", (*(diska + i)).taldea);
			printf("Diskaren prezioa: %.2f\n", (*(diska + i)).prezioa);
			printf("\n");

			printf("Orain eman bere ID berria:");
			fgets(str, 128, stdin);
			sscanf(str, "%i", (*(diska+i)).id);

			printf("Orain eman bere izenburu berria:");
			fgets((*(diska + i)).izenburua, 128, stdin);

			printf("Orain eman bere talde berria:");
			fgets((*(diska + i)).taldea, 128, stdin);

			printf("Orain eman bere prezio berria:");
			fgets(str, 128, stdin);
			sscanf(str, "%f", (*(diska + i)).prezioa);

			aurkitu = 1;
		}

		i++;
	}
	if (aurkitu == 0) {
		printf("Ez dago disko hori.");
	}
	aux = getchar();
	system("cls");

}