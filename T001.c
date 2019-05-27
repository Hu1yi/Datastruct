#include <stdio.h>
#include <stdlib.h>
#define Listsize 100  //顺序表可容纳最大值

//声明顺序表
typedef struct sqList{
    int data[Listsize];  //顺序表数据部分
    int Length;          //顺序表长度
}sqlist;

void Insertlist(sqlist * List, int ele){  //向顺序表中插入元素
    int i, k = List->Length;
    for (i = 0; i < List->Length; i++) {
        if(ele < List->data[i]){
            k = i;                 //找到待插入元素的位置
            break;
        }
    }
    if(k != List->Length) {         //待插入元素不是最大的
        for (i = List->Length; i > k; i--) {  //其他元素向后移动
            List->data[i] = List->data[i - 1];
        }
        List->data[i] = ele;           //插入元素
    } else                          //待插入元素是最大的，直接放在顺序表结尾
        List->data[k] = ele;
    List->Length += 1;
}

int main(){
    sqlist * sq;                 //创建顺序表
    sq = (sqlist *)malloc(sizeof(sqlist)); //分配内存
    sq->Length = 0;               //初始化
    int i, j, k, ele;
    scanf("%d",&sq->Length);
    for( i = 0; i < sq->Length; i++)
    {
        scanf("%d",&sq->data[i]);
    }
    scanf("%d",&ele);
    Insertlist(sq,ele);
    for( i = 0; i < sq->Length; i++)
    {
        printf("%d ",sq->data[i]);
    }
}