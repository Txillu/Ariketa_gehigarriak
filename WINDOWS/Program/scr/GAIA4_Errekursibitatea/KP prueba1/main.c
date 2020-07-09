#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int maximoa(int arraya[], int tamaina);
int main() {

	int bektorea[] = {5,4,92,1,75,125,6,3,75,5,4,54,65,74,0};
	int tam = 15;
	char str[128];
	int max;

	
	max = maximoa(bektorea, tam);


	printf("%i da balio maximoa", max);


	return 0;
}

int maximoa(int arraya[], int tamaina) {

	int max;

	if (tamaina == 1) {

		return arraya[tamaina];
	}

	else {

		max = maximoa(arraya, tamaina - 1);

		if (max < arraya[tamaina]) {

			max = arraya[tamaina];
		}
		return max;
	}
}

