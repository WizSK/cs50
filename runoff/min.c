#include <stdio.h>

// Return the minimum number of votes any remaining candidate has
#define ARR 11
int arr[ARR] = {-100, 1, 2, 3, 4, 5, 6, 7, 8, 0, -1};

int find_min(void);


int main(void) {
    printf("%i\n", find_min());
}
int find_min(void)
{
    // TODO
    int min = 0;
    for (int i = 0; i < ARR; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
