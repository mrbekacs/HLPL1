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
    
    while (1)
    {
        scanf("%d", &arraySize);

        if(arraySize == 0)
        {
            return 0;
        }

        int *newArray = (int *)malloc(sizeof(int) * arraySize);
        int index = 0;

        for (int j=0; j < arraySize; j++)
        {
            int newItem;
            scanf("%d", &newItem);

            newArray[index] = newItem;
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