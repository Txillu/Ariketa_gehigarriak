#ifndef _TESTUA_
#define _TESTUA_

#define FILE_IZENA_TESTUA "datuak.txt"

#define MAX_ERABIL	20

typedef struct {
	char izena[20];
	char password[20];

}ERABILTZAILEA;

void FITX_TESTUA_adibidea();
void FITX_TESTUA_irakurriErabiltzaileak();

#endif