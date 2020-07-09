#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int batura(int n);

int main() {


	int n,guztira=0,kont=1;
	char str[128];

	printf("Eman zenbaki bat eta 1-etik zenbaki horrerarteko zenbakin arteko batura esango dizut:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &n);

	guztira = batura(n);

	printf("%i da zenbakien arteko batura.", guztira);

	return 0;
}

int batura(int n) {

	int guztira=0;

	if (n==0) {
		return n;
	}
	else {
		guztira = n + batura(n - 1);
	}
	return guztira;
}
