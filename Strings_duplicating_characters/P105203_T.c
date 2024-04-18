#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *double_uppers(char *original)
{
    char *new = (char *)malloc(sizeof(char) * strlen(original) * 2 + 1);
    int len = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (isupper(c))
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

    while (1)
    {
        gets(line);
        if (strcmp(line, "") == 0)
        {
            return 0;
        }

        puts(double_uppers(line));
    }

    return 0;
}
