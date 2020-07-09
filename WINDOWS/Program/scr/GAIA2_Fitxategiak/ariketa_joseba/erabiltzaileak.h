#ifndef _ERABILTZAILEAK_H
#define _ERABILTZAILEAK_

#define FITX1_IZENA "erabil1.dat"

typedef enum {ADMIN, EROSLE,NONE}MOTA;

typedef struct {
	int id;
	char username[48];
	char password[48];
	MOTA mota;


}ERABIL;
void ERABIL_idatzi();
void ERABIL_irakurri();
void ERABIL_idatzi_Testuan();
void ERABIL_irakurri_Testuan();

#endif