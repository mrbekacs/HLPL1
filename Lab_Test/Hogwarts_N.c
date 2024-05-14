#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[16];
    int score;
    int wins;
}HOUSE;

int cmp(const void *a, const void *b)
{
    const HOUSE *house1 = (const HOUSE *)a;
    const HOUSE *house2 = (const HOUSE *)b;

    if (house1->score != house2->score)
    {
        return house2->score - house1->score;
    }

    if (house1->wins != house2->wins)
    {
        return house1->wins - house2->wins;
    }

    return strcmp(house1->name, house2->name);
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
        fprintf(stderr, "Missing the output argument");
        return 3;
    }

    FILE* input = fopen(argv[1], "r");
    if (!input)
    {
        fprintf(stderr, "Can't find input file");
        return 2;
    }

    FILE* temp = fopen(argv[1], "r");
    if (!temp)
    {
        fclose(input);
        fprintf(stderr, "Cant find output file");
        return 4;
    }

    FILE* output = fopen(argv[2], "w");

    HOUSE myHouse[20];
    int count = 0;
    int n;
    char line[120];

    if(fgets(line, sizeof(line), input) != NULL)
    {
        n = atoi(line);
    }

    for (int i=0; i<n; i++)
    {
        fgets(line, sizeof(line), input);

        char* token = strtok(line, ";");
        if (token != NULL) strcpy(myHouse[count].name, token);

        token = strtok(NULL, ";");
        if (token != NULL) myHouse[count].score = atoi(token);

        token = strtok(NULL, ";");
        if (token !=NULL) myHouse[count].wins = atoi(token);

        count++;
    }

    qsort(myHouse, count, sizeof(HOUSE), cmp);

    for (int i=0; i<count; i++)
    {
        fprintf(output, "%s;%d;%d\n", myHouse[i].name, myHouse[i].score, myHouse[i].wins);
    }

    return 0;
}