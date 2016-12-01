/*
  Lightoj 1070
  a^2+b^2 = (a+b) (a+b) - 2ab
  a^3+b^3 = (a^2+b^2) (a+b) - (a+b) (a+b)
  a^4+b^4 = (a^3+b^3) (a+b) - (a^2+b^2) (a+b)
  So, F(n) = (a+b) * F(n-1) + ab * F(n-2)
*/
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
ULL mat[2][2], a, b;
void bigmodExpon (int e) {
    if (e <= 1) return;
    bigmodExpon (e>>1);
    ULL tt[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ULL sum = 0;
            for (int k = 0; k < 2; k++) sum += mat[i][k] * mat[k][j];
            tt[i][j] = sum;
        }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) mat[i][j] = tt[i][j];
    if (e %2 == 1) {
        ULL temp[2][2] = {a, -b, 1, 0};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ULL sum = 0;
                for (int k = 0; k < 2; k++) sum += tt[i][k] * temp[k][j];
                mat[i][j] = sum;
            }
        }
    }
}
int main ()
{
    int tc, cs = 0, n;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %llu %llu %d", &a, &b, &n);
        printf ("Case %d: ", ++cs);
        if (n == 0) {printf ("2\n"); continue; }
        if (n == 1) {printf ("%llu\n", a); continue; }
        mat[0][0] = a; mat[0][1] = -b; mat[1][0] = 1; mat[1][1] = 0;
        bigmodExpon (n-1);
        printf ("%llu\n", mat[0][0] * a + mat[0][1] * 2);
    }

    return 0;
}
