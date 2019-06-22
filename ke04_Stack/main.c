#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>
#include "stack.h"

int main()
{
    Stack st;
    Init(&st,5);
    int i=0;
    for(;i<10;i++)
        PushStack(&st,i);
    ShowStack(&st);
    //Pop
    PopStack(&st);
    ShowStack(&st);
    //gettop
    ElemType tmp;
    GetTop(&st,&tmp);
    printf("top is %d\n",tmp);
    //size
    PopStack(&st);
    printf("stack size is %d\n",StackSize(&st));
    //ClearStack
    ClearStack(&st);
    ShowStack(&st);
    exit(0);
}
