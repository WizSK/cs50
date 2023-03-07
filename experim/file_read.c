#include <stdio.h>
#define MAX 1000

int main(int argc, char *argv[])
{
   if (argc < 2) {
        printf("./prog file.txt\n");
        return 1;
    }

    // Open the file 
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
        return -1;
    
    int array[MAX];
    fread(array, sizeof(int), MAX, file);
    for (int i = 0; i < MAX; i++)
        printf("%i\n", array[i]);

    fclose(file);
}

