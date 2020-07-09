#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int faktoriala(int zbk);

int main() {
	int emaitza, zbk;
	char str[128];

	printf("Eman zenbaki bat eta bere faktoriala kalkulatuko dut:\n");
	fgets(str, 129, stdin);
	sscanf(str, "%i", &zbk);
	
	emaitza = faktoriala(zbk);

	printf("Hau da %i faktorialaren emaizta: %i", zbk, emaitza);
	return 0;
}

int faktoriala(int zbk) {

	int emaitza;

	if (zbk == 0) {

		emaitza = 1;
	}
	else {

		emaitza = zbk*faktoriala(zbk - 1);

	}


	return emaitza;
}