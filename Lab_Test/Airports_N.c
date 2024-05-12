#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[31];
    char city[31];
    int runways;
    int time;

}AIRPORT;

int cmp(const void* a, const void* b)
{
    const AIRPORT* airport1 = (const AIRPORT*)a;
    const AIRPORT* airport2 = (const AIRPORT*)b;

    if (airport1->runways != airport2->runways)
    {
        return airport2->runways - airport1->runways;
    }

    if (airport1->time != airport2->time)
    {
        return airport2->time - airport1->time;
    }

    return strcmp(airport1->name, airport2->name);

}

int main(int argc, char* argv[])
{
    char line[102];
    AIRPORT myAirports[20];
    int count = 0;
    int n;

    if(argc==1)
    {
        printf("No input file\n");
        return 1;
    }

    FILE* input = fopen(argv[1], "r");

    if (!input)
    {
        printf("Couldn't open input file\n");
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
        return 4;
    }

    fgets(line, sizeof(line), input);
    n = atoi(line);

    for (int i=0; i<n; i++)
    {
        fgets(line, sizeof(line), input);

        char* token = strtok(line, ";");
        if (token != NULL) strcpy(myAirports[count].name, token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(myAirports[count].city, token);

        token = strtok(NULL, ";");
        if (token !=NULL) myAirports[count].runways = atoi(token);

        token = strtok(NULL, ";");
        if (token !=NULL) myAirports[count].time = atoi(token);

        count++;
    }

    qsort(myAirports, count, sizeof(AIRPORT), cmp);

    for (int i=0; i<count; i++)
    {
        fprintf(output, "%s;%s;%d;%d\n", myAirports[i].name, myAirports[i].city, myAirports[i].runways, myAirports[i].time);
    }

    fclose(input);
    fclose(output);

    return 0;
}