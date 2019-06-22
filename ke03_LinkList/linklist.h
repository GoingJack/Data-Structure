#ifndef __LINKLIST
#define __LINKLIST
#define ElemType int
typedef struct LinkList
{
    ElemType _data;
    struct LinkList *_next;
}LinkList,*pLinkList;
static pLinkList ApplyNode(ElemType val,pLinkList next);
bool Init(pLinkList seq);
bool Insert_ListHead(pLinkList list,ElemType val);
bool Insert_ListTail(pLinkList list,ElemType val);
bool Insert_ListPos(pLinkList list,ElemType val,int pos);

void Show(pLinkList list);

bool Delete_ListPos(pLinkList list,int pos);

bool Delete_ListHead(pLinkList list);

bool Delete_ListTail(pLinkList list);

void Reverse_List(pLinkList list);
#endif
