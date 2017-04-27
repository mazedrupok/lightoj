#include <bits/stdc++.h>
using namespace std;
char a[105], b[105];
int dp[105][105] = {0};
string str[105][105];
int main ()
{
    freopen ("in.txt", "r", stdin);
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %s %s", a, b);
        int len1 = strlen(a), len2 = strlen (b);
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) str[i][j] = "";
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    str[i][j] = str[i-1][j-1] + a[i-1];
                }
                else if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    str[i][j] = str[i-1][j];
                }
                else if (dp[i-1][j] < dp[i][j-1]) {
                    dp[i][j] = dp[i][j-1];
                    str[i][j] = str[i][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                    str[i][j] = min (str[i][j-1], str[i-1][j]);
                }
            }
        }
        if (dp[len1][len2] == 0) printf ("Case %d: :(\n", ++cs);
        else printf ("Case %d: %s\n", ++cs, str[len1][len2].c_str());
    }
    return 0;
}
