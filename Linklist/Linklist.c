//
// Created by 29558 on 2023/12/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Linklist.h"
bool Initlist(Linklist L){  //初始化单链表
    L = (Linklist) malloc(sizeof(LNode));  //给单链表加一个节点(头节点)
    if(L == NULL){
        return false;
    }
        L->next = NULL;
        return true;
}
//前插操作（用在按位序插入的第二步骤）
bool InsertPrionNode(Linklist p, int num){
    if(p == NULL) return false;
    LNode *m = (Linklist) malloc(sizeof(LNode));
    if(m == NULL) return false;
    //这两步插入新的节点
    m->next = p->next; //让m的指针指向和p指针指向一样的下一个节点
    p->next = m; //让p的指针指向m
    //接下来将插入的新节点里的元素和前一个节点的元素交换，就实现前插操作了
    m->element = p->element;//将p的元素复制到m里
    p->element =num;//再用num把p的元素覆盖
    return true;
}
//后插操作（用在按位序插入的第二步骤）
bool InsertPointNode(Linklist p,int num){
    if(p == NULL) return false;
    LNode *n = (LNode *) malloc(sizeof(LNode));
    if(n == NULL) return false;
    n->element = num;
    n->next = p->next;
    p->next = n;
    return true;
}
//按位序插入
//在第i个位置插入元素e
bool listInsert(Linklist L, int i,int num){
    if(i < 1) return false;
    LNode *p;//定义节点p
    p = L;//p节点当作头节点
    int j = 0;
    //循环找到第i个位置的前一个节点
    while (p != NULL && j < j - i){
        p = p->next;
        j++;
    }
    return InsertPointNode(p,num);
}
//按位序删除
//删除第i个的元素
bool listdelete(Linklist L, int i){
    if(i < 1) return false;
    LNode *p;//指针p指向当前扫描到的节点
    p = L;//L指向头节点，头节点是第0个节点(不存数据)
    int j = 0;//当前p指向的是第几节点
    //循环找到第i-1个节点
    while (p != NULL && j < j - i){
        p = p->next;
        j++;
    }
    if(p == NULL) return false;//i值不合法
    if(p->next == NULL) return false;//第i-1个位置之后没有节点
    LNode *q = p->next; //令q指向被删除节点
    p->next = q->next; //p节点指向被删除的q节点指向的下一个节点，就是把q断链
    free(q); //释放被删除节点的存储空间
    return true;
}
//删除指定节点
bool deleteNode(Linklist p){
    if(p == NULL) return false;
    LNode *q = p->next; //令q指向被删除节点
    p->element = p->next->element; //将被删除节点的数据复制到p里
    p->next = q->next; //使被删除的节点q断链
    free(q); //释放q的空间
    return true;
}
//按位查找
Linklist GetElement(Linklist L,int i){
    if(i < 0) return NULL;
    LNode *p;//指针p指向当前扫描到的节点
    p = L;//L指向头节点，头节点是第0个节点(不存数据)
    int j = 0;//当前p指向的是第几节点
    //循环找到第i个节点
    while (p != NULL && j < i){
        p = p->next;
        j++;
    }
    printf("%d\n",j);
    return p;
}
//按值查找
Linklist LocateElem(Linklist L,int e){
    LNode *p = L->next;
    while (p != NULL && p->element != e){
        p = p->next;
    }
    printf("%p\n",p);
    return p;
}
//求表长度
int Getlength(Linklist L){
    int len = 0;
    LNode *p = L;
    while (p->next != NULL){
        p = p->next;
        len++;
    }
    printf("%d\n",len);
    return len;
}
//尾插法
Linklist TailInsert(){
    int x;
    Linklist L;
    L = (LNode *)malloc(sizeof(LNode)); //建立一个头指针
    Linklist s ,r = L; //这时r，s都指头节点
    scanf("%d",&x); //输入节点的值
    while (x != 0){
        s = (LNode*)malloc(sizeof(LNode)); //申请一个新节点
        s->element = x;//将用户输入的x放到s节点的数据域
        r->next = s; //让r的指针下一个节点，也就是指向s
        r = s; //r指向新的表尾节点
        scanf("%d",&x);
    }
    r->next = NULL; //跳出循环后，r指向null，表明r是尾指针
    return L;
}
//头插法
Linklist HeadInsert(){
    int x;
    Linklist L;
    Linklist s;
    L = (LNode *)malloc(sizeof(LNode)); //建立一个头指针
    L->next = NULL;
    scanf("%d",&x);
    while (x != 0){
        //   l -> s  -> null,s是新建立的
        //以此类推：l -> s2 -> s1 -> s -> null
        s = (LNode*)malloc(sizeof(LNode)); //申请一个新节点
        s->element = x;//将用户输入的x放到s节点的数据域
        s->next = L->next; //令s指向下一个节点的指针与l的相同
        L->next = s; //令l指向的下一个节点为s
        scanf("%d",&x);
    }
    return L;
}
void printList(Linklist L){
    Linklist j ;
    j = L->next;
    while (j!=NULL){
        printf("%d\t",j->element);
        j = j->next;
    }
}

int main(){
    Linklist s;
    Initlist(s);
    s = TailInsert();
    Getlength(s);
    // L =  HeadInsert();
    LocateElem(s,12);
    printList(s);

}