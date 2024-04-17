#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_consonants(char *original)
{
    char *newS = (char *)calloc(strlen(original), sizeof(char));
    int newSLen = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char cChar = original[i];

        if (strchr("aoieuAOIEU1234567890 ", cChar) != NULL)
        {
            // is a vowel
            newS[newSLen] = cChar;
            newSLen++;
        }
    }

    return newS;
}

int main()
{
    char line[101];
    gets(line);
    int n = atoi(line);

    for (int i = 0; i < n; i++)
    {
        gets(line);

        puts(delete_consonants(line));
    }

    return 0;
}