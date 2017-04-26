#include <bits/stdc++.h>
using namespace std;
#define ll long long
char s[51];
int len, dp[51][51][51];
bool mix = 0;
bool fun (int pos, int zero, int one) {
    if (one > 2 || zero > 4) return 0; //bad
    if (pos >= len) return 1;
    int &ret = dp[pos][zero][one];
    if (ret != -1) return ret;

    if (s[pos] == '1') return ret = fun (pos+1, 0, one+1);
    else if (s[pos] == '0') return ret = fun (pos+1, zero+1, 0);
    else if (s[pos] == '?') {
        bool a = fun (pos+1, zero+1, 0);
        bool b = fun (pos+1, 0, one+1);
        if (a ^ b == 1) mix = 1;
        return ret = a|b;
    }
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, x, k;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %s", s);
        len = strlen (s);
        for (int i = 0; i < len; i++) {
            if (s[i] == '?') continue;
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') s[i] = '1';
            else s[i] = '0'; //consonant, can be 5 zeros
        }
        memset (dp, -1, sizeof (dp));
        mix = 0;
        bool pp = fun (0, 0, 0);
        printf ("Case %d: ", ++cs);
        if (mix == 1) printf ("MIXED\n");
        else if (pp == 0) printf ("BAD\n");
        else printf ("GOOD\n");
    }

    return 0;
}
