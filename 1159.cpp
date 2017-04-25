#include <bits/stdc++.h>
using namespace std;
int len1, len2, len3;
int dp[51][51][51];
char a[51], b[51], c[51];
int fun (int i, int j, int k) {
    if (i >= len1 || j >= len2 || k >= len3) return 0;
    int &ret = dp[i][j][k];
    if (ret != -1) return ret;
    int w, x, y, z;
    w = x = y = z = 0;
    if (a[i] == b[j] && b[j] == c[k]) w = 1 + fun (i+1, j+1, k+1);
    x = fun (i+1, j, k);
    y = fun (i, j+1, k);
    z = fun (i, j, k+1);
    return ret = max (max (w, x), max (y, z));
}
int main ()
{
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %s %s %s", a, b, c);
        len1 = strlen (a);
        len2 = strlen (b);
        len3 = strlen (c);
        memset (dp, -1, sizeof (dp));
        printf ("Case %d: %d\n", ++cs, fun (0, 0, 0));
    }
    return 0;
}
