#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[1001], t[1001];
int sz, tz;
int dp[1001][1001];
int pp[1001][1001];
void mod (int &r) {
    if (r < 0) r += 1000007;
    r %= 1000007;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, q;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %s %s", s+1, t+1);
        sz = strlen (s+1);
        tz = strlen (t+1);
        for (int i = 0; i <= sz; i++) {
            for (int j = 0; j <= tz; j++) {
                if (i == 0 || j == 0) {dp[i][j] = 0; continue;}
                if (s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
            }
        }
        //cout << dp[sz][tz] << endl;
        for (int i = 0; i <= sz; i++) {
            for (int j = 0; j <= tz; j++) {
                if (i == 0 || j == 0) {pp[i][j] = 1; continue;}
                pp[i][j] = 0;
                if (s[i] == t[j]) pp[i][j] = pp[i-1][j-1];
                else {
                    if (dp[i][j] == dp[i-1][j]) pp[i][j] += pp[i-1][j];     mod (pp[i][j]);
                    if (dp[i][j] == dp[i][j-1]) pp[i][j] += pp[i][j-1];     mod (pp[i][j]);
                    if (dp[i][j] == dp[i-1][j-1]) pp[i][j] -= pp[i-1][j-1]; mod (pp[i][j]);
                }
            }
        }
        printf ("Case %d: %d\n", ++cs, pp[sz][tz]);
    }
    return 0;
}
