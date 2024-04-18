#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *double_vowels(char *original)
{
    char *new = (char *)malloc(sizeof(char) * strlen(original) * 2 + 1);
    int len = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (strchr("aoieuAOIEU", c) != NULL)
        {
            new[len] = c;
            len++;
            new[len] = c;
            len++;
        }
        else
        {
            new[len] = c;
            len++;
        }
    }

    new[len] = '\0';
    return new;
}


int main()
{
    char line[101];

    while (1)
    {
        gets(line);
        if (strcmp(line, "") == 0)
        {
            return 0;
        }

        puts(double_vowels(line));
    }

    return 0;
}