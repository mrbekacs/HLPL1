#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_odd_digits(char *original)
{
    char *newString = (char *)malloc(sizeof(char) * strlen(original) + 1);
    int newStrSize = 0;

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
                newString[newStrSize] = cChar;
                newStrSize++;
            }
        }
        else
        {
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
    gets(line);
    int n = atoi(line);

    for (int i = 0; i < n; i++)
    {
        gets(line);

        puts(delete_odd_digits(line));
    }

    return 0;
}