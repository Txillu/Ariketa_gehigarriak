#define _CRT_SECURE_NO_WARNINGS
#define KAR_MAX 79

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


char* konkatenatu(char* str1, char* str2);
char* ezabatu(char* str1, char* str2);
char* moztu(char* str1, char kar);
void maiuskularatu(char* str);
void minuskularatu(char* str);

//------------------------EZ DU ONDO FUNTZIONATZEN--------------------------

int main() {

	int i = 0;
	char str[128];
	char aukera,kar=0;
	char* str1=0, *str2=0;
	
	do
	{
		printf("Zer aukera egin nahi duzu:\n");
		printf("\ti: Katea pantailan idatzi.\n");
		printf("\tk : Beste kate bat gehitu(konkatenatu).\n");
		printf("\te : Barnean daukan azpi - kate bat ezabatu.\n");
		printf("\tz : Karaktere batetik aurrera moztu.\n");
		printf("\tM : Maiuskulatara pasatu.\n");
		printf("\tm : Minuskulatara pasatu.\n");
		printf("\tx : Irten.\n");
		fgets(str, 128, stdin);
		sscanf(str, "%c", &aukera);
	
		if (aukera == 'i') {

			printf("%s\n", str1);
		}
		else if (aukera=='k') {

			str1=konkatenatu(&str1, &str2);

		}
		else if (aukera == 'e'){

			str1=ezabatu(&str1,  &str2);
		}
		else if (aukera == 'z') {

			str1=moztu(&str1, kar);
		}	
		else if (aukera == 'M'){

			maiuskularatu(&str1);
		}
		else if (aukera == 'm') {

			minuskularatu(&str1);
		}

	} while (aukera!='x');

	return 0;
}

char* konkatenatu(char* str1, char* str2) {

	char* esaldia=0;
	char str[128],str3[128];
	int i = 0;


	printf("Eman lehenengo esaldia:\n");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	str1 = str;

	printf("Eman bigarren esaldia:\n");
	fgets(str3, 128, stdin);
	str3[strlen(str3) - 1] = '\0';
	str2 = str3;

	esaldia = (char*)malloc(sizeof(char));

	esaldia=strcat(str1, str2);

	return esaldia;
}

char* ezabatu(char* str1, char* str2) {
	char* berria;
	char str[128];

	printf("zer ezabatu nahi duzu:\n");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';

}

char* moztu(char* str1, char kar) {

}

void maiuskularatu(char* str){
	int i = 0;
	char c;

	while (*(str + i) != '\0') {
		c = *(str+i);
		putchar(toupper(c));
		i++;
	}

	getchar();
	system("cls");

}

void minuskularatu(char* str) {
	int i = 0;
	char c;

	while (*(str + i) != '\0') {
		c = *(str + i);
		putchar(tolower(c));
		i++;
	}
	getchar();
	system("cls");
}