#include <stdio.h>
#include "SeqList.h"

int main() {
    SeqList s;
    //初始化数组
    SeqListInit(&s);
    //尾插
    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    //头插
    SeqListPushFront(&s, 6);
    SeqListPushFront(&s, 8);
    SeqListPushFront(&s, 9);
    SeqListPushFront(&s, 10);
    SeqListPushFront(&s, 12);
    //尾删
    SeqListPopBack(&s);
    //头删
    SeqListPopFront(&s);
    //数据插入
    SeqListInsert(&s, 0, 3);
    SeqListInsert(&s, 3, 3);
    //数据修改
    SeqListModify(&s, 0, 7);
   //数据查找
    SeqListFind(&s, 5);
    //数据删除
    SeqListDelete(&s, 35);
    //顺序表销毁
    SeqListDestroy(&s);
    //数据打印
    SeqListPrint(&s);
    printf("%p\n",&s);
    return 0;
}
