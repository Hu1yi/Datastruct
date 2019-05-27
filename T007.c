#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct lineStack{
    char data;
    struct lineStack * next;
}lineStack;

lineStack* push(lineStack * stack,char a){
    //创建存储新元素的节点
    lineStack * line=(lineStack*)malloc(sizeof(lineStack));
    line->data=a;
    //新节点与头节点建立逻辑关系
    line->next=stack;
    //更新头指针的指向
    stack=line;
    return stack;
}
lineStack * pop(lineStack * stack){
    if (stack) {
        //声明一个新指针指向栈顶节点
        lineStack * p=stack;
        //更新头指针
        stack=stack->next;
        free(p);
    }else{
        printf("栈内没有元素");
        return stack;
    }
    return stack;
}

int main() {
    lineStack * stack = NULL;
    char a[SIZE] ;
    gets(a);
    char *b = a;
    while (*b != '\0'){
        if (*b == '{' || *b == '[' || *b == '('){
            stack = push(stack, *b);
            b++;
            continue;
        }
        if ((*b == '}' && stack->data == '{')||(*b == ']' && stack->data == '[')||(*b == ')' && stack->data == '(')) {
            stack = pop(stack);
            b++;
            continue;
        }
        if ((*b == '}' && stack->data != '{')||(*b == ']' && stack->data != '[')||(*b == ')' && stack->data != '(')){
            printf("no\n");
            return 0;
        }
        b++;
    }

        printf("yes\n");
    return 0;
}