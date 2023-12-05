//
// Created by 29558 on 2023/11/30.
//
#include <stdio.h>
#include "SeqList.h"
//初始化顺序表
void SeqListInit(SeqList* L){
    L ->list = NULL;
    L ->MaxSize = 0;
    L ->Length = 0;
}
//打印顺序表
void SeqListPrint(SeqList* L){
    for (int i = 0; i < L ->Length; ++i) {
        printf("%d",L ->list[i]);
    }
    printf("\n");
}
//判断顺序表长度是否需要增加长度
void SeqListCheckLength(SeqList* L){
    //当数组长度与最大容量相等，则使用realloc进行扩容
    if(L ->Length == L ->MaxSize){
        //当最大容量Maxsize等于0时为其赋值为4，若不为0，则翻倍扩容
        int NewMaxSize = L ->MaxSize == 0 ? 4 : L ->MaxSize * 2;
        //为当前容量翻倍扩容
        int* temp = realloc(L ->list, sizeof(int)* NewMaxSize);
        //对是否扩容进行检查
        if(temp == NULL){
            printf("realloc fail\n");
            exit(-1);//终止程序
        } else {
            L ->list = temp;
            L ->MaxSize = NewMaxSize;
        }
    }
}
//销毁顺序表
void SeqListDestroy(SeqList* L){
    free(L ->list);
    L ->list = NULL;
    L ->MaxSize = 0;
    L ->Length = 0;
}
//尾插
void SeqListPushBack(SeqList* L, int x){
    //插入之前先检查容量是否足够
    SeqListCheckLength(L);
    //L ->length指的是顺序表的长度，长度由最后一位决定，
    //即第list[l -> length]个位置，所以尾插法在此位置插入元素
    L ->list[L ->Length] = x;
    //每插入一个元素，数组的长度+1
    L ->Length++;
}
//尾删
void SeqListPopBack(SeqList* L){
    if(L ->Length > 0){
        --L ->Length;
    }
}
//头插
void SeqListPushFront(SeqList* L, int x){

    //先检查容量是否充足
    SeqListCheckLength(L);
    //将所有元素倒序往后移动
    //length表示元素个数，数组下标=元素个数-1，
    //所以这时把length的最后位置定义成last。[last]加1，就相当于数组下标往后移动一位，即数组多了一个位置
    for (int end = L ->Length - 1; end >= 0; end--)
    {
        L ->list[end + 1] = L ->list[end];
    }
    L ->list[0] = x;
    L ->Length++;//每插入一个元素，数组的长度+1
}
//头删
void SeqListPopFront(SeqList* L) {
    //判断顺序表是否有元素
    if (L ->Length > 0){
        //将表头后的数据从前往后，往前移动一位
        int first = 1;
        while (first < L->Length) {
            //原理：用后一个元素覆盖前一个元素
            L->list[first - 1] = L->list[first];
            first++;
        }
        //循环结束，数组长度减少
        L->Length--;
    }
}
//数据查询
int SeqListFind(SeqList* L, int x){
    //通过数组下标遍历顺序表中的元素
    for (int i = 0; i < L ->Length; i++) {
        //若需要查找的x与数组元素相同，则返回在数组中的位置，即数组下标
        if (x == L ->list[i]){
            return i;
        }
    }
    return -1;
}
//数据插入
void SeqListInsert(SeqList* L, size_t i, int x){
    assert(i >=0 && i <= L->Length);
    SeqListCheckLength(L);
    int end = L->Length-1;
    //将第i个位置之后的元素倒序往后移动
    while (end >= i ){
        L ->list[end + 1] =  L ->list[end];
        end--;
    }
    L ->list[i] = x; //在第i个位置放入x
    L->Length++;
}
//数据删除
void SeqListDelete(SeqList* L, size_t i){
    assert(i >= 0 && i < L->Length);
    size_t begin = i - 1;
    //与数据插入同理
    while (begin < L ->Length){
        L ->list[begin -1] =  L ->list[begin];
        begin++;
    }
    L ->Length--;
}
//数据修改
void SeqListModify(SeqList* L, size_t i, int x){
    assert(i >= 0 && i <= L->Length);
    L ->list[i] = x;
}
