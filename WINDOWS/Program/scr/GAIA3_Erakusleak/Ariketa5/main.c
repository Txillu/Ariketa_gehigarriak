#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void zenbakiakIrakurri(float*, int*);
void zenbakiakOrdenatu(float*, int);
void zenbakiakIdatzi(float*, int);

int main(int argc, char* argv[])
{
	float zenbakia[100];
	int   kop;

	zenbakiakIrakurri(zenbakia, &kop);
	zenbakiakOrdenatu(zenbakia, kop);
	zenbakiakIdatzi(zenbakia, kop);
	return 0;
}

void zenbakiakIrakurri(float* lista, int* kop)
{
	char str[128];
	int i = 0,aukera;

	do
	{
		printf("Eman zenbaki bat:\n");
		fgets(str, 128, stdin);
		sscanf(str, "%f", lista + i);
		i++;

		printf("Jarraitu nahi duzu zenbakiak sartzen? (1=bai 0=ez)\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i", &aukera);
	} while (aukera==1);
	*kop = i;
}

void zenbakiakOrdenatu(float* lista, int kop)
{
	int i, j;
	float tmp;

	for (i = 0; i < kop ; i++)
	{
		for (j = i + 1; j < kop; j++)
			if (*(lista + j) < *(lista+i)) {
				tmp = *(lista + i);
				*(lista+i)=*(lista+j);
				*(lista + j) = tmp;
			}
	
	}
}

void zenbakiakIdatzi(float* Lista, int n)
{
	int i;

	for (i = 0; i < n; i++){

		printf("%.2f ", *(Lista + i));

	}

	printf("\n");
}
