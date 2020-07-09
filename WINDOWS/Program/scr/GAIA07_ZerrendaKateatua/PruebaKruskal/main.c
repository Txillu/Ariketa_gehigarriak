#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct ertza {

	int erpinaA;
	int erpinaB;
	int pisua;
	struct ertza* ptrHurrengoa;

}ERTZA;

ERTZA* HasierakoGrafoa = NULL;
ERTZA* KruskalGrafoa = NULL;
int ertzKop;
int erpinKop;

typedef struct egoera {

	int izena;
	struct egoera* ptrHurrengoa;
}EGOERA;

EGOERA* zuhaitza[100];
int egoeraZenb=0;



void ertzaSortu();
void puntuaListanSartu(char v1, char v2, int pisua);
void zuhaitzaSortu();
void kruskal();
ERTZA* pisuTxikiena();
void biPuntuenIndizea(char erpinaA, char erpinaB,int i1,int i2);
void zuhaitzaSartu(int i1,int i2);
void kruskalGrafoaEgin(char erpinaA, char erpinaB, int pisua);
void puntuaHasieratikKendu(ERTZA* pisua);
void erakutsiPausuak();




int main() {


	printf("Kruskal prueba");
	ertzaSortu();
	zuhaitzaSortu();
	kruskal();

	getchar();
	return 0;
}

