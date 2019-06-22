#ifndef __SEQLIST_H
#define __SEQLIST_H
#include <stdbool.h>
typedef int ElemType;
#define LENGTH 10
typedef struct SeqList
{
    ElemType data[LENGTH];
    int count;
}SeqList,*pSeqList;

bool InitList_Sq(pSeqList seq);

static bool ListisEmpty(pSeqList seq);//判断List是否为空

static bool ListisFull(pSeqList seq);//判断List是否已满

void InsertList_SqOfHead(pSeqList seq,ElemType val);//头插

void InsertList_SqOfTail(pSeqList seq,ElemType val);//尾插

void InsertList_SqOfPos(pSeqList seq,ElemType val,int pos);//按照位置插入

void ShowList_Sq(pSeqList seq);//打印当前List所有的元素

void DeleteList_SqOfHead(pSeqList seq);//从头删除List中的元素

void DeleteList_SqOfPos(pSeqList seq,int pos);//从特定位置删除List中的元素

void DeleteList_SqOfTail(pSeqList Seq);//从尾处删除List中的元素

void ClearList_Sq(pSeqList seq);//清空List

void ReverseList_Sq(pSeqList seq,void(*Swap)(ElemType*,ElemType*));//逆置当前的List

int FindList_SqOfVal(pSeqList seq,ElemType val);//给定元素的数值返回元素的下标

bool FindList_SqOfPos(pSeqList seq,int pos,ElemType *val);//给定位置返回元素的内容

int FindList_SqOfLocate(pSeqList seq,ElemType val,
        bool(*compare)(ElemType,ElemType));//根据用户提供的函数找元素


#endif
