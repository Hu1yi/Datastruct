#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int l, int r){
    int temp;
    while (l < r){
        temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }
}
void clcirshiftright(int n, int k ){
    int a[n+1];
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }
    k = k % n; //循环右移的结果和右移的前n(数组长度）个结果一致，所以做取余操作。
    if(k == 0) // 如果取余操作之后的m等于0，则不需要移动
        return;
    else{
        swap(a, 1, n-k);
        swap(a, n-k+1,n);
        swap(a, 1, n);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ",a[i]);
    }

}


int main() {
    int n ,k;
    scanf("%d %d",&n, &k);
    clcirshiftright(n, k);
    return 0;
}