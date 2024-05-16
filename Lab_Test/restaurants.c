#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[101];
    char cuisine[51];
    int rating;
}RESTAURANT;

int cmp(const void *a, const void *b)
{
    const RESTAURANT *etterem1 = (const RESTAURANT *)a;
    const RESTAURANT *etterem2 = (const RESTAURANT *)b;

    if (etterem1->rating != etterem2->rating)
    {
        return etterem2->rating - etterem1->rating;
    }

    int Csort = strcmp(etterem2->cuisine, etterem1->cuisine);
    if (Csort != 0)
    {
        return Csort;
    }

    return strcmp(etterem1->name, etterem2->name);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Missing the input file\n");
        return 1;
    }

    FILE* input = fopen(argv[1], "r");

    if (!input)
    {
        printf("Cant open the input file\n");
        return 2;
    }

    if (argc == 2)
    {
        printf("Missing the output file");
        return 3;
    }

    FILE* temp = fopen(argv[2], "r");

    if(!temp)
    {
        printf("Cant open the output file");
        return 4;
    }

    FILE* output = fopen(argv[2], "w");

    if (!output)
    {
        printf("Cant find output file\n");
        fclose(input);
        return 4;
    }

    RESTAURANT myEtterem[125];
    char line[157];
    int count = 0;

    while (fgets(line, sizeof(line), input))
    {
        char* token = strtok(line, ";");
        if (token != NULL) strcpy(myEtterem[count].name, token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(myEtterem[count].cuisine, token);

        token = strtok(NULL, ";");
        if (token != NULL) myEtterem[count].rating = atoi(token);

        count++;
    }

    qsort(myEtterem, count, sizeof(RESTAURANT), cmp);

    for (int i=0; i<count; i++)
    {
        fprintf(output, "%s;%s;%d\n", myEtterem[i].name, myEtterem[i].cuisine, myEtterem[i].rating);    
    }

    fclose(input);
    fclose(output);

    return 0;

}