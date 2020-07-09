#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<time.h>

#define RAND30000 "rand30000.txt"
#define RAND50000 "rand50000.txt"

void fitxategiaSortu_Ireki_30000();
void fitxategiaSortu_Ireki_50000();

int zenbakiakArrayanSartu(int zerrenda[], int kopurua, int aukera);
void shellSort(int zerrenda[], int kopurua);


int main() {
	system("cls");
	int n, i;
	char str[128];

	int zerrenda[30000], kopurua = 0, zerrenda5[50000];

	float t_hasiera, t_bukaera, t_guztira;

	printf("Zenbat zenbakirekin egin da duzu, 1-30000 zenbaki, 2-50000 zenbaki:\n");

	fgets(str, 128, stdin);
	sscanf(str, "%i", &n);

	if (n == 1) {


		fitxategiaSortu_Ireki_30000();
		kopurua = zenbakiakArrayanSartu(zerrenda, kopurua, n);

		t_hasiera = clock();
		shellSort(zerrenda,kopurua);
		t_bukaera = clock();

		t_guztira = (t_bukaera - t_hasiera) / CLOCKS_PER_SEC;
		printf("\n%f segundu iraun du desordenatutako zerrenda bat ordenatzen.\n\n", t_guztira);

		//-------------------------------ORDENTAUTAKO ZERRENDAREN NEURKETA ETA SORTU-----------------------------

		int zerrendaOrdenatuta[30000];

		for (i = 0; i < 30000; i++) {

			zerrendaOrdenatuta[i] = i;
		}

		t_hasiera = clock();
		shellSort(zerrendaOrdenatuta, 30000);
		t_bukaera = clock();

		t_guztira = (t_bukaera - t_hasiera) / CLOCKS_PER_SEC;
		printf("\n%f segundu iraun du ordenatuakoa zerrenda bat ordenatzen.\n\n", t_guztira);
		//----------------------------------------------------------------------------------------------------



		printf("Hemen zerrendako lehengo 10-ak\n");

		for (i = 0; i < 10; i++) {

			printf("%i\n", zerrenda[i]);

		}

		printf("Hemen zerrendako azkenengo 10-ak\n");

		for (i = 29999; i > 29989; i--) {

			printf("%i\n", zerrenda[i]);

		}


	}
	else if (n == 2) {

		fitxategiaSortu_Ireki_50000();
		kopurua = zenbakiakArrayanSartu(zerrenda5, kopurua, n);

		t_hasiera = clock();
		shellSort(zerrenda5, kopurua);
		t_bukaera = clock();

		t_guztira = (t_bukaera - t_hasiera) / CLOCKS_PER_SEC;
		printf("\n%f segundu iraun du desordenatutako zerrenda bat ordenatzen.\n\n", t_guztira);

		//-------------------------------ORDENTAUTAKO ZERRENDAREN NEURKETA ETA SORTU-----------------------------

		int zerrendaOrdenatuta[50000];

		for (i = 0; i < 50000; i++) {

			zerrendaOrdenatuta[i] = i;
		}

		t_hasiera = clock();
		shellSort(zerrendaOrdenatuta, 50000);
		t_bukaera = clock();

		t_guztira = (t_bukaera - t_hasiera) / CLOCKS_PER_SEC;
		printf("\n%f segundu iraun du ordenatuakoa zerrenda bat ordenatzen.\n\n", t_guztira);
		//----------------------------------------------------------------------------------------------------



		printf("Hemen zerrendako lehengo 10-ak\n");

		for (i = 0; i < 10; i++) {

			printf("%i\n", zerrenda5[i]);

		}

		printf("Hemen zerrendako azkenengo 10-ak\n");

		for (i = 49999; i > 49989; i--) {

			printf("%i\n", zerrenda5[i]);

		}


	}
	else {
		printf("Eman aukera egokia\n");

	}

	return 0;
}

void fitxategiaSortu_Ireki_30000() {

	int aukera;
	char str[128];
	int zenbakia;
	FILE* fitx;


	printf("Fitxategia sortu nahi duzu? 1-Bai 0-Ez\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &aukera);
	if (aukera == 1) {
		fitx = fopen(RAND30000, "w");
		if (fitx > 0) {

			for (int i = 0; i < 30000; i++) {
				zenbakia = rand();
				fprintf(fitx, "%i\n", zenbakia);
			}

			fclose(fitx);
		}
		else {
			printf("arazoa egon da fitxategia irekitzerakoan\n");
		}
	}
}

void fitxategiaSortu_Ireki_50000() {

	int aukera, zenbakia;
	char str[128];
	FILE* fitx;


	printf("Fitxategia sortu nahi duzu? 1-Bai 0-Ez\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &aukera);
	if (aukera == 1) {
		fitx = fopen(RAND50000, "w");
		if (fitx > 0) {

			for (int i = 0; i < 50000; i++) {
				zenbakia = rand();
				fprintf(fitx, "%i\n", zenbakia);
			}
			fclose(fitx);
		}
		else {
			printf("arazoa egon da fitxategia irekitzerakoan\n");
		}
	}

}

int zenbakiakArrayanSartu(int zerrenda[], int kopurua, int aukera) {

	int i = 0;

	if (aukera == 1) {
		FILE* fitx;
		fitx = fopen(RAND30000, "r");
		if (fitx > 0) {

			for (i = 0; i < 30000; i++) {

				fscanf(fitx, "%i", &zerrenda[i]);

			}


		}
		else {
			printf("arazoa egon da fitxategia irekitzerakoan\n");
		}
		if (fitx > 0) {
			fclose(fitx);
		}

	}
	else {
		FILE* fitx;
		fitx = fopen(RAND50000, "r");
		if (fitx > 0) {

			for (i = 0; i < 50000; i++) {

				fscanf(fitx, "%i", &zerrenda[i]);
			}


		}
		else {
			printf("arazoa egon da fitxategia irekitzerakoan\n");
		}
		if (fitx > 0) {
			fclose(fitx);
		}

	}
	return i;
}

void shellSort(int zerrenda[], int kopurua) {
	
	int i, j, k, tmp;

	for ( i = kopurua / 2; i > 0; i /= 2) {
		for ( k = i; k < kopurua; k += 1) {
			 tmp = zerrenda[k];
			
			for (j = k; j >= i && zerrenda[j - i] > tmp; j -= i) {
				zerrenda[j] = zerrenda[j - i];
			}
			zerrenda[j] = tmp;
		}
	}

}

