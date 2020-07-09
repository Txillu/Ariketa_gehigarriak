#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int konbinazio(int m, int n);
int faktorial(int zenbakia);

int main() {

	int m, n,emaitza;
	char str[128];


	printf("Eman zenbaki bat:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &m);

	printf("Eman beste zenbaki bat:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &n);

	if (m > n) {

		emaitza=konbinazio(m, n); // HAU MATE DISKRETAN IKASITAKO FORMULA DA

		int formula;			  // HAU CLASSROOM-EN JARRITAKO FORMULA APLIKATU DUT
		if(n==0){
			formula = 1;
		}
		else {
			formula = konbinazio(m - 1, n - 1) + konbinazio(m - 1, n);
		}
		printf("Emaitza %i da\n", emaitza); 
		printf("Emaitza %i da", formula);

	}
	else if (m == n) {
		printf("Emaitza 1 da");
	}
	else {

		printf("Bi zenbaki horiekin ezinda konbinaketarik egin.");
	}

	return 0;
}

int konbinazio(int m, int n) {

	int nFaktorial, mFaktorial, kenketarenFaktorial;
	int emaitza;

	nFaktorial = faktorial(n);
	mFaktorial = faktorial(m);
	kenketarenFaktorial = faktorial(m - n);

	emaitza = mFaktorial / (nFaktorial * kenketarenFaktorial);

	return emaitza;
}


int faktorial(int zenbakia){

	int emaitza;

	if(zenbakia == 0) {
		emaitza = 1;
	}
	else {
		emaitza = zenbakia * faktorial(zenbakia - 1);

	}
	return emaitza;
}