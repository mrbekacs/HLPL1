#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char world[31];
    int height;
    int time;
} ROLLER_COASTER;

int cmp(const void *a, const void *b)
{
    const ROLLER_COASTER *coaster1 = (const ROLLER_COASTER *)a;
    const ROLLER_COASTER *coaster2 = (const ROLLER_COASTER *)b;

    if (coaster1->time != coaster2->time)
        return coaster1->time - coaster2->time;

    if (coaster1->height != coaster2->height)
        return coaster2->height - coaster1->height;

    return strcmp(coaster1->name, coaster2->name);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Error: Missing command-line arguments (Missing input)\n");
        return 1;
    }

    if (argc < 3)
    {
        fprintf(stderr, "Error: Missing command-line arguments (Missing output)\n");
        return 3;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        fprintf(stderr, "Error: Cannot open input file\n");
        return 2;
    }

    FILE *temp = fopen(argv[2], "r");
    if (!temp)
    {
        fclose(input);
        fprintf(stderr, "Error: Cannot open output file\n");
        return 4;
    }
    fclose(temp);

    FILE *output = fopen(argv[2], "w");
    if (!output)
    {
        fclose(input);
        fprintf(stderr, "Error: Cannot open output file\n");
        return 4;
    }

    ROLLER_COASTER myCoaster[20];
    char line[102];
    int count = 0;

    while (fgets(line, sizeof(line), input))
    {
        char *token = strtok(line, ";");
        if (token != NULL)
            strcpy(myCoaster[count].name, token);

        token = strtok(NULL, ";");
        if (token != NULL)
            strcpy(myCoaster[count].world, token);

        token = strtok(NULL, ";");
        if (token != NULL) myCoaster[count].height = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL) myCoaster[count].time = atoi(token);

        count++;
    }

    qsort(myCoaster, count, sizeof(ROLLER_COASTER), cmp);

    for (int i = 0; i < count; i++)
    {
        fprintf(output, "%s;%s;%d;%d\n",
                myCoaster[i].name, myCoaster[i].world, myCoaster[i].height, myCoaster[i].time);
    }

    fclose(input);
    fclose(output);

    return 0;
}