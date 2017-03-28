#include <bits/stdc++.h>
using namespace std;

const int MX = 505;
int grun[MX][MX];
int dx[] = {-2, -3, -2, -1, -1,  1};
int dy[] = { 1, -1, -1, -2, -3, -2};

int fun (int x, int y) {
    if( x == 0 && y == 0) return 0; // base case , grundy is always zero
    if (x == 1 && y == 0) return 0;
    if (x == 1 && y == 1) return 0;
    int &ret = grun[x][y];
    if( ret != -1 ) return ret;

    set <int> s;
    for (int i = 0;  i < 6; i++) {
        if(x + dx[i] >= 0 && y + dy[i] >= 0) s.insert( fun (x+dx[i], y+dy[i]) );
    }
    int ans = 0;
    while(s.find(ans) != s.end()) ans++;
    return ret = ans;
}
int main()
{
    memset (grun, -1, sizeof (grun));
    int cs = 0, tc, n, x, y, ans;
    scanf(" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        ans = 0;
        while (n--) {
            scanf (" %d %d", &x, &y);
            ans ^= fun (x, y);
        }
        if ( ans ) printf ("Case %d: Alice\n", ++cs);
        else printf ("Case %d: Bob\n", ++cs);
    }
    return 0;
}
