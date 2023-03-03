#include <stdio.h>

int main(void)
{
    int week, i;
    printf("How many weeks are you doing Cs50: ");
    scanf("%i", &week);
    double sum, temp;
    for (i = 0; i < week; i++) {
        printf("Time spent in week %i: ", i);
        scanf("%lf", &temp);
        sum += temp;
    }

    printf("Avarage tiem spent in each week: %.1lf hr\n", sum / i);
        
}
