#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[33][2][2][33], len;
string s;
ll fun (int i, bool pre, bool small, int l) {
    if (i == len) return l;
    ll &ret = dp[i][pre][small][l];
    if (ret != -1) return ret;
    ll a = 0, b = 0;
    if (s[i] == '1') {
        if (pre == 1) a = fun (i+1, 1, small, l+1);
        else a = fun (i+1, 1, small, l);
        b = fun (i+1, 0, 1, l);
    }
    else {
        if (small) {
            if (pre) a = fun (i+1, 1, small, l+1);
            else a = fun (i+1, 1, small, l);
        }
        b = fun (i+1, 0, small, l);
    }
    return ret = a+b;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n, q, a, b, k;
    scanf (" %d", &tc);
    while (tc--) {
    memset (dp, -1, sizeof (dp));
        scanf (" %d", &n);
        int p = n;
        len = 0;
        s = "";
        while (p) {
            s += (p%2 + 48);
            p >>= 1;
            len++;
        }
        reverse (s.begin(), s.end());
        //cout << s << endl;


        printf ("Case %d: %lld\n", ++cs, fun (0, 0, 0, 0));
    }
    return 0;
}
