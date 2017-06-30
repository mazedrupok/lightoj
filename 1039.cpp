#include <bits/stdc++.h>
#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
const double EPS = 1e-9;

using namespace std;
map <string, int> vis, level;
int fun (string s, string t) {
    if (vis[s] || vis[t]) return -1;
    queue <string> q;
    q.push(s);
    level[s] = 0;
    string u, v;
    while (q.empty() == 0) {
        u = q.front(); q.pop();
        if (u == t) return level[u];
        for (int i = 0; i < 3; i++) {
            v = u; v[i] == 'z' ? v[i] = 'a' : v[i] = char (v[i]+1);
            if (!vis[v]) {
                q.push (v);
                vis[v] = 1;
                level[v] = level[u] + 1;
            }
            v = u; v[i] == 'a' ? v[i] = 'z' : v[i] = char (v[i]-1);
            if (!vis[v]) {
                q.push (v);
                vis[v] = 1;
                level[v] = level[u] + 1;
            }
        }
    }
    return -1;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n;
    string s, t, q1, q2, q3;
    string str;
    sc (tc);
    while (tc--) {
        cin >> s >> t;
        sc (n);
        while (n--) {
            cin >> q1 >> q2 >> q3;
            For (i, q1.size())
            For (j, q2.size())
                For (k, q3.size()) {
                    str = "";
                    str += q1[i]; str += q2[j]; str += q3[k];
                    vis[str] = 1;
                }
        }
        printf ("Case %d: %d\n", ++cs, fun (s, t));
        level.clear();
        vis.clear();
    }
    return 0;
}

