#include <stdio.h>
#include <stdlib.h>

int count_of_odds(int *numbers, int length)
{
    int count = 0;

    for (int i=0; i< length; i++)
    {
        int e = numbers[i];

        if (e % 2 != 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int arraySize;
    while (1)
    {
        scanf("%d", &arraySize);
        
        if (arraySize == 0)
        {
            return 0;
        }
        
        int *new_array = (int *)malloc(sizeof(int) * arraySize);
        int index = 0;

        for (int j=0; j < arraySize; j++)
        {
            int newItem;
            scanf("%d", &newItem);

            new_array[index] = newItem;
            index++;
        }

        printf("%d\n", count_of_odds(new_array, arraySize));
    }
    return 0;
}