#include <stdio.h>
#include <stdlib.h>

int count_of_local_maximum(int *numbers, int length)
{
    int count = 0;

    for ( int i=1; i < length-1; i++)
    {
        if (numbers[i-1] < numbers[i] && numbers[i] > numbers[i+1])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int arraySize;

    while(1)
    {
        scanf("%d", &arraySize);

        if(arraySize == 0)
        {
            return 0;
        }

        int *newArray = (int *)malloc(sizeof(int) * arraySize);
        int index = 0;

        for(int j=0; j < arraySize; j++)
        {
            int newItem;
            scanf("%d", &newItem);

            newArray[index] = newItem;
            index++;
        }

        printf("%d\n", count_of_local_maximum(newArray, arraySize));
    }

    return 0;
}