void ertzaSortu() {
	char str[128];
	int v1, v2;
	int pisua;


	printf("Eman ertz kopurua: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &erpinKop);

	printf("Eman ertz kopurua: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &ertzKop);

	printf("Eman puntuak ondorengo formatuan.\n");

	for (int i = 0; i < ertzKop; i++) {
	//	printf("hasiera puntuaren letra, bukaera puntuaren letra, ertzaren pisua (A B 7):\n");
		fgets(str, 128, stdin);
		sscanf(str, "%i %i %i", &v1, &v2, &pisua);
		puntuaListanSartu(v1, v2, pisua);
	}



}

void puntuaListanSartu(int v1, int v2, int pisua) {

	ERTZA* e1, *e2;
	e1 = (ERTZA*)malloc(sizeof(ERTZA));
	e1->ptrHurrengoa = NULL;
	e1->erpinaA = v1;
	e1->erpinaB = v2;
	e1->pisua = pisua;

	if (HasierakoGrafoa == NULL) {
		HasierakoGrafoa = e1;
	}
	else {
		for (e2 = HasierakoGrafoa; e2->ptrHurrengoa != NULL; e2 = e2->ptrHurrengoa);
		e2->ptrHurrengoa = e1;
	}

}

void zuhaitzaSortu() {

	EGOERA* s;
	int booleano,i=0;
	ERTZA* n;

	s = (EGOERA*)malloc(sizeof(EGOERA));
	s->ptrHurrengoa = NULL;
	s->izena = HasierakoGrafoa->erpinaA;
	zuhaitza[egoeraZenb] = s;
	egoeraZenb++;

	for (n = HasierakoGrafoa; n != NULL; n = n->ptrHurrengoa) {

		booleano = 1;

		for (i = 0; i < egoeraZenb; i++) {
			if (n->erpinaA == zuhaitza[i]->izena) {
				booleano = 0;
			}
		}

		/*while (i < egoeraZenb && booleano == 1) {


			if (n->erpinaA == zuhaitza[i]->izena) {
			booleano = 0;
			}
			i++;
		}*/
		if (booleano == 1) {

			s = (EGOERA*)malloc(sizeof(EGOERA));
			s->ptrHurrengoa = NULL;
			s->izena = n->erpinaA;
			zuhaitza[egoeraZenb] = s;
			egoeraZenb++;
		}


		booleano = 1;
		//i = 0;

		for (i = 0; i < egoeraZenb; i++) {
			if (n->erpinaB == zuhaitza[i]->izena) {
				booleano = 0;
			}
		}

		/*while (i < egoeraZenb && booleano == 1) {


			if (n->erpinaB == zuhaitza[i]->izena) {
				booleano = 0;
			}
			i++;
		}*/

		if (booleano == 1) {

			s = (EGOERA*)malloc(sizeof(EGOERA));
			s->ptrHurrengoa = NULL;
			s->izena = n->erpinaB;
			zuhaitza[egoeraZenb] = s;
			egoeraZenb++;
		}

		
	}

}

void kruskal() {

	ERTZA* e;
	e = HasierakoGrafoa;

	if (HasierakoGrafoa == NULL) {
		printf("\n\n");


		ERTZA* aux= KruskalGrafoa;
		while(aux!=NULL){
			printf("%i %i %i\n", aux->erpinaA, aux->erpinaB, aux->pisua);
			aux = aux->ptrHurrengoa;
		}
		return;
	}
	int booleano;

	ERTZA* ertzPisuTxikiena=pisuTxikiena();
	 
	int i1, i2;

	biPuntuenIndizea(ertzPisuTxikiena->erpinaA, ertzPisuTxikiena->erpinaB, &i1, &i2);
	if (i2 != i1) {

		zuhaitzaSartu(i1, i2);
		kruskalGrafoaEgin(ertzPisuTxikiena->erpinaA, ertzPisuTxikiena->erpinaB, ertzPisuTxikiena->pisua);
		puntuaHasieratikKendu(ertzPisuTxikiena);
	}
	else {
		puntuaHasieratikKendu(ertzPisuTxikiena);
	}
	
	kruskal();

}

ERTZA* pisuTxikiena() {

	ERTZA* ertza,*ertza1;
	int min;

	if (HasierakoGrafoa == NULL) {

		return NULL;
	}
	else {

		ertza1 = HasierakoGrafoa;
		min = HasierakoGrafoa->pisua;
		for (ertza = HasierakoGrafoa; ertza != NULL; ertza = ertza->ptrHurrengoa) {

			if (ertza->pisua < min) {
				ertza1 = ertza;
				min = ertza->pisua;
			}

		}
		return ertza1;
	}
}

void biPuntuenIndizea(int erpinaA, int erpinaB, int *i1, int* i2) {

	int i = 0;
	EGOERA* s;
	
	for (i = 0; i < egoeraZenb; i++) {
		for (s=zuhaitza[i]; s!=NULL; s=s->ptrHurrengoa)
		{
			if (s->izena == erpinaA) {
				*i1 = i;
			}
			if (s->izena == erpinaB) {
				*i2 = i;
			}
		}

	}
}

void zuhaitzaSartu(int i1, int i2) {

	EGOERA* e;

	for (e = zuhaitza[i1]; e->ptrHurrengoa != NULL; e = e->ptrHurrengoa);

	e->ptrHurrengoa = zuhaitza[i2];
	zuhaitza[i2] = NULL;


}

void kruskalGrafoaEgin(int erpinaA, int erpinaB, int pisua) {

	ERTZA* aux,* kurtsorea;

	aux = (ERTZA*)malloc(sizeof(ERTZA));

	aux->erpinaA = erpinaA;
	aux->erpinaB = erpinaB; 
	aux->pisua = pisua;
	aux->ptrHurrengoa = NULL;

	if (KruskalGrafoa == NULL) {
		KruskalGrafoa = aux;
	}
	else {

		kurtsorea = KruskalGrafoa;
		while (kurtsorea->ptrHurrengoa != NULL) {
			kurtsorea = kurtsorea->ptrHurrengoa;
		}
		kurtsorea->ptrHurrengoa = aux;
	}
}

void puntuaHasieratikKendu(ERTZA* e) {

	if (e == HasierakoGrafoa) {

		HasierakoGrafoa = HasierakoGrafoa->ptrHurrengoa;
		free(e);
	}

	else {
		ERTZA* kurtsorea;

		for (kurtsorea = HasierakoGrafoa; kurtsorea->ptrHurrengoa != e; kurtsorea = kurtsorea->ptrHurrengoa);
		kurtsorea->ptrHurrengoa = e->ptrHurrengoa;
		free(e);
	}
}

