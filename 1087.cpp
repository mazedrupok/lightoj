#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n, x, q, a, b;
    char ch;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        vector <int> vc;
        for (int i = 0; i < n; i++) {
            scanf (" %d", &x);
            vc.push_back (x);
        }
        printf ("Case %d:\n", ++cs);
        while (q--) {
            scanf (" %c %d", &ch, &b);
            if (ch == 'c') {
                if (b > vc.size()) printf ("none\n");
                else {
                    b--;
                    printf ("%d\n", vc[b]);
                    vc.erase(vc.begin() + b);
                }
            }
            else {
                vc.push_back (b);
            }
        }
    }

    return 0;
}
