#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "orokorrak.h"
#include "Erabiltzaileak.h"

/*
int ERABILTZAILEAK_sortu_(ERABILTZAILEA erabil[], int kop) {
	
//	int ADMIN = 1, EROSLE = 2;

	strcpy(erabil[0].izena, "admin");
	strcpy(erabil[0].password, "qwerty");
	erabil[0].mota = 'ADMIN';


	strcpy(erabil[0].izena, "joseba");
	strcpy(erabil[0].password, "123");
	erabil[0].mota = 'EROSLE';


	strcpy(erabil[0].izena, "irati");
	strcpy(erabil[0].password, "321");
	erabil[0].mota = 'EROSLE';


}

*/

int ERABILTZAILE_MotaKonprobatu(ERABILTZAILEA erabiltzailea){

	ERABILTZAILEA admin, erosle,erosle1;
	int mota;

	//--------------ADMIN  ERABIOTZAILEA----------------------
	admin.izena[0] = 'a';
	admin.izena[1] = 'd';
	admin.izena[2] = 'm';
	admin.izena[3] = 'i';
	admin.izena[4] = 'n';
	admin.izena[5] = '\n';

	admin.password[0] = 'a';
	admin.password[1] = 'd';
	admin.password[2] = 'm';
	admin.password[3] = 'i';
	admin.password[4] = 'n';
	admin.password[5] = '\n';

	//-----------------EROSLE ERABILZTAILE----------------
	erosle.izena[0] = 'j';
	erosle.izena[1] = 'o';
	erosle.izena[2] = 's';
	erosle.izena[3] = 'e';
	erosle.izena[4] = 'b';
	erosle.izena[5] = 'a';
	erosle.izena[6] = '\n';


	erosle.password[0] = '1';
	erosle.password[1] = '2';
	erosle.password[2] = '3';
	erosle.password[3] = '\0';
	erosle.password[4] = '\0';



	//-----------------EROSLE ERABILZTAILE----------------

	erosle1.izena[0] = 'i';
	erosle1.izena[1] = 'r';
	erosle1.izena[2] = 'a';
	erosle1.izena[3] = 't';
	erosle1.izena[4] = 'i';
	erosle1.izena[5] = '\n';

	erosle1.password[0] = '3';
	erosle1.password[1] = '2';
	erosle1.password[2] = '1';
	erosle1.password[3] = '\0';
	erosle1.password[4] = '\0';
	

	//-----------------ADMIN KONPROBAZIOA----------------
	int i=0, egoera = 0, desberdin = 0;

	if (egoera==0){

		while ( i < 5) {

			if ((erabiltzailea.izena[i] == admin.izena[i]) && (erabiltzailea.password[i] == admin.password[i])) {

				mota = 1;
				egoera = 1;
			}
			else {
				mota = 0;
			}
			i++;
		}
	}
	
	//------------------EROSLE KONPRONAZIOA---------------
	i = 0;
	if (egoera == 0) {

		while (i < 6 && desberdin == 0) {

			if ((erabiltzailea.izena[i] == erosle.izena[i]) && (erabiltzailea.password[i] == erosle.password[i])) {

				mota = 2;
				egoera = 1;

			}
			else {
				desberdin = 1;
				mota = 0;
			}
			i++;
		}
	}

	i = 0, desberdin = 0;
	if (egoera == 0) {

		while (i < 5&& desberdin==0) {

			if ((erabiltzailea.izena[i] == erosle1.izena[i]) && (erabiltzailea.password[i] == erosle1.password[i])) {

				mota = 2;
				egoera = 1;

			}
			else {
				desberdin = 1;
				mota = 0;
			}
			i++;
		}
	}


	return mota;
}
