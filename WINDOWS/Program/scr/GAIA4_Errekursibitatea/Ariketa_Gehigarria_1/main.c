#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void ehunekoak(int n, int kont);


int main() {

	int zenbakia, kont=10;
	char str[128];

	printf("Eman zenbaki bat eta bere ehuneko 10, 20, 30, 40, 50, 60, 70, 80, 90 eta 100 esango dizut:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &zenbakia);

	ehunekoak(zenbakia, kont);

	return 0;
}

void ehunekoak(int n, int kont) {

	if (kont == 100) {
		printf("Ehuneko %i = %.2f\n", kont, ((float)kont * n) / 100);
	}
	else {
		printf("Ehuneko %i = %.2f\n", kont, ((float) kont*n)/100);
		ehunekoak(n, kont + 10);
	}

}
