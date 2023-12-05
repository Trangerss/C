//
// Created by 29558 on 2023/11/30.
//

#ifndef SEQLIST_SEQLIST_H
#define SEQLIST_SEQLIST_H

#endif //SEQLIST_SEQLIST_H
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//创建动态顺序表
typedef struct{
    int* list;
    int MaxSize;
    int Length;
}SeqList;
void SeqListInit(SeqList* L); //初始化顺序表
void SeqListPrint(SeqList* L); //打印顺序表
void SeqListCheckLength(SeqList* L); //检查长度是否已满，否则增加长度
void SeqListDestroy(SeqList* L); //销毁顺序表
void SeqListPushBack(SeqList* L, int x); //尾插
void SeqListPopBack(SeqList* L); //尾删
void SeqListPushFront(SeqList* L, int x); //前插
void SeqListPopFront(SeqList* L); //前删
int SeqListFind(SeqList* L, int x); //数据查找
void SeqListInsert(SeqList* L, size_t pos, int x); //数据插入
void SeqListDelete(SeqList* L, size_t pos); //数据删除
void SeqListModify(SeqList* L, size_t pos, int x); //数据修改

