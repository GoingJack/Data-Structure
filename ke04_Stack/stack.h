#ifndef __STACK_H
#define __STACK_H
typedef int ElemType;
typedef struct Stack
{
    ElemType *_pdata;
    int _top;
    int _size;
}Stack,*pStack;
void Init(pStack st,int size);
void DestroyStack(pStack st);
void ClearStack(pStack st);
bool StackFull(pStack st);
bool StackEmpty(pStack st);
void GetTop(pStack st,ElemType *out);
void PopStack(pStack st);
int StackSize(pStack st);
void PushStack(pStack st,ElemType in);
static void expand(pStack st);

#endif
