#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "This is a simple string";
    char* pch;
    pch = strstr(str, "simple");
    strcpy(pch, "sample");

    puts(str);
    return 0;
}