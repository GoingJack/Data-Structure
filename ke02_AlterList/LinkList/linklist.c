#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
static pLinkList ApplyNode(ElemType val,pLinkList next)
{
    pLinkList tmp = (pLinkList)malloc(sizeof(LinkList));
    assert(tmp != NULL);
    if(tmp == NULL)
        return NULL;
    tmp->val = val;
    tmp->next = next;

    return tmp;
}
bool Init(pLinkList seq)
{
    seq->next = NULL;
    seq->val = 0;
}
bool Insert_ListHead(pLinkList list,ElemType val)
{
    pLinkList tmp = ApplyNode(val,list->next);
    if(tmp == NULL)
        return false;
    list->next = tmp;
    return true;
}
bool Insert_ListTail(pLinkList list,ElemType val)
{
    pLinkList tmp = list;
    while(tmp != NULL)tmp = tmp-next;
    return Insert_ListHead(tmp,val);
}
bool Insert_ListPos(pLinkList list,ElemType val,int pos)
{
    pLinkList tmp = list;
    for(int i=0;i<pos;i++)
        tmp = tmp->next;
    return Insert_ListHead(tmp,val);
}
void Show(pLinkList list)
{
    pLinkList p = list;
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p = p->next;
    }
}
