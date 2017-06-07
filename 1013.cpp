#include <bits/stdc++.h>
#define ll long long
using namespace std;
int sz, tz, len;
char s[31], t[31];
int dp[31][31];
ll dp1[31][31][61];
int fun (int i, int j) {
    if (i == sz) return tz-j;
    if (j == tz) return sz-i;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = 1e9;
    if (s[i] == t[j]) ret = min (ret, 1 + fun (i+1, j+1));
    else {
        ret = min (ret, 1 + fun (i+1, j));
        ret = min (ret, 1 + fun (i, j+1));
    }
    return ret;
}
ll fun1 (int i, int j, int l) {
    if (i == sz) {
        if (l+tz-j == len) return 1;
        return 0;
    }
    if (j == tz) {
        if (l+sz-i == len) return 1;
        return 0;
    }
    ll &ret = dp1[i][j][l];
    if (ret != -1) return ret;
    ret = 0;
    if (s[i] == t[j]) {
        ret += fun1 (i+1, j+1, l+1);
    }
    else {
        ret += fun1 (i+1, j, l+1);
        ret += fun1 (i, j+1, l+1);
    }
    return ret;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n, q, a, b, k;
    scanf (" %d", &tc);

    while (tc--) {
        memset (dp, -1, sizeof (dp));
        memset (dp1, -1, sizeof (dp1));
        scanf (" %s %s", s, t);
        sz = strlen(s);
        tz = strlen(t);
        len = fun (0, 0);
        printf ("Case %d: %d %lld\n", ++cs, len, fun1(0,0,0));
    }
    return 0;
}
