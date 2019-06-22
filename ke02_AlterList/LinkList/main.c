#include <stdio.h>
#include <stdbool.h>
#include "linklist.h"
int main()
{
    LinkList head;
    Init(&head);
    Insert_ListHead(&head,10);
    Show(&head);
    return 0;
}
