#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[51];
    int salary;
    char department[31];
} EMPLOYEE;

int cmp(const void *a, const void *b)
{
    const EMPLOYEE *e1 = (const EMPLOYEE *)a;
    const EMPLOYEE *e2 = (const EMPLOYEE *)b;

    if (e1->salary != e2->salary)
    {
        return e2->salary - e1->salary;
    }

    int dept = strcmp(e1->department, e2->department);
    if (dept != 0)
    {
        return dept;
    }

    return strcmp(e1->name, e2->name);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Missing input file arg\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        printf("Cant find input file\n");
        return 2;
    }

    if (argc == 2)
    {
        printf("Missing output file argument\n");
        return 3;
    }

    FILE *temp = fopen(argv[2], "r");
    if (!temp)
    {
        printf("Cant find output file\n");
        fclose(input);
        return 4;
    }

    FILE *output = fopen(argv[2], "w");
    if (!output)
    {
        printf("Cant find output file\n");
        fclose(input);
        return 4;
    }

    char line[92];
    int count = 0;
    EMPLOYEE arr[125];

    while (1)
    {

        fgets(line, sizeof(line), input);

        if (strcmp(line, "END") == 0)
        {
            break;
        }
        
        line[strlen(line) - 1] = '\0';
        char *token = strtok(line, ";");
        if (token != NULL)
            strcpy(arr[count].name, token);

        token = strtok(NULL, ";");
        if (token != NULL)
            arr[count].salary = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL)
            strcpy(arr[count].department, token);

        count++;
    }

    qsort(arr, count, sizeof(EMPLOYEE), cmp);

    for (int i = 0; i < count; i++)
    {
        fprintf(output, "%s;%d;%s\n", arr[i].name, arr[i].salary, arr[i].department);
    }

    fclose(input);
    fclose(output);

    return 0;
}