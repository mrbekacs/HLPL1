#include <stdio.h>
#include <stdlib.h>

int count_of_local_minimums(int *numbers, int length)
{
    int count = 0;

    for ( int i=1; i < length-1; i++)
    {
        if (numbers[i-1] > numbers[i] && numbers[i] < numbers[i+1])
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

    for(int i=0; i < test_cases; i++)
    {
        int arraySize;
        scanf("%d", &arraySize);

        int *newArray = (int *)malloc(sizeof(int) * arraySize);
        int index = 0;

        for(int j=0; j < arraySize; j++)
        {
            int newItem;
            scanf("%d", &newItem);

            newArray[index] = newItem;
            index++;
        }

        printf("%d\n", count_of_local_minimums(newArray, arraySize));
    }

    return 0;

}