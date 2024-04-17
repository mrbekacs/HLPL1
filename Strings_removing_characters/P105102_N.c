#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *delete_lowers(char *original)
{
    char *newString = (char *)malloc(sizeof(char) * strlen(original) + 1);
    int newStrSize = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (!islower(c))
        {
            newString[newStrSize] = c;
            newStrSize++;
        }
    }

    newString[newStrSize] = '\0';
    return newString;
}

int main()
{
    char line[101];
    gets(line);
    int n = atoi(line);

    for (int i = 0; i < n; i++)
    {
        gets(line);
        puts(delete_lowers(line));
    }

    return 0;
}