#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    char code[6];
    char name[51];
    char theme[31];
    int bricks;
}LEGO_SET;

int cmp(const void* a, const void* b)
{
    const LEGO_SET *lego1 = (const LEGO_SET*)a;
    const LEGO_SET *lego2 = (const LEGO_SET*)b;

    if (lego1->bricks != lego2->bricks)
    {
        return lego2->bricks - lego1->bricks;
    }

    int themeSort = strcmp(lego1->theme, lego2->theme);
    if (themeSort != 0)
    {
        return themeSort;
    }

    int nameSort = strcmp(lego1->name, lego2->name);
    if (nameSort != 0)
    {
        return nameSort;
    }

    int icode1 = atoi(lego1->code);
    int icode2 = atoi(lego2->code);
    return icode1 - icode2;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Missing input argument");
        return 1;
    }

    if (argc < 3)
    {
        fprintf(stderr, "Missing output argument");
        return 3;
    }

    FILE* input = fopen(argv[1], "r");

    if (!input)
    {
        fprintf(stderr, "Cant find input file");
        return 2;
    }

    FILE *temp = fopen(argv[2], "r");
    if (!temp)
    {
        fclose(input);
        fprintf(stderr, "Cant find output file");
        return 4;
    }

    FILE *output = fopen(argv[2], "w");

    LEGO_SET arr[30];
    char line[202];
    int count = 0;
    int n;

    while (1)
    {
        fgets(line, sizeof(line), input);
        if (strcmp(line, "END") == 0)
        {
            break;
        }
        char *token = strtok(line, ";");
        if (token != NULL) strcpy(arr[count].code, token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(arr[count].name, token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(arr[count].theme, token);

        token = strtok(NULL, ";");
        if (token != NULL) arr[count].bricks = atoi(token);

        count++;
    }

    qsort(arr, count, sizeof(LEGO_SET), cmp);

    for (int i = 0; i < count; i++)
    {
        // atoi(arr[i].code) IMPORTANT!!!
        fprintf(output, "%d;%s;%s;%d\n", atoi(arr[i].code), arr[i].name, arr[i].theme, arr[i].bricks);
    }

    return 0;
}