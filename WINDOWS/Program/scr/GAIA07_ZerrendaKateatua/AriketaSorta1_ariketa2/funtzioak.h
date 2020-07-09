#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

typedef struct Pelikula {
	int id;
	char izenburua[MAX_KAR];
	struct Pelikula* ptrHurrengoa;
}PELIKULA;

char menua();
void aukeraExekutatu(char aukera, PELIKULA** burua);

PELIKULA* sortuPelikulaBat();
void bistaratuPelikulak(PELIKULA* burua);
void sartuPelikulakZerrendan(PELIKULA** burua);
int pelikulenMenua();
void sartuPelikulaBuztanean(PELIKULA* burua);
PELIKULA* baAlDago(int id, PELIKULA* ptrAux);
void kendu(int id, PELIKULA** burua);


#endif // !FUNTZIOAK_H
