#include <stdio.h>
#include <stdlib.h>

typedef struct link{
    int data;
    struct link *next, *pre;
}lnode, *linklist;

linklist initlist(linklist L){
    linklist p = L;
    linklist s;
    for (int i = 0; i < 5000; ++i) {
        s = (linklist)malloc(sizeof(lnode));
        s->data = 0;

        s->next = L;
        s->pre = p;
        p->next = s;
        L->pre = s;
        p = p->next;
    }
    return L;
}
int main() {
    int n;
    linklist num, sum;
    scanf("%d", &n);

    num = initlist(num);
    sum = initlist(sum);

    num->next->data = 2;
    sum->next->data = 2;

    linklist p, q;
    p = num->pre;
    int temp = 0, ret = 0;
    for (int i = 1; i < 5000; ++i) {
        p = num->pre;
        while (p != num){  //计算除法，从后往前，一直到num
            temp = (p->data * i + ret);
            p->data = temp % 10;
            ret = temp / 10;
            p = p->pre;
        }
        ret = 0;
        p = num->next;

        while (p != num){  //计算乘法，从前往后
            temp = (ret * 10 + p->data);
            p->data = temp / (2 * i + 1);
            ret = temp % (2 * i + 1);
            p = p->next;
        }

        ret = 0;
        p = num->pre;
        q = sum->pre;
        while (p != num){
            temp = ret + p->data +q->data;
            q->data = temp % 10;
            ret = temp / 10;
            q = q->pre;
            p = p->pre;
        }

    }
    printf("3.");
    q = sum->next->next;
    //q = sum;
    while (n){
        printf("%d",q->data);
        q = q->next;
        n--;
    }
    printf("\n");
    return 0;
}