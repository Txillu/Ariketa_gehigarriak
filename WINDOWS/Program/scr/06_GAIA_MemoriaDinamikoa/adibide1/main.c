#include <stdio.h>

int* batuketa_bug(int m, int n);
int* batuketa_heap(int m, int n);
void foo(int m, int n);

int main(int argc, char** argv) {
	int* emaitza;
	emaitza = batuketa_bug(3, 2);
	foo(3, 2);
	printf("Emaitza main-ean = %d\n", *emaitza); //stack-ko helbidea batenedukia boistaratzen
	printf("/////////////////////////////////////////////////////\n");
	emaitza = batuketa_heap(3, 2);
	foo(3, 2);
	printf("Emaitza main-ean = %d\n", *emaitza); //heap-ko helbidea batenedukia boistaratzen
	free(emaitza);
	getchar();
	return 0;
}

//int batuketa(int m, int n) -> OK
//void batuketa(int m, int n , int *pemaitza ) -> OK
int* batuketa_bug(int m, int n) // -> DANGER!!!!!!!!!!!!!!!!!!!!!
{
	int emaitza = 0; //PILA, STACT
	int* ptrRet = &emaitza; //DEKO PILAKO HELBIDEA -> DANGER
	*ptrRet = m + n;

	return ptrRet; // -> pilako helbidea bat ERROR!!!!!!!!!!
	//return &emaitza;
}

int* batuketa_heap(int m, int n) // -> DANGER!!!!!!!!!!!!!!!!!!!!!
{
	int* ptrRet = malloc(sizeof(int)); //HEAP-ko memoria helbide bat buletatzen du
	*ptrRet = m + n;
	return ptrRet;
}

void foo(int m, int n) {
	printf("M aldagaiaren balorea: %i\n", m);
	printf("N aldagaiaren balorea: %i\n", n);

}