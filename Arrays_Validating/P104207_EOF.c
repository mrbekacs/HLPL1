#include <stdio.h>
#include <stdlib.h>

int is_twisting(int *numbers, int length)
{
    int result = 1;

    for (int i = 1; i < length - 1; i++)
    {
        // if curr ele > 0
        if (numbers[i] > 0)
        {
            if (numbers[i - 1] <= 0 && numbers[i + 1] <= 0)
            {
                result = 1;
            }
            else
            {
                result = 0;
                return result;
            }
        }

        // if curr ele < 0
        if (numbers[i] < 0)
        {
            if (numbers[i - 1] >= 0 && numbers[i + 1] >= 0)
            {
                result = 1;
            }
            else
            {
                result = 0;
                return result;
            }
        }

        if (numbers[i] == 0 && numbers[i + 1] == 0 && numbers[i - 1] == 0)
        {
            result = 0;
            return result;
        }
    }

    return result;
}

int main()
{
    int arraySize;

    while(scanf("%d", &arraySize) != EOF)
    {
        int *newArray = (int *)malloc(sizeof(int) * arraySize);
        int index = 0;

        for (int i=0; i < arraySize; i++)
        {
            int item;
            scanf("%d", &item);

            newArray[index] = item;
            index++;
        }

        if (is_twisting(newArray, arraySize))
        {
            printf("True\n");
        }
        else
        {
            printf("False\n");
        }
        
    }
    
    return 0;
}