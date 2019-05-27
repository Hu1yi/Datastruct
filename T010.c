#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *Date;
    int front;
    int rear;
    int K;
} Queue;
Queue* CreateQueue(int k){
    Queue *Q;
    Q = (Queue*)malloc(sizeof(Queue));
    Q->K = k + 1;
    Q->Date = (int*)malloc(sizeof(int)*Q->K);
    Q->front = Q->rear = 0;
    return Q;
}

void AddQ(Queue *Q, int item) {
    if((Q->rear+1)%Q->K == Q->front){
        return;
    } else{
        Q->rear = (Q->rear+1)%Q->K;
        Q->Date[Q->rear] = item;
    }

}

int DeleteQ(Queue *Q)
{
    if(Q->rear == Q->front){
        printf("队列为空\n");
        return NULL;
    }
    else{
        Q->front = (Q->front+1)%Q->K;
        return Q->Date[Q->front];
    }
}
void Fibonacci(int k,int max)
{
    Queue *q;
    int i, item, t = 1,j = 0;
    q = CreateQueue(k);
    for(i = 0; i<k; i++)
        if(i == k-1)
            AddQ(q,1);
        else
            AddQ(q,0);
    while(t <= max){
        j++;
        //printf("%d ",DeleteQ(q));
        DeleteQ(q);
        AddQ(q,t);
        t = 0;
        for(i = 0; i<k; i++){
            item = DeleteQ(q);
            t += item;
            AddQ(q,item);
        }
    }
    for(i = 0; i<k; i++){
        item = DeleteQ(q);
        printf("%d ", item);
        AddQ(q,item);
    }
}
int main() {
    int max, k;
    scanf("%d %d",&max,&k);
    Fibonacci(k, max);

}