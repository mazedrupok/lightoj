#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <ll> prime;
bool mark[1000001] = {0};
void factor (int n) {
    for (int i = 2; i <= n; i++) {
        if (mark[i] == 0) {
            prime.push_back ((ll) i);
            for (int j = i+i; j <= n; j += i) {
                mark[j] = 1;
            }
        }
    }
}
int main ()
{
    int tc, cs = 0;
    factor (1000000);
    //cout << prime.size() << endl;
    ll a, b, lcm, ans, lcm_ab;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld %lld %lld", &a, &b, &lcm);
        if (lcm %a || lcm %b) {
            printf ("Case %d: impossible\n", ++cs);
            continue;
        }
        ans = 1;
        lcm_ab = (a*b) / __gcd (a, b);
        for (int i = 0; i < prime.size(); i++) {
            if (prime[i] > lcm) break;
            if (lcm %prime[i] == 0) {
                int cnt1 = 0, cnt2 = 0;
                while (lcm %prime[i] == 0) {
                    cnt1++;
                    lcm /= prime[i];
                }
                while (lcm_ab %prime[i] == 0) {
                    cnt2++;
                    lcm_ab /= prime[i];
                }
                if (cnt1 > cnt2) while (cnt1--) ans *= prime[i];
            }
        }

        printf ("Case %d: %lld\n", ++cs, ans);
    }
    return 0;
}
