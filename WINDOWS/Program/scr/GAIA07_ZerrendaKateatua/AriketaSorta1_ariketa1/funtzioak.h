#ifndef FUNTZIOAK_H
#define FUNZTIOAK_H

typedef struct nodoa {
	int zbn;
	struct nodoa* hurrengoa;
}NODOA;


void sartuZenbakia(NODOA** phead, int znb);
NODOA* bilatu(NODOA* lehena, int valor);
void kenduZenbakia(NODOA** phead, int znb);
void erakutsiLista(NODOA* lehena);

#endif // !FUNTZIOAK_K
