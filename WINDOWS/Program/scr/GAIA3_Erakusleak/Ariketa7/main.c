#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

char* nire_strstr(const char* s1, const char* s2);

int main() {

	char esaldi1[128];
	char esaldi2[128];


	printf("Eman lehenego karatekte kate bat:\n");
	fgets(esaldi1, 128, stdin);
	esaldi1[strlen(esaldi1) - 1] = '\0';

	printf("Eman bigarren karatekte kate bat:\n");
	fgets(esaldi2, 128, stdin);
	esaldi2[strlen(esaldi2) - 1] = '\0';

	printf("%s\n",nire_strstr(esaldi1,esaldi2));

	return 0;
}

char* nire_strstr(const char* s1, const char* s2) {

	char* esaldi;
	int aldiz = 0, i = 0, j = 0, irten = 0;

	aldiz = strlen(s1);
	esaldi = '\0';

	while (i < aldiz && irten == 0) {
		j = 0;
		while ((*(s1 + i + j) == *(s2 + j)) && (*(s2 + j) != '\0')) {

			j++;
		}
		if (*(s2 + j) == '\0')
		{
			esaldi = s1 + i;
			irten = 1;
		}
		i++;
	}


	return esaldi;

}

