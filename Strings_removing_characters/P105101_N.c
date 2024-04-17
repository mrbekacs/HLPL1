#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *delete_spaces(char *original)
{
    char *newStr = (char *)malloc(sizeof(char) * strlen(original) + 1);
    int newStrLen = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (!(c == ' '))
        {
            newStr[newStrLen] = c;
            newStrLen++;
        }
    }

    newStr[newStrLen] = '\0';
    return newStr;
}


int main()
{
    char line[101];
    gets(line);
    int n = atoi(line);

    for (int i = 0; i < n; i++)
    {
        gets(line);
        puts(delete_spaces(line));
    }

    return 0;
}
