#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "alterlist.h"
bool Compare(ElemType elem1,ElemType elem2)
{
    return elem1 > elem2;
}
int main()
{
    AlterList seq;
    Init(&seq,10);
    int i = 0;
    for(;i<10;i++)
    {
        Insert_Head(&seq,i);
    Show_List(&seq);
    }
    Insert_Head(&seq,10);
    Insert_Tail(&seq,20);
    Insert_Pos(&seq,300,1);
    Show_List(&seq);
    Reverse_List(&seq);
    Show_List(&seq);
    DeleteList_Head(&seq);
    Show_List(&seq);
    DeleteList_Tail(&seq);
    Show_List(&seq);
    DeleteList_Pos(&seq,4);
    Show_List(&seq);
    //搜索
    ElemType tmp;
    //按照下标搜索
    if(SearchList_Pos(&seq,3,&tmp))
    {
        printf("the pos 3 is %d\n",tmp);
    }
    int pos;
    if(SearchList_Val(&seq,&pos,5))
    {
        printf("the number 5 position is %d\n",pos);
    }
    if(SearchList_Locate(&seq,5,Compare,&pos))
    {
        printf("the first number is greater than 5 is %d\n",seq._pdata[pos]);
    }
    ClearList(&seq);
    DestoryList(&seq);
    return 0;
}

