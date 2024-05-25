#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[41];
    int power;
    char type[81];
} POKEMON;

int cmp(const void *a, const void *b)
{
    const POKEMON *toy1 = (const POKEMON *)a;
    const POKEMON *toy2 = (const POKEMON *)b;

    int Thetype = strcmp(toy2->type, toy1->type);
    if (Thetype != 0)
    {
        return Thetype;
    }

    int Thename = strcmp(toy1->name, toy2->name);
    if (Thename != 0)
    {
        return Thename;
    }

    return (toy2->power - toy1->power);
}

int main(int argc, char *argv[])
{
    FILE *input = fopen(argv[1], "r");

    POKEMON MyArray[152];
    int count = 0;
    char line[128];

    while (1)
    {
        fgets(line, sizeof(line), input);

        if (strcmp(line, "END") == 0)
        {
            break;
        }

        line[strlen(line) - 1] = '\0';

        char *token = strtok(line, ",");
        if (token != NULL)
            strcpy(MyArray[count].name, token);

        token = strtok(NULL, ",");
        if (token != NULL)
            MyArray[count].power = atoi(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(MyArray[count].type, token);

        count++;
    }

    qsort(MyArray, count, sizeof(POKEMON), cmp);

    FILE *output = fopen(argv[2], "w");

    for (int i = 0; i < count; i++)
    {
        fprintf(output, "%s,%d,%s\n", MyArray[i].name, MyArray[i].power, MyArray[i].type);
    }

    return 0;
}   