#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[101];
    char author[51];
    int price;
}BOOKS;

int cmp(const void* a, const void* b)
{
    const BOOKS* kitap1 = (const BOOKS *)a;
    const BOOKS* kitap2 = (const BOOKS *)b;

    if (kitap1->price != kitap2->price)
    {
        return kitap2->price - kitap1->price;
    }

    int autSort = strcmp(kitap1->author, kitap2->author);

    if (autSort != 0)
    {
        return autSort;
    }

    return strcmp(kitap1->title, kitap2->title);

}

int main(int argc, char* argv[])
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
        return 3;
    }

    FILE* temp = fopen(argv[2], "r");

    if (!temp)
    {
        printf("Cant open the output file\n");
        fclose(input);
        return 4;
    }

    FILE* output = fopen(argv[2], "w");

    BOOKS myArray[125];
    char line[160];
    int count = 0;

    while(fgets(line, sizeof(line), input))
    {
        line[strlen(line) - 1] = '\0';
        char *token = strtok(line, ";");
        if (token != NULL) strcpy(myArray[count].title, token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(myArray[count].author, token);

        token = strtok(NULL, ";");
        if (token != NULL) myArray[count].price = atoi(token);

        count++;
    }

    qsort(myArray, count, sizeof(BOOKS), cmp);

    for (int i=0; i<count; i++)
    {
        fprintf(output, "%s;%s;%d\n", myArray[i].title, myArray[i].author, myArray[i].price);
    }

    return 0;

}