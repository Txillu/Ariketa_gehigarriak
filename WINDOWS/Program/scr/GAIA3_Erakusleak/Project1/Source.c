#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	int tam,esaldi2Tam;
	char aux;

	char esaldi1[128]= "hauascasc ";
	char esaldi2[128] = "kaixcaascasco ";

	char* ptrEsaldi1 = "hauascasc";
	char* ptrEsaldi2 = "kaixcaascasco";

	esaldi2Tam= strlen(ptrEsaldi2);

	tam=nireStrcat(*ptrEsaldi2,*ptrEsaldi1,esaldi2Tam);
	
	printf("%i", tam);
	aux = getchar();
	return 0;

}

int nireStrcat(char* ptrEsaldi2, char* ptrEsaldi1,int esaldi2Tam)
{
	int tam, i = 0;

	do
	{
		*(ptrEsaldi2 + (esaldi2Tam + i)) = *(ptrEsaldi1 + i);
		i++;
	} while ((*(ptrEsaldi1 + (i - 1)) != '\0'));
	tam = sizeof(ptrEsaldi2);
	return tam;
}
