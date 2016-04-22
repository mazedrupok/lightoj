#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, tc, cs = 0, d, cnt, m;

    scanf(" %d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &d);
        m = d %n;
        cnt = 1;
        while (m) {
            m = (m *10 + d);
            m = m %n;
            cnt++;
        }
        printf ("Case %d: %d\n", ++cs, cnt);
    }
    return 0;
}
