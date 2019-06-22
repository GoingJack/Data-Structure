#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "linklist.h"
int main()
{
    pLinkList head = (pLinkList)malloc(sizeof(LinkList));
    Init(head);
    Insert_ListHead(head,10);
    Show(head);
    Insert_ListTail(head,20);
    Show(head);
    Insert_ListPos(head,30,1);
    Show(head);
    int i=0;
    for(;i<5;i++)
        Insert_ListHead(head,i);
    Show(head);
    //删除
    Delete_ListHead(head);
    printf("delete head\n");
    Show(head);
    //删除尾删
    Delete_ListTail(head);
    printf("delete tail\n");
    Show(head);
    //位置删除
    Delete_ListPos(head,4);
    printf("delete pos 4\n");
    Show(head);
    //逆置
    Reverse_List(head);
    printf("reverse list\n");
    Show(head);
    //清空链表
    Clear_List(head);
    Show(head);

    free(head);
    head=NULL;
    exit(0);
}
