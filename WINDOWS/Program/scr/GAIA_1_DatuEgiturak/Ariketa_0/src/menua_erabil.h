#ifndef MENUA_ERABIL_H
#define MENUA_ERABIL_H

typedef enum { ITXI,  DISKA_GEHITU, EROSI, KARRITO_IKUSI, BISTARATU_STOCKA}ERABIL_AUKERA;



int MENUA_erabil(DISKA_MOTA carrito[], DISKA_MOTA stocka[],int zenbat, int kop);
int MENUA_ERABIL_exekutatu(int aukera, DISKA_MOTA carrito[], DISKA_MOTA stocka[], int zenbat);

int MENUA_ERABIL_diskaGehitu(DISKA_MOTA carrito[], DISKA_MOTA stocka[], int zenbat, int kop);
void MENUA_ERABIL_ikusiStock(DISKA_MOTA carrito[], DISKA_MOTA stocka[], int zenbat);
void MENUA_ERABIL_karritoIkusi(DISKA_MOTA stocka[], int zenbat);
void MENUA_ERABIL_erosi(DISKA_MOTA carrito[],int kop);


#endif // !MENUA_ERABBIL_H
