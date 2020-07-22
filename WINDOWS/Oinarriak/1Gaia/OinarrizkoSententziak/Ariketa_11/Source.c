#define _CRT_SECURE_NO_WARNINGS	

#include<stdio.h>

int main() {

	int zenbakia, karratua, batura = 0;
	char str[128];

	printf("Eman zenbaki bat eta kapikua den esango dizut: \n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);

	int alderantziz = 0, hondarra=0;
	int kopia = zenbakia;
	while (zenbakia>0){

		hondarra = zenbakia % 10;
		zenbakia = zenbakia / 10;
		alderantziz = alderantziz * 10 + hondarra;
		
	}

	if (kopia == alderantziz) {
		printf("Kapikua da");
	}
	else {
		printf("Ez da kapikua");
	}

	return 0;
}