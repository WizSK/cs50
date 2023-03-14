#include <bits/pthreadtypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;
    /*
    t->num = 3;
    t->next = NULL;

    list = t;

    t = malloc(sizeof(node));
    if (t == NULL)
        return 1;
    t->num = 4;
    t->next = list;
    list = t;
    for (node *i = list; i->next != NULL; i = i->next)
    {
        printf("%i\n", i->num);
    }

    */

    for (int i = 1; i < argc; i++)
    {
        node *tmp = malloc(sizeof(node));
        tmp->num = atoi(argv[i]);
        tmp->next = list;
        list = tmp;
    }



    node *temp = list;
    while (temp!= NULL)
    {
        printf("%i\n", temp->num);
        node *t = temp;
        temp = temp->next;
    }

    temp = list;
    while (temp != NULL)
    {
        node *tm = temp->next;
        free(temp);
        temp = tm;
    }
    // node *ptr = list;
    // while (ptr != NULL)
    // {
    //     node *next = ptr->next;
    //     free(ptr);
    //     ptr = next;
    // }
}
    

