#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funtzioak.h"

// Menua pantailaratuko duen funtzioa
char menua()
{
	char aukera;
	char str[MAX_KAR];

	printf("============================================\n\n\n\n");
	printf("                   MENUA                    ");
	printf("\n\n\n============================================\n");
	printf("a: Sartu pelikula multzo bat zerrendan\n");
	printf("b: Pelikulak pantailaratu\n");
	printf("c: Pelikula bat alokatu\n");
	printf("d: Pelikula bat bueltatu\n");
	printf("e: Alokatutako Pelikulak pantailaratu\n");
	printf("f: Alokatutako gabeko pelikulak  pantailaratu\n"); //erabilita pelikual guztien zerrenda , 


	
	printf("0: Irten\n");
	printf("===========================================\n");
	
	fgets(str, MAX_KAR, stdin);
	sscanf(str, "%c", &aukera);
		
	return aukera;
}

void aukeraExekutatu(char aukera, NODO_PELIKULA ** ppBurua, NODO_PELIKULA** ppAlokatuak)
{	
	char str[128];
	int egoera = 0;
	switch (aukera) {
		case 'a':
			sartuPelikulakZerrendan(ppBurua);
			break;
		case 'b':
			bistaratuPelikulak(*ppBurua);
			break;
		case 'c':
			printf("Sartu alokatu nahi duzun pelikukaren izena:");
			fgets(str, 128, stdin);
			str[strlen(str) - 1] = '\0';
			egoera = pelikulaBatAlokatu(*ppBurua, str, ppAlokatuak);
			if (egoera != 0) {
				printf("Pelkikula alokatuta.\n") ;
			}
			else {
				printf("Ezin daiteke alokatu pelikula.\n");
			}

			break;
		case 'd':
			printf("Sartu alokatu nahi duzun pelikukaren izena:");
			fgets(str, 128, stdin);
			str[strlen(str) - 1] = '\0';
			egoera = pelikulaBatBueltatu( str, ppAlokatuak);
			if (egoera != 0) {
				printf("Pelkikula buelatuta.\n");
			}
			else {
				printf("Ez   pelikula ondo bueltatu.\n");
			}
		
			break;
		case 'e':
			bistaratuPelikulak(*ppAlokatuak);
			break;
		case 'f':
			
			break;
		default:
			printf("Sartu aukera egokia bat...\n");
			break;
	}
}


void bistaratuPelikulaBat(PELIKULA pel) {
	printf("Id:%i  izenburua:%s Alokatua:%i \n",
		pel.id, pel.izenburua, pel.alokatua);
}


void bistaratuPelikulak(NODO_PELIKULA* burua) {
	NODO_PELIKULA* ptrAux;//ZERRENDAN MUGITZEKO

	ptrAux = burua;
	if (ptrAux == NULL) printf("Ez dago pelikularik gordeta.\n");
	while (ptrAux != NULL) {//PELIKULA GUZTIAK HARTZEN BANAN BANAN
		bistaratuPelikulaBat( *(ptrAux->pelikula) );//pelikula bat 
		ptrAux = ptrAux->ptrHurrengoa;
	}
}


