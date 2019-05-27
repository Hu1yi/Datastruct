#include <stdio.h>
#include <stdlib.h>

int enQueen(char *a, int front, int rear, char ele, int max){
    if(((rear + 1) % max) == front) {//添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
        return rear;
    }
    a[rear%max] = ele;
    rear++;
    return rear;

}
int deQueen(char *a, int front, int rear, int max){
    if(rear == front) {//如果front==rear，表示队列为空
        return front;
    }
    //printf("%c ",a[front]);
    front = (front + 1) % max;
    return front;

}

int main() {
    int n;
    char ele;
    int rear = 0, front = 0, length = 0, i = 0;
    scanf("%d",&n);
    getchar();
    int max = n + 1;
    char a[max];
    while (1) {
        while ((ele = getchar()) != '\n') {
            if (ele == 32) continue;
            rear = enQueen(a, front, rear, ele, max);
            length++;
        }
        if (length == n) {
            printf("yes\n");
            break;
        }
        else {
            printf("no\n");
            continue;

        }
    }
    scanf("%c",&ele);
    while (a[front] != ele){
        front = deQueen(a,front,rear,max);
    }
    front = deQueen(a,front,rear,max);
    for (int j = front; j < rear; ++j) {
        printf("%c ",a[j]);
    }
    printf("\n%c",a[front]);
    return 0;
}