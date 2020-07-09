#include <stdio.h>
#include <stdlib.h>


#include "fitxBitarra.h"
#include "fitxTestua.h"

int  main() {
	char aux;
	//PROGRAMA
	FITX_BITARRA_adibidea();
	FITX_TESTUA_adibidea();
	//FITXATEGIAK IRAKURTZEN
	FITX_TESTUA_irakurriErabiltzaileak();
	//BUKAERA
	printf("Sakatureturn bukatzeko...");
	aux = getchar();
	return 0;

}