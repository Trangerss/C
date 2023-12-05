//
// Created by 29558 on 2023/12/5.
//

#ifndef SEQLIST_DOULINKLIST_H
#define SEQLIST_DOULINKLIST_H

#endif //SEQLIST_DOULINKLIST_H
//结点结构体
typedef struct Node{
    int data; //数据域
    struct Node *prev; //前指针
    struct Node *next; //后指针
}Node;
//双链表结构体
typedef struct DoubleList{
    Node* head;     //头结点
    Node* tail;     //尾结点
    size_t size;    //链表长度
}DoubleList;

//初始化链表
void Init_list(DoubleList* list);
//释放链表
void Free_list(DoubleList* list);
//获取链表长度
size_t Get_size(DoubleList* list);
//获取头结点
Node* Get_head(DoubleList* list);
//获取尾结点
Node* Get_tail(DoubleList* list);
//遍历链表
void show_list(DoubleList* list);
//插入一个头结点
void Push_head(DoubleList* list, int data);
//插入一个尾结点
void Push_tail(DoubleList* list, int data);
//任意位置插入结点
bool Insert_node(DoubleList* list, int index, int data);
//删除任意位置结点
bool Del_node(DoubleList* list, int index);
//获取任意位置结点
Node* Get_node(DoubleList* list, int index);
//删除头结点
void Del_head(DoubleList* list);
//删除尾结点
void Del_tail(DoubleList* list);
//获取链表中指定数据所在的第一个结点
Node* Find_data(DoubleList* list, int data);
//修改链表中指定结点的值
bool Modify_node(DoubleList* list, int index, int data);
//修改链表中指定的第一个数据
bool Modify_data(DoubleList* list, int data, int val);
