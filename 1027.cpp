#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e16;
const int N = 100005;
int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0, n, x, deno, nume, gc;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        deno = 0, nume = 0;
        while (n--) {
            scanf (" %d", &x);
            nume += abs (x);
            if (x > 0) deno++;
        }
        if (deno == 0) {
            printf ("Case %d: inf\n", ++cs);
            continue;
        }
        gc = __gcd (deno, nume);
        nume /= gc;
        deno /= gc;
        printf ("Case %d: %d/%d\n", ++cs, nume, deno);
    }
    return 0;
}
