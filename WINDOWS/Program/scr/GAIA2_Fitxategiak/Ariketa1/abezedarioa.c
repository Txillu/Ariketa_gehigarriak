#include<stdio.h>


#include"abezedarioa.h"

void abc() {

	FILE* abezedarioa;
	char minus = 'a';
	char mayus = 'A';

	int irakurritakoak = 1;
	abezedarioa = fopen("abecedario.txt",
		"w");
	if (abezedarioa > 0) {
		char str[20];
		//fscanf(fitx_erakuslea, "%s", str);
		while (irakurritakoak >= 1 && minus <='z'){
		//	fputc(minus, abezedarioa);
			fprintf(abezedarioa, "%c ", minus);
			minus++;
		}
		fputc('\n', abezedarioa);
		printf("Minuskula egina.\n");
		while (irakurritakoak >= 1 && mayus <= 'Z') {
			//fputc(mayus, abezedarioa);
			fprintf(abezedarioa, "%c ", mayus);
			mayus++;
		}
		printf("Mayuskulak egina.");
	}
	else {

		printf("Errorea %s fitxategia sortzerakoan.\n",
			FITXATEGIA);
	}

	if (abezedarioa > 0) {
		fclose(abezedarioa);
	}

}