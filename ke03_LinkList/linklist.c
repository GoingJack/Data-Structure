#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "linklist.h"
static pLinkList ApplyNode(ElemType val,pLinkList next)
{
    pLinkList tmp = (pLinkList)malloc(sizeof(LinkList));
    assert(tmp != NULL);
    if(tmp == NULL)
        return NULL;
    tmp->_data = val;
    tmp->_next = next;

    return tmp;
}
bool Init(pLinkList seq)
{
    assert(seq != NULL);
    if(seq == NULL)
        return false;
    seq->_next = NULL;
}
bool Insert_ListHead(pLinkList list,ElemType val)
{
    assert(list != NULL);
    if(list == NULL)
        return false;
    pLinkList tmp = ApplyNode(val,list->_next);
    assert(tmp != NULL);
    if(tmp == NULL)
        return false;
    list->_next = tmp;
    return true;
}
bool Insert_ListTail(pLinkList list,ElemType val)
{
    assert(list != NULL);
    if(list == NULL)
        return false;
    pLinkList tmp = list;
    while(tmp->_next != NULL)tmp = tmp->_next;
    return Insert_ListHead(tmp,val);
}
bool Insert_ListPos(pLinkList list,ElemType val,int pos)
{
    pLinkList tmp = list;
    int i = 0;
    for(;i<pos;i++)
        tmp = tmp->_next;
    return Insert_ListHead(tmp,val);
}
void Show(pLinkList list)
{
    pLinkList p = list->_next;
    while(p!=NULL)
    {
        printf("%d ",p->_data);
        p = p->_next;
    }
    printf("\n+++++++++++++++++++++++++++\n");
}
bool Delete_ListHead(pLinkList list)
{
    assert(list != NULL);
    if(list == NULL)
        return false;
    pLinkList tmp = list->_next;
    list->_next = tmp->_next;
    free(tmp);
}
bool Delete_ListTail(pLinkList list)
{
    assert(list != NULL);
    if(list == NULL)
        return false;
    if(list->_next==NULL)//当前链表为空
        return true;
    pLinkList tmp = list;
    while(1)
    {
        pLinkList cur = tmp->_next;
        if(cur->_next==NULL)
            break;
        tmp = tmp->_next;
    }
    free(tmp->_next);
    tmp->_next=NULL;
    return true;
}
bool Delete_ListPos(pLinkList list,int pos)
{
    assert(list != NULL);
    if(list == NULL)
        return false;
    int i=0;
    pLinkList tmp = list;
    for(;i<pos&&tmp->_next!=NULL;i++)
    {
        tmp=tmp->_next;
    }
    return Delete_ListHead(tmp);
}
void Reverse_List(pLinkList list)
{
    assert(list != NULL);
    if(list == NULL)
        return false;
    pLinkList pre = list;
    pLinkList cur = pre->_next;
    pLinkList save;
    while(1)
    {
        save = cur->_next;
        cur->_next = pre;
        if(save == NULL)
            break;
        pre = cur;
        cur = save;
    }
    pLinkList tmp = list->_next;
    tmp->_next = NULL;
    list->_next = cur;
    return true;
}
void Clear_List(pLinkList list)
{
    assert(NULL != list);
    if(list == NULL)
        return;
    pLinkList save = list->_next;
    pLinkList tmp = save;
    while(tmp != NULL)
    {
        save = tmp->_next;
        free(tmp);
        tmp = save;
    }
    list->_next = NULL;
}
