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
        
        if (has_matching_parity(newArray, arraySize) == 0)
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