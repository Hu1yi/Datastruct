#include <stdio.h>
#include <stdlib.h>

typedef struct Dnode{
    char data;
    struct Dnode *pre;
    struct Dnode *next;
    int freq;
}DNODE, *Dlink;

Dlink initList(int n){
    Dlink p = (Dlink)malloc(sizeof(DNODE));
    Dlink temp = p;
    for (int i = 0; i < n; ++i) {
        Dlink q = (Dlink)malloc(sizeof(DNODE));
        scanf("%c",&q->data);
        getchar();
        q->freq = 0;
        q->pre = temp;
        q->next = p;
        temp->next =q;
        if (temp == p)
            temp->pre = q;
        temp = temp->next;
    }
    p->pre = temp;
    temp->next = p;
    p->freq = 0;
    return p;
}

Dlink location(Dlink L, char c){
    Dlink p, q;
    p = L->next;
    while (p != L && p->data != c){//找c的位置
        p = p->next;
    }
    if (p == L) return NULL;// 没找到
    else{   //找到c的位置
        p->freq++;
        p->pre->next = p->next;
        p->next->pre = p->pre;  //将c所在节点摘下
        q = p->pre;
        while (q != L && q->freq < p->freq) q = q->pre;
        if (q == L){
            q->next->pre = p;
            p->next = q->next;
            q->next =p;
            p->pre = q;
        } else{
            p->next = q->next;
            q->next->pre = p;
            p->pre = q;
            q->next = p;
        }
        return L;
    }
}

void Display(Dlink p){
    Dlink  L = p;
    p = p->next;
    while (p != L){
        printf("%c ",p->data);
        p = p->next;
    }
}

int main() {
    int m,n;
    scanf("%d %d",&m, &n);
    getchar();
    Dlink L = initList(m);
    //Display(L);
    char a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%c",&a[i]);
        getchar();
    }
    for (int j = 0; j < n; ++j) {
        L = location(L,a[j]);
    }
    Display(L);

    return 0;
 }