#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char world[31];
    int height;
    int time;

}ROLLER_COASTER;

int cmp(const void* a, const void* b)
{
    const ROLLER_COASTER* coaster1 = (const ROLLER_COASTER*)a;
    const ROLLER_COASTER* coaster2 = (const ROLLER_COASTER*)b;

    if (coaster1->time != coaster2->time)
    {
        return coaster1->time - coaster2->time;
    }

    if (coaster1->height != coaster2->height)
    {
        return coaster2->height - coaster1->height;
    }

    return strcmp(coaster1->name, coaster2->name);

}

int main(int argc, char* argv[])
{
    char line[102];
    ROLLER_COASTER myCoaster[20];
    int count = 0;
    int n;

    if (argc == 1)
    {
        printf("No input file\n");
        return 1;
    }

    FILE* input = fopen(argv[1], "r");

    if (!input)
    {
        printf("Couln't open the file\n");
        return 2;
    }

    if (argc == 2)
    {
        printf("No output file\n");
        return 3;
    }

    FILE* output = fopen(argv[2], "w");

    if (!output)
    {
        printf("Couldn't open output file\n");
    }

    fgets(line, sizeof(line), input);
    n = atoi(line);

    for (int i=0; i<n; i++)
    {
        fgets(line, sizeof(line), input);

        char* token = strtok(line, ";");
        if (token != NULL) strcpy(myCoaster[count].name, token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(myCoaster[count].world, token);

        token = strtok(NULL, ";");
        if (token != NULL) myCoaster[count].height = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL) myCoaster[count].time = atoi(token);

        count++;
    }

    qsort(myCoaster, count, sizeof(ROLLER_COASTER), cmp);

    for ( int i=0; i<n; i++)
    {
        fprintf(output, "%s;%s;%d;%d\n", myCoaster[i].name, myCoaster[i].world, myCoaster[i].height, myCoaster[i].time);
    }

    fclose(input);
    fclose(output);

    return 0;

}