#include <stdio.h>
#include <stdlib.h>

int has_matching_parity(int *numbers, int length)
{
    int result = 1;

    for (int i = 0; i < length; i++)
    {
        if (!(((i % 2 == 0) && (numbers[i] % 2 == 0)) || ((i % 2 != 0) && (numbers[i] % 2 != 0))))
        {
            result = 0;
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

        int *newArr = (int *)malloc(sizeof(int) * arraySize);
        int newArrLen = 0;

        for (int j = 0; j < arraySize; j++)
        {
            int newItem;
            scanf("%d", &newItem);

            newArr[newArrLen] = newItem;
            newArrLen++;
        }

        if (has_matching_parity(newArr, arraySize) == 0)
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