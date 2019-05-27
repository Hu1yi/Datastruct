#include <stdio.h>
#include <stdlib.h>
#define Listsize 100  //顺序表可容纳最大值

//声明顺序表
typedef struct sqList{
    int data[Listsize];  //顺序表数据部分
    int Length;          //顺序表长度
}sqlist;

sqlist * createlist(int n){
    sqlist * sq;                 //创建顺序表
    sq = (sqlist *)malloc(sizeof(sqlist)); //分配内存
    sq->Length = n;               //初始化
    int i, j, k, ele;
    for( i = 0; i < sq->Length; i++)
    {
        scanf("%d",&sq->data[i]);
    }
    return sq;
}

void Display(sqlist *sq){
    for( int i = 0; i < sq->Length; i++)
    {
        printf("%d ",sq->data[i]);
    }
    //printf("\n");
}
void deleteele(sqlist *sq, int m){
    for (int i = 0; i < sq->Length; ++i) {
        if(sq->data[i] == m){
            for (int j = i; j < sq->Length; ++j) {
                sq->data[j] = sq->data[j+1];
            }
            sq->Length -= 1;
            break;
        }
    }
}
int main(){
    int n[3];
    for (int i = 0; i < 3; ++i) {
        scanf("%d",&n[i]);
    }
    sqlist *a = createlist(n[0]);
    sqlist *b = createlist(n[1]);
    sqlist *c = createlist(n[2]);
    //Display(a);
    //Display(b);
    //Display(c);
    for (int j = 0; j < b->Length; ++j) {
        for (int k = 0; k < c->Length; ++k) {
            if (b->data[j] == c->data[k])
                deleteele(a, b->data[j]);
        }
    }
    Display(a);


}