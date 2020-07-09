#define _CRT_SECURE_NO_WARNINGS
#define MAX_STR 128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diskoa {
	
	int ID;
	char izenburua[MAX_STR];
	int urtea;
	struct diskoa* hurrengoa;

}DISKOA;

DISKOA* sortuDiska();
DISKOA* diskoaLehenaSartu(DISKOA* lehena, DISKOA* berria);
void bistaratudenak(DISKOA* lehena);

int main() {

	DISKOA* lehena=NULL;
	DISKOA* berria=NULL;
	int i = 0;

	for (i = 0; i < 3; i++) {

		berria = sortuDiska();
		lehena = diskoaLehenaSartu(lehena, berria);
	}

	bistaratudenak(lehena);

	return 0;
}

DISKOA* sortuDiska() {

	DISKOA* berria;
	char str[MAX_STR];

	berria = (DISKOA*)malloc(sizeof(DISKOA));

	printf("Eman diskoaren ID-a:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &(berria->ID));

	printf("Eman diskoaren Izenburua:\n");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(berria->izenburua, str);

	printf("Eman diskoaren ureta:\n");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &(berria->urtea));

	berria->hurrengoa = NULL;

	return berria;
}

DISKOA* diskoaLehenaSartu(DISKOA* lehena, DISKOA* berria) {

	if (lehena == NULL) {

		lehena = berria;
		berria->hurrengoa = NULL;

	}

	else {

		berria->hurrengoa = lehena;
		lehena = berria;

	}
	

	return berria;
}

void bistaratudenak(DISKOA* lehena) {

	while (lehena!= NULL) {
		printf("---------------%i------------------\n",lehena->ID);
		printf("%s (%i)\n", lehena->izenburua,lehena->urtea);
		lehena = lehena->hurrengoa;
	}

}