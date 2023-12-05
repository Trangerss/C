//
// Created by 29558 on 2023/12/5.
//

#ifndef SEQLIST_LINKLIST_H
#define SEQLIST_LINKLIST_H

#endif //SEQLIST_LINKLIST_H
typedef struct LNode{  //定义一个节点
    int element;  //数据域
    struct LNode *next;  //指针域（指向下一个节点）
}LNode,*Linklist;

//初始化单链表
bool Initlist(Linklist L);
//前插操作（用在按位序插入的第二步骤）
bool InsertPrionNode(Linklist p, int num);
//后插操作（用在按位序插入的第二步骤）
bool InsertPointNode(Linklist p,int num);
//按位序插入,在第i个位置插入元素e
bool listInsert(Linklist L, int i,int num);
//按位序删除,删除第i个的元素
bool listdelete(Linklist L, int i);
//删除指定节点
bool deleteNode(Linklist p);
//按位查找
Linklist GetElement(Linklist L,int i);
//按值查找
Linklist LocateElem(Linklist L,int e);
//尾插法
Linklist TailInsert();
//头插法
Linklist HeadInsert();