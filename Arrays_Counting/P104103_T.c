#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num)
{
    int sRoot = sqrt(num);

    for (int i = 2; i <= sRoot; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int count_of_primes(int *numbers, int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        int item = numbers[i];

        if (isPrime(item))
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

        int* newArray = (int*) malloc(sizeof(int) * arraySize);
        int newLen = 0;

        for (int i = 0; i < arraySize; i++)
        {
            int newItem;
            scanf("%d", &newItem);

            newArray[newLen] = newItem;
            newLen++;
        }
        printf("%d\n", count_of_primes(newArray, newLen));
    }

    return 0;
}