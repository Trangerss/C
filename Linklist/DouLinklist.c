//
// Created by 29558 on 2023/12/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DouLinklist.h"
//创建双向链表结点
Node* Create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));//申请内存
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

//初始化链表
void Init_list(DoubleList* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

//释放链表
void Free_list(DoubleList* list)
{ //循环遍历链表
    while(list->size)
    {
        Node* tmp = list->head; //创建tmp指向第一个节点
        list->head = list->head->next; //让第一个节点指向下一个节点
        free(tmp); //释放第一个节点
        tmp = NULL;
        list->size--;
    }
}

//获取链表长度
size_t Get_size(DoubleList* list)
{
    return list->size;
}

//获取头结点
Node* Get_head(DoubleList* list)
{
    return list->head;
}

//获取尾结点
Node* Get_tail(DoubleList* list)
{
    return list->tail;
}

//遍历链表
void show_list(DoubleList* list)
{
    Node* node = list->head; //让node等于头节点
    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", node->data);
        node = node->next; //循环指向每一个节点
    }
    printf("\n");
}

//插入一个头结点
void Push_head(DoubleList* list, int data)
{
    Node* new_node = Create_node(data); //创建新节点

    //链表为空
    if(list->size == 0)
    {
        //插入的结点既是头结点，也是尾结点
        list->head = new_node;
        list->tail = new_node;
    }
        //链表不为空
    else
    {
        //将新结点和链表通过前驱指针prev和后继指针next连接起来
        new_node->next = list->head;
        list->head->prev = new_node;
        //将头结点改为新插入的结点
        list->head = new_node;
    }
    list->size++;
}

//插入一个尾结点
void Push_tail(DoubleList* list, int data)
{
    Node* new_node = Create_node(data);

    //链表为空
    if(list->size == 0)
    {
        //插入的结点既是尾结点，也是头结点
        list->tail = new_node;
        list->head = new_node;
    }
        //链表不为空
    else
    {
        //将新结点和链表通过前驱指针prev和后继指针next连接起来
        list->tail->next = new_node;
        new_node->prev = list->tail;
        //将尾结点改为新插入的结点
        list->tail = new_node;
    }
    list->size++;

}

//任意位置插入结点
bool Insert_node(DoubleList* list, int index, int data)
{
    //插入的位置超出链表的范围
    if(index <0 || index > list->size)
        return false;
    //插入的位置如果等于0，等同于插入头结点
    if(index == 0)
    {
        Push_head(list,data);
        return true;
    }
        //插入的位置如果等于链表的长度，等同于插入尾结点
    else if(index == list->size)
    {
        Push_tail(list,data);
        return true;
    }

    Node* tmp = NULL;
    //插入的位置如果小于等于中间位置，那插入的位置更靠近头结点
    if(index <= list->size / 2)
    {
        //从头结点开始往后遍历到插入的前一个位置
        tmp = list->head;
        for(int i=0; i<index-1;i++)
        {
            tmp = tmp->next;
        }
    }
        //插入的位置如果大于中间位置，那插入的位置更靠近尾结点
    else
    {
        //从尾结点开始往前遍历到插入的前一个位置
        tmp = list->tail; //定义tmp为头指针
        for (int i = 0; i < list->size - index; ++i)
        {
            tmp = tmp->prev;
        }
    }

    Node* new_node = Create_node(data);

    tmp->next->prev = new_node; //tmp的下一个节点的前指针指向新节点
    new_node->next = tmp->next; //新节点的后指针指向tmp的下一个节点
    tmp->next = new_node; //tmp的后指针指向新节点，不再指向以前的节点
    new_node->prev = tmp; //新节点的前指针指向tmp
    list->size++; //链表长度+1
    return true;
}

//删除头结点
void Del_head(DoubleList* list)
{
    if(list->size == 0)
        return;
    if(list->size == 1)
    {
        free(list->head);//释放内存
        Init_list(list);
        return;
    }

    Node* tmp = list->head;//让tmp变成要删除的头节点
    list->head = tmp->next; //让头节点变为tmp的下一个节点，也就是让要删除的头节点的下一个节点变为新的头节点
    list->head->prev = NULL; //再让新的头节点指向null，而不是指向要删除的头节点

    free(tmp);//释放内存
    tmp = NULL; //删除头节点
    list->size--;
}

//删除尾结点
void Del_tail(DoubleList* list)
{
    if(list->size == 0)
        return;
    if(list->size == 1)
    {
        free(list->tail);//释放内存
        Init_list(list);
        return;
    }
    //与删除头节点相同
    Node* tmp = list->tail;//保存尾结点
    list->tail = tmp->prev;
    list->tail->next = NULL;

    free(tmp);//释放内存
    tmp = NULL;
    list->size--;
}

//删除任意位置结点
bool Del_node(DoubleList* list, int index)
{
    //判断插入的位置是否超出链表的范围
    if(index < 0 || index > list->size)
        return false;
    //删除的位置如果等于0，等同于删除头结点
    if(index == 0)
    {
        Del_head(list);
        return true;
    }
    //删除的位置如果等于链表的长度，等同于删除尾结点
    if(index == list->size)
    {
        Del_tail(list);
        return true;
    }

    Node* tmp = NULL;

    //删除的位置如果小于中间位置
    if(index < list->size/2)
    {
        //从头结点开始往后遍历到删除的的结点
        tmp = list->head;
        for (int i = 0; i < index; ++i)
        {
            tmp = tmp->next;
        }
    }
        //删除的位置如果大于等于中间位置
    else
    {
        //从尾结点开始往前遍历到删除的结点
        tmp = list->tail;
        for (int i = 0; i < list->size - index - 1; ++i)
        {
            tmp = tmp->prev;
        }
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);//释放内存
    tmp = NULL;
    list->size--;
    return true;
}

//获取任意位置结点
Node* Get_node(DoubleList* list, int index)
{
    //判断插入的位置是否超出链表的范围
    if(index < 0 || index > list->size)
        return NULL;
    Node* node = NULL;
    //目标结点的位置如果小于中间位置
    if(index < list->size / 2)
    {
        //从头结点开始往后遍历到目标结点
        node = list->head;
        for(int i =0; i < index ; i++)
        {
            node = node->next;
        }
    }
        //目标结点的位置如果大于等于中间位置
    else
    {
        //从尾结点开始往前遍历到目标结点
        node = list->tail;
        for (int i = 0; i < list->size - index - 1; ++i)
        {
            node = node->prev;
        }
    }
    return node;
}

//获取链表中指定数据所在的第一个结点
Node* Find_data(DoubleList* list, int data)
{
    if(list->size == 0)
        return NULL;
    Node* node = list->head;
    while(node)
    {
        if(node->data == data)
            return node;
        node = node->next;
    }
    return NULL;
}

//修改链表中指定结点的值
bool Modify_node(DoubleList* list, int index, int data)
{
    Node* node = Get_node(list,index);
    if(node)
    {
        node->data = data;
        return true;
    }
    return false;
}

//修改链表中指定的第一个数据
bool Modify_data(DoubleList* list, int data, int val)
{
    Node* node = Find_data(list,data);
    if(node)
    {
        node->data = val;
        return true;
    }
    return false;
}
int main(){
    return 0;
}