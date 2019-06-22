#include "seqlist.h"
#include <stdio.h>
void Swap(ElemType *a,ElemType *b)
{
    if(a==NULL||b==NULL)
        return;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
bool compare(ElemType ele1,ElemType ele2)
{
    return ele1 > ele2;
}
int main()
{
    SeqList seq;
    if(!InitList_Sq(&seq))
    {   
        printf("初始化失败\n");
        return 0;
    }
    InsertList_SqOfHead(&seq,1);
    InsertList_SqOfHead(&seq,2);
    InsertList_SqOfTail(&seq,3);
    InsertList_SqOfPos(&seq,4,3);
    InsertList_SqOfTail(&seq,5);
    InsertList_SqOfTail(&seq,6);
    InsertList_SqOfTail(&seq,7);
    printf("元素的个数为%d\n",seq.count);
    int i=0;
    printf("所有的元素为:\n");
    ShowList_Sq(&seq);
    //删除
    DeleteList_SqOfHead(&seq);
    ShowList_Sq(&seq);
    DeleteList_SqOfTail(&seq);
    ShowList_Sq(&seq);
    DeleteList_SqOfPos(&seq,3);
    ShowList_Sq(&seq);
    //逆置
    ReverseList_Sq(&seq,Swap);
    ShowList_Sq(&seq);

    //找元素的下标
    int tmp = FindList_SqOfVal(&seq,3);
    printf("3的下标为%d\n",tmp);
    //根据下标找元素
    ElemType val;
    FindList_SqOfPos(&seq,1,&val);
    printf("1下标对应的元素是%d\n",val);
    //根据用户提供的比较函数找下标
    tmp = FindList_SqOfLocate(&seq,5,compare);
    printf("第一个比5大的元素为:%d\n",tmp);



    return 0;
}
