#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(){

	int lehenZenbakia, bigarrenZenbakia, hirugarrenZenbakia, tmp, aldaketa = 0;
	char str[128];

	printf("Eman hiru zenbaki hutsunearekin separatuta eta txikitik handira ordenatuko dizut:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i %i %i", &lehenZenbakia, &bigarrenZenbakia, &hirugarrenZenbakia);

	do
	{
		aldaketa = 1;
		if (lehenZenbakia > bigarrenZenbakia) {
			tmp = lehenZenbakia;
			lehenZenbakia = bigarrenZenbakia;
			bigarrenZenbakia = tmp;
			aldaketa = 0;
		}
		if (bigarrenZenbakia > hirugarrenZenbakia) {
			tmp = bigarrenZenbakia;
			bigarrenZenbakia = hirugarrenZenbakia;
			hirugarrenZenbakia = tmp;
			aldaketa = 0;

		}
		if (lehenZenbakia > hirugarrenZenbakia) {
			tmp = lehenZenbakia;
			lehenZenbakia = hirugarrenZenbakia;
			hirugarrenZenbakia = tmp;
			aldaketa = 0;

		}

	} while (aldaketa == 0);


	
	printf("%i %i %i", lehenZenbakia, bigarrenZenbakia, hirugarrenZenbakia);

	return 0;
}