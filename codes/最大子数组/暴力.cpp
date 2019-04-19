#include <cstdio>

int n, A[10001], ans = -1e9;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++) {
            int diff = A[j] - A[i];
            if (diff > ans)
                ans = diff;
        }
    printf("%d\n", ans);
    return 0;
}

/* 样例输入 输出43
17
100 113 110 85 105 102 86 63 81 101 94 106 101 79 94 90 97
*/
