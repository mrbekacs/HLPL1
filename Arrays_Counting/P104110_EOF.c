#include <stdio.h>
#include <stdlib.h>

int count_of_increasing_neighbours(int *numbers, int length)
{
    int count = 0;

    for (int i = 0; i < length - 1; i++)
    {
        if (numbers[i] < numbers[i + 1])
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
        int *newArray = (int *)malloc(sizeof(int) * arraySize);
        int index = 0;

        for (int j = 0; j < arraySize; j++)
        {
            int new;
            scanf("%d", &new);

            newArray[index] = new;
            index++;
        }

        printf("%d\n", count_of_increasing_neighbours(newArray, arraySize));
    }

    return 0;
}