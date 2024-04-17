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