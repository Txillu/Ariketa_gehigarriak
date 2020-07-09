#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"funtzioak.h"



int main() {

	ERTZA* HasierakoGrafoa = NULL;
	ERTZA* KruskalGrafoa = NULL;
	int ertzKop;

	EGOERA* zuhaitza[100];
	int ZuhaitzaKop = 0;



	printf("Kruskal prueba");
	HasierakoGrafoa=ertzaSortu(HasierakoGrafoa);
	IbilbideMinimoarenZuhaitzaSortu(HasierakoGrafoa,zuhaitza,&ZuhaitzaKop);
	kruskal(HasierakoGrafoa,zuhaitza,KruskalGrafoa,ZuhaitzaKop);

	getchar();
	return 0;
}
