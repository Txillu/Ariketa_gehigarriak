#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>

void hanoi(int n, char hasiera, char erdikoa, char azkena);

int main() {

	char hasiera = 'A';
	char erdikoa = 'B';
	char azkena = 'C';
	int n;
	char str[128];

	long t_0, t_bukaera;
	double secs;

	int mov;

	printf("Zenbat disko daude:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &n);

	mov = pow(2, n) - 1;
	printf("%i mugimendu egin beharko duzu.\n", mov);	
	printf("Jo edozein tekla mugimenduak ikusteko.\n");
	getchar();

	printf("Hauek dira egin beharreko mugimenduak: (A lehenengo pila B erdiko pila eta C azkenengo pila izanik) \n");
	t_0 = clock();
	hanoi(n, hasiera, erdikoa, azkena);
	t_bukaera = clock();

	secs = (t_bukaera - t_0) / CLOCKS_PER_SEC;
	printf("\n%g segundu\n", secs);
	getchar();
	return 0;
}

void hanoi(int n, char hasiera, char erdikoa, char azkena) {

	if (n == 1) {
		printf("%c->%c", hasiera, azkena);
	}
	else {
		hanoi(n - 1, hasiera, azkena, erdikoa);
		printf("\n%c->%c\n", hasiera, azkena);
		hanoi(n - 1, erdikoa, hasiera, azkena);
	}
}