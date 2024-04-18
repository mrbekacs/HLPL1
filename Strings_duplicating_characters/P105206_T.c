#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *double_consonants(char *original)
{
    char *new = (char *)malloc(sizeof(char) * strlen(original) * 2 + 1);
    int StrSize = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (!isalpha(c) || isalpha(c) && strchr("aoiueAOIUE", c) != NULL)
        {
            new[StrSize] = c;
            StrSize++;
        }
        else
        {
            new[StrSize] = c;
            StrSize++;
            new[StrSize] = c;
            StrSize++;
        }
    }

    new[StrSize] = '\0';
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

        puts(double_consonants(line));
    }

    return 0;
}