#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void zerrenda(int n[],int ,int kont);

int main() {


	int n[] = {1,5,3,4,9,8,3,8};
	int kop = 8,kont=0;
	char str[128];


	zerrenda(n,kop,kont);



	return 0;
}

void zerrenda(int n[],int kop,int kont) {
	if (kont == kop-1) {
		printf("%i, ", n[kont]);
	}
	else {
		printf("%i, ", n[kont]);
		zerrenda(n, kop, kont + 1);
	}

}
