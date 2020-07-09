#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int bakoitienBatuketa(int* n);

int main() {

	int zerrenda[] = { 1,5,3,4,2,6,9,7,1,20,41,32,0,5,-1 };   // emaitza 72
	int kop = 15, batura;

	batura= bakoitienBatuketa(zerrenda);

	printf("\nZerrendan dagoen zenbakien batura %i da\n", batura);


	int zerrenda1[] = { 5,4,6,1,8,4,5,10,3,-1 };  // emaitza 14
	kop = 10;

	batura = bakoitienBatuketa(zerrenda1);

	printf("\nZerrendan dagoen zenbakien batura %i da\n", batura);

	int zerrenda2[] = { 5,3,97,20,1,6,4,2,14,3652,15,4563,1054,321,852,-1 };  // emaitza 5005
	kop = 15;

	batura = bakoitienBatuketa(zerrenda2);

	printf("\nZerrendan dagoen zenbakien batura %i da\n", batura);



	return 0;
}

int bakoitienBatuketa(int* n) {

	int batuketa=0;

	if (*(n) == -1) {

		return 0;

	}

	else {

		if (*(n) % 2 != 0) {
			return batuketa = *(n) + bakoitienBatuketa((n + 1));
		}
		else {
			return batuketa = bakoitienBatuketa((n + 1));
		}

	}
}
