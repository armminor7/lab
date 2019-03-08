#include <math.h>
#include <ctype.h>
#include <stdio.h>

void removeTarget(int *array, int size, int target);

int main()
{
    int num, count, target, i;

    scanf("%d", &num);
    scanf("%d", &count);

    int numbers[num];
    int *numbersPtr = &numbers[0];

    // initialize array numbers from 1 to num by numbersPtr
    for (i=1; i<=num; i++, numbersPtr++) {
       *numbersPtr = i;
    }

    // loop through count
    for (i=0; i<count; i++) {
        scanf("%d", &target);
        removeTarget(&numbers[0], num, target);
    }

    numbersPtr = &numbers[0];

    // print elements in numbers using numberPtr
    for (i=1; i<=num; i++, numbersPtr++) {
           printf("%d ", *numbersPtr);
    }
    puts("");
}

// remove target from array by pointer *array and append last position by 0
void removeTarget(int *array, int size, int target)
{
    int i;
    for(i=0; i<size; i++)
    {
        if (*array == target)
        {
            for(i; i<size; i++)
            {
                *array = *(array+1);
                array++;
            }
            *(array-1) = 0;
            return;
        }
        array++;
    }
    return;
}