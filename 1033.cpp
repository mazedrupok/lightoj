#include <bits/stdc++.h>
using namespace std;
string s;
int dp[100][100];
int func (int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    if (s[l] == s[r]) dp[l][r] = func (l+1, r-1);
    else dp[l][r] = 1 + min (func (l+1, r), func (l, r-1));
    return dp[l][r];
}
int main ()
{
    int tc, cs = 0;
    cin >> tc;
    while (tc--) {
        cin >> s;
        memset (dp, -1, sizeof (dp));
        printf ("Case %d: %d\n", ++cs, func (0, s.size()-1));
    }
    return 0;
}
