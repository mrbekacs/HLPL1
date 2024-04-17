#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_consonants(char *original)
{
    char *newS = (char *)malloc((sizeof(char) * strlen(original)) + 1);
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

    newS[newSLen] = '\0';
    return newS;
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

        puts(delete_consonants(line));
    }
    
    return 0;
}