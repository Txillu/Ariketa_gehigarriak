#define _CRT_SECURE_NO_WARNINGS
#define MAX_GAIXO 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include".\src\gaixoak.h"

int main() {


	GAIXOA gaixo[MAX_GAIXO];
	int zenbat=0;


	zenbat=gaixoakIrakurri(gaixo,zenbat);
	egoeraIrakurri(gaixo);

	positibo(gaixo,zenbat);

	fitxategiPasatu(gaixo, zenbat);

	return 0;
}