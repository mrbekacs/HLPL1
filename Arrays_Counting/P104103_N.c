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
    int test_cases;
    scanf("%d", &test_cases);

    for (int i=0; i < test_cases; i++)
    {
        int arraySize;
        scanf("%d", &arraySize);

        int* newArray = (int*)malloc(sizeof(int) * arraySize);
        int index = 0;

        for (int j=0; j < arraySize; j++)
        {
            int newItem;
            scanf("%d", &newItem);

            newArray[index] = newItem;
            index++;
        }

        printf("%d\n", count_of_primes(newArray, arraySize));

    }

    
    return 0;
}