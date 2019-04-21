#include <cstdio>
#include <cstring>
#define N 50

void multiply (int a[][N], int ai, int aj, int b[][N], int bi, int bj, int c[][N], int ci, int cj, int n) {
    if (n == 1) c[ci][cj] += a[ai][aj] * b[bi][bj];
    else {
        multiply (a, ai    , aj    , b, bi    , bj    , c, ci    , cj    , n/2);
        multiply (a, ai    , aj+n/2, b, bi+n/2, bj    , c, ci    , cj    , n/2);
        multiply (a, ai    , aj    , b, bi    , bj+n/2, c, ci    , cj+n/2, n/2);
        multiply (a, ai    , aj+n/2, b, bi+n/2, bj+n/2, c, ci    , cj+n/2, n/2);
        multiply (a, ai+n/2, aj    , b, bi    , bj    , c, ci+n/2, cj    , n/2);
        multiply (a, ai+n/2, aj+n/2, b, bi+n/2, bj    , c, ci+n/2, cj    , n/2);
        multiply (a, ai+n/2, aj    , b, bi    , bj+n/2, c, ci+n/2, cj+n/2, n/2);
        multiply (a, ai+n/2, aj+n/2, b, bi+n/2, bj+n/2, c, ci+n/2, cj+n/2, n/2);
    }
}

int main () {
    int n;
    int a[N][N], b[N][N], c[N][N];
    memset(c, 0, sizeof(c));
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &b[i][j]);
    multiply (a, 0, 0, b, 0, 0, c, 0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
