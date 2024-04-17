#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int square(int n) 
{
    int s = sqrt(n);

    if (s*s == n)
    {
        return 1;
    } 

    else 
    {
        return 0;
    }
}

int count_of_squares(int* numbers, int length)
{
    int count = 0;

    for (int i=0; i<length; i++)
    {
        int item = numbers[i];

        if(square(item))
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
        if(arraySize == 0)
        {
            return 0;
        }
        
        int *newArray = (int *)malloc(sizeof(int) * arraySize);
        int index = 0;

        for(int i=0; i < arraySize; i++)
        {
            int newItem;
            scanf("%d", &newItem);

            newArray[index] = newItem;
            index++;
        }

        printf("%d\n", count_of_squares(newArray, arraySize));
    }

    return 0;
}