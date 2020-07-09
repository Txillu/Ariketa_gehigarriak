#include <stdio.h>
#include <stdlib.h>
#include "funtzioak.h"

int main(int argc, char **argv)
{
	char aukera = '0';
	NODO_PELIKULA *burua = NULL; //beti egongo dira hemen pelikula danak 
	NODO_PELIKULA *alokatuak = NULL; //hemen egongo dira referentziak momentuan alokatuta daueden pelikulei


	printf("***Ariketa. pelikulen zerrenda bat edukita estilo bakoitzeko zerrendak eduki optimizatuta**\n");
	aukera = menua();
	//Sartu pelikulak 
	//bistaratu , kendu , gehirtu
	//filtratu/auleratu estilo batekoak eta gero eurekin lan egin 
	//, baina zerrend aoriginala mantenduz!!!!!!!!!!!!!!
	//adibidez , pareak inparak , neskak , mutilak , etc.....
	
	while (aukera != '0')
	{
		aukeraExekutatu(aukera, &burua, &alokatuak);
		//burua = aukeraExekutatu(aukera, burua);
		aukera = menua();
	}
	hustuZerrenda(&alokatuak, 0);
	hustuZerrenda(&burua, 1);
	bistaratuPelikulak(alokatuak);
	bistaratuPelikulak(burua);

	getchar();
	return 0;
}

