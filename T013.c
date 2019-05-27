#include <stdio.h>
#include <stdlib.h>

typedef struct OLNode{
    int i, j, e; //矩阵三元组i代表行 j代表列 e代表当前位置的数据
    struct OLNode *right, *down;  //指针域 右指针 下指针
}OlNode, *OLink;

typedef struct
{
    OLink *rhead, *chead; //行和列链表头指针
    int mu, nu, tu;  //矩阵的行数,列数和非零元的个数
}CrossList;

CrossList create(CrossList M, int m, int n, int t){
    int a, b, c;
    OLink p, q;
    M.chead = (OLink *)malloc((n + 1) * sizeof(OLink));
    M.rhead = (OLink *)malloc((m + 1) * sizeof(OLink));
    M.mu = m;
    M.nu = n;
    M.tu = t;
    for (int i = 1; i <= m; i++)
    {
        M.rhead[i] = NULL;
    }
    for (int j = 1; j <= n; j++)
    {
        M.chead[j] = NULL;
    }
    for (int k = 0; k < t; ++k) {
        scanf("%d %d %d",&a, &b, &c);
        p = (OLink)malloc(sizeof(OlNode));
        p->i = a;
        p->j = b;
        p->e = c;
        //链接到行的指定位置
        if (NULL == M.rhead[a] || M.rhead[a]->j > b){
            M.rhead[a] = p;
            p->right = NULL;
        } else{
            for (q = M.rhead[a]; (q->right) && q->right->j < b; q = q->right);
            p->right = q->right;
            q->right = p;
        }
        //链接到列的指定位置
        if (NULL == M.chead[b] || M.chead[b]->i > a){
            M.chead[b] = p;
            p->down = NULL;
        }
        else
        {
            for (q = M.chead[b]; (q->down) && q->down->i < a; q = q->down);
            p->down = q->down;
            q->down = p;
        }

    }
    return M;

}
void Disp(CrossList M){
    for (int i = 1; i <= M.mu; ++i) {
        if(M.rhead[i] != NULL){
            OLink  p = M.rhead[i];
            while (p){
                printf("%d %d %d\n",p->i, p->j, p->e);
                p = p->right;
            }
        }
    }
}

CrossList AddMat(CrossList A, CrossList B){
    /*
     *
    当 pa 结点的列值 j > pb 结点的列值 j 或者 pa == NULL （说明矩阵 A 该行没有非 0 元素），两种情况下是一个结果，就是将 pb 结点插入到矩阵 A 中。
    当 pa 结点的列值 j < pb 结点的列值 j ，说明此时 pb 指向的结点位置比较靠后，此时需要移动 pa 的位置，找到离 pb 位置最近的非 0 元素，然后在新的 pa 结点的位置后边插入；
    当 pa 的列值 j == pb 的列值 j， 且两结点的值相加结果不为 0 ，只需要更改 pa 指向的结点的值即可；
    当 pa 的列值 j == pb 的列值 j ，但是两结点的值相加结果为 0 ，就需要从矩阵 A 的十字链表中删除 pa 指向的结点。
    *
    */
    OLink pa, pb;//新增两个遍历两个矩阵的节点
    OLink * hl=(OLink*)malloc(A.nu*sizeof(OLink));//用于存储当前遍历的行为止以上的区域每一个列的最后一个非0元素的位置。
    OLink pre=NULL;//用于指向pa指针所在位置的此行的前一个结点
    //遍历初期，首先要对hl数组进行初始化，指向每一列的第一个非0元素
    for (int j=1; j<=A.nu; j++) {
        hl[j]=A.chead[j];
    }
    //按照行进行遍历
    for (int i = 1; i <= A.mu ; ++i) {
        //遍历每一行以前，都要pa指向矩阵M当前行的第一个非0元素；指针pb也是如此，只不过遍历对象为矩阵N
        pa = A.rhead[i];
        pb = B.rhead[i];
        while (pb){    //当pb为NULL时，说明矩阵N的当前行的非0元素已经遍历完。
            //创建一个新的结点，每次都要复制一个pb结点，但是两个指针域除外。（复制的目的就是排除指针域的干扰）
            OLink p=(OlNode*)malloc(sizeof(OlNode));
            p->i=pb->i;
            p->j=pb->j;
            p->e=pb->e;
            p->down=NULL;
            p->right=NULL;

            //第一种情况
            if(pa == NULL || pa->j > pb->j){
                //如果pre为NULL，说明矩阵M此行没有非0元素
                if (pre == NULL) {
                    A.rhead[p->i]=p;
                }else{
            //由于程序开始时pre肯定为NULL，所以，pre指向的是第一个p的位置，在后面的遍历过程中，p指向的位置是逐渐向后移动的，所有，pre肯定会在p的前边
                    pre->right=p;
                }
                p->right=pa;
                pre=p;
                //在链接好行链表之后，链接到对应列的列链表中的相应位置
                if (!A.chead[p->j]||A.chead[p->j]->i>p->i) {
                    p->down=A.chead[p->j];
                    A.chead[p->j]=p;
                }else{
                    p->down=hl[p->j]->down;
                    hl[p->j]->down=p;
                }
                //更新hl中的数据
                hl[p->j]=p;
            }else{
                //第二种情况，只需要移动pa的位置，继续判断pa和pb的位置，一定要有continue
                if (pa->j<pb->j) {
                    pre=pa;
                    pa=pa->right;
                    continue;
                }
                //第三、四种情况，当行标和列标都想等的情况下，需要讨论两者相加的值的问题
                if (pa->j==pb->j) {
                    pa->e+=pb->e;
                    //如果为0，摘除当前结点，并释放所占的空间
                    if (pa->e==0) {
                        if (pre==NULL) {
                            A.rhead[pa->i]=pa->right;
                        }else{
                            pre->right=pa->right;
                        }
                        p=pa;
                        pa=pa->right;
                        if (A.chead[p->j]==p) {
                            A.chead[p->j]=hl[p->j]=p->down;
                        }else{
                            hl[p->j]->down=p->down;
                        }
                        free(p);
                    }
                }
            }
            pb=pb->right;
        }
    }
    //用于输出矩阵三元组的功能函数
    Disp(A);
    return A;

}
int main() {
    int m, n, t1, t2;
    scanf("%d %d %d %d", &m, &n, &t1, &t2);  //矩阵的行数、列数，AB矩阵非零元素个数；
    CrossList A, B;
    A.rhead = NULL;
    A.chead = NULL;
    B.rhead = NULL;
    B.chead = NULL;
    A = create(A, m, n, t1);
    B = create(B, m, n, t2);
    A = AddMat(A, B);
    //Disp(A);
    //Disp(B);

    return 0;
}