#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>
#include "cirlist.h"
static CirList ApplyNode(ElemType val,CirList next)
{
    CirList p = (CirList)malloc(sizeof(CNode));
    assert(NULL != p);
    if(p == NULL)
        return NULL;
    p->_data = val;
    if(next)//如果next为空证明当前循环链表只有一个节点
        p->_next = next;
    else
        p->_next = p;
    return p;
}
static bool IsEmpty(CirList list)
{
    return list == NULL;
}
static size_t Length(CirList list)
{
    if(list == NULL)return 0;
    CirList p = list;
    int count = 0;
    while(p->_next != list)
    {
        count++;
        p = p->_next;
    }
    return count + 1;
}

bool Init_List(CirList *list)
{
    assert(NULL != list);
    if(list == NULL)
        return;
    *list = NULL;
    return true;
}

bool Insert_ListTail(CirList *list,ElemType val)
{
    //如果list为空，当前循环链表没有节点
    if(*list==NULL)
    {
        *list = ApplyNode(val,NULL);
        return true;
    }
    //找到循环链表最后一个元素
    CirList p = *list;
    while(p->_next != *list)
        p=p->_next;
    p->_next = ApplyNode(val,p->_next);
    return true;
}
bool Insert_ListHead(CirList *list,ElemType val)
{
    if(*list == NULL)
        return Insert_ListTail(list,val);
    Insert_ListTail(list,val);
    CirList p = *list;
    while(p->_next != *list)
        p = p->_next;
    *list = p;
    return true;
}
bool Insert_ListPos(CirList *list,ElemType val,int pos)
{
    if(*list == NULL)
        return Insert_ListTail(list,val);
    if(pos % Length(*list) == 0)                          
         return Insert_ListTail(list,val);
    if(pos == 0)
        return Insert_ListHead(list,val);
    pos %= Length(*list);
    CirList p = *list;
    while(pos>1)
    {
        p=p->_next;
        pos--;
    }
    p->_next = ApplyNode(val,p->_next);
    return true;
}
void Show(CirList list)
{
    if(list == NULL)
        return;
    CirList p = list;
    while(p->_next != list)
    {
        printf("%d ",p->_data);
        p=p->_next;
    }
    printf("%d \n",p->_data);
}
bool Delete_ListHead(CirList *list)
{
    if(IsEmpty(*list))return false;
    int len = Length(*list);
    CirList p = *list;
    while(p->_next != *list)
        p = p->_next;
    CirList q = *list;
    *list = q->_next;
    p->_next = *list;
    free(q);
    if(len == 1)
        *list = NULL;
    return true;
}
bool Delete_ListPos(CirList *list,int pos)
{
    if(pos == NULL || pos % Length(*list) == 0)
        return Delete_ListHead(list);
    int len = Length(*list);
    CirList p = *list;
    while(pos > 1)
    {
        p = p->_next;
        pos--;
    }
    CirList q = p->_next;
    p->_next = q->_next;
    free(q);

    if(len == 1)
        *list = NULL;

    return true;
}
bool Delete_ListTail(CirList *list)
{
    return Delete_ListPos(list,Length(*list) - 1);
}
