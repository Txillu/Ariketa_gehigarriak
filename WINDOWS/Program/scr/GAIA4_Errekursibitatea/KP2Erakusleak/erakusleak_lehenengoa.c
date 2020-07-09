#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char* atikGertuen(char* esaldia);
char*ztikGertuen(char* esaldia);
void ordezkatu(char* a, char* z);

int main() {

	char esaldia[128];
	char* a, * z;

	printf("Eman esaldi bat eta a-tik gertuen eta z-tik gertuen dauden karaktereak lekuz aldatuko ditu:\n");
	fgets(esaldia, 128, stdin);
	esaldia[strlen(esaldia) - 1] = '\0';

	a = atikGertuen(esaldia);
	z = ztikGertuen(esaldia);

	ordezkatu(a, z);

	printf("hau da esaldi berria %s", esaldia);

	return 0;
}

char* atikGertuen(char* esaldia) {

	int i = 0,j=0,aurkitu=0;
	char letra = 'a';

	do
	{
		i = 0;
		for ( j = 0; j < strlen(esaldia); j++) {

			if (*(esaldia + j) == letra) {

				aurkitu = 1;

				return (esaldia + j);

			}
		}
		letra++;

	} while (aurkitu==0);
	

}

char* ztikGertuen(char* esaldia) {
	int i = 0, j = 0, aurkitu = 0;
	char letra = 'z';

	do
	{
		i = 0;
		for (j = 0; j < strlen(esaldia); j++) {

			if (*(esaldia + j) == letra) {
				aurkitu = 1;
				return (esaldia + j);

			}
		}
		letra--;

	} while (aurkitu == 0);

}

void ordezkatu(char* a, char* z) {

	int aux;

	aux = *a;
	*a = *z;
	*z = aux;

}

