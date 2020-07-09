#ifndef ERABILTZAILEAK_H
#define ERABILTZAILEAK_H


typedef struct erabiltzailea {

	char izena[128];
	char password[128];
	char mota[128];

}ERABILTZAILEA;

int ERABILTZAILE_MotaKonprobatu(ERABILTZAILEA erabiltzailea);


#endif // !ERABILTZAILEAK_H
