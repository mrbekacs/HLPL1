#include <stdio.h>
#include <stdlib.h>

int is_monotone_increasing(int *numbers, int length)
{
    int result = 1;

    for(int i=0; i < length; i++)
    {
        if (numbers[i] >= numbers[i+1])
        {
            return 0;
        }

    }

    return result;
}

int main()
{
    int arraySize;
    while (scanf("%d", &arraySize) != EOF)
    {
        int *newArray = (int *)malloc(sizeof(int) * arraySize);
        int index = 0;

        for (int j = 0; j < arraySize; j++)
        {
            int new;
            scanf("%d", &new);

            newArray[index] = new;
            index++;
        }

        if (is_monotone_increasing(newArray, arraySize) == 0)
        {
            printf("False\n");
        }
        else
        {
            printf("True\n");
        }
    }

    return 0;
}