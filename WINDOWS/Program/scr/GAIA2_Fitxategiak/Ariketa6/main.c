#include<stdio.h>
#include<string.h>

#include "bitarra.h"

int main() {

	float zenbakiak[20], n;
	KONPLEXUA zenbaki[20];
	int i=0,kont=0;
	char str[128];
	int aukera = 0;

	printf("Zer sartu nahi duzu: 1-Errealak edo 2-Konplexua?\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &aukera);

	if (aukera==1) {

		printf("Eman zenbaki errealak, 0-rekin bukatu.\n");
		do
		{
			fgets(str, 128, stdin);
			sscanf(str, "%f", &n);
			if (n != 0)
			{
				zenbakiak[i] = n;
				i++;
				kont++;
			}
		} while (n != 0);

		bitarraPasatu(zenbakiak, kont);
	}
	else if(aukera==2){
		int bukatu = 0;
		do
		{	
				printf("Eman %i zenbaki konplexuaren zati erreala:\n", i);
				fgets(str, 128, stdin);
				sscanf(str, "%i", &zenbaki[i].erreala);

				printf("Orain %i eman zenbakiaren zati imaginarioa:\n", i);
				fgets(str, 128, stdin);
				sscanf(str, "%ij", &zenbaki[i].imaginarioa);
				if (zenbaki[i].erreala == 0 && zenbaki[i].imaginarioa == 0) {
					bukatu = 1;
				}
				i++;
				kont++;
		} while (bukatu==0);
	
		konplexuBitarra(zenbaki, kont);
		
	}


	return 0;
}