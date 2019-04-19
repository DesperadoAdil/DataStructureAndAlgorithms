#include <cstdio>

int n, A[10001], Diff[10001];

int cross (int l, int m, int h) {
    int sum = 0, maxl = -1e9, maxr = -1e9;
    for (int i = m; i >= l; i--) { //从中点开始向左寻找最大子数组
        sum += Diff[i];
        if (sum > maxl) maxl = sum;
    }
    sum = 0;
    for (int i = m+1; i <= h; i++) { //从中点开始向右寻找最大子数组
        sum += Diff[i];
        if (sum > maxr) maxr = sum;
    }
    return (maxl+maxr);
}

int find (int l, int h) {
    if (h == l) return Diff[h];
    int m = (h + l) / 2;
    int lsum = find (l, m); //最大子数组完全位于左子数组
    int rsum = find (m+1, h); //最大子数组完全位于右子数组
    int csum = cross (l, m, h); //最大子数组跨越了中点
    if (lsum >= rsum && lsum >= csum) return lsum; //返回最大的那一个
    else if (rsum >= lsum && rsum >= csum) return rsum;
    else return csum;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (i) Diff[i] = A[i] - A[i-1]; //差分
    }
    printf("%d\n", find(1, n));
    return 0;
}
