#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
/*
 * 本题有一定的问题，需要重新考虑
 * */

typedef struct stack{
    char data;
    struct stack *next;
}lineStack;

int getpri(char a){
    switch (a){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }

}

lineStack * push(lineStack *stack, char ele){
    lineStack *temp = (lineStack *)malloc(sizeof(lineStack));
    temp->data = ele;
    temp->next = stack;
    stack = temp;
    return stack;
}

lineStack *pop(lineStack *stack){
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
        if (*b == '('){
            stack = push(stack, *b);
        } else if(*b == ')'){
            while (stack){
                if(stack->data != '(')
                    printf("%c",stack->data);
                stack = pop(stack);
            }
        } else if(*b == '+' || *b == '-'|| *b == '/'|| *b == '*') {
            if(stack == NULL) {
                stack = push(stack, *b);
            }else if (getpri(stack->data) < getpri(*b)){
                stack = push(stack, *b);
            } else{
                while (stack){
                    if(stack->data != '(')
                        printf("%c", stack->data);
                    stack = pop(stack);
                }
                stack = push(stack, *b);
            }
        } else
            printf("%c",*b);
        b++;
    }
    if(stack){
        printf("%c",stack->data);
        stack = pop(stack);
    }
    return 0;
}