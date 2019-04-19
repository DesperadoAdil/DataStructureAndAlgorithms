#include <cstdio>

int n, A[11][11], B[11][11], C[11][11];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf ("%d", &A[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf ("%d", &B[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                C[i][j] += A[i][k] * B[k][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}
