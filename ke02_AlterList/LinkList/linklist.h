#ifdef __LINKLIST
#define __LINKLIST
#define ElemType int
typedef struct LinkList
{
    ElemType val;
    struct LinkList *next;
}LinkList,*pLinkList
static bool ApplyNode(ElemType val,pLinkList next);
bool Init(pLinkList seq);
bool Insert_ListHead(pLinkList list,ElemType val);
bool Insert_ListTail(pLinkList list,ElemType val);
bool Insert_ListPos(pLinkList list,ElemType val);

void Show(plinkList list);

#endif