PELIKULA* sortuPelikulaBat(){
	PELIKULA* ptr; //return 
	char str[MAX_KAR];
	
	ptr = (PELIKULA*)malloc(sizeof(PELIKULA));

	printf("Sartu pelikularen identifikatzailea: ");
	fgets(str , MAX_KAR , stdin);
	str[strlen(str) - 1] = '\0';
	sscanf(str, "%i", &(ptr->id));

	printf("Sartu pelikularen izena: ");
	fgets(str, MAX_KAR, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(ptr->izenburua, str);

	ptr->alokatua = 0;//ez dago alokatua

	return ptr; //heap dagoen pelikualren helbidea
}
void sartuPelikulakZerrendan(NODO_PELIKULA ** ppBurua) {
	int jarraitu = 1;
	NODO_PELIKULA*  ptrAux = NULL;
	PELIKULA*  ptrPelikula = NULL;

	while (jarraitu == 1) {
		ptrPelikula = sortuPelikulaBat();//1 malloc
		ptrAux = (NODO_PELIKULA*)malloc(sizeof(NODO_PELIKULA)); //2 malloc
		ptrAux->pelikula = ptrPelikula;//esleitzen dogu pelikula helbidea nodoan

		//sartu buruan funtzioa NODOA
		if (*ppBurua == NULL) {
			*ppBurua = ptrAux;
			(*ppBurua)->ptrHurrengoa = NULL;

		}
		else {
			
			ptrAux->ptrHurrengoa = *ppBurua;
			*ppBurua = ptrAux;
		}
		jarraitu = pelikulenMenua();
	}
}
						//pelikula guztien zerrenda , nombre de la peli a alquilar , la lista de alquiladas
int pelikulaBatAlokatu(NODO_PELIKULA* pBurua, char str[], NODO_PELIKULA** ppAlokatuak) {
	NODO_PELIKULA* aux;
	int ret = -1;
	aux = pBurua;
	if (pBurua != NULL) {
		while (aux != NULL) {
			if (strcmp(aux->pelikula->izenburua, str) == 0) {
				//aurkitua
				if (aux->pelikula->alokatua == 0) {
					aux->pelikula->alokatua = 1;
					sartuPelikulaBuruan(ppAlokatuak, aux->pelikula);
					ret = 1;
				}else {
					//jada alokatuta
					ret = 0;
				}

			}
			aux = aux->ptrHurrengoa;
		}
	}
	return ret;

}

void sartuPelikulaBuruan(NODO_PELIKULA ** ppBurua, PELIKULA*  ptrPelikula) {
	NODO_PELIKULA* berria;
	berria = (NODO_PELIKULA*)malloc(sizeof(NODO_PELIKULA));
	berria->pelikula = ptrPelikula;////////////////////////////
	//sartu buruan
	//berriaren hurrengoa burua
	berria->ptrHurrengoa = *ppBurua;
	//berria izango da buru berria
	*ppBurua = berria;

		
}
						//izena , aolkatuakoak
int pelikulaBatBueltatu( char str[], NODO_PELIKULA** ppAlokatutakoak) {
	NODO_PELIKULA* aux;
	NODO_PELIKULA* tmp;
	int ret = 0;
	aux = *ppAlokatutakoak;
	if (aux != NULL) {
		if (strcmp(aux->pelikula->izenburua, str) == 0) {//lehengo pelikula netregatu 
			aux->pelikula->alokatua = 0;
			*ppAlokatutakoak = aux->ptrHurrengoa;
			free(aux);
			ret = 1;
		}
		else {
			//erdiko elementu bat kendu
			while ( (aux->ptrHurrengoa) != NULL && ret == 0) {
				if (strcmp(aux->ptrHurrengoa->pelikula->izenburua, str) == 0) {
					tmp = aux->ptrHurrengoa;//kendu behar dugun nodoa 
					tmp->pelikula->alokatua = 0;//nodo horretan dagoen pelikularen alokatu 0
					aux->ptrHurrengoa = aux->ptrHurrengoa->ptrHurrengoa;
					//aux->ptrHurrengoa = tmp->ptrHurrengoa;
					free(tmp);//ezabatzen dugu entregatu pelikularen nodoa
					ret = 1;
				}
				aux = aux->ptrHurrengoa;
			}
		}
	}
			

		
	return ret;

}

int pelikulenMenua() {
	int ret = 0;
	char kar;
	char str[MAX_KAR];

	printf("Zerrendan pelikula gehiago sartu nahi dituzu? (b: bai)\n");
	fgets(str, MAX_KAR, stdin);
	sscanf(str, "%c", &kar);


	if (kar == 'b') {
		ret = 1;
	}
	return ret;
}

void hustuZerrenda(PNODO_PELIKULA* ppBurua, int edukia) {
	PNODO_PELIKULA aux,tmp;
	aux = *ppBurua;
	if (aux != NULL) {
		while (aux != NULL) {
			tmp = aux;
			aux = aux->ptrHurrengoa;
			//////////////////////////////
			
			free(tmp);
		}
		*ppBurua = NULL;
	}

}

