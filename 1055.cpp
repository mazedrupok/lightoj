#include <bits/stdc++.h>

#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
#define pb push_back
#define mk make_pair
#define pr pair<int,int>
#define ff first
#define ss second
using namespace std;
int dx4[]={0,0,-1,1}; int dy4[]={1,-1,0,0}; //4 direction

int n;
char s[11][11];
pr A, B, C;
vector <pr > T;
pr move (pr u, int i) {
    pr v;
    v.ff = u.ff + dx4[i];
    v.ss = u.ss + dy4[i];
    if (v.ff < 0 || v.ff >= n || v.ss < 0 || v.ss >= n) return u;
    if (s[v.ff][v.ss] == '#') return u;
    return v;
}
bool check_desti (pr a, pr b, pr c) {
    vector <pr> tm;
    tm = T;
    do {
        if (a == tm[0] && b == tm[1] && c == tm[2]) return 1;
    } while (next_permutation(tm.begin(), tm.end()));
    return 0;
}
int bfs () {
    queue <pair<pair<pr,pr>, pr> > q;
    map <pair<pair<pr,pr>, pr>, int> step;
    pair <pair<pr,pr>, pr> u, v;
    u = mk(mk(A,B), C);
    q.push (u);
    step[u] = 0;
    while (!q.empty()) {
        u = q.front(); q.pop();
        A = u.ff.ff;
        B = u.ff.ss;
        C = u.ss;
        if (check_desti(A,B,C)) return step[u];
        For (i, 4) {
            pr a, b, c;
            a = move (A, i);
            b = move (B, i);
            c = move (C, i);
            if (a == b && b == c) {a = A; b = B; c = C;}
            if (a == b) {a = A; b = B;}
            if (a == c) {a = A; c = C;}
            if (c == b) {c = C; b = B;}
            v = mk(mk(a,b), c);
            if (step.count(v) == 0) {
                step[v] = step[u] + 1;
                q.push (v);
            }
        }
    }
    return -1;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0;
    sc (tc);
    while (tc--) {
        sc (n);
        For (i, n)
        For (j, n) {
            scc (s[i][j]);
            if (s[i][j] == 'A') A = mk (i, j) , s[i][j] = '.';
            if (s[i][j] == 'B') B = mk (i, j) , s[i][j] = '.';
            if (s[i][j] == 'C') C = mk (i, j) , s[i][j] = '.';
            if (s[i][j] == 'X') T.pb (mk (i, j) ) , s[i][j] = '.';
        }
        int res = bfs ();
        if (res == -1) printf ("Case %d: trapped\n", ++cs);
        else printf ("Case %d: %d\n", ++cs, res);

        T.clear();
    }
    return 0;
}
