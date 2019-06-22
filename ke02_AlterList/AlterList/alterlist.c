#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "alterlist.h"
void Init(pAlterList seq,int size)
{
    seq->_pdata = (ElemType *)malloc(sizeof(ElemType)*size);
    seq->_size = size;
    seq->_count = 0;
}
void Insert_Tail(pAlterList seq,ElemType val)
{
    if(IsFull(seq))
    {
        if(!Expand(seq))
            return;
    }
    seq->_pdata[seq->_count]=val;
    seq->_count++;

}
void Insert_Head(pAlterList seq,ElemType val)
{
    if(IsFull(seq))
    {
        if(!Expand(seq))
            return;
    }
    int i = seq->_count - 1;
    for(;i>=0;i--)
    {
        seq->_pdata[i+1] = seq->_pdata[i];
    }
    seq->_pdata[0] = val;
    seq->_count++;
}
void Insert_Pos(pAlterList seq,ElemType val,int pos)
{
    if(IsFull(seq))
    {
        if(!Expand(seq))
            return;
    }
    if(pos > seq->_count)
        pos == seq->_count;
    if(pos == seq->_count)
        Insert_Tail(seq,val);
    int i = seq->_count;
    for(;i>=pos;i--)
        seq->_pdata[i+1]=seq->_pdata[i];
    seq->_pdata[pos] = val;
    seq->_count++;
}
void Show_List(pAlterList seq)
{
    int i=0;
    printf("\n*************************\n");
    for(;i<seq->_count;i++)
        printf("%d ",seq->_pdata[i]);
    printf("\n*************************\n");
    
}
bool Expand(pAlterList seq)
{
    if(seq == NULL)
        return false;
    seq->_size *= 2;
    int i=0;
    ElemType *tmp = (ElemType*)malloc(sizeof(ElemType)*seq->_size);
    for(i;i<seq->_count;i++)
    {
        tmp[i] = seq->_pdata[i];
    }
    free(seq->_pdata);
    seq->_pdata = tmp;
    return true;
}
void Clear_List(pAlterList seq)
{
    seq->_count = 0;
}
bool IsFull(pAlterList seq)
{
    return seq->_count == seq->_size;
}
bool IsEmpty(pAlterList seq)
{
    return seq->_count == 0;
}
static void Swap(ElemType *elem1,ElemType *elem2)
{
    *elem1 = *elem1 ^ *elem2;
    *elem2 = *elem1 ^ *elem2;
    *elem1 = *elem1 ^ *elem2;
}
void Reverse_List(pAlterList seq)
{
    assert(seq->_count > 1);
    int i=0;
    int j=seq->_count - 1;
    for(;i!=j;i++,j--)
    {
        Swap(&seq->_pdata[i],&seq->_pdata[j]);
    }
}
void DeleteList_Head(pAlterList seq)
{
    assert(seq!=NULL);
    if(seq == NULL)
        return;
    if(IsEmpty(seq))
        return;
    int i=1;
    for(;i<seq->_count;i++)
        seq->_pdata[i-1]=seq->_pdata[i];
    seq->_count--;
}
void DeleteList_Tail(pAlterList seq)
{
    assert(seq != NULL);
    if(seq == NULL)
        return;
    if(IsEmpty(seq))
        return;
    seq->_count--;
}
void DeleteList_Pos(pAlterList seq,int pos)
{
    assert(seq != NULL);
    if(seq == NULL)
        return;
    if(IsEmpty(seq))
        return;
    int i = pos;
    for(;i<seq->_count - 1;i++)
        seq->_pdata[i]=seq->_pdata[i+1];
    seq->_count--;
}
bool SearchList_Pos(pAlterList seq,int pos,ElemType *out)
{
    assert(seq != NULL);
    if(seq == NULL)
        return false;
    if(seq->_count <= 0)
        return false;
    if(pos >= seq->_count)
        pos = seq->_count-1;
    *out = seq->_pdata[pos];
    return true;
}
bool SearchList_Val(pAlterList seq,int *pos,ElemType in)
{
    assert(seq != NULL);
    if(seq == NULL)
        return false;
    if(seq->_count <= 0)
        return false;
    int i = 0;
    for(;i<seq->_count;i++)
    {
        if(seq->_pdata[i] == in)
        {
            *pos = i;
            return true;
        }
    }
    return false;
}
bool SearchList_Locate(pAlterList seq,ElemType in,
        bool (*Compare)(ElemType,ElemType),int *pos)
{

    assert(seq != NULL);
    if(seq == NULL)
        return false;
    if(seq->_count <= 0)
        return false;
    int i = 0;
    for(;i<seq->_count;i++)
    {
        if(Compare(seq->_pdata[i],in))
        {
            *pos = i;
            return true;
        }
    }
    return false;
}
void ClearList(pAlterList seq)
{
    assert(seq != NULL);
    if(seq == NULL)
        return;
    seq->_count = 0;
}
void DestoryList(pAlterList seq)
{
    assert(seq != NULL);
    free(seq->_pdata);
    seq->_pdata=NULL;
    seq->_count = 0;
    seq->_size=0;
}
