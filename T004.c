#include <stdio.h>
#include <stdlib.h>

typedef struct LINK{
    int ele;
    struct LINK *next;
}Lklist, *Linklist;

Linklist initLklist(int num){   //带头节点的链表创建
    Linklist p = (Linklist)malloc(sizeof(Linklist));  //创建一个头节点
    Linklist temp = p;     //声明一个指针指向头节点
    for (int i = 0; i <num ; ++i) {  //创建链表
        Linklist t = (Linklist)malloc(sizeof(Linklist));
        scanf("%d",&t->ele);
        t->next = NULL;
        temp->next = t;
        temp = temp->next;
    }
    return p;
}
void DisplayLk(Linklist p){
    p = p->next;
    while(p){
        printf("%d ",p->ele);
        p = p->next;
    }
    printf("\n");
}
void invertLk(Linklist L){
    Linklist p, q, r;
    if(L->next == NULL) return;
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

Linklist merge(Linklist pa, Linklist pb){  //归并
    Linklist head = pa;
    Linklist temp = head;
    pa = pa->next;
    pb = pb->next;
    while(pa && pb){
        if(pa->ele < pb->ele){
            temp->next = pa;
            pa = pa->next;
            temp = temp->next;
        }
        else if(pa->ele > pb->ele){
            temp->next = pb;
            pb = pb->next;
            temp = temp->next;
        }
        else{
            temp->next = pa;
            pa = pa->next;
            temp = temp->next;
            temp->next =pb;
            pb = pb->next;
            temp = temp->next;
        }
    }
    if(pa != NULL)
        temp->next = pa;
    if(pb != NULL)
        temp->next = pb;
    return head;
}
int main() {
    int n[2];
    for (int i = 0; i < 2; ++i) {
        scanf("%d",&n[i]);
    }
    Linklist a, b;
    a = initLklist(n[0]);
    b = initLklist(n[1]);
    //DisplayLk(a);
    //DisplayLk(b);
    Linklist head = merge(a, b);
    invertLk(head);
    DisplayLk(head);
    return 0;
}