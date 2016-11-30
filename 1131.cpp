#include <bits/stdc++.h>
using namespace std;
int mat[6][6];
int mod, a1, b1, c1, a2, b2, c2;
void bigmodExpon (int e) {  //mat ^e %mod
    if (e <= 1) return;
    bigmodExpon (e >> 1);
    int tt[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int sum = 0;
            for (int k = 0; k < 6; k++) sum += (mat[i][k] * mat[k][j]) %mod;
            tt[i][j] = sum %mod;
        }
    }
    for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++) mat[i][j] = tt[i][j];

    if (e %2 == 1) { //if odd one more multiply with previous square
        int temp[6][6];
        for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) temp[i][j] = 0;
        temp[0][0] = a1; temp[0][1] = b1; temp[0][5] = c1;
        temp[3][2] = c2; temp[3][3] = a2; temp[3][4] = b2;
        temp[1][0] = temp[2][1] = temp[4][3] = temp[5][4] = 1;

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                int sum = 0;
                for (int k = 0; k < 6; k++) sum += (tt[i][k] * temp[k][j]) %mod;
                mat[i][j] = sum %mod;
            }
        }
    }
}
int main ()
{
    int tc, cs = 0, n, f0, f1, f2, g0, g1, g2, Fn, Gn, q;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d %d", &a1, &b1, &c1);
        scanf (" %d %d %d", &a2, &b2, &c2);
        scanf (" %d %d %d", &f0, &f1, &f2);
        scanf (" %d %d %d", &g0, &g1, &g2);
        scanf (" %d %d", &mod, &q);
        printf ("Case %d:\n", ++cs);
        while (q--) {
            scanf (" %d", &n);
            if (n == 0) {printf ("%d %d\n", f0 %mod, g0 %mod); continue; }
            else if (n == 1) {printf ("%d %d\n", f1 %mod, g1 %mod); continue; }
            else if (n == 2) {printf ("%d %d\n", f2 %mod, g2 %mod); continue; }
            else if (n == 3) {printf ("%d %d\n", (a1*f2 + b1*f1 + c1*g0) %mod, (a2*g2 + b2*g1 + c2*f0) %mod); continue; }
            for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++) mat[i][j] = 0;
            mat[0][0] = a1; mat[0][1] = b1; mat[0][5] = c1;
            mat[3][2] = c2; mat[3][3] = a2; mat[3][4] = b2;
            mat[1][0] = mat[2][1] = mat[4][3] = mat[5][4] = 1;

            bigmodExpon (n-2);
            Fn = (mat[0][0] * f2)%mod + (mat[0][1] * f1)%mod + (mat[0][2] * f0)%mod + (mat[0][3] * g2)%mod + (mat[0][4] * g1)%mod + (mat[0][5] * g0)%mod;
            Gn = (mat[3][0] * f2)%mod + (mat[3][1] * f1)%mod + (mat[3][2] * f0)%mod + (mat[3][3] * g2)%mod + (mat[3][4] * g1)%mod + (mat[3][5] * g0)%mod;
            printf ("%d %d\n", Fn %mod, Gn %mod);
        }
    }

    return 0;
}
