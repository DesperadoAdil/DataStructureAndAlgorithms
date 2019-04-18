#include <cstdio>

int n, A[10001];

int main () {
    scanf ("%d", &n); //序列元素个数
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]); //要排序的序列
    for (int i = 2; i <= n; i++) {
        int key = A[i], j = i - 1;
        while (j > 0 && A[j] > key)
            A[j+1] = A[j--];
        A[j+1] = key;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    return 0;
}
