#include <stdio.h>
#include <stdlib.h>
#define Size 10

typedef struct LINK{
    int ele;
    struct LINK *next;
}Lklist, *Linklist;

void createSqList(int *L, int num){
    for (int i = 0; i < num; ++i) {
        scanf("%d",&L[i]);
    }
}
Linklist initLklist(int num, int *a){   //带头节点的链表创建
    Linklist p = (Linklist)malloc(sizeof(Lklist));  //创建一个头节点
    Linklist temp = p;     //声明一个指针指向头节点
    for (int i = 0; i <num ; ++i) {  //创建链表
        Linklist t = (Linklist)malloc(sizeof(Lklist));
        t->ele = a[i];
        t->next = NULL;
        temp->next = t;
        temp = temp->next;
    }
    return p;
}

void invertSq(int *L, int n){   //数组逆序
    int t;
    for (int i = 0; i <= (n-1)/2; ++i) {
        t = L[i];
        L[i] = L[n-1-i];
        L[n-1-i] = t;
    }
}
void invertLk(Linklist L){   //链表逆序
    Linklist p, q, r;
    if(L->next == NULL) return;  //链表为空返回
    p = L->next;
    q = p->next;
    p->next =NULL;
    while(q){
        r = q->next;
        q->next = L->next;
        L->next = q;
        q = r;
    }
}
void DisplaySq(int *L, int n){
    for (int i = 0; i < n; ++i) {
        printf("%d ",L[i]);
    }
    printf("\n");
}
void DisplayLk(Linklist p){
    p = p->next;
    while(p){
        printf("%d ",p->ele);
        p = p->next;
    }
    //printf("\n");
}
int main() {
    int num;
    int a[Size];
    scanf("%d",&num);
    createSqList(a, num);
    Linklist p = initLklist(num ,a);
    invertSq(a, num);
    invertLk(p);
    DisplaySq(a, num);
    DisplayLk(p);

    return 0;
}