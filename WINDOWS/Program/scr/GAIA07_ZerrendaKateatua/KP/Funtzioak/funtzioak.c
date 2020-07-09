#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"funtzioak.h"


void ikasleakSartu(IKASLEA** burua){

    IKASLEA* ikasle=NULL,*aux;
    int n = 0;

    while (n < 5) {

        ikasle=ikasleBatSortu();
        aux = ikasle;
        if (*burua == NULL) {
            *burua = aux;
            (*burua)->hurrengoa = NULL;

        }
        else {

            aux->hurrengoa = *burua;
            *burua = aux;
        }
        n++;
    }

}

IKASLEA* ikasleBatSortu(){

    IKASLEA* sortu = NULL;
    char str[MAX_STR];

    sortu = (IKASLEA*)malloc(sizeof(IKASLEA));


    printf("Eman ikaslearen izena: ");
    fgets(str, MAX_STR, stdin);
    str[strlen(str) - 1] = '\0';
    strcpy(sortu->izena, str);

    printf("Eman ikaslearen batazbesteko nota: ");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &sortu->batazbeste);

    printf("Eman ikaslearen suspentso kopurua: ");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &sortu->susKop);

    printf("Eman ikaslearen matrikulatutako ikasgai kopurua: ");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &sortu->matriKop);

    printf("Eman ikaslearen jarrera (1-desegokia, 0-egokia): ");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &sortu->jarrera);

    printf("Eman ikasleak hirutik behera duten ikasgai kopurua: ");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &sortu->hiruBehera);

    sortu->hurrengoa = NULL;

    return sortu;
}

void pantailaratu(IKASLEA* burua) {

    IKASLEA* aux;

    aux = burua;

    if (aux == NULL) {
        printf("Ez dago ikaslerik");
    }
    else {
        
        while (aux != NULL) {
            ikasleBatPantaiaratu(*(aux));

            aux = aux->hurrengoa;
        }

    }
}

void ikasleBatPantaiaratu(IKASLEA aux) {

    printf("IZENA: %s\n", aux.izena);
    printf("BATAZBESTEKO NOTA: %i\n", aux.batazbeste);
    printf("SUSPENTSO KOPURUA: %i\n", aux.susKop);
    printf("MATRIKULATUTAKO IKASGAI KOPURUA: %i\n", aux.matriKop);
    if (aux.jarrera == 0) {
        printf("JARRERA: egokia");
    }
    else {
        printf("JARRERA: desegokia");
    }
    printf("HIRUTIK BEHERAKO SUSPENTSO KOPURUA: %i\n", aux.hiruBehera);


}

void konpentsazio(IKASLEA* burua) {

    float aprobatu = (burua->matriKop * 75) / 100;
    IKASLEA* aux=burua;

    if (burua == NULL) {

        printf("EZ dago ikaslerik.");

    }
    else {

        while (aux != NULL) {

        }
    }
}

