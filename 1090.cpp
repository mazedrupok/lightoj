/* lightoj 1090*/
#include <bits/stdc++.h>
#define pb push_back
#define ull unsigned long long
#define MX 5000001
using namespace std;
int func (int d, int n) {
    int cnt = 0;
    for (int i = d; i <= n; i = i*d) cnt += (int) (n/i);
    return cnt;
}
int main ()
{
    int tc, cs = 0, n, r, p, q, twos, fives, zeros, cnt;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d %d %d", &n, &r, &p, &q);
        twos = 0, fives = 0;
        zeros = 0;
        twos += func (2, n); //2's can be less, must calculate
        fives += func (5, n);
        twos -= func (2, n-r);
        fives -= func (5, n-r);
        twos -= func (2, r);
        fives -= func (5, r);

        int cnt5 = 0, cnt2 = 0;
        while (p %5 == 0) {
            p /= 5; cnt5++;
        }
        while (p %2 == 0) {
            p /= 2; cnt2++;
        }

        fives += (cnt5*q);
        twos += (cnt2*q);
        //cout << fives << " " << twos << endl;
        zeros = max (0, min (twos, fives));
        printf ("Case %d: %d\n", ++cs, zeros);
    }
    return 0;
}
