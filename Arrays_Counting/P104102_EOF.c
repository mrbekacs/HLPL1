#include <stdio.h>
#include <stdlib.h>

int count_of_odds(int *numbers, int length)
{
    int count = 0;

    for (int i=0; i< length; i++)
    {
        int e = numbers[i];

        if (e % 2 == 0)
        {
            count++;
        }
    }

    return count;
}



int main()
{
    int arraySize;
    
    while (scanf("%d", &arraySize) != EOF)
    {
        int *new_array = (int *)malloc(sizeof(int) * arraySize);
        int currentLength = 0;

        for (int j = 0; j < arraySize; j++)
        {
            int newItem;
            scanf("%d", &newItem);

            new_array[currentLength] = newItem;
            currentLength++;
        }

        printf("%d\n", count_of_odds(new_array, arraySize));
    }

    return 0;
}