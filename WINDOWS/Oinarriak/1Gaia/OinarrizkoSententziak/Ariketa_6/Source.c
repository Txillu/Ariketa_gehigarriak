#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {


	int n, m;
	char str[128];
	printf("Eman bi zenbaki eta euren arteko berreka egingo dizut: ");
	fgets(str, 128, stdin);
	sscanf(str, "%i %i", &n, &m);

	int i = 1;
	int emaitza=n;
	while (i < m) {
	
		emaitza = emaitza * n;
		i++;
	}
	printf("%i da emaitza", emaitza);

	return 0;
}