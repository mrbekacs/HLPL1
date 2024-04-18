#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *double_digits(char *original)
{
    char *new = (char *)malloc(sizeof(char) * strlen(original) * 2 + 1);
    int newLen = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (!isdigit(c))
        {
            new[newLen] = c;
            newLen++;
        }
        else
        {
            new[newLen] = c;
            newLen++;
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
        puts(double_digits(line));
    }

    return 0;
}