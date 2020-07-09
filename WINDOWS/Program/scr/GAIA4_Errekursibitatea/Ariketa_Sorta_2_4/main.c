#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>    // KOMENTATUTAKOA ORDENATZE METODORAKO DA
#define TXIKIA 0.001

float nire_sin(float x);
float nire_cos(float x);

int main() {

	
			clock_t t_ini, t_fin;
		double secs;

		t_ini = clock();

	

	float x;
	char str[128];
	float sin, cos;

	printf("Eman zenbaki bat radianetan eta beraren sin eta cos kalkulatuko dut:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &x);

	sin = nire_sin(x);
	cos = nire_cos(x);

	printf("%f da sin(x)-ren emaitza\n", sin);
	printf("%f da cos(x)-ren emaitza\n", cos);

	
	t_fin = clock();

		secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
		printf("%f milisegundos\n", secs * 1000.0);


	

	return 0;
}

float nire_sin(float x) {

	float sin;

	if (x < TXIKIA) {
		return sin = x;
	}
	else {
		sin = 2 * nire_sin(x / 2) * nire_cos(x / 2);
	}
	return sin;
}

float nire_cos(float x) {

	float cos;

	if (x < TXIKIA) {
		return cos = 1 - 0.5 * (x * x);
	}
	else {
		cos = nire_cos(x / 2) * nire_cos(x / 2) - nire_sin(x / 2) * nire_sin(x / 2);
	}

	return cos;
}