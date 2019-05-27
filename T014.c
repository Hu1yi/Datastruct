#include <stdio.h>
#include <stdlib.h>

typedef enum {ATOM, LIST} ElemTag;
typedef char AtomElem;

typedef struct GLNode{
    ElemTag tag;
    union {
        AtomElem atom;
        struct {
            struct GLNode *head, *tail;
        }ptr;
    };
}*GList,List;

GList createGlist(GList C){
    C = (GList)malloc(sizeof(List));


}
int main(){

}