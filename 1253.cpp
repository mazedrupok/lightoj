#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ios::sync_with_stdio(0); cin.tie(0);
//    freopen ("in.txt", "r", stdin);
//    freopen ("out.txt", "w", stdout);
    int n;
    int tc, cs = 0;
    int sum, x;
    scanf (" %d", &tc);
    while (tc--) {
        int cnt = 0;
        scanf (" %d", &n);
        sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf (" %d", &x);
            if(x == 1) cnt++;
            sum ^= x;
        }
        if (n == cnt) {
            if(cnt %2 == 0)  printf ("Case %d: Alice\n", ++cs);
            else printf ("Case %d: Bob\n", ++cs);
            continue;
        }
        if (sum == 0) printf ("Case %d: Bob\n", ++cs);
        else printf ("Case %d: Alice\n", ++cs);
    }
    return 0;
}
