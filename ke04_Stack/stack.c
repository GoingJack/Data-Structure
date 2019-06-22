#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "stack.h"

void Init(pStack st,int size)
{
    st->_top = 0;
    st->_size = size;
    st->_pdata = (ElemType*)malloc(sizeof(ElemType)*size);
}
bool StackEmpty(pStack st)
{
    return st->_top == 0;
}
bool StackFull(pStack st)
{
    return st->_top == st->_size;
}
static void expand(pStack st)
{
    assert(st != NULL);
    if(NULL == st)
        return;
    ElemType *tmp = (ElemType*)malloc(sizeof(ElemType)*2*st->_size);
    int i=0;
    for(;i<st->_top;i++)
        tmp[i]=st->_pdata[i];
    free(st->_pdata);
    st->_pdata = tmp;
    st->_size*=2;
}
void PushStack(pStack st,ElemType in)
{
    if(StackFull(st))
    {
        expand(st);
    }
    st->_pdata[st->_top]=in;
    st->_top++;
}
void GetTop(pStack st, ElemType *out)
{
    assert(st != NULL);
    if(st == NULL)
        return;
    if(StackEmpty(st))
        return;
    *out = st->_pdata[st->_top-1];
}
void PopStack(pStack st)
{
    if(StackEmpty(st))
        return;
    st->_top--;
}
void ShowStack(pStack st)
{
    int i=0;
    for(;i<st->_top;i++)
        printf("%d ",st->_pdata[i]);
    printf("\n++++++++++++++++++++++++++\n");
}
void ClearStack(pStack st)
{
    assert(st != NULL);
    if(st == NULL)
        return;
    free(st->_pdata);
    st->_pdata=NULL;
    st->_size = 0;
    st->_top = 0;
}
int StackSize(pStack st)
{
    assert(st != NULL);
    if(st == NULL)
        return;
    return st->_size;
}
