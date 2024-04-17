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
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int len;
        scanf("%d", &len);

        int *newArr = (int *)malloc(sizeof(int) * len);
        int newArrLen = 0;

        for (int j = 0; j < len; j++)
        {
            int new;
            scanf("%d", &new);

            newArr[newArrLen] = new;
            newArrLen++;
        }

        if (is_twisting(newArr, newArrLen))
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