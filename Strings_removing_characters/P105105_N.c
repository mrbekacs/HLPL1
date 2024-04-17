#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_vowels(char *original)
{
    char *new = (char *)malloc(sizeof(char) * strlen(original) + 1);
    int newLen = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (strchr("aoeuiAOEUI", c) == NULL)
        {
            // not vowel
            new[newLen] = c;
            newLen++;
        }
    }

    new[newLen] = '\0';
    return new;
}

int main()
{
    char line[101];
    gets(line);
    int n = atoi(line);

    for (int i = 0; i < n; i++)
    {
        gets(line);

        puts(delete_vowels(line));
    }

    return 0;
}