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
    //printf("\n");
}
int main() {
    int n[3];
    for (int i = 0; i < 3; ++i) {
        scanf("%d",&n[i]);
    }
    Linklist a, b, c;
    a = initLklist(n[0]);
    b = initLklist(n[1]);
    c = initLklist(n[2]);
    Linklist pa = a;
    Linklist pb = b->next;
    Linklist pc = c->next;
    Linklist head = a;
    //DisplayLk(a);
    //DisplayLk(b);
    //DisplayLk(c);
    while (pa->next && pb && pc){
        if(pb->ele != pc->ele ){  //b c表元素不相同
            if(pb->ele > pc->ele)
                pc = pc->next;
            else
                pb = pb->next;
        }
        if(pb && pc){     //b c 表中有相同元素
            while(pb->next!=NULL&&pb->ele==pb->next->ele || pc->next!=NULL&&pc->ele==pc->next->ele){//使pa和pb移向重复元素中的最后一个元素
                if(pb->next!=NULL && pb->ele==pb->next->ele)
                    pb=pb->next;
                if(pc->next!=NULL && pc->ele==pc->next->ele)
                    pc=pc->next;
            }
            while (pa->next != NULL && pa->next->ele < pb->ele)
                pa = pa->next;
            if(pa->next != NULL && pa->next->ele == pb->ele){
                Linklist q=pa->next;
                pa->next=q->next;
                free(q);
            }
            pb=pb->next;
            pc=pc->next;//pa pb同时移动到下一个节点
        }

    }
    DisplayLk(a);
    return 0;
}