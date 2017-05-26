#include <bits//stdc++.h>
using namespace std;
#define ll long long
#define MX 100005
ll a[MX];
int freq[MX];
void solve() {
    int n, m;
    scanf (" %d %d", &n, &m);
    ll ans = 0;
    a[0] = 0;
    memset (freq, 0, sizeof (freq));
    for (int i = 1; i <= n; ++i) {
        scanf (" %d", &a[i]);
        a[i] %= m;
        a[i] = (a[i] + a[i - 1]) % m;
        ans += freq[a[i]];
        freq[a[i]]++;
    }
    ans += freq[0];

    printf("%lld\n", ans);
}

int main()
{
    freopen ("in.txt", "r", stdin);
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        printf ("Case %d: ", ++cs);
        solve ();
    }
    return 0;
}
