#include <stdio.h>
#include <stdlib.h>
#define number 10
//三元组结构体
typedef struct {
    int i,j;    //行标，列标
    int data;   //数值
}triple;
//稀疏矩阵结构体
typedef struct {
    triple data[number];//存储该矩阵中所有非0元素的三元组
    int num;   //n和m分别记录矩阵的行数和列数，num记录矩阵中所有的非0元素的个数
}TsMatrix;

TsMatrix createMatrix(TsMatrix T){
    for (int i = 0; i < T.num; ++i) {
        scanf("%d %d %d",&T.data[i].i,&T.data[i].j,&T.data[i].data);
    }
    return T;
}
TsMatrix addMatrix(TsMatrix A, TsMatrix B){
    TsMatrix S;
    int v = 0;
    int i= 0, j = 0, k = 0;
    while (i < A.num && j < B.num) {
        if (A.data[i].i == B.data[j].i) {  //先控制行相等
            if (A.data[i].j < B.data[j].j) {
                S.data[k].data = A.data[i].data;
                S.data[k].i = A.data[i].i;
                S.data[k].j = A.data[i].j;
                k++;
                i++;
            } else if (A.data[i].j > B.data[j].j) {
                S.data[k].data = B.data[j].data;
                S.data[k].i = B.data[j].i;
                S.data[k].j = B.data[j].j;
                k++;
                j++;
            } else {
                v = A.data[i].data + B.data[j].data; //相加是否为0
                if (v != 0) {
                    S.data[k].data = v;
                    S.data[k].i = B.data[j].i;
                    S.data[k].j = B.data[j].j;
                    k++;
                }
                i++;
                j++;
            }
        } else if (A.data[i].i < B.data[j].i) { //行不相等
            S.data[k].data = A.data[i].data;
            S.data[k].i = A.data[i].i;
            S.data[k].j = A.data[i].j;
            k++;
            i++;
        } else {
            S.data[k].data = B.data[j].data;
            S.data[k].i = B.data[j].i;
            S.data[k].j = B.data[j].j;
            k++;
            j++;
        }
    }
    S.num = k;
    return S;

}

void Disp(TsMatrix M){
    for (int i = 0; i < M.num; ++i) {
        printf("%d %d %d\n",M.data[i].i, M.data[i].j, M.data[i].data);
    }

}
int main() {
    TsMatrix A, B, S;
    int m, n;
    scanf("%d %d",&m, &n);
    A.num = m;
    B.num = n;

    A = createMatrix(A);
    B = createMatrix(B);
    //Disp(A);
    //Disp(B);

    S = addMatrix(A, B);
    Disp(S);
    return 0;
}