#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void foo(int *a);

typedef struct {

	char izena[128];
	char abizena[128];
	int id;

}PERTSONA;

PERTSONA sortuPertsona_V1(PERTSONA ptr);
void sortuPertsona_V2(PERTSONA* ptr);


int main()
{
	int aux;
	int *a = 10;

	PERTSONA per1 = { "Qing Yu","Jiang",18 };
	PERTSONA* ptrper1;
	int zenb=10;
	int* ptrZenb;
	int balorea;


	ptrZenb = &zenb;
	sortuPertsona_V2(&per1);

	*ptrZenb = 2;
	balorea = *ptrZenb + 9;

	ptrper1 = &per1;

	(*ptrper1).id = 7;//-----------Biak berdina egiten dute
	ptrper1->id = 7;//------------Biak berdina egiten dute


	foo(&a);

	printf("%i", a);

	aux = getchar();
	return 0;

}

void foo(int *a)
{
	*a = 11;
}
PERTSONA sortuPertsona_V1(PERTSONA ptr) {

	PERTSONA per1;

	per1.id = 7;
	return per1;
}

void sortuPertsona_V2(PERTSONA* ptr) {

	ptr->id = 7;

}