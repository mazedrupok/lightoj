#include <bits/stdc++.h>
using namespace std;
#define ll long long
char s[1001];
int len, dp[1001];
bool isPalin (int a, int b) {
    for (int i = a, j = b; i < j; i++, j--)
        if (s[i] != s[j]) return 0;
    return 1;
}
int fun (int pos) {
    if (pos >= len) return 0;
    int &ret = dp[pos];
    if (ret != -1) return ret;
    int best = len;
    for (int i = pos; i < len; i++) {
        if (isPalin(pos, i) == 1) {
            best = min (best, 1 + fun (i+1));
        }
    }
    return ret = best;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, x, k;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %s", s);
        len = strlen (s);
        memset (dp, -1, sizeof (dp));
        printf ("Case %d: %d\n", ++cs, fun (0));
    }

    return 0;
}
