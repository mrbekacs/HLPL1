#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *double_lowers(char *original)
{
    char *new = (char *)malloc(sizeof(char) * strlen(original) * 2 + 1);
    int len = 0;

    for (int i = 0; i < strlen(original); i++)
    {
        char c = original[i];

        if (islower(c))
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
    gets(line);
    int n = atoi(line);

    for (int i = 0; i < n; i++)
    {
        gets(line);
        puts(double_lowers(line));
    }

    return 0;
}