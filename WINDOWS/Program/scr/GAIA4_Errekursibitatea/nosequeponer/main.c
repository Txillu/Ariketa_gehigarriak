#include <stdio.h>
#define dim 3

void permutazioak(int*, int);
void swap(int v[], int i, int j);

int main(int argc, char* argv[]) {

	int zbk[] = { 1,2,3,4 }, z;
	char str[3];

	permutazioak(zbk, 0);

	for (z = 0; z < dim; z++) printf("%d ", zbk[z]);
	printf("Sakatu \"return\" amaitzeko .....");
	fgets(str, 3, stdin);
	return 0;
}

void permutazioak(int* zbk, int i)
{
	int j;

	if (i == dim)
	{
		for (j = 0; j < dim; j++) printf("%d ", zbk[j]);
		printf("\n");
	}
	else
	{
		for (j = i; j < dim; j++) {
			swap(zbk, i, j);
			permutazioak(zbk, i + 1);
			swap(zbk, i, j);
		}
	}

}

void swap(int v[], int i, int j) {
	int t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}