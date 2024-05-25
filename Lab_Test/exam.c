#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[31];
    char toppings[31]; //should be 61
    int price;
}PIZZA;

int cmp(const void* a, const void* b)
{
    const PIZZA* slice1 = (const void *)a;
    const PIZZA* slice2 = (const void *)b;

    int topSort = strcmp(slice2->toppings, slice1->toppings);
    if (topSort != 0)
    {
        return topSort;
    }

    if (slice1->price != slice2->price)
    {
        return slice1->price - slice2->price;
    }

    return strcmp(slice2->name, slice1->name);
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
        printf("Missing the output file\n");
        return 1;
    }

    FILE* temp = fopen(argv[2], "r");

    if(!temp)
    {
        printf("Cant open the output file\n");
        fclose(input);
        return 4;
    }

    FILE* output = fopen(argv[2], "w");

    PIZZA myPizza[151];
    char line[99];
    int count = 0;

    while(fgets(line, sizeof(line), input))
    {
        char* token = strtok(line, ";");
        if (token != NULL) strcpy(myPizza[count].name, token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(myPizza[count].toppings, token);

        token = strtok(NULL, ";");
        if (token != NULL) myPizza[count].price = atoi(token);


        count++;
    }

    qsort(myPizza, count, sizeof(PIZZA), cmp);

    for (int i=0; i<count; i++)
    {
        fprintf(output, "%s;%s;%d\n", myPizza[i].name, myPizza[i].toppings, myPizza[i].price);
    }

    return 0;
}
