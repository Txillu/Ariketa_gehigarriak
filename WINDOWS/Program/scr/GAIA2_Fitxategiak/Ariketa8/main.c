#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fichOrg, * fichDest; 
    char* irakurritakoa; // irakurritakoa gordetzeko
    char nombreOrg[80], zati[80];
    int luzeera;
    int kop; 
    int i, zati_kop = 4;
    /* Accedo al fichero de origen */
    printf("Idatzi fixategiaren izena eta bere formatua: ");
    scanf("%s", &nombreOrg);
    if ((fichOrg = fopen(nombreOrg, "rb")) == NULL) {
        printf("Ez da izen hori duen fitxategirik.\n");
    }

     // fitxaren luzeera
    fseek(fichOrg, 0, SEEK_END);
    luzeera = ftell(fichOrg);
    fseek(fichOrg, 0, SEEK_SET);
  
    irakurritakoa = (char*)malloc(luzeera);
 
    for (i = 0; i < zati_kop; i++) {
        sprintf(zati, "%s.00%i.txt", nombreOrg, i);
        if ((fichDest = fopen(zati, "wb")) == NULL) {
            printf("Ezin izan da fixtategia sortu.\n");

        }
        fseek(fichOrg, i * luzeera / zati_kop, SEEK_SET);
        kop = fread(irakurritakoa, 1, luzeera / zati_kop, fichOrg);

        fwrite(irakurritakoa, 1, kop, fichDest);

    }

    printf("Egina.\n");

    fclose(fichOrg);
    return 0;
}