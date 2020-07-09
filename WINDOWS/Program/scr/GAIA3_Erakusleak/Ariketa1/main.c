#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int nire_strlen(char esaldi1[]);
int nire_strlen_V2(char* esaldi1);

int main() {

	int aux,tam,tam2;
	char esaldi1[128];

	printf("Eman esaldi bat eta beraren karktektere kopurua esangom dizut:\n");
	fgets(esaldi1, "%s", stdin);

	tam=nire_strlen(esaldi1);
	tam2 = nire_strlen_V2(&esaldi1);
	printf("Emandako esaldiak %i karaktere ditu\n", tam);//
	printf("Emandako esaldiak %i karaktere ditu\n", tam2);

	return 0;
}

int nire_strlen(char esaldi1[]) {

	int  tam=0,i=0;

	while (esaldi1[i] != '\n') {
		tam++;
		i++;
	}

	return tam;
}
int nire_strlen_V2(char* esaldi1) {

	int  tam = 0, i = 0;

	while (*(esaldi1+i) != '\n') {
		tam++;
		i++;
	}

	return tam;

}
