#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_odd_digits(char *original)
{
    char *newStr = (char *)malloc(sizeof(char) * strlen(original) + 1);
    int newStrLen = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char cChar = original[i];

        // check digit
        if (strchr("1234567890", cChar) != NULL)
        {
            int d = cChar;
            // if odd, add
            if (d % 2 == 0)
            {
                newStr[newStrLen] = cChar;
                newStrLen++;
            }
        }
        else
        {
            newStr[newStrLen] = cChar;
            newStrLen++;
        }
    }

    newStr[newStrLen] = '\0';
    return newStr;
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

        puts(delete_odd_digits(line));
    }
    
    return 0;
}