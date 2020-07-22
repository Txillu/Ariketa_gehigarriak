#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {

	int zenbakia;
	char str[128];
	printf("Eman zenbaki bat eta lehen den esango dizut: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);

	int kont=1,lehenaDa=1;

	while (lehenaDa==1&&kont<zenbakia){

	

		kont++;

	}
	if (lehenaDa == 0) {
		printf("Ez da lehena");
	}
	else {
		printf("Lehena da");
	}

	return 0;
}