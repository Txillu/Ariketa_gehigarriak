#include<stdio.h>
#include<string.h>

#include "fitxategi.h"

int main() {

	int i,kop;
	float zenbakiak[100];
	char str[128];

	kop=zenbakiak_Irakurri(zenbakiak);

	for (i = 0; i < kop; i++) {
		printf("%f\n", zenbakiak[i]);
	}

	return 0;
}