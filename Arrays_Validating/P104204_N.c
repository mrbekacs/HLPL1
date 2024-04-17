#include <stdio.h>
#include <stdlib.h>

int is_monotone_decreasing(int *numbers, int length)
{
    int result = 1;

    for(int i=0; i < length; i++)
    {
        if (numbers[i] < numbers[i+1])
        {
            return 0;
        }

    }

    return result;
}

int main()
{
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++)
    {
        int arraySize;
        scanf("%d", &arraySize);

        int *newArray = (int *)malloc(sizeof(int) * arraySize);
        int newArrLen = 0;

        for (int j = 0; j < arraySize; j++)
        {
            int newItem;
            scanf("%d", &newItem);

            newArray[newArrLen] = newItem;
            newArrLen++;
        }

        if (is_monotone_decreasing(newArray, arraySize) == 0)
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