#include <cstdio>

int n, A[10001], Diff[10001], ans, maxl;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (i) Diff[i] = A[i] - A[i-1]; //差分
    }
    ans = maxl = Diff[1]; //初始 最大子数组和边界最大子数组都是 Diff[1]
    for (int i = 2; i < n; i++) {
        if (maxl + Diff[i] >= Diff[i]) maxl += Diff[i]; //如果前边界最大子数组加上 Diff[i]之后更大了，那么更新成为新的边界最大子数组
        else maxl = Diff[i]; //否则 Diff[i]成为新的边界最大子数组
        if (maxl > ans) ans = maxl; //比较原最大子数组和边界最大子数组的较大者
    }
    printf("%d\n", ans);
    return 0;
}
