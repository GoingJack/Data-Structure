#include <stdio.h>
#include <stdbool.h>
#include "cirlist.h"

int main()
{
    CirList list = (CirList)malloc(sizeof(CNode));
    Init_List(&list);

    Insert_ListHead(&list,10);
    Show(list);

    Insert_ListTail(&list,11);
    Show(list);

    Insert_ListHead(&list,20);
    Show(list);

    Insert_ListHead(&list,30);
    Show(list);

    Insert_ListPos(&list,40,2);
    Show(list);

    Insert_ListPos(&list,50,0);
    Show(list);

    Insert_ListPos(&list,60,12);
    Show(list);

    Insert_ListPos(&list,70,15);
    Show(list);

    Delete_ListHead(&list);
    Show(list);

    Delete_ListTail(&list);
    Show(list);

    Delete_ListPos(&list,3);
    Show(list);
    return 0;
}
