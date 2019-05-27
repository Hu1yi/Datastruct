#include <stdio.h>
#include <stdlib.h>

void init(int *a, int m){
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
}

void Display(int *a, int n){
    for (int i = 0; i < n; ++i) {
        printf("%d\n",a[i]);
    }
}

void merge(int *a, int *b, int m, int n, int *s){
    int i, j ,k;
    for ( i = 0, j = 0, k =0; i < m, j < n; k++) {
        if (a[i] < b[j]){
            s[k] = a[i];
            i++;
        } else if(a[i] > b[j]) {
            s[k] = b[j];
            j++;
        } else{
            s[k++] = a[i++];
            s[k] = b[j++];
        }
    }
    if(i != m){
        for (; i < m; ++i) {
            s[k++] = a[i];
        }
    }
    if(j != n){
        for (; j < n; ++j) {
            s[k++] = b[j];
        }
    }

}

int main() {
    int m, n;
    scanf("%d",&m);
    int a[m];
    init(a, m);
    scanf("%d",&n);
    int b[n];
    init(b, n);
    //Display(a, m);
    //Display(b, n);
    int k = m + n;
    int c[k];
    int *s ;
    s = c;
    merge(a, b, m, n, s);
    Display(s, m+n);
    return 0;
}