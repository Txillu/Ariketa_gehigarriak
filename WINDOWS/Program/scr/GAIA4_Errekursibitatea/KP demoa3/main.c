#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

float nire_expon(float x);

int main() {

	float emaitza = 0, zenbakia;
	char str[128];

	printf("Eman zenbaki bat eta e ber zenbaki horiren emaitza emango diuzt:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &zenbakia);

	emaitza = nire_expon(zenbakia);

	printf("e^%.2f zenbakiaren emaitza %f da",zenbakia, emaitza);

	return 0;
}

float nire_expon(float x){
	
	float emaitza=0;
	float txikia = 0.0001;

	if (x < txikia) {

		return x= 1 + x;

	}
	else {

		emaitza = nire_expon(x / 2) * nire_expon(x / 2);
	}
	return emaitza;
}