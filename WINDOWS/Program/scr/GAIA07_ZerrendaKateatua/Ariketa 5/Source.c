#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_STR 128
typedef enum { WESTERN, DRAMA, THRILLER, COMEDIA } GENEROA;



typedef struct Pelikula {
	int id;
	char izenburua[MAX_STR];
	GENEROA gen;
	char zuzendaria[MAX_STR];
	int urtea;
	struct Pelikula* ptrHurrengoa;
}PELIKULA;


void bistaratuPelikulenZerrenda(PELIKULA* ptr);
void bistaratuPelikulaBat(PELIKULA* ptrPelikula);

PELIKULA* sortuPelikula();
PELIKULA* sartuBuruan(PELIKULA* lehena, PELIKULA* berria);
PELIKULA* sartuBukaeran(PELIKULA* lehena, PELIKULA* berria);


int main() {

	int i = 0;
	PELIKULA* ptrLehena = NULL;
	PELIKULA* ptrElementua = NULL;


	for (i = 0; i < 3; i++) {
		ptrElementua = sortuPelikula();
		ptrLehena = sartuBukaeran(ptrLehena, ptrElementua);
	}

	bistaratuPelikulenZerrenda(ptrLehena);



	getchar();
	return 0;
}


PELIKULA* sartuBukaeran(PELIKULA* lehena, PELIKULA* berria) {
	PELIKULA* aux = NULL; //zerrendan zehar mugitzeko
	aux = lehena;

	if (lehena == NULL) {
		//zerrenda utzik dago eta oso erreza da elementu berri bat bukaeran sartzea 
		//zuzenean lehenengo posizioan bihurtuz, elemenu bakar batekin lehena azkena da ;-)
		lehena = berria;
		berria->ptrHurrengoa = NULL;
	}
	else {
		//AZKEN ELEMENTUAN KOKATZEN GARA
		while (aux->ptrHurrengoa != NULL) {
			aux = aux->ptrHurrengoa;
		}
		aux->ptrHurrengoa = berria;
	}

	return lehena;
}

PELIKULA* sortuPelikula() {
	PELIKULA* pelikula = NULL;
	char str[MAX_STR];
	pelikula = (PELIKULA*)malloc(sizeof(PELIKULA));//pelikula baten datuak gordetzeko memoria  zatia sortuta

	printf("ID:");
	fgets(str, MAX_STR, stdin);//buletau memoria horren helbidea
	sscanf("%i", &(pelikula->id));

	printf("Izenburua:");
	fgets(str, MAX_STR, stdin);//buletau memoria horren helbidea
	str[strlen(str) - 1] = '\0';
	strcpy(pelikula->izenburua, str);


	pelikula->ptrHurrengoa = NULL;
	return pelikula;



}

PELIKULA* sartuBuruan(PELIKULA* lehena, PELIKULA* berria) {

	if (lehena == NULL) {
		//zerrenda utzik dago eta oso erreza da elementu berri bat buruan sartzea 
		//zuzenean lehena bihurtuz ;-)
		lehena = berria;
		berria->ptrHurrengoa = NULL;
	}
	else {
		//zerrendan elementuak dauz
		berria->ptrHurrengoa = lehena;
		lehena = berria;

	}
	return berria;
}


void bistaratuPelikulenZerrenda(PELIKULA* ptr) {
	//zerrenda muguit ub ehar gara azkenengo elementuraiano eta joan bistaratzen

	//1. zerrenda hutsik dago , arraiekin if (kop == 0) ez bistaratu 

	if (ptr != NULL) {
		do {
			bistaratuPelikulaBat(ptr);
			//hurrengo elementu ahartu i++ pelikulak[i]
			ptr = ptr->ptrHurrengoa;
		} while (ptr != NULL); //i < kop 

	}
	else {
		printf("Ez dago pelikualrik zerrednaª!!!!!\n");
	}




}

void bistaratuPelikulaBat(PELIKULA* ptrPelikula) {

	printf("---------------%i--------------------\n", ptrPelikula->id);
	printf("IZENBURUA:%s (%i)\n", ptrPelikula->izenburua, ptrPelikula->urtea);
}