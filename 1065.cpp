#include <bits/stdc++.h>
using namespace std;
int mat[2][2];
int mod;
void matSq (int e) {
    int tt[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int sum = 0;
            for (int k = 0; k < 2; k++) sum += (mat[i][k] * mat[k][j] %mod);
            tt[i][j] = sum %mod;
        }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            mat[i][j] = tt[i][j];

    if (e %2 == 1) { //if odd one more multiply with square
        int tq[2][2] = {1, 1, 1, 0};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int sum = 0;
                for (int k = 0; k < 2; k++) sum += (tt[i][k] * tq[k][j]) %mod;
                mat[i][j] = sum %mod;
            }
        }
    }
}
void bigmod (int e) {  //mat ^e %mod
    if (e <= 1) return;
    bigmod (e >> 1);
    matSq (e);
}
int main ()
{
    int tc, cs = 0, a, b, n, m, res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d %d %d", &a, &b, &n, &m);
        if (n == 0) {printf ("Case %d: %d\n", ++cs, a%m); continue;}
        if (n == 1) {printf ("Case %d: %d\n", ++cs, b%m); continue;}
        mod = 1;
        while (m--) mod *= 10;
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[1][0] = 1;
        mat[1][1] = 0;
        bigmod (n-1);
        res = (mat[0][0] * b) %mod + (mat[0][1] * a) %mod;
        printf ("Case %d: %d\n", ++cs, res %mod);
    }

    return 0;
}
