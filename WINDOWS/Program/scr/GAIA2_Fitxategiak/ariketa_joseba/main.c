#include <stdio.h>
#include <stdlib.h>

#include "errealak.h"
#include "irudikariak.h"
#include "erabiltzaileak.h"


int main() {
	char aux = 'a';
	printf("-------------fitxategi bitarrak--------------\n");

	ERREALAK_idatzi();
	ERREALAK_irakurri();
	ERREALAK_idatzi_Testuan();
	ERREALAK_irakurri_Testuan();
	
	
	IRUDIKARIAK_idatzi();
	IRUDIKARIAK_irakurri();
	IRUDIKARIAK_idatzi_Testuan();
	IRUDIKARIAK_irakurri_Testuan();

	ERABIL_idatzi();
	ERABIL_irakurri();
	ERABIL_idatzi_Testuan();
	ERABIL_irakurri_Testuan();

	//////////////////////////
	printf("Sakatu return bukatzeko....");
	aux = getchar();
	return 0;
}