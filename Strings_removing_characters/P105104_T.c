#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_digits(char *original)
{
    char *newString = (char *)malloc((sizeof(char) * strlen(original)) + 1);
    int newStrSize = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char cChar = original[i];

        if (strchr("1234567890", cChar) == NULL)
        {
            // not a digit, add
            newString[newStrSize] = cChar;
            newStrSize++;
        }
    }

    newString[newStrSize] = '\0';
    return newString;
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

        puts(delete_digits(line));
    }
    
    return 0;
}