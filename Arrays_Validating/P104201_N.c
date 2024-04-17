#include <stdio.h>
#include <stdlib.h>

int is_palindrome(int *numbers, int length)
{
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        if (numbers[start] != numbers[end])
        {
            return 0;
        }

        start++;
        end--;
    }
    
    return 1;
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

        if (is_palindrome(newArray, arraySize) == 0)
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