#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"Funtzioak/funtzioak.h"


int main() {

	IKASLEA* burua;

	 ikasleakSartu(&burua);

	 pantailaratu(burua);

	 konpentsazio(&burua);

	return 0;
}