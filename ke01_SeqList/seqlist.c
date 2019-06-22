#include "seqlist.h"
#include <stdio.h>
#include <assert.h>
static bool ListisEmpty(pSeqList seq)
{
    assert(seq != NULL);
    if(seq == NULL)
        return true;
    return false;
}

bool InitList_Sq(pSeqList seq)
{
    if(ListisEmpty(seq))
        return false;
    seq->count = 0;

    return true;
}
static bool ListisFull(pSeqList seq)
{
    if(seq->count >= LENGTH)
        return true;
    return false;
}
void InsertList_SqOfHead(pSeqList seq,ElemType val)
{

    if(ListisFull(seq))
        return;
    int i = seq->count;
    for(;i>=0;i--)
    {
        seq->data[i]=seq->data[i - 1];
    }
    seq->data[0]=val;
    seq->count++;
}
void InsertList_SqOfTail(pSeqList seq,ElemType val)
{
    if(ListisFull(seq))
        return;
    seq->data[seq->count]=val;
    seq->count++;
}
void InsertList_SqOfPos(pSeqList seq,ElemType val,int pos)
{
    if(ListisFull(seq))
        return;
    if(pos > seq->count || pos < 0)
        return;
    int i=seq->count;

    for(;i>pos;i--)
        seq->data[i]=seq->data[i-1];
    seq->data[pos]=val;
    seq->count++;
}
void ShowList_Sq(pSeqList seq)
{
    printf("\n");
    int i=0;
    for(;i<seq->count;i++)
        printf("%d ",seq->data[i]);
    printf("\n");
}
void DeleteList_SqOfHead(pSeqList seq)
{
    if(ListisEmpty(seq))
        return;
    int i = 1;
    for(;i<seq->count;i++)
        seq->data[i-1]=seq->data[i];
    seq->count--;
}
void DeleteList_SqOfTail(pSeqList seq)
{
    if(ListisEmpty(seq))
        return;
    seq->count--;
}
void DeleteList_SqOfPos(pSeqList seq,int pos)
{
    if(ListisEmpty(seq))
        return;
    if(pos < 0 || pos > LENGTH)
        return;
    if(pos > seq->count)
        pos = seq->count;

    if(pos == LENGTH - 1)
    {
        seq->count--;
        return;
    }
    if(pos == 0)
    {
        DeleteList_SqOfHead(seq);
        return;
    }
    int i = pos;
    // 1 2 3 4 5
    for(;i<seq->count-1;i++)
        seq->data[i]=seq->data[i+1];
    seq->count--;
}
void ClearList_Sq(pSeqList seq)
{
    seq->count = 0;
}
void ReverseList_Sq(pSeqList seq,void(*Swap)(ElemType*,ElemType*))
{
    if(seq->count<=1)
        return;
    int i = 0;
    int j = seq->count - 1;
    for(;i < j;i++,j--)
    {
        Swap(&seq->data[i],&seq->data[j]);
    }
}
int FindList_SqOfVal(pSeqList seq,ElemType val)
{
    if(ListisEmpty(seq))
        return;
    int i=0;
    for(;i<seq->count;i++)
    {
        if(seq->data[i]==val)
        {
            return i;
        }
    }
    return -1;
}
bool FindList_SqOfPos(pSeqList seq,int pos,ElemType *val)
{
    if(ListisEmpty(seq))
        return false;
    if(pos<0||pos>=seq->count)
        return false;
    *val = seq->data[pos];
    return true;
}
//这个函数用于不确定比较的数据元素的类型的方法，需要用户提供相关
//比较函数 返回值为数组下标
int FindList_SqOfLocate(pSeqList seq,ElemType val,
        bool(*compare)(ElemType,ElemType))
{
    if(ListisEmpty(seq))
        return -1;
    int i=0;
    for(;i<seq->count;i++)
    {
        if(compare(seq->data[i],val))
            return i;
    }
    return -1;
}
