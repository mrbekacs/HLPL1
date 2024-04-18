#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *double_even_digits(char *original)
{
    char *new = (char *)malloc(sizeof(char) * strlen(original) * 2 + 1);
    int len = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (isdigit(c) && c % 2 == 0)
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
    while (gets(line) != NULL)
    {
        puts(double_even_digits(line));
    }

    return 0;
}