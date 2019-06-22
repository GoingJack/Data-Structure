#ifndef __ALTERLIST
#define __ALTERLIST
#define ElemType int
typedef struct
{
    ElemType *_pdata;
    int _size;
    int _count;
}*pAlterList,AlterList;
void Init(pAlterList seq,int size);

void Insert_Head(pAlterList seq,ElemType val);

void Insert_Tail(pAlterList seq,ElemType val);

void Insert_Pos(pAlterList seq,ElemType val,int pos);

bool IsFull(pAlterList seq);

bool IsEmpty(pAlterList seq);

bool Expand(pAlterList seq);

void Show_List(pAlterList seq);

void Reverse_List(pAlterList seq);

void DeleteList_Head(pAlterList seq);

void DeleteList_Pos(pAlterList seq,int pos);

void DeleteList_Head(pAlterList seq);

bool SearchList_Locate(pAlterList seq,ElemType in, 
                bool (*Compare)(ElemType,ElemType),int *pos);

bool SearchList_Val(pAlterList seq,int *pos,ElemType in);

bool SearchList_Pos(pAlterList seq,int pos,ElemType *out);

void ClearList(pAlterList seq);

void DestoryList(pAlterList seq);
#endif
