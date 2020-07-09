#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int lehenaKonprobatu(int zenb,int i);

int main() {

	int zenbakia, lehena;
	char str[128];

	printf("Eman zenbaki bat eta lehena den esango diut:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);

	lehena=lehenaKonprobatu(zenbakia,zenbakia/2);

	if (lehena == 1) {
		printf("Lehena da");

	}
	else {
		printf("EZ da lehena");
	}

	return 0;
}

int lehenaKonprobatu(int zenb,int i) {
	int lehena = 0;
	if (i == 1) {
		return 1;
	}
	else {

		if (zenb % i == 0) {
			return 0;
		}
		else {
			return lehenaKonprobatu(zenb, i - 1);
		}
	}

}