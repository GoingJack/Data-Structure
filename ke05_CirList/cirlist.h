#ifndef __CIRLIST_H
#define __CIRLIST_H
typedef int ElemType;
typedef struct CNode
{
    ElemType _data;
    struct CNode *_next;
}CNode,*CirList;

bool Init_List(CirList *list);//初始化循环链表

bool Insert_ListHead(CirList *list,ElemType val);//头插

bool Insert_ListTail(CirList *list,ElemType val);//尾插

bool Insert_ListPos(CirList *list,ElemType val,int pos);//按照位置插入

void Show(CirList list);//显示整个循环链表

bool Delete_ListHead(CirList *list);//删除头节点
bool Delete_ListTail(CirList *list);//删除尾节点
bool Delete_ListPos(CirList *list,int pos);//按照位置删除节点
#endif
