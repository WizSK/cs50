#include <stdio.h>

int ss(int arg[], int lent);

int main(void)
{
    int num[] = {3, 4, 1, 5, 2, 6, 10, 8, 9, 7, '\0'};

    int len;

    // get the len of array
    for (len = 0; num[len] != '\0'; len++)
        ;
    ss(num, 9);

    for (int j = 0; j <= len; j++) {
        printf("%i\n", num[j]);
    }


}


int ss(int arg[], int len)
{
    int small = arg[1];
    int index = 0;
    int i = 0;
    int sind;
    int temp;

    while (1)
    {
        if (index >= len){
            return 0; 
        }

        if (i > len) {
            temp = arg[index];
            arg[index++] = arg[i];
            i = index;
            small = arg[index];
        }
        else {
            printf("%i and small %i\n", arg[i], small);
            if (small > arg[i]){
                small = arg[i];
                sind = i;
            }
            i++;
        }
    }
}
