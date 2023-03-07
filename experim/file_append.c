#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("./prog file.txt\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
        return -1;
    printf("Give some comma separated values: ");
    char val[100];
    scanf("%s", val);
    fprintf(file, "%s", val);
    fclose(file);
}